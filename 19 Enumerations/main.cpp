/* Enumerations
*	A user-defined type that models a set of constant integral values. Example: day of the week, suits in a deck, etc
*	Enumerations are used for readibility and algorithm correctness
*	Structure: enum-key enum-name : enumerator-type {};
*   Typically enumeration is used with "Switch" statements
*/

#include <iostream>
#include <vector>

/* COURSE MATERIAL */
int main() {

	// *** Unscoped Enumeration ***
	// Are allowed to be accessed anywhere in the program. Issues with unscoped enumeration:
	//		1) You can't have two enum elements with the same name (even in different enumerations)
	//		2) It is possible to compare different enums because of their underlying value - but this might not be the intent
	
	// Implementation & Syntax:
	enum {Red, Green, Blue};	// Implicit initialization: compiler will assign 0, 1, 2 to each element
	enum : uint8_t {A, B, C};	// It's possible to assign the type of the enumerators
	enum Deck {Hearts, Diamonds, Spade, Clubs};		// Naming the enumerator as "Deck"
	enum Days {M=1, T=2, W=3};			// Explicit Initialization: provide the enumaration to each item

	// Use enumeration as variables
	enum Direction {North, South, East, West};
	Direction dir{ North };
	std::cout << dir << std::endl;		// Prints the value of North, in this case 0 - use a switch to display the actual enum string or overload << operator

	// *** Scoped Enumeration ***
	// Structure: enum class enum-name: enum-type {};
	enum class Months {J,F,M,A,My,Jn,Jl,Ag,S,O,N,D};

	std::cout << std::endl;
	return 0;
}