/* Program Flows
*	Includes: If statements, switch, and Loops
*		For loop: used to iterate a specific number of times
*		While loop: iterate while conditions is true; stop when condition becomes false; check condition at beginning of iteration
*		Do-While loop: same as while loop but condition is checked at the end of every iteration
*		continue & break
*		nested loop exercise
*/

#include <iostream>
#include <vector>

using namespace std;

/* COURSE MATERIAL
int main() {

	//if statement ===========
	int num{};
	cout << "Enter a number: ";
	cin >> num;

	if (num > 10 && num < 100) {
		cout << "Your number is between 10 and 100" << endl;
		cout << "Your number is " << num - 10 << " numbers away from 10" << endl;
		cout << "Your number is " << 100- num << " numbers away from 100" << endl;
	}
	else if (num >=100)	//note: single line statement do no need {}
		cout << "Your number outside the bounds!" << endl;
	else 
		cout << "Your number is weird!" << endl;
	cout << endl;

	//switch statement ============
	char letter_grade{};
	cout << "Enter the letter grade you expect: ";
	cin >> letter_grade;

	switch (letter_grade)
	{
	case 'A':
	case 'a': 
		cout << "You need a 90 or above" << endl;
		break;
	case 'B':
	case 'b': 
		cout << "You need 80 to 89" << endl;
		break;
	case 'C':
	case 'c':
		cout << "You need 70 to 79" << endl;
		break;
	case 'D':
	case 'd':
		cout << "You need 60 to 69, go study!" << endl;
		break;
	case 'F':
	case 'f':
	{
		char confirm{};
		cout << "Are you sure you want an F? (y/n)";
		cin >> confirm;
		if (confirm == 'Y' || confirm == 'y') {
			cout << "Ok, you need a score below 60" << endl;
		}
		else {
			cout << "Good, go study!" << endl;
		}
		break;
	}
	default:
		cout << "This is not a valid letter" << endl;
	}

	//conditional operator --> (cond_expr) ? expr1 : expr2
	cout << endl;
	cout << ((num > 100) ? "Greater than 100" : "Smaller than 100") << endl;
	cout << ((num % 2 == 0) ? "Even" : "Odd") << endl;
	cout << endl;

	//FOR looping ============
	//initialization can happen inside the loop
	for (int i{ 1 }; i <= 5; ++i) {
		cout << i << endl;
	}
	
	//another way to iterate through array or vector
	int scores[]{ 100,99,98,97 };
	for (auto item : scores) {
		cout << item << endl;
	}
	cout << endl;

	//WHILE looping ===========
	int i{ 1 };
	while (i <= 10) {
		if (i % 2 == 0)
			cout << i << endl;
		++i;
	}
	cout << endl;

	//DO-WHILE looping ==========
	//you are guaranteed the loop runs at least once
	int number{};
	do {
		cout << "Enter a number between 1 and 5: ";
		cin >> number;
	} while (number < 1 || number > 5);
	cout << endl;

	//CONTINUE & BREAK ==============
	vector<int> values{ 1,2,-1,3,-1,-99,7,8,10 };
	for (auto val : values) {
		if (val == -99)	//break will exit the loop entirely
			break;
		else if (val == -1)
			continue;	//continue will go back to the begining of the loop
		else
			cout << "Last good value is: " << val << endl;
	}

	cout << endl;

	//EXCERSICE
	vector <int> vec{ 2,4,6,8 };
	int result{ 0 };
	if (vec.size() <= 1)
		result = 0;
	else {
		for (int i{ 0 }; i < vec.size() ; ++i) {
			for (int j{ i+1 }; j < vec.size(); ++j)
			{
				cout << vec[i] << " * " << vec[j] << endl;
				result += (vec[i] * vec[j]);
			}
		}
	}
	cout << "Final result is: " << result << endl;

	return 0;
}
*/

/* SECTION CHALLENGE */
// Building a menu to generate a vector
// Note: there is no error checking on this program

int main() {
	vector<int> values{};
	bool done{ false };
	char choice{};
	int number{};
	
	while (!done) {
		cout << endl;
		cout << "P - print a number" << endl;
		cout << "A - add a number" << endl;
		cout << "M - display mean of numbers" << endl;
		cout << "S - display smallest number" << endl;
		cout << "L - display largest number" << endl;
		cout << "C - clear list" << endl;
		cout << "Q - quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) 
		{
		//printing the list
		case 'P':
		case 'p':
		{
			cout << "[ ";
			for (int i{ 0 }; i < values.size(); ++i) {
				cout << values.at(i) << " ";
			}
			cout << "]" << endl;
			break;
		}
		//adding number
		case 'A':
		case 'a':
		{
			cout << "Enter a number to add: ";
			cin >> number;
			values.push_back(number);
			cout << number << " added to the list" << endl;
			break;
		}
		//mean
		case 'M':
		case 'm':
		{
			if (values.size() > 0) {
				double average{0.0};
				for (int i{ 0 }; i < values.size(); ++i)
					average += values.at(i);
				average = average / values.size();
				cout << "The average is: " << average << endl;
			}
			else
				cout << "List is empty, add elements to list" << endl;
			break;
		}
		//smallest
		case 'S':
		case 's':
		{
			if (values.size() > 0) {
				int small{values.at(0)};
				for (int i{ 1 }; i < values.size(); ++i) {
					if (values.at(i) < small)
						small = values.at(i);
				}
				cout << "Smallest value is: " << small << endl;
			}
			else
				cout << "List is empty, add elements to the list" << endl;
			break;
		}
		//largest
		case 'L':
		case 'l':
		{
			if (values.size() > 0) {
				int large{ values.at(0) };
				for (int i{ 1 }; i < values.size(); ++i) {
					if (values.at(i) > large)
						large = values.at(i);
				}
				cout << "Largest value is: " << large << endl;
			}
			else
				cout << "List is empty, add elements to the list" << endl;
			break;
		}
		//clear
		case 'C':
		case 'c':
		{
			values.clear();
			cout << "List is clear" << endl;
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
		default:
			cout << endl << "Selection is not valid, try again" << endl;
		}
	}

	cout << endl;
	return 0;
}
