#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include<vector>
#include <string>

typedef struct ACCOUNT{
double AccountBalance;
int AccountNumber;
std::string FirstName;
std::string LastName;
} ACCOUNT;

void functionstart(std::vector<ACCOUNT>&);
void functionstart(std::vector<ACCOUNT>&);
void Make(std::vector <ACCOUNT>& );
void printAllAccounts(std::vector <ACCOUNT>& );
void Deposit(std::vector <ACCOUNT>& );
void Withdraw(std::vector <ACCOUNT>& );
void Print(std::vector <ACCOUNT>& );
void Delete(std::vector <ACCOUNT>& );
void sortACCOUNTs(std::vector <ACCOUNT>& );
void validinput(int input, int& responsetype);

#endif // FUNCTIONS_H_INCLUDED
