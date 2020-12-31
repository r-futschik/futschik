#include <iostream>
#include <thread>
#include <mutex>
#include "CLI11.hpp"
#include "philosopher.h"
#include "semaphor.h"

using namespace std;







int main(int argc, char* argv[]) {
    
    CLI::App app("Dining philosophers simulation");

    bool deadlockPrevention = false;
    app.add_flag("-n, --nodeadlock", deadlockPrevention, "Prevent a deadlock at all");

    bool livelock = false;
    app.add_flag("-l,--livelock", livelock, "Simulate a livelock");

    CLI11_PARSE(app, argc, argv);

    std::timed_mutex gabel1, gabel2, gabel3, gabel4, gabel5;

    Semaphor* sem;
    if (deadlockPrevention){
        sem = new Semaphor(4);
    } else {
        sem = nullptr;
    }

    Philosopher p1{1, ref(gabel1), ref(gabel2), ref(sem), livelock}; 
    Philosopher p2{2, ref(gabel2), ref(gabel1), ref(sem), livelock};
    Philosopher p3{3, ref(gabel3), ref(gabel4), ref(sem), livelock};
    Philosopher p4{4, ref(gabel4), ref(gabel5), ref(sem), livelock};
    Philosopher p5{5, ref(gabel5), ref(gabel1), ref(sem), livelock};

    thread t1{p1};
    thread t2{p2};
    thread t3{p3};
    thread t4{p4};
    thread t5{p5};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    
    
}