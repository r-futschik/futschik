#include <iostream>

#include <thread>
#include <mutex>
#include <sstream>
#include <iomanip>

#include "philosopher.h"

using namespace std;

mutex out_mtx;

void println(const vector<string>& v){
    lock_guard<mutex> lg{out_mtx};
    cout << "Philosopher " << v[0] << v[1] << endl;
}

void Philosopher::operator()() {
    ostringstream buf;
    while (true) {
        println({to_string(number), " is thinking..."});
        this_thread::sleep_for(chrono::milliseconds(1000));



       println({to_string(number), " attempts to get left fork"});
        

        left_fork.lock();
        println({to_string(number), " got left fork. Now he wants the right one..."});
        

        right_fork.lock();

        println({to_string(number), " got right fork. Now he is eating..."});
        

        this_thread::sleep_for(chrono::milliseconds(2000));
        println({to_string(number), " finished eating"});
        

        left_fork.unlock();
        println({to_string(number), " released left fork"});
        
        
        right_fork.unlock();
        println({to_string(number), " released right fork"});
        
    }
}