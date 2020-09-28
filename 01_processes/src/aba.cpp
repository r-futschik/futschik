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

    auto pid{fork()};

    if (pid == 0) {
        execl("./charout", "charout", "A", nullptr);
        if (errno){
            cerr << strerror(errno) << endl;
            quick_exit(1);
        }
        
    } else {
        int status{};
        while (i++ < 6){
            cout << "B" << flush;
            this_thread::sleep_for(sleeptime);
        }

        kill(pid, SIGKILL);
        waitpid(pid, &status, 0);



        cout << "subprocess " << pid << " exited with " << WEXITSTATUS(status) << endl;
        
    }


    
}