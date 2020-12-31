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

int main(int argc, char* argv[]) {

    vector<string> str_vektor;

    vector<future<vector<InfInt>>> future_vektor;
    
    CLI::App app("Factor Numbers");
    
    app.add_option("number", str_vektor, "numbers to factor")->required()->check(checkString);
    bool activate_async;
    app.add_flag("-a, --async", activate_async, "async");

    CLI11_PARSE(app, argc, argv);

    vector<InfInt> int_vektor;
    for(const auto& value: str_vektor) {
        int_vektor.push_back(value);
    }

    for(unsigned i=0; i < int_vektor.size(); i++) {
        cout << int_vektor[i] << ": ";
        if (activate_async) {
            future_vektor.push_back(std::async(launch::async, get_factors, int_vektor[i]));
            for(const auto& factor: future_vektor[i].get() ){
                cout << factor << " ";
            }
        } else {
            for(const auto& factor: get_factors(int_vektor[i]) ){
                cout << factor << " ";
            }
        }
        

        cout << endl;
    }
    
}