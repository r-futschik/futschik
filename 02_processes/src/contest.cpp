#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;


class Car{
    public:
    string name;

    Car(string name){
        this->name = name;
    }

    void operator()() {
        int count{1};
        Car car{name};

        while (true) {
            cout << count << " "<< this->name << endl;

            this_thread::sleep_for(chrono::milliseconds(1000));
            count++;
        }
    }
};




int main() {
    thread t{Car("Porsche")};
    
    t.join();

}
