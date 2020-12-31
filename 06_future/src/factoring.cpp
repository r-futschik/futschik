#include <iostream>
#include <vector>
#include <string>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include "InfInt.h"
#pragma GCC diagnostic pop

#include "CLI11.hpp"

using namespace std;


string checkString(const string &str){
    if (str.find_first_not_of("0123456789") != string::npos)
        return "number: " + str + " contains not numeric character";
    return string();
}

int main(int argc, char* argv[]) {

    vector<string> str_vektor;

    CLI::App app("Factor Numbers");
    
    app.add_option("number", str_vektor, "numbers to factor")->required()->check(checkString);
    app.add_option("-a, --async", "async");

    CLI11_PARSE(app, argc, argv);

    vector<InfInt> int_vektor;
    for(const auto& value: str_vektor) {
        int_vektor.push_back(value);
        std::cout << value << endl;
    }

    for(const auto& value: int_vektor) {
        std::cout << value << endl;
    }
    
}