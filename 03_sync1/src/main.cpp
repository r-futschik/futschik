#include "account.h"
#include "CLI11.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

using namespace std;

void withdraw(Account& acc, int amount, bool& success){
    
    if (acc.withdraw(amount)){
        success = true;
    } else {
        success = false;
    }
    
}

int main(int argc, char* argv[]) {
    CLI::App app("Account app");

    int balance{0};
    app.add_option("balance", balance, "Initial balance")->required();

    int deposits{5};
    app.add_option("-d,--deposits", deposits, "Count of deposits(default=5)", true);
    CLI11_PARSE(app, argc, argv);

    

    Account acc1{Account()};

    acc1.deposit(balance);
    /*
    Punkt 1
    acc1.deposit(15);
    acc1.withdraw(6);
    acc1.withdraw(10);

    cout << "Balance: " << acc1.get_balance() << endl;
    */

    /*
    bool succ1;
    bool succ2;
    acc1.deposit(1);
    thread t{withdraw, ref(acc1), 1, ref(succ1)};
    thread t2{withdraw, ref(acc1), 1, ref(succ2)};
    t.join();
    t2.join();

    */
    
      
    thread t{Depositer(), ref(acc1), deposits};
    

    t.join();

    cout << "Balance: " << acc1.get_balance() << endl;
}