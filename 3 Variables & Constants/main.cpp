/* Variables and constants and how to use them
	
	// Initialization - 3 ways of doing it
	int age1 = 21;  OR	int age2(21);	OR	int age3{ 21 };

	Data Types
	Characters: char, char16_t, char32_t, wchar_t
	Integers: short int, long int, long long int, unsigned int
	Floating: float, double, long double
*/

#include <iostream>
#include <climits>

using namespace std;

// Global variables (declared outside functions)
//	 int age{21}; 

/* COURSE MATERIAL
int main() {

	double len{ 0 };
	double width{ 0 };

	cout << "Enter the length and width of the room: ";
	cin >> len >> width;
	
	double area = 0;
	area = len * width;

	cout << "The area of the room is " << area << endl;

	// Operator sizeof()
	sizeof(int);
	sizeof(double);
	sizeof(area);

	// Constants
	const int months{ 12 };
	cout << "\nThere is always " << months << " in a year" << endl;

	return 0;
}
*/

/* SECTION CHALLENGE 
	Room Cleaning Services, small rooms $25, large rooms $35, tax 6%
*/
int main() {

	const double small_room_price{ 25.0 };
	const double large_room_price{ 35.0 };
	const double tax{ 0.06 };
	
	cout << "Welcome to Room Cleaning Services" << endl;
	cout << "---------------------------------" << endl;
	cout << endl;
	// Asking for number of rooms
	int small_room{ 0 };
	cout << "How many small rooms would you like clean? ";
	cin >> small_room;
	int large_room{ 0 };
	cout << "How many large rooms would you like clean? ";
	cin >> large_room;
	cout << endl;

	// Working on the Estimate
	double total_cost = (small_room * small_room_price) + (large_room * large_room_price);
	double total_tax = total_cost * tax;
	double estimate = total_cost + total_tax;

	cout << "Estimate for room cleaning services:" << endl;
	cout << "Number of small rooms: " << small_room << endl;
	cout << "Number of large rooms: " << large_room << endl;
	cout << "Price for small room cleaning: " << small_room_price << endl;
	cout << "Price for large room cleaning: " << large_room_price << endl;
	cout << "Cost: $" << total_cost << endl;
	cout << "Tax:  $" << total_tax << endl;
	cout << "=====================================" << endl;
	cout << "Total Estimate: $" << estimate << endl;
	cout << "Estimate is valid for " << 30 << " days" << endl;

	return 0;
}