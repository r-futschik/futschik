#pragma once


#ifndef WORK_QUEUE_H
#define WORK_QUEUE_H

#include <condition_variable>
#include <mutex>


class WorkQueue {
    private:
    std::queue<WorkPacket> queue;
    std::mutex mtx;
    std::condition_variable not_empty;
    
    public:
    void push(WorkPacket packet);
    WorkPacket pop();
};


#endif