#include "account.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <random>
#include <iomanip>

using namespace std;

void withdraw(Account& acc, int amount, bool& success){
    
    if (acc.withdraw(amount)){
        success = true;
    } else {
        success = false;
    }
    
}

int main() {
    bool succ1;
    bool succ2;
    int count{0};
    Account acc1{Account()};

    /*
    Punkt 1
    acc1.deposit(15);
    acc1.withdraw(6);
    acc1.withdraw(10);

    cout << "Balance: " << acc1.get_balance() << endl;
    */

    while (acc1.get_balance() == 0){
        acc1.deposit(1);
        thread t{withdraw, ref(acc1), 1, ref(succ1)};
        thread t2{withdraw, ref(acc1), 1, ref(succ2)};
        t.join();
        t2.join();
        count += 1;
    }
    

    cout << "Balance: " << acc1.get_balance() << " " << succ1 << " " << succ2 << " " << count << endl;
}