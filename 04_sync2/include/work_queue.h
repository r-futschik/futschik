#pragma once

#ifndef WORK_QUEUE_H
#define WORK_QUEUE_H

class WorkQueue {
    private:
    std::queue<WorkPacket> queue;

    public:
    void push(WorkPacket packet);
    void pop();
};


#endif