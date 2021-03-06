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
    unique_lock<mutex> guard{m};
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



void Depositer::operator()(Account& account, int amount){
    for(int i = 0; i < amount; i++){
        account.deposit(1);
    }
    
}