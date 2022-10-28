/* TRUST_ACCOUNT CLASS */

#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double rate)
	:Savings_Account{ name,balance,rate }, num_withdraws{0} {
	// Adding bonus when opening the account with more than bonus_threshold
	if (balance >= def_bonus_threshold)
		this->balance += def_max_bonus_amount;
}


// Destructor - can use the Savings Account class 

// Deposit function - invoking Savings Account class method
bool Trust_Account::deposit(double amount) {
	if (amount >= def_bonus_threshold) {
		Savings_Account::deposit(amount);
		Account::deposit(def_max_bonus_amount);	// Bonus deposit
		return true;
	}
	else
		return (Savings_Account::deposit(amount));
}

// Withdrawal function - adds a "fee" to each withdraw
bool Trust_Account::withdraw(double amount) {
	if (num_withdraws >= def_max_num_withdraw) {
		std::cout << "Only 3 withdrawals allowed" << std::endl;
		return false;
	}
	else {
		if (amount <= (def_max_withdraw_percent * balance)) {
			num_withdraws+=1;
			return (Savings_Account::withdraw(amount));
		}
		else {
			std::cout << "Only 20% of balance allowed to withdraw" << std::endl;
			return false;
		}
	}
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
	os << "Trust Account: " << account.name << " has a balance of: $" << account.balance << ", (" << account.int_rate << "% interest)" << std::endl;
	return os;
}