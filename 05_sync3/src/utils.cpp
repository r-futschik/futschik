#include "utils.h"
#include <iostream>
#include <mutex>

using namespace std;

recursive_mutex Utils::out_mtx;

void Utils::println() {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << endl;
}