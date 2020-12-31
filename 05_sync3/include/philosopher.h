#pragma once


#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <iostream>
#include <mutex>
#include <string>
#include "semaphor.h"


class Philosopher {
    private:
    int number = 1;
    std::timed_mutex& left_fork;
    std::timed_mutex& right_fork;

    Semaphor* semaphor;
    
    public:
    Philosopher(int number, std::timed_mutex& left_fork, std::timed_mutex& right_fork, Semaphor* semaphor) : number(number), left_fork(left_fork), right_fork(right_fork), semaphor(semaphor) {};
    Philosopher() = delete;
    void operator()();
};


#endif