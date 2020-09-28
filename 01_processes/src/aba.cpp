#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <sys/wait.h>

using namespace std;



int main() {

    chrono::milliseconds sleeptime(500);

    int i{0};
    int j{0};

    auto pid{fork()};

    if (pid == 0) {
        while (i < 6){
            cout << "B" << flush;
            this_thread::sleep_for(sleeptime);
            i++;
        }
    } else {
        int status{};
        while (j < 6){
            cout << "A" << flush;
            this_thread::sleep_for(sleeptime);
            j++;
        }

        kill(pid, SIGKILL);
        waitpid(pid, &status, 0);

        cout << "subprocess " << pid << " exited with " << WEXITSTATUS(status) << endl;
        
    }


    
}