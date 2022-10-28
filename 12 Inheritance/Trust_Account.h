// Trust Account is a type of the Savings Account with the following properties:
// Only 3 withdrawals allow and each must be less than 20% of the account balance
// Each deposit over $5000 gets a $50 bonus

#pragma once

#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
	friend std::ostream& operator<<(std::ostream& os, const Trust_Account& account);

private:
	int num_withdraws;
	// Creating constant expressions for default values
	static constexpr const char* def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
	static constexpr double def_bonus_threshold = 5000.0;
	static constexpr double def_max_bonus_amount = 50.0;
	static constexpr double def_max_withdraw_percent = 0.2;
	static constexpr int def_max_num_withdraw = 3;


public:
	Trust_Account(std::string name = def_name, double balance = def_balance, double rate = def_int_rate);

	// Re-define withdraw and deposit methods
	bool deposit(double amount);
	bool withdraw(double amount);

};