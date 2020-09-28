#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdlib>

using namespace std;



int main() {

    auto pid{fork()};
    if (pid == 0) {
        while (true){
            cout << "A";
        }
    } else {
        while (true){
            cout << "B";
        }
    }
    
}