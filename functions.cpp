#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include "functions.h"
using namespace std;

void functionstart(vector<ACCOUNT>& BankAccounts);
void Make(vector <ACCOUNT>& BankAccounts);
void printAllAccounts(vector <ACCOUNT>& BankAccounts);
void Deposit(vector <ACCOUNT>& BankAccounts);
void Withdraw(vector <ACCOUNT>& BankAccounts);
void Print(vector <ACCOUNT>& BankAccounts);
void Delete(vector <ACCOUNT>& BankAccounts);
void sortAccounts(vector <ACCOUNT>& BankAccounts);
void validinput(int input, int & responsetype);



void functionstart(vector<ACCOUNT>& BankAccounts)
{
int selection;
    cout << "\nWelcome to MadeUp Banking. Select options below: " << endl;
    cout << "1. Make new account.\n2. Display all accounts.\n3. Deposit to an account." <<endl;
    cout << "4. Withdraw from an account.\n5. Print account.\n6. Delete an account.\n7. Quit." << endl;



    cout << "Selection: ";
    cin >> selection;


	switch(selection)
		{
		case 1: Make(BankAccounts);
		break;

		case 2: printAllAccounts(BankAccounts);
		break;

		case 3: Deposit(BankAccounts);
		break;

		case 4: Withdraw(BankAccounts);
		break;

		case 5: Print(BankAccounts);
		break;

		case 6: Delete(BankAccounts);
		break;

        case 7: cout << "\nProgram Terminated\n"; exit(0);
		}
}



void Make(vector<ACCOUNT>& BankAccounts) {


    int AccountNumber;
	static int NumberofAccounts = 0;
    double AccountBalance;
	NumberofAccounts ++;

generate:
	srand(time(NULL));
    AccountNumber = rand()%9000 + 1000;


    for (int i = 0; i < BankAccounts.size(); i++)
        {

        if (AccountNumber == BankAccounts[i].AccountNumber)
            {
                goto generate;
            }
        }

    ACCOUNT BankAccount;
    BankAccount.AccountNumber = AccountNumber;
    cout << "Creating bank account number " << AccountNumber << endl;
    cout << endl;
    cout << "Enter first name: ";
    cin >> BankAccount.FirstName;
    cout << "Enter last name: ";
    cin >> BankAccount.LastName;
    cout << "Enter starting balance: ";

    int responsetype = -1;

input:
    cin >> AccountBalance;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(9999999, '\n');
        cout << "Invalid input.\nEnter new number: ";
        goto input;
    }
    validinput(AccountBalance, responsetype);
    if (responsetype == 1)
    {
        cout << "Enter positive number: ";
        goto input;
    }

    BankAccount.AccountBalance = AccountBalance;
    BankAccounts.push_back(BankAccount);



sortAccounts(BankAccounts);

}


void printAllAccounts(vector<ACCOUNT>& BankAccounts) {

    for (int index = 0; index < BankAccounts.size(); index++){
        cout << "\nAccount number: " << BankAccounts[index].AccountNumber << "     " << "Balance: " << BankAccounts[index].AccountBalance << endl;
        cout << "Last name: " << BankAccounts[index].LastName << "     " << "First name: " << BankAccounts[index].FirstName << endl;
        }

functionstart(BankAccounts);

}

void Deposit(vector<ACCOUNT>& BankAccounts){

    int responsetype = -1;
    int AccountNumber;
    double Deposit;
    cout << "Enter Account Number for deposit: ";
input:
    cin >> AccountNumber;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(9999999, '\n');
        cout << "Invalid input.\nEnter new number: ";
        goto input;
    }
    validinput(AccountNumber, responsetype);
    if (responsetype == 1)
    {
        cout << "Enter positive number: ";
        goto input;
    }

    int index;
    bool found = false;

    for (int i = 0; i < BankAccounts.size(); i++)
        {

        if (AccountNumber == BankAccounts[i].AccountNumber)
            {
            index = i;
            found = true;
            }

        }
        if (found == true)
            {
            cout << "Enter amount to be deposited: ";
           DEPOSIT:
           cin >> Deposit;
           if (cin.fail())
                {
                cin.clear();
                cin.ignore(9999999, '\n');
                cout << "Invalid input.\nEnter new number: ";
                goto DEPOSIT;
                }
            validinput(Deposit, responsetype);
            if (responsetype == 1)
                {
                cout << "Enter positive number: ";
                goto DEPOSIT;
                }
            BankAccounts[index].AccountBalance += Deposit;
            }
        else if (found == false)
            {
                cout << "Account Number not found." << endl;


            }
