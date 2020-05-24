#ifndef COMMON_THREAD_H_
#define COMMON_THREAD_H_

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Thread {
public:
	Thread(){}
    void start();
    void join();
    virtual void run() = 0;
    virtual ~Thread(){}
    Thread(const Thread &) = delete;
    Thread &operator=(const Thread &) = delete;
    Thread(Thread &&other);
    Thread &operator=(Thread &&other);

private:
    std::thread thread;
};

#endif /* COMMON_THREAD_H_ */
