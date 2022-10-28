#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
//#include "Savings_Account.h"
//#include "Checking_Account.h"
//#include "Trust_Account.h"

// NOTE: Use base class pointers to ACCOUNT class. This allows you to remove all other functions 
//		 since everything is dynamically binded to the account class. 
//		This is why Dynamic Polymorphism works - the system will figure out which one to use

// Utility helper functions for Account class

void display(const std::vector<Account*> &accounts);
void deposit(std::vector<Account*> &accounts, double amount);
void withdraw(std::vector<Account*> &accounts, double amount);

/*
// Utility helper functions for Savings Account class

void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &accounts, double amount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);

// Utility helper functions for Checking Account class
void display(const std::vector<Checking_Account> &accounts);
void deposit(std::vector<Checking_Account> &accounts, double amount);
void withdraw(std::vector<Checking_Account> &accounts, double amount);

// Utility helper functions for Trust Account class
void display(const std::vector<Trust_Account> &accounts);
void deposit(std::vector<Trust_Account> &accounts, double amount);
void withdraw(std::vector<Trust_Account> &accounts, double amount);
*/

#endif