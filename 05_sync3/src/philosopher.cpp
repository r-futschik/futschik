#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <iomanip>
#include <initializer_list>
#include "philosopher.h"
#include "utils.h"

using namespace std;


void Philosopher::operator()() {
    ostringstream buf;
    while (true) {
        Utils::println("Philosopher", to_string(number), "is thinking...");
        this_thread::sleep_for(chrono::milliseconds(1000));



       Utils::println("Philosopher", to_string(number), "attempts to get left fork");
        

        left_fork.lock();
        Utils::println("Philosopher", to_string(number), "got left fork. Now he wants the right one...");
        
        this_thread::sleep_for(chrono::milliseconds(5000));

        right_fork.lock();

        Utils::println("Philosopher", to_string(number), "got right fork. Now he is eating...");
        

        this_thread::sleep_for(chrono::milliseconds(2000));
        Utils::println("Philosopher", to_string(number), "finished eating");
        

        left_fork.unlock();
        Utils::println("Philosopher", to_string(number)," released left fork");
        
        
        right_fork.unlock();
        Utils::println("Philosopher", to_string(number)," released right fork");
        
    }
}