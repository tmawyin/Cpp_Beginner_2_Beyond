/* FUNCTIONS 
/	functions syntax & prototypes (header files)
/		pass by value VS pass by reference
/	funtion overloading allows you to use the same function name (diff arguments)
/	static variables are only initialized once, after that they retain whatever value is assigned
/	in-line functions
/	recursive functions
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;


/* COURSE MATERIAL

//function to calculate area of circle
void area_circle() {
	double rad{ 5 };
	//cout << "Please enter the radius: ";
	//cin >> rad;
	//cout << endl;
	cout << "The area of the circle is: " << (3.141592653 * pow(rad, 2)) << endl;
}

//function prototype - allows you to write the function after the main()
//note the default value is provided in the funct. prototype
void say_hello(string name=" ");

//function overloading
void print_value(int);
void print_value(double);

//functions with arrays - this function will modify the array
//the function should have "const int arr[]" to avoid this, but no assignement can be done
void set_array(int arr[], size_t size) {
	for (size_t i{ 0 }; i < size; ++i)
		arr[i] = 10 * i + 5;
}


//pass by reference - using the "&" operator
void clearing_num(int&); //this is the function prototype
void clearing_num(int &num) {
	num = 0;
	cout << "Number set to " << num << endl;
}

//inline functions
inline int add_num(int a, int b) {
	return a + b;
}

//recursive function - factorial calculation
double factorial(int n) {
	if (n == 0)	//base case
		return 1;
	return n * factorial(n - 1); //recursive case
}

int main() {

	cout << "=== Functions ===" << endl;
	say_hello("Tom");
	area_circle();

	cout << endl << "=== Funct Overloading ===" << endl;
	print_value(1);
	print_value(1.0);

	cout << endl << "=== Functions with Arrays ===" << endl;
	int arr[5]{ 1,2,3,4,5 };
	cout << "Original Array: " << arr[3] << endl;
	set_array(arr, 5);
	cout << "New Array: " << arr[3] << endl;
	cout << "See, it changed the array" << endl;

	cout << endl << "=== Pass by Reference ===" << endl;
	int num{ 100 };
	cout << "initial number is: " << num << endl;
	clearing_num(num);

	cout << endl << "=== Scope ===" << endl;
	int value{ 100 };
	cout << "The original value is: " << value << endl;
	//scope block:
	{
		int value{ 200 };
		cout << "The value inside block is: " << value << endl;
	}
	cout << "The value outside the block is: " << value << endl;

	cout << endl << "=== In Line Functions ===" << endl;
	int result{};
	cout << "The result value is: " << add_num(100, 200) << endl;

	cout << endl << "=== Recursive Functions ===" << endl;
	cout << "The factorial of 8 is: " << factorial(8) << endl;

	cout << endl;
	return 0;
}

//function prototype - function can be defined here.
void say_hello(string name) {
	cout << "Hello and Welcome "<< name << endl;
}

//function overloading - you need to implement all overloads
void print_value(int num) {
	cout << "The integer number is: " << num << endl;
}
void print_value(double num) {
	cout << "The double number is: " << num << endl;
}

*/

/* SECTION CHALLENGE */
// Creating a menu to work with a vector but this time using functions

void print_menu();
char get_selection();
void print_list(const vector<int>&);
void add_number(vector<int>&);
void calc_mean(const vector<int>&);
void find_smallest(const vector<int>&);
void find_largest(const vector<int>&);
void find_value(const vector<int>&);
void clear_vector(vector<int>&);

int main() {
	vector <int> values{};
	bool done{ false };
	char choice{};

	while (!done) {
		//printing the menu
		print_menu();

		//getting the user input
		choice = get_selection();

		//going through the choices
		switch (choice)
		{
			//printing the list
		case 'P':
		case 'p':
		{
			print_list(values);
			break;
		}
		//adding number
		case 'A':
		case 'a':
		{
			add_number(values);
			break;
		}
		case 'M':
		case 'm':
		{
			calc_mean(values);
			break;
		}
		//smallest
		case 'S':
		case 's':
		{
			find_smallest(values);
			break;
		}
		//smallest
		case 'L':
		case 'l':
		{
			find_largest(values);
			break;
		}
		//clear
		case 'C':
		case 'c':
		{
			clear_vector(values);
			break;
		}
		//find value:
		case 'F':
		case 'f':
		{
			find_value(values);
			break;
		}
		//quit
		case 'Q':
		case 'q':
		{
			cout << endl << "Goodbye..." << endl;
			done = true;
			break;
		}
		//
		default:
			cout << endl << "Selection is not valid, try again" << endl;
		}
	}
	
	return 0;
}

void print_menu() {
	cout << endl;
	cout << "P - print a number" << endl;
	cout << "A - add a number" << endl;
	cout << "M - display mean of numbers" << endl;
	cout << "S - display smallest number" << endl;
	cout << "L - display largest number" << endl;
	cout << "C - clear list" << endl;
	cout << "Q - quit" << endl << endl;
}

char get_selection() {
	char selection{};
	cout << "Enter your selection: ";
	cin >> selection;
	return selection;
}

void print_list(const vector<int> &v){
	cout << "[ ";
	for (int i{ 0 }; i < v.size(); ++i) {
		cout << v.at(i) << " ";
	}
	cout << "]" << endl;
}

void add_number(vector<int>& v) {
	int num{};
	cout << endl << "Enter a number to add: ";
	cin >> num;
	v.push_back(num);
	cout << num << " added to the list" << endl;
}

void calc_mean(const vector<int>& v) {
	cout << endl;
	if (v.size() > 0) {
		double average{ 0.0 };
		for (int i{ 0 }; i < v.size(); ++i)
			average += v.at(i);
		average = average / v.size();
		cout << "The average is: " << average << endl;
	}
	else
		cout << "List is empty, add elements to list" << endl;
}

void find_smallest(const vector<int>& v) {
	cout << endl;
	if (v.size() > 0) {
		int small{ v.at(0) };
		for (int i{ 1 }; i < v.size(); ++i) {
			if (v.at(i) < small)
				small = v.at(i);
		}
		cout << "Smallest value is: " << small << endl;
	}
	else
		cout << "List is empty, add elements to the list" << endl;
}

void find_largest(const vector<int>& v) {
	cout << endl;
	if (v.size() > 0) {
		int large{ v.at(0) };
		for (int i{ 1 }; i < v.size(); ++i) {
			if (v.at(i) > large)
				large = v.at(i);
		}
		cout << "Largest value is: " << large << endl;
	}
	else
		cout << "List is empty, add elements to the list" << endl;
}

void clear_vector(vector <int>& v) {
	v.clear();
	cout << endl << "The list is clear" << endl;
}

void find_value(const vector <int>& v) {
	int num{};
	bool found{ false };
	cout << endl << "Enter a number to find: ";
	cin >> num;
	if (v.size() > 0) {
		for (auto n : v) {
			if (num == n) {
				cout << endl << num << " was found" << endl;
				found = true;
				break;
			}
		}
		if (!found)
			cout << endl << "Your number is not in the list" << endl;
	}
	else
		cout << "List is empty, add elements to the list"<< endl;
}