#include <iostream>
#include<string>
#include<Windows.h>

struct BankAccount
{
    int accountNumber{ 0 };
    std::string cardholderName;
    double amoutOfMony;
};

void changeAccountBalance(BankAccount& bankAccount, double newBalance) {
    bankAccount.amoutOfMony =  newBalance;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BankAccount bankAccount;

    std::cout << "Введите номер счет: ";
    std::cin >> bankAccount.accountNumber;

    std::cout << "Введите имя владельца: ";
    std::cin >> bankAccount.cardholderName;

    std::cout<< "Введите баланс: ";
    std::cin >> bankAccount.amoutOfMony;

    double newBalance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    changeAccountBalance(bankAccount, newBalance);

    std::cout << "Ваш счет: " << bankAccount.cardholderName << ", " << bankAccount.accountNumber
        << ", " << bankAccount.amoutOfMony << std::endl;

    return 0;
}
