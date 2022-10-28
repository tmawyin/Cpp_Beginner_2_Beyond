// Alternative to the include statements, some compilers can use the following statement below:
//#pragma once


#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

// Building the Account class
class Account {
private:
	static int num_accounts;
	double balance;
	int type;	//1: checking, 2: savings, 3: investment

public:
	//Constructor (can be overloaded)
	Account(double bal=0.0, int t=1);
	
	/* Removing overladed constructors since using "default" values */
	//Account();
	//Account(double);
	
	Account(const Account&);	//declaring a Copy Constructor

	//Destructor
	~Account();
	
	//Method Declarations
	void set_balance(double);
	double get_balance() const;	//making this method a "const" - meaning it will NOT change attributes on the class
	bool deposit(double);
	bool withdraw(double);
	static int get_num_accounts();
};

#endif // !_ACCOUNT_H_

