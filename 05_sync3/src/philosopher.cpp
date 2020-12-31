#include <iostream>

#include <thread>
#include <mutex>
#include <sstream>
#include <iomanip>
#include <initializer_list>
#include "philosopher.h"

using namespace std;

mutex out_mtx;

void println(const initializer_list<string>& list){
    lock_guard<mutex> lg{out_mtx};
    for (auto element : list){
        cout << element;
    }
    cout << endl;
}

void Philosopher::operator()() {
    ostringstream buf;
    while (true) {
        println({"Philosopher ", to_string(number), " is thinking..."});
        this_thread::sleep_for(chrono::milliseconds(1000));



       println({"Philosopher ", to_string(number), " attempts to get left fork"});
        

        left_fork.lock();
        println({"Philosopher ", to_string(number), " got left fork. Now he wants the right one..."});
        

        right_fork.lock();

        println({"Philosopher ", to_string(number), " got right fork. Now he is eating..."});
        

        this_thread::sleep_for(chrono::milliseconds(2000));
        println({"Philosopher ", to_string(number), " finished eating"});
        

        left_fork.unlock();
        println({"Philosopher ", to_string(number), " released left fork"});
        
        
        right_fork.unlock();
        println({"Philosopher ", to_string(number), " released right fork"});
        
    }
}