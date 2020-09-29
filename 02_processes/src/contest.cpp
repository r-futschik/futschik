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
    int max;

    Car(string name, int max){
        this->name = name;
        this->max = max;
    }

    void operator()() {
        int count{1};
        float seconds{};
        float gesTime{};
        random_device rd;
        mt19937 gen{rd()};
        uniform_real_distribution<> dis{1, 10};


        while (count <= max) {
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


void startRace(string name, float &gesTime, int max) {
    int count{1};
    float seconds{};
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis{1, 10};


    while (count <= max) {
        seconds = dis(gen);
        gesTime += seconds;
        seconds *= 1000.0;
            
        this_thread::sleep_for(chrono::milliseconds((int)seconds));

        cout << to_string(count) + " " + name + " mit "  << setprecision(3) << (seconds / 1000.0) << " Sekunden" << endl;

        count++;
    }
}


bool IsOnlyDigits(string text){
    for (int i = 0; i < int(text.size()); i++)
    {
        if (!isdigit(text[i]))
        return false;
    }

    return true;
}

void help(){
    cout << "Usage: contest [-h | --help | LAPS]" << endl;
}


void error(string msg){
    cout << msg << endl;
    help();
}


int main(int argc, char* argv[]) {
    string input{};


    if (argc <= 2){
        if (argc == 1){
            input = "10";
        }
        else {
            input = argv[1];
        }

        if (IsOnlyDigits(input)){
            if (stoi(input) > 0 && stoi(input) < 16) {
                float gesTime{};
                string name{"VW"};
                

                Car porsche{Car("Porsche", stoi(input))};

                thread t{ref(porsche)};
                thread t2{startRace, name, ref(gesTime), stoi(input)};

                t.join();
                t2.join();


                if (porsche.getTime() < gesTime){
                    cout << "Sieger ist: " << porsche.name << " mit " << setprecision(3) << porsche.getTime() << "s" << endl;
                    cout << "Verlierer ist: " << name << " mit " << setprecision(3) << gesTime << "s" << endl;
                }
                else {
                    cout << "Sieger ist: " << name << " mit " << setprecision(3) << gesTime << "s" << endl;
                    cout << "Verlierer ist: " << porsche.name << " mit " << setprecision(3) << porsche.getTime() << "s" << endl;
                }
            } 
            else {
                error("Out of range (1 <= LAPS < 16): " + input + " \n Run with --help for more information.");
            }
        }
        else {
            if (input == "--help" || input == "-h"){
                help();
            }
            else {
                error("Could not convert: " + input + "\n Run with --help for more information.");
            }
        }
        

    }
    else {
        error("Too many parameters");
    }
}
