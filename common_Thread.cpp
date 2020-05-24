#include "common_Thread.h"
#include <utility>

void Thread::start() {
    this->thread = std::thread(&Thread::run, this);
}

void Thread::join() {
    this->thread.join();
}

Thread::Thread(Thread &&other) {
    this->thread = std::move(other.thread);
}

Thread &Thread::operator=(Thread &&other) {
    this->thread = std::move(other.thread);
    return *this;
}
