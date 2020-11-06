#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;


void WorkQueue::push(WorkPacket packet){
    this->queue.push(packet);
}


void WorkQueue::pop(){
    this->queue.pop();
}