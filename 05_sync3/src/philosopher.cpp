#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <iomanip>
#include <initializer_list>
#include "philosopher.h"
#include "Utils.h"

using namespace std;


void Philosopher::operator()() {
    ostringstream buf;
    while (true) {
        Utils::println("Philosopher", to_string(number), "is thinking...");
        this_thread::sleep_for(chrono::milliseconds(1000));

        
        while (true) {
            Utils::println("Philosopher", to_string(number), "attempts to get left fork");
            
            if (semaphor != nullptr) {
                semaphor->aquire();
            }
            left_fork.lock();
            Utils::println("Philosopher", to_string(number), "got left fork. Now he wants the right one...");

            this_thread::sleep_for(chrono::milliseconds(5000));

            if (livelock) {
                if (right_fork.try_lock_for(3000ms)) {
                    Utils::println("Philosopher", to_string(number), "got right fork. Now he is eating...");
                    break;
                } else {
                    this_thread::sleep_for(chrono::milliseconds(100));
                    left_fork.unlock();
                    Utils::println("Philosopher", to_string(number), "released left fork due to timeout getting the right one!");
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    continue;
                }
            } else {
                right_fork.lock();
                Utils::println("Philosopher", to_string(number), "got right fork. Now he is eating...");
                break;
            }
        }

        if (semaphor != nullptr) {
            semaphor->release();
        }

        left_fork.unlock();
        Utils::println("Philosopher", to_string(number), "released left fork");
        
        
        right_fork.unlock();
        Utils::println("Philosopher", to_string(number), "released right fork");
        
    }
}