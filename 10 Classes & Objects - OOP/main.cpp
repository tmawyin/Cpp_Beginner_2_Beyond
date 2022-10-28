/* OOP - Classes and Objects
*  Classes and Objects help manage large programs and abstractions
*  Classes - blueprint from which objects are created, they have attributes and functions (methods)
*  Object - is a specific instance of a class. 
*/

#include <iostream>
#include <vector>
#include <string>
#include "Account.h"
#include "Movies.h"

using namespace std;

//* COURSE MATERIAL */

////====== Declaring Class & Creating Objects =====
//class Player {
//public:
//	//attributes (data)
//	static int num_players;
//	string name;
//	int exp;
//private:
//	int health;
//
//	//methods (functions)
//public:
//	void talk(string text) { 
//		cout << name << " says: " << text << endl;
//	}
//	bool is_dead() {
//		if (health == 0)
//			return true;
//		else
//			return false;
//	}
//	
//	void set_health(int);
//};
////defining methods outside the class definition
//void Player::set_health(int value) {
//	health = value;
//}
//
//int main() {
//	//creating Player objects
//	Player frank;
//	Player *enemy;
//
//	//using attributes
//	frank.name = "Frank";
//	frank.set_health(100);
//	frank.exp = 12;
//	frank.talk("hi there");
//	
//	//Player object with pointers (allocated in heap)
//	enemy = new Player;
//	enemy->name = "Destroyer";
//	enemy->set_health(100);
//	(*enemy).exp = 15;
//	enemy->talk("I will destroy you!!");
//	delete enemy;
//	cout << endl;
//
//	// ---- Working with header files (see Account.h)
//	cout << "--- Welcome to The Bank ---" << endl;
//	cout << "Creating a new checking account" << endl;
//	Account checking;
//	checking.set_balance(1000);
//	cout << "Your account balance is: $" << checking.get_balance() << endl;
//	cout << "Withdrawing $200 from account" << endl;
//	if (checking.withdraw(200)) {
//		cout << "Withdrawal Completed. Your new balance is: $" << checking.get_balance() << endl;
//	}
//	cout << endl;
//
//	// --- Working with overladed constructors & initialization list
//	cout << "Creating a new account" << endl;
//	Account checking2(1500,1);
//	cout << "Your account balance is: $" << checking2.get_balance() << endl;
//
//	// --- Shallow vs Deep Copy vs Move Constructor
//	/* Shallow copy refers to the use of a class and a pointer, when a copy of the pointer is 
//	*  created and later destructed, the memory locations is also removed, so the original data
//	*  points to a non-valid memory location
//	* 
//	*  Deep copy uses a copy constructor but allocates it's own memory and copies the value of
//	*  the pointer to the new allocated memory
//	* 
//	*  Move Constructor uses an r-value reference to move the pointer instead of creating a copy
//	*  its declaration: Type::Type(Type &&source): data{source.data} { source.data = nullptr; };
//	*/
//
//	// --- Static Class Members
//	cout << endl << "Total number of accounts: " << Account::get_num_accounts() << endl;
//
//	// -- Struc vs Class
//	// struc members are always public while class member are private
//
//	// --- Friends of classes: use keyword "friend" - alows functions or other class to access methods
//
//	cout << endl;
//	return 0;
//}


//* SECTION CHALLENGE */

// Function prototypes
void increment_watched(Movies& movies, string name);
void add_movie(Movies& movies, string name, string rating, int watched);

/******************************************************************
 * helper function
 * increment_watched expects a reference to a Movies object
 * and the name of the movie to increment the watched count
 *
 * If the watched count was incremented successfully it
*  displays a success message
*  otherwise the watched count could not be incremented
*  because the name of the movie was not found
 * ***************************************************************/

void increment_watched(Movies& movies, string name) {
    if (movies.increment_watched(name)) {
        cout << name << " watch incremented" << endl;
    }
    else {
        cout << name << " not found" << endl;
    }
}

/******************************************************************
* helper function
*  add_movie expects a reference to a Movies object
 * and the name of the movie, the rating and the watched count
 *
 * If the movie was successfully added to the movies object it
*  displays a success message
*  otherwise the movie was not added
*  because the name of the movie was already in movies
 * ***************************************************************/
void add_movie(Movies& movies, string name, string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) {
        cout << name << " added" << endl;
    }
    else {
        cout << name << " already exists" << endl;
    }
}

int main() {

    Movies my_movies;

    my_movies.display();

    add_movie(my_movies, "Big", "PG-13", 2);                 // OK
    add_movie(my_movies, "Star Wars", "PG", 5);             // OK
    add_movie(my_movies, "Cinderella", "PG", 7);           // OK

    my_movies.display();   // Big, Star Wars, Cinderella

    add_movie(my_movies, "Cinderella", "PG", 7);            // Already exists
    add_movie(my_movies, "Ice Age", "PG", 12);              // OK

    my_movies.display();    // Big, Star Wars, Cinderella, Ice Age

    increment_watched(my_movies, "Big");                    // OK
    increment_watched(my_movies, "Ice Age");              // OK

    my_movies.display();    // Big and Ice Age watched count incremented by 1

    increment_watched(my_movies, "XXX");         // XXX not found

    return 0;
}