functionstart(BankAccounts);
}
void Withdraw(vector<ACCOUNT>& BankAccounts)
{
    int responsetype = -1;
    int AccountNumber;
    double Withdrawl;
    cout << "Enter Account Number for withdrawl: ";
input:
    cin >> AccountNumber;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(9999999, '\n');
        cout << "Invalid input.\nEnter new number: ";
        goto input;
    }
    validinput(AccountNumber, responsetype);
    if (responsetype == 1)
    {
        cout << "Enter positive number: ";
        goto input;
    }

    int index;
    bool found = false;
    for (int i = 0; i < BankAccounts.size(); i++)
        {

        if (AccountNumber == BankAccounts[i].AccountNumber)
            {
            found = true;
            index = i;
            }
        }
        if (found == true)
        {

            cout << "Enter amount to be withdrawn: ";
            Withdraw:
            cin >> Withdrawl;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(9999999, '\n');
                cout << "Invalid input.\nEnter new number: ";
                goto Withdraw;
            }
            validinput(Withdrawl, responsetype);
            if (responsetype == 1)
            {
                cout << "Enter positive number: ";
                goto Withdraw;
            }


            BankAccounts[index].AccountBalance -= Withdrawl;

        }
        else if (found == false)
        {
            cout << "Account Number not found. " << endl;
        }


    functionstart(BankAccounts);
}
void Print(vector<ACCOUNT>& BankAccounts)
{
int AccountNumber;
int responsetype = -1;
cout << "Enter Account Number: ";
input:
    cin >> AccountNumber;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(9999999, '\n');
        cout << "Invalid input.\nEnter new number: ";
        goto input;
    }
    validinput(AccountNumber, responsetype);
    if (responsetype == 2)
    {
        cout << "Enter positive number: ";
        goto input;
    }
    int index;
    bool found = false;
    for (int i = 0; i < BankAccounts.size(); i++)
    {

        if (AccountNumber == BankAccounts[i].AccountNumber)
            {
            found = true;
            index = i;
            }
    }
    if (found == true)
        {
        cout << "\nAccount number: " << BankAccounts[index].AccountNumber << "     " << "Balance: " << BankAccounts[index].AccountBalance << endl;
        cout << "Last name: " << BankAccounts[index].LastName << "     " << "First name: " << BankAccounts[index].FirstName << endl;

        }
    else if (found == false)
    {
        cout << "Account Number not found. " << endl;

    }
	functionstart(BankAccounts);

}

void Delete(vector<ACCOUNT>& BankAccounts){
    int AccountNumber;
    cout << "Enter Account Number to be deleted: ";
    int responsetype = -1;
    bool found = false;
input:
    cin >> AccountNumber;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(9999999, '\n');
        cout << "Invalid input.\nEnter new number: ";
        goto input;
    }
    validinput(AccountNumber, responsetype);
    if (responsetype == 1)
    {
        cout << "Enter positive number: ";
        goto input;
    }



    int index;

    for (int i = 0; i < BankAccounts.size(); i++)
        {
        if (BankAccounts[i].AccountNumber == AccountNumber)
            {

            index = i;
            found = true;
            }
        }
    if (found == true)
    {
        BankAccounts.erase(BankAccounts.begin()+index);
        cout << "Account deleted. " << endl;
    }
    else if (found == false)
    {
    cout << "Account Number not found." << endl;
    }


functionstart(BankAccounts);
}

void sortAccounts(vector<ACCOUNT>& BankAccounts)
{
    ACCOUNT TEMPVECTOR;
    int minimum =10000;
    int index = 0;
    int j = 0;
    int i = 0;
    for(j = 0; j < BankAccounts.size(); j++)
    {
    minimum = 10000;
    TEMPVECTOR = BankAccounts[j];
        for  (i = j; i < BankAccounts.size(); i++)
        {
              if (BankAccounts[i].AccountNumber < minimum)
                {
                    minimum = BankAccounts[i].AccountNumber;
                    index = i;

                }
        }

    TEMPVECTOR=BankAccounts[index];
    BankAccounts.at(index) = BankAccounts.at(j);
    BankAccounts.at(j) = TEMPVECTOR;
    }
functionstart(BankAccounts);
}


void validinput(int input, int& responsetype)
{
    if (input < 0)
    {
        responsetype = 1; //negative numbers
    }
    else
    {
        responsetype = 3; //valid input
    }
}
