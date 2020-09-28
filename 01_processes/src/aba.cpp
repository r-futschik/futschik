#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdlib>
#include <chrono>

using namespace std;



int main() {

    std::chrono::milliseconds sleeptime(500);
    auto pid{fork()};
    cout << "Hi" << endl;
    if (pid == 0) {
        while (true){
            cout << "A" << flush;
            std::this_thread::sleep_for(sleeptime);
        }
    } else {
        while (true){
            cout << "B" << flush;
            std::this_thread::sleep_for(sleeptime);
        }
    }

    cout << "Bye" << endl;
    
}