#include "account.h"
#include <thread>
#include <mutex>

using namespace std;


mutex m;
int Account::get_balance(){
    return this->balance;
}

void Account::deposit(int amount){
    this->balance += amount;
}

bool Account::withdraw(int amount){
    
    lock_guard<mutex> guard{m};
    if (this->balance - amount >= 0){
        this->balance -= amount;
        return true;
    }

    return false;
}


