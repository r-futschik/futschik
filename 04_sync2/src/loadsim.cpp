#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>

#include "work_packet.h"
#include "work_queue.h"

using namespace std;



void worker(int id, WorkQueue& q){
    ostringstream buf;
    
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};
    float seconds {};

    while (true) {
        seconds = dis(gen);
        seconds *= 1000;

        buf << "W" << id <<" : Want work packet" << endl;
        cout << buf.str() << flush;
        buf.str("");

        WorkPacket processedPacket {q.pop()};
        buf << "W" << id <<" : Got work packet " << processedPacket.get_id() << endl;
        cout << buf.str() << flush;
        buf.str("");
        this_thread::sleep_for(chrono::milliseconds(int(seconds)));
        
        buf << "W" << id <<" : Processed work packet " << processedPacket.get_id() << " (" << setprecision(2) << (seconds / 1000.0) << ")" << endl;
        cout << buf.str() << flush;
        buf.str("");
        
    }
}



void submitting(WorkQueue& q){
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{0, 1};
    float seconds {};

    int i {};
    ostringstream buf;
    while (true){
        seconds = dis(gen);
        seconds *= 1000;
        buf << "B : Waiting to submit work packet " << i << endl;
        cout << buf.str() << flush;
        buf.str("");
        this_thread::sleep_for(chrono::milliseconds((int)seconds));
        q.push(WorkPacket(i));
        buf << "B : Submitted work packet " << i << " (" << setprecision(2) << (seconds / 1000.0) << ")" << endl;
        cout << buf.str() << flush;
        buf.str("");
        
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