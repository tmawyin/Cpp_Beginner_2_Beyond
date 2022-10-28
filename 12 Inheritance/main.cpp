/* Inheritance
*	Method to create new classes from existing classes. Can modifity the class to do what we need
*	Public inheritance: "is-a" relationship. Example: Checking_Account "is-a" Account
*	Composition: "has-a" relationship. Example: Person "has-a" Account
*/

#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

/* COURSE MATERIAL */
//int main() {
//
//	// Basic Inheritance
//	Account acc{};
//	acc.deposit(100.00);
//	acc.withdraw(50.00);
//	
//	cout << endl;
//
//	/* Note on constructor of derived class:
//	*	the base class constructor is created first, then the derived class constructor
//	//*	the derived class destructor is executed first, then the base class destructor
//	*/
//	Savings_Account sav_acc{};
//	sav_acc.deposit(500.00);
//	sav_acc.withdraw(10.50);
//
//	cout << endl;
//
//	// Example of redefining and invoking base class methods 
//	Savings_Account other_acc{ "myAct", 1000, 4.0 };
//	other_acc.deposit(150.00);			// redefining and invoking base class method (See Savings_Account.cpp)
//	other_acc.display_balance();		// base class method
//
//	cout << endl;
//	return 0;
//}


/* SECTION CHALLENGE */
int main() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{ "Larry" });
    accounts.push_back(Account{ "Moe", 2000 });
    accounts.push_back(Account{ "Curly", 5000 });

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{ "Superman" });
    sav_accounts.push_back(Savings_Account{ "Batman", 2000 });
    sav_accounts.push_back(Savings_Account{ "Wonderwoman", 5000, 5.0 });

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // ****** ADDING CHECKING + TRUST ACCOUNT ********
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{ "Hulk" });
    check_accounts.push_back(Checking_Account{ "Cpt America", 2000 });
    check_accounts.push_back(Checking_Account{ "Iron Man", 5000 });

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    Trust_Account a{};
    Trust_Account b{"B"};
    Trust_Account c{"C", 2000};
    Trust_Account d{"D", 5000, 5};

    a.deposit(200);
    a.withdraw(100);
    a.withdraw(2);
    a.withdraw(3);
    a.withdraw(4);
    a.withdraw(5);
    cout << a;
    cout << d;
    b.deposit(10000);
    cout << b;

    cout << endl;
    return 0;
}
