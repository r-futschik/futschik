#include <iostream>
#include <mutex>
#include "semaphor.h"

using namespace std;

void Semaphore::aquire() {
    unique_lock<mutex> ug{mtx};
    not_free.wait(ug, [this] { return counter > 0; });
    counter--;
}

void Semaphore::release() {
    lock_guard<mutex> lg{mtx};
    counter++;
    not_free.notify_one();
}

int Semaphore::available_permits() {
    return counter;
}