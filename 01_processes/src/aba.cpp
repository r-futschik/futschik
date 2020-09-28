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

    

    chrono::milliseconds sleeptime(3000);

    cout << "waiting for 3 seconds" << endl;

    auto pid{fork()};

    if (pid == 0) {
        const char* A{getenv("ABA_LETTER_A")};
        if (A){
            execl("./charout", "charout", A, nullptr);
            if (errno){
                cerr << "starting charout failed: "<< strerror(errno) << endl;
                quick_exit(1);
            }
        }
        else{
            cout << "Letter A not set" << endl;
        }
        
        
        
    } else {

        auto processpid{fork()};

        if (processpid == 0) {
            const char* B{getenv("ABA_LETTER_B")};
            if (B){
                execl("./charout", "charout", "B", nullptr);
                if (errno){
                cerr << "starting charout failed: " << strerror(errno) << endl;
                quick_exit(1);
                }
            } 
            else {
                cout << "Letter B not set" << endl;
            }
        }
        else {
            int status{};
            int status2{};
            
            this_thread::sleep_for(sleeptime);

            cout << "\nkilling both subprocesses with pids " << pid << " and " << processpid << endl;
            kill(pid, SIGKILL);
            kill(processpid, SIGKILL);

            cout << "for both subprocesses to be dead" << endl;
            waitpid(pid, &status, 0);
            waitpid(processpid, &status2, 0);

            cout << "subprocess " << pid << " exited with " << WEXITSTATUS(status) << endl;
            cout << "subprocess " << processpid << " exited with" << WEXITSTATUS(status2) << endl;
            
        }

        
        
    }


    
}