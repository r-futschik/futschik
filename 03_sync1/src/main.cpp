#include "account.h"

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

int main() {
    bool succ1;
    bool succ2;

    Account acc1{Account()};

    /*
    Punkt 1
    acc1.deposit(15);
    acc1.withdraw(6);
    acc1.withdraw(10);

    cout << "Balance: " << acc1.get_balance() << endl;
    */

    
    acc1.deposit(1);
    thread t{withdraw, ref(acc1), 1, ref(succ1)};
    thread t2{withdraw, ref(acc1), 1, ref(succ2)};
    t.join();
    t2.join();

    
    

    cout << "Balance: " << acc1.get_balance() << " " << succ1 << " " << succ2 << endl;
}