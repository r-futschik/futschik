#include "account.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


mutex m;
int Account::get_balance(){
    return this->balance;
}

void Account::deposit(int amount){
    int tmp{this->balance};
    this_thread::sleep_for(10ms);
    this->balance = tmp + amount;
}

bool Account::withdraw(int amount){
    
    lock_guard<mutex> guard{m};
    if (this->balance - amount >= 0){
        this->balance -= amount;
        return true;
    }

    return false;
}



void Depositer::operator()(Account& account){
    for(int i = 0; i < 5; i++){
        account.deposit(1);
    }
    
}