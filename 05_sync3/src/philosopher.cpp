#include <iostream>

#include <thread>
#include <mutex>
#include <sstream>
#include <iomanip>

#include "philosopher.h"

using namespace std;



void Philosopher::operator()() {
    ostringstream buf;
    while (true) {
        buf << "Philosopher " << number << " is thinking..." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << buf.str() << flush;
        buf.str("");


        buf << "Philosopher " << number << " attempts to get left fork" << endl;
        cout << buf.str() << flush;
        buf.str("");

        left_fork.lock();
        buf << "Philosopher " << number << " got left fork. Now he wants the right one..." << endl;
        cout << buf.str() << flush;
        buf.str("");

        right_fork.lock();

        buf << "Philosopher " << number << " got right fork. Now he is eating..." << endl;
        cout << buf.str() << flush;
        buf.str("");

        this_thread::sleep_for(chrono::milliseconds(2000));
        buf << "Philosopher " << number << " finished eating" << endl;
        cout << buf.str() << flush;
        buf.str("");

        left_fork.unlock();
        buf << "Philosopher " << number << " released left fork" << endl;;
        cout << buf.str() << flush;
        buf.str("");
        
        right_fork.unlock();
        buf << "Philosopher " << number << " released right fork" << endl;;
        cout << buf.str() << flush;
        buf.str("");
    }
}