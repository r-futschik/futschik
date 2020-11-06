#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <chrono>
#include "work_packet.h"
#include "work_queue.h"

using namespace std;

int main() {
    WorkQueue q{WorkQueue()};
    int i{};
    while (true) {
        q.push(WorkPacket(i));
        cout << "B: Submitted work packet " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        i++;
    }
}