#pragma once

#ifndef SEMAPHOR_H
#define SEMAPHOR_H

#include <mutex>
#include <condition_variable>

class Semaphore {
    private:
        int counter; 
        std::condition_variable not_free;
        std::mutex mtx;

    public:
        Semaphore() {
            counter = 0;
        };
        Semaphore(int start_value) {
            counter = start_value;
        };

        void aquire();
        void release();
        int available_permits();
};

#endif