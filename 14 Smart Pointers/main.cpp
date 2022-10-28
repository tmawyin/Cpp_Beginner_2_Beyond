/* Smart Pointers
*	Help to solve a lot of the issues with raw pointers such as memory leaks, dangling pointers, or unintialized pointers
*	Smart pointers are objects - can only point to heap-allocation memory
*	Smart pointers have a wrapper around a raw pointer (i.e., you can use *, ->). However, no arithmetic is supported
* 
*	RAII - Resource Acquisition Is Initialization
*		This means they need to acquire resources (like opening a file or allocating memory) and 
*		is initalization means that they need a constructor/destructor
*/

#include <iostream>
#include <vector>
#include <memory>	// Required for smart pointers

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

using namespace std;

/* COURSE MATERIAL */
/*int main() {

	// ======= Unique Pointers =======
	//	There can only be ONE unique pointer pointing to the object in heap
	//	Cannot be assigned or copied. However, it can be moved. Owns what it poitns to
	//	When destroyed, what it points to gets destroyed automatically
	unique_ptr<int> p1{ new int{100} };
	std::cout << *p1 << endl;	// Can be dereferenced
	*p1 = 200;				// Can be re-assigned a value

	std::cout << p1.get() << endl;	// get() returns a pointer to the managed object
	p1.reset();					// Can get reset to a nullptr

	// Other ways of allocating of unique pointers C++14
	unique_ptr<int> p2 = make_unique < int> (100);
	auto p3 = make_unique<double>(99.9899);

	// Example of how unique ptrs can't be copied only moved
	unique_ptr<int> p4;
	//p4 = p2;	is not allowed!
	p4 = move(p2);	// is allowed, and p2 becomes nullptr
	if (!p2)
		std::cout << "p2 is null pointer" << endl;
	std::cout << "p4 = " << *p4 << endl;
	std::cout << "----------" << endl;

	// ----- Unique Pointers with Account class -----
	unique_ptr<Account> a1 = make_unique<Checking_Account>("Moe", 5000);
	a1->deposit(1000);
	a1->withdraw(500);
	std::cout << *a1 << endl;

	vector<unique_ptr<Account>> accounts;
	accounts.push_back(make_unique<Checking_Account>("Jim", 1000));
	accounts.push_back(make_unique<Savings_Account>("Bob", 1000,5.2));
	accounts.push_back(make_unique<Trust_Account>("Dan", 1000,3.0));

	for (const auto &acc: accounts) {		// Important: Use by reference since you can't copy unique pointers
		std::cout << *acc << endl;
	}

	std::cout << "----------" << endl;
	// ======= Shared Pointers =======
	//	Provides shared ownership of heap object. It is not unique, many can share same object on heap
	//	Can be assigned and moved. It can be passed to functions by value
	//	Do not support managing arrays by default.
	//	Use a counter to know how many pointers point to the heap, when counter = 0 destroy the heap
	shared_ptr<int> s1{ new int {100} };
	*s1 = 200;			// Can be re-asigned a value
	std::cout << "S1 Count:" << s1.use_count() << endl;		// Returns the number of shared object managing the heap
	s1.reset();			// Sets s1 to null ptr and reduces counter

	// Other ways to initialize and allocate shared ptrs
	shared_ptr<int> s2 = make_shared<int>(100);		// "make_shared" is more efficient
	shared_ptr<int> s3{ s2 };
	shared_ptr<int> s4;
	s4 = s2;
	
	// ----- Shared Pointers with Account class -----
	shared_ptr<Account> acc1 = make_shared<Checking_Account>("Moe, 5000");
	shared_ptr<Account> acc2 = make_shared<Savings_Account>("Curly, 6000", 1.0);
	shared_ptr<Account> acc3 = make_shared<Trust_Account>("Larry, 3000", 3.0);

	vector<shared_ptr<Account>> shrd_accounts;
	shrd_accounts.push_back(acc1);
	shrd_accounts.push_back(acc2);
	shrd_accounts.push_back(acc3);

	// Note: the count would be 2 since we push a copy of each shared_ptr to the vector
	for (const auto& acc : shrd_accounts) {
		std::cout << *acc << endl;
		std::cout << "Use count: " << acc.use_count() << endl;
	}

	std::cout << "----------" << endl;
	// ======= Weak Pointer =======
	//	Always created from shared pointers
	//	Do not participate in owning relationship. Does not increment counter
	//	Useful when strong circular reference between classes exist
	
	// ======= Custom Deleters =======
	//	You can write a function: void my_deleter(Some_Class *raw_ptr)
	//	Create the pointer as: shared_ptr<Some_Class> ptr {new Some_Class{}, my_deleter};
	// 
	//	You can also use lambda expression to generate a deleter when creating the pointer

	std::cout << endl;
	return 0;
} */

/* SECTION CHALLENGE */
// 
class Test {
private:
	int data;
public:
	Test() : data{ 0 } { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
	Test(int data) : data{ data } { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
	int get_data() const { return data; }
	~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);

// make(): Creates and returns a unique pointer of a vector that contains shared_pts of the class type Test.
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
	return make_unique<vector<shared_ptr<Test>>>();
}

// fill(): Fills in the vector with user data
void fill(std::vector<std::shared_ptr<Test>>& vec, int num) {
	int data;
	for (int i = 1; i <= num; i++) {
		std::cout << "Data for element [" << i << "]: ";
		std::cin >> data;
		vec.push_back(make_shared<Test>(data));
	}
}

// display(): Shows the contents of the vector on the screen
void display(const std::vector<std::shared_ptr<Test>>& vec) {
	std::cout << endl;
	std::cout << "==== Vector elements ====" << endl;
	for (const auto &elem : vec)
		std::cout << elem->get_data() << endl;
	std::cout << "=========================" << endl << endl;
}


int main() {
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points do you want to enter: ";
	int num;
	std::cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);
	return 0;
}