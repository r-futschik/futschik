#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <random>
#include <iomanip>

using namespace std;


class Car{
    public:
    string name;
    float gesTime{0};

    Car(string name){
        this->name = name;
    }

    void operator()() {
        int count{1};
        Car car{name};
        float seconds{};
        float gesTime{};
        random_device rd;
        mt19937 gen{rd()};
        uniform_real_distribution<> dis{1, 3};


        while (count <= 10) {
            seconds = dis(gen);
            gesTime += seconds;
            seconds *= 1000.0;
            
            this_thread::sleep_for(chrono::milliseconds((int)seconds));

            cout << to_string(count) + " " + this->name + " mit "  << setprecision(3) << (seconds / 1000.0) << " Sekunden" << endl;

            count++;
        }

        this->gesTime += gesTime;

    
    }

    float getTime(){
        return this->gesTime;
    }
};


void startRace(string name, float &gesTime) {
    int count{1};
    Car car{name};
    float seconds{};
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 3};


    while (count <= 10) {
        seconds = dis(gen);
        gesTime += seconds;
        seconds *= 1000.0;
            
        this_thread::sleep_for(chrono::milliseconds((int)seconds));

        cout << to_string(count) + " " + name + " mit "  << setprecision(3) << (seconds / 1000.0) << " Sekunden" << endl;

        count++;
    }




    
    }



int main() {

    float gesTime{};

    Car porsche{Car("Porsche")};

    thread t{ref(porsche)};
    thread t2{startRace, "VW", ref(gesTime)};

    t.join();
    t2.join();


    cout << porsche.getTime() << endl;
    cout << gesTime << endl;
    

}
