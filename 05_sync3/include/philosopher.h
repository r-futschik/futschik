#pragma once


#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <condition_variable>
#include <mutex>


class Philosopher {
    private:
    int number;
    std::timed_mutex& leftFork;
    std::timed_mutex& rightFork;
    
    public:
    Philosopher(int number, std::timed_mutex& left_fork, std::timed_mutex& right_fork);
};


#endif