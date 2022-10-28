// Savings Account is a type of Account that adds interest rate
// Each deposit into this account add some pre-defined interest rate 

#pragma once

#include "Account.h"


/* Note: Copy/Move constructors or Overloading Operators are not directly inherited.
	you need to explicitely copy/move the base class portion from the derived class copy/move constructor */

class Savings_Account : public Account {
	friend std::ostream& operator<<(std::ostream& os, const Savings_Account& account);

private:
	// Creating constant expressions for default values
	static constexpr const char* def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;

protected:
	double int_rate;

public:
	// Using constructors from the base class: serves to initialize the "base" portion of the derived class
	//using Account::Account;	// (not needed)

	//Savings_Account();		// no-args constructor (not needed)

	// Using additional parameters on the Savings_Account class to pass to the Account class
	Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	
	~Savings_Account();

	// New deposit method (withdraw method is inherited, see implementation)
	bool deposit(double amount);
	bool withdraw(double amount);
	
};