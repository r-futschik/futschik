#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void f() {
    int count{1};
    while (true) {
        cout << count << " Porsche" << endl;

        this_thread::sleep_for(chrono::milliseconds(1000));
        count++;
    }
}

int main() {
    thread t{f};
    
    t.join();

}
