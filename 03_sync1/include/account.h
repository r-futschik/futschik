#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account{
    private:
    int balance{0};

    public:
    int get_balance();
    void deposit(int amount);
    bool withdraw(int amount);
};


class Depositer{

    public:
    void operator()(Account& account, int amount);
};
#endif 