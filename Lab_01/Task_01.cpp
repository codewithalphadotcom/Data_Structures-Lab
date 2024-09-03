#include <iostream>
using namespace std;

class BankAccount
{
    double balance;

public:
    BankAccount()
    {
        this->balance = 0;
    }

    BankAccount(double balance)
    {
        this->balance = balance;
    }

    BankAccount(const BankAccount &account)
    {
        balance = (account.balance) - 200;
    }

    void Display()
    {
        cout << "Your Account Balance is: " << balance << "\n\n";
    }
};

int main()
{
    BankAccount account1;
    account1.Display();

    BankAccount account2(1000);
    account2.Display();

    BankAccount account3(account2);
    account3.Display();
    account2.Display();

    return 0;
}