#include <iostream>
#include <thread>
#include <mutex>

#include "philosopher.h"

using namespace std;










int main() {
    
    std::timed_mutex gabel1, gabel2, gabel3, gabel4, gabel5;

    Philosopher p1{1, ref(gabel1), ref(gabel2)}; 
    Philosopher p2{2, ref(gabel2), ref(gabel1)};
    Philosopher p3{3, ref(gabel3), ref(gabel4)};
    Philosopher p4{4, ref(gabel4), ref(gabel5)};
    Philosopher p5{5, ref(gabel5), ref(gabel1)};

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