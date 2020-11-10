#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <chrono>
#include <sstream>

#include "work_packet.h"
#include "work_queue.h"

using namespace std;



void worker(int id, WorkQueue& q){
    ostringstream buf;
    
    while (true) {
        
        buf << "W" << id <<" : Want work packet" << endl;
        cout << buf.str() << flush;
        buf.str("");
        
        WorkPacket processedPacket {q.pop()};
        buf << "W" << id <<" : Got work packet " << processedPacket.get_id() << endl;
        cout << buf.str() << flush;
        buf.str("");
        this_thread::sleep_for(chrono::milliseconds(1000));
        
        buf << "W" << id <<" : Processed work packet " << processedPacket.get_id() << endl;
        cout << buf.str() << flush;
        buf.str("");
        
    }
}

void submitting(WorkQueue& q){
    int i {};
    ostringstream buf;
    while (true){
        q.push(WorkPacket(i));
        buf << "B : Submitted work packet " << i << endl;
        cout << buf.str() << flush;
        buf.str("");
        this_thread::sleep_for(chrono::milliseconds(500));
        i++;
    }
}


int main() {
    
    WorkQueue q{WorkQueue()};
    thread b{submitting, ref(q)};
    thread w1{worker, 1, ref(q)};
    thread w2{worker, 2, ref(q)};

    w1.join();
    w2.join();
    b.join();

    
    
}