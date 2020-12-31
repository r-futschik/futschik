#include <iostream>
#include <vector>
#include <string>
#include <future>
#include <thread>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop

#include "calc_factors.h"
#include "CLI11.hpp"

using namespace std;


string checkString(const string &str){
    if (str.find_first_not_of("0123456789") != string::npos)
        return "number: " + str + " contains not numeric character";
    return string();
}

void output(vector<InfInt>& numbers, vector<shared_future<vector<InfInt>>>& results){
    for(unsigned i=0; i < numbers.size(); i++) {
        cout << numbers[i] << ": ";
        results[i].wait();
        for(const auto& factor: results[i].get() ){
            cout << factor << " ";
        }
        cout << endl;
    }
}

void checkFactor(vector<InfInt>& numbers, vector<shared_future<vector<InfInt>>>& results){
    for(unsigned i=0; i < numbers.size(); i++) {
        for(const auto& factor: results[i].get() ){
            if (numbers[i] % factor != 0){
                cerr << "Factors didnt add up" << endl;
            }
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    vector<string> str_vektor;

    vector<InfInt> int_vektor;

    vector<shared_future<vector<InfInt>>> future_vektor;
    
    CLI::App app("Factor Numbers");
    
    app.add_option("number", str_vektor, "numbers to factor")->required()->check(checkString);
    bool activate_async;
    app.add_flag("-a, --async", activate_async, "async");

    CLI11_PARSE(app, argc, argv);

    


    for(unsigned i=0; i < str_vektor.size(); i++) {
        
        int_vektor.push_back(str_vektor[i]);
        future_vektor.push_back(std::async(launch::async, get_factors, int_vektor[i]));
    }


    
    thread t {output, ref(int_vektor), ref(future_vektor)};

    t.join();

    
}