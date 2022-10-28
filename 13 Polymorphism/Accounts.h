// FOR COURSE MATERIAL ONLY

#pragma once

#include <iostream>

// Note the "virtual" keyword - ensures dynamic binding is possible
class Account {
public:
	virtual void withdraw() {
		std::cout << "In Account::withdraw" << std::endl;
	}
	
	// Pure virtual method - forces derived class to implement this
	// and makes Account an Abstract class (can't be instanciated anymore)
	virtual void add_rewards() = 0;

	virtual ~Account() {}	// Make destructors virtual (otherwise static binding will happen)
};

// Note the "override" keyword - helps ensure this method is overriden at compiling
class Checking :public Account {
public:
	virtual void withdraw() override {
		std::cout << "In Checking::withdraw" << std::endl;
	}
	virtual ~Checking(){}
	
	virtual void add_rewards(){
		std::cout << "No rewards in Checking accounts" << std::endl;
	}
};

class Savings:public Account {
public:
	virtual void withdraw() override {
		std::cout << "In Savings::withdraw" << std::endl;
	}
	virtual ~Savings() {}

	virtual void add_rewards() {
		std::cout << "1% cash back on Savings accounts" << std::endl;
	}
};


// Note the "final" keyword - no other class can be derived from the Trust Account
// If a method is set final - it prevents further overriding of the method
class Trust final : public Account {
public:
	virtual void withdraw() override {
		std::cout << "In Trust::withdraw" << std::endl;
	}
	virtual ~Trust() {}

	virtual void add_rewards() {
		std::cout << "2% cash back on Trust accounts" << std::endl;
	}
};