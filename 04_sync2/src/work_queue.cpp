#include <iostream>
#include <queue>
#include <thread>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;


void WorkQueue::push(WorkPacket packet){
    lock_guard<mutex> lck{mtx};
    this->queue.push(packet);
    not_empty.notify_one();
}


WorkPacket WorkQueue::pop(){
    unique_lock<mutex> lck{mtx};
    not_empty.wait(lck, [this]{ return queue.size();});
    WorkPacket processedPacket {queue.front()};
    queue.pop();
    return processedPacket;
}