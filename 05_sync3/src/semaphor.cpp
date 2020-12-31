#include <iostream>
#include <mutex>
#include "semaphor.h"

using namespace std;

void Semaphor::aquire() {
    unique_lock<mutex> ug{mtx};
    not_free.wait(ug, [this] { return counter > 0; });
    counter--;
}

void Semaphor::release() {
    lock_guard<mutex> lg{mtx};
    counter++;
    not_free.notify_one();
}

int Semaphor::available_permits() {
    return counter;
}