#pragma once

#include <string>
#include <iostream>

class Account {
	friend std::ostream& operator<<(std::ostream& os, const Account& account);

private:
	// Creating constant expressions for default values
	static constexpr const char* def_name = "Unnamed Account";
	static constexpr double def_balance = 0.0;

protected:
	double balance;
	std::string name;

public:
	//Account();		// no-args constructor (not needed - default implementation is taken care by other constructor)
	Account(std::string act_name = def_name, double act_balance = def_balance);
	~Account();

	bool deposit(double amount);
	bool withdraw(double amount);
	void display_balance();
	double get_balance();
};

/* Notes on access levels.
* public: access is made available to all members and objects of the base and derived class
* protected: access is made availabe to all members of the base and derived class but NOT the objects of either
* private: access is made available only to the base class member and NOT the base class objects or the derived class methods/objects
*/