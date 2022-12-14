/* Lambda Expression
*	Basically they work as in-line functions to avoid writing small functions
*	lambdas are converted into function objects
*/

#include <iostream>
#include <vector>
#include <functional>		// required to use "function" when passing expressions to function
#include <numeric>
#include <algorithm>

/* COURSE MATERIAL */
struct Square_functor {
	void operator()(int x) {
		std::cout << x * x;
	}
};

// Passing expressions to a function: 2 ways of writting them
// Note: the lambda type is "void" and it expects and "int" as parameter
void test(std::function<void(int)> lmd) {
	lmd(50);
}
void foo(void(*lmd)(int)) {
	lmd(100);
}

// Returning expressions from a function. Alternative way is to use: void (*sqr())(int){ return []....}
std::function<void(int)> sqr() {
	return [](int x) {std::cout << x * x << std::endl; };
}
auto cube() {		// Using auto to deduce the return type
	return [](int x) {std::cout << x * x * x << std::endl; };
}

// Predicate lambda function: takes a vector of nums and applies the "predicate" lambda function
void print_if(std::vector<int> nums, bool (*predicate)(int)) {
	for (int i : nums)
		if (predicate(i))		// Note: lambda conditional returns T/F, so if it's True, the value is printed
			std::cout << i;
}

int main() {
	// Using function objects
	Square_functor square;			// Withou lambda expressions we would have to build function classes like this one
	square(4);
	std::cout << std::endl;

	// Structure of a Lambda Expression: []()->return_tye specifiers {};
	// []: defines start of expression & contains capture list
	// (): parameter list
	// ->return_type: return type (can be ommited if void)
	// specifiers: mutable and constexpr
	// {}: body of the code

	// **** Stateless Lambda Expressions ****
	[]() {std::cout << "Hi!" << std::endl; }();						// You need the () at the end to instaciate the lambda
	[](int x) {std::cout << "Number: " << x << std::endl; }(5);		// use the (#) to pass the value

	auto l = []() {std::cout << "Bye" << std::endl; };				// can assign lambda expressions to a variable
	l();	// Displays 'Bye'

	auto s = [](int x, int y) -> int {return x + y; };				// use the -> to specify the return value (can be ommited if easy to deduct)
	std::cout << s(3, 4) << std::endl;

	auto p = [](auto x) {std::cout << x << std::endl; };			// use of "auto" in the parameter type when different types will be passed
	p(10);
	p("Hello");

	// We can pass lambda expressions to functions
	test(p);
	foo(p);

	auto c = cube();				// Using a function that returns a lambda expression
	c(3);

	// ** Example of a predicate lambda - a reason to pass lambda to a function
	std::vector<int> n{ 1,2,3,4,5,6 };
	print_if(n, [](auto x) {return x % 2 == 0; });		// Displays even
	std::cout << std::endl;
	print_if(n, [](auto x) {return x % 2 != 0; });		// Displays odd
	std::cout << std::endl;

	// Checking the data type of the lambda expression 
	std::cout << typeid(p).name() << std::endl;

	// **** Stateful Lambda Expressions ****
	// [captured variables] () -> return specifiers {};
	// captured variables: instanciate variables for the scope of the lambda expression only. 
	//	Think of the capture variables as the private parameters in a lambda Class generated by the compiler
	int y{ 10 };
	[y](int x) {std::cout << x + y << std::endl; }(5);		// displays 15

	auto t = [y](int x) mutable {							// mutable allows us to change the value of y (only in the scope of the expression)
		y += 20;											// Note: everytime the lambda gets called, the 'y' value will keep increasing by 20
		std::cout << x + y << std::endl; 
	};
	t(5);	// Note how y is now 30
	t(1);	// Note how y is now 50
	std::cout << "Parameter 'y' doesn't change outside lambda scope: " << y << std::endl;

	[&y]() {y = 200;}();									// passing by reference will change the value outside of the lambda scope
	std::cout << "Parameter 'y' changed (passed by reference): " << y << std::endl;

	// Default captures:
	// [=]: default capture by value. Example [=, &x]: captures everything by value except variable x
	// [&]: default capture by reference. 
	// [this]: default capture "this" object by reference.
	int num1{ 100 };
	int num2{ 200 };
	int num3{ 300 };

	[=]() mutable {		// All capture variables passed by value (they won't change outside the lambda scope)
		num1 += 100;
		num2 += 100;
		std::cout << "Inside lambda: " << num1 << " & " << num2 << std::endl;
	}();
	std::cout << "Outside lambda: " << num1 << " & " << num2 << std::endl;

	// **** Lambda & the STL ****
	//	lambdas are generally used with STL algorithms like: for_each(), is_permutation(), transform(), remove_if(), etc.
	std::vector<int> test_scores{ 93,80,85,91,79,89 };
	int bonus{ 5 };
	std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(),
		[bonus](int score) {return score += bonus; });

	std::for_each(test_scores.begin(), test_scores.end(), [](int score) {std::cout << score << " "; });
	std::cout << std::endl;



	std::cout << std::endl;
	return 0;
}