#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdlib>

using namespace std;



int main() {

    auto pid{fork()};
    if (pid == 0) {
        cout << "child is waiting... " << flush;
        sleep(10); cout << "done" << endl;
        quick_exit(EXIT_SUCCESS);
    } else {
        cout << "child pid is " << pid << endl;
    }
    cout << "parent terminates" << endl;
}