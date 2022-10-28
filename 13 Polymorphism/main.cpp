/* Polymorphism
*	dynamic polymorphism requires: inheritance and "virtual" functions
*	Declare "virtual" functions on the base class. It is best practice to make all overwritten derived methods as "virtual" too
*	Declare all destructors as "virtual" too
* 
*	Use the "override" keyword (end of function declaration) when planning on overriding functions
*	Use the "final" keyworkd (en of function declaration) when no more classes can be derived from this class
* 
*	Pure virtual functions - makes base class an abstract classes and forces methods from derived classes to be overriden
*	Abstract classes - can be used as interfaces for multiple classes
*/

#include <iostream>
#include <vector>
//#include "Accounts.h"     // COURSE MATERIAL ONLY
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

/* COURSE MATERIAL */

//int main() {
//
//	// Polymorphism is best used when using pointers
//	//Account *p1 = new Account();			// Account is an abstract class, can't be instanciated
//	Account *p2 = new Checking();
//	Account *p3 = new Savings();
//	Account *p4 = new Trust();
//
//	Account* acts[] = {p2,p3,p4};
//
//	for (auto i = 0; i < 3; i++)
//		acts[i]->withdraw();	// dynamic bounding - will call the withdraw method based on the type of Account
//	
//	cout << endl;
//	
//	for (auto i = 0; i < 3; i++)
//		acts[i]->add_rewards();
//
//	// Freeing memory allocated
//	//delete p1;
//	delete p2;
//	delete p3;
//	delete p4;
//
//	cout << endl;
//	return 0;
//}


/* SECTION CHALLENGE */
int main() {
    cout.precision(2);
    cout << fixed;

    Checking_Account frank{ "Frank", 5000 };
    cout << frank << endl;

    Account* trust = new Trust_Account("James");
    cout << *trust << endl;

    Account* p1 = new Checking_Account("Larry", 10000);
    Account* p2 = new Savings_Account("Moe", 1000);
    Account* p3 = new Trust_Account("Curly");

    std::vector<Account*> accounts{ p1,p2,p3 };

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    display(accounts);

    delete p1;
    delete p2;
    delete p3;
 
    // OLD CODE TO TEST VECTORS
    /*
    // Account
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

    // Checking

    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{ "Kirk" });
    check_accounts.push_back(Checking_Account{ "Spock", 2000 });
    check_accounts.push_back(Checking_Account{ "Bones", 5000 });

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust

    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account{});
    trust_accounts.push_back(Trust_Account{ "Athos", 10000, 5.0 });
    trust_accounts.push_back(Trust_Account{ "Porthos", 20000, 4.0 });
    trust_accounts.push_back(Trust_Account{ "Aramis", 30000 });

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i = 1; i <= 5; i++)
        withdraw(trust_accounts, 1000);
    */


    return 0;
}