#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <random>

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
        float seconds{};

        random_device rd;
        mt19937 gen{rd()};
        uniform_real_distribution<> dis{1, 10};


        while (true) {
            seconds = dis(gen) * 1000.0;
            cout << to_string(count) + " " + this->name + "mit " + to_string(seconds / 1000.0) + " Sekunden" << endl;

            this_thread::sleep_for(chrono::milliseconds((int)seconds));

            count++;
        }
    }
};




int main() {
    thread t{Car("Porsche")};
    thread t2{Car("VW")};

    


    t.join();
    t2.join();

}
