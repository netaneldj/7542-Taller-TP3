#include "common_Socket.h"
#include <cstring>
#include <unistd.h>
#include <stdexcept>

#define ACCEPT_QUEUE_LEN 10
#define SKT_ERROR -1

SocketError::SocketError() throw() {
	int _errno = errno;

	const char *m = strerror(_errno);
	strncpy(msg_error, m, SKT_ERROR_BUFF_LEN);

	msg_error[SKT_ERROR_BUFF_LEN - 1] = '\0';
}

const char* SocketError::what() const throw() {
	return msg_error;
}

SocketError::~SocketError() throw() {}

Socket::Socket() {
	this->s = 0;
	this->skt = 0;
    this->ptr = NULL;
    this->addr = NULL;
}

Socket::Socket(int skt) {
	this->s = 0;
	this->skt = skt;
    this->ptr = NULL;
    this->addr = NULL;
}

Socket::~Socket() {
	if (this->skt != SKT_ERROR) {
		this->close();
	}
    this->s = -1;
    this->skt = -1;
}

bool Socket::addrinfo(char *host, char* port) {
	struct addrinfo hints;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;
	this->s = getaddrinfo(host, port, &hints, &this->addr);
   	if (this->s != 0) throw SocketError();
   	return true;
}


bool Socket::connect(char* host, char* port) {
	bool are_we_connected = false;

	if (!addrinfo(host,port)) {
		return are_we_connected;
	}

   	for (this->ptr = this->addr; this->ptr!=NULL &&
   		 !are_we_connected; this->ptr=this->ptr->ai_next) {
   		this->skt = socket(this->ptr->ai_family,
   				this->ptr->ai_socktype, this->ptr->ai_protocol);
      	if (this->skt == SKT_ERROR) {
      		throw SocketError();
   		} else {
      		this->s = ::connect(this->skt,
      				this->ptr->ai_addr, this->ptr->ai_addrlen);
      		if (this->s == SKT_ERROR) {
      			::close(this->skt);
      			throw SocketError();
      		}
      		are_we_connected = (this->s != -1);
      }
    }
   	freeaddrinfo(this->addr);
	if (are_we_connected == false) {
		return false;
	}
	return true;
}

bool Socket::bind(char *port) {
	bool are_we_binded = false;

	if (!addrinfo(NULL,port)) {
		return are_we_binded;
	}

   	for (this->ptr = this->addr; this->ptr!=NULL &&
   		 !are_we_binded; this->ptr=this->ptr->ai_next) {
   		this->skt = socket(this->ptr->ai_family,
   				this->ptr->ai_socktype, this->ptr->ai_protocol);
      	if (this->skt == SKT_ERROR) {
      		throw SocketError();
      	} else {
      		this->s = ::bind(this->skt,
      				this->addr->ai_addr, this->addr->ai_addrlen);
      		if (this->s == SKT_ERROR) {
      			::close(this->skt);
      			throw SocketError();
      		}
      		are_we_binded = (this->s != -1);
      }
    }
   	freeaddrinfo(this->addr);
	if (are_we_binded == false) {
		return false;
	}
	return true;
}

bool Socket::listen() {
    this->s = ::listen(this->skt, ACCEPT_QUEUE_LEN);
    if (this->s == SKT_ERROR) throw SocketError();
    return true;
}

Socket Socket::accept() {
	int skt_a = ::accept(this->skt, nullptr, nullptr);
	if (skt_a == SKT_ERROR) throw SocketError();
	return Socket(skt_a);
}

void Socket::close() {
    ::shutdown(this->skt, SHUT_RDWR);
    ::close(this->skt);
}

int Socket::send(const char* msg, size_t length) {
	size_t sent = 0;
	int s = 0;
	bool is_the_socket_valid = true;

	while (sent < length && is_the_socket_valid) {
		s = ::send(this->skt, msg+sent, length-sent, MSG_NOSIGNAL);
		if (s <= 0) {
			is_the_socket_valid = false;
		} else {
			sent += s;
		}
	}
	return sent;
}

int Socket::recv(char* response, size_t length) {
	size_t received = 0;
	int s = 0;
	bool is_the_socket_valid = true;
	while (received < length && is_the_socket_valid) {
		s = ::recv(this->skt, response+received, length-received, MSG_NOSIGNAL);
		if (s <= 0) {
			is_the_socket_valid = false;
			return -1;
		} else {
			received += s;
		}
	}
	return received;
}

Socket::Socket(Socket &&other) {
	this->s = other.s;
	this->skt = other.skt;
	this->ptr = other.ptr;
	this->addr = other.addr;
	other.s = -1;
    other.skt = -1;
    other.ptr = NULL;
    other.addr = NULL;
}

Socket &Socket::operator=(Socket &&other) {
    this->skt = other.skt;
    other.skt = -1;
    return *this;
}

int Socket::operator()(const char* msg, size_t length) {
	return this->send(msg,length);
}
