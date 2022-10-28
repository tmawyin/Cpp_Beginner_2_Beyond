/* Overloading Operator
*  Allows user to create operators for our own defined types
*  
*/

#include <iostream>
#include <vector>
#include <cstring>
#include "MyString.h"

using namespace std;

/* COURSE MATERIAL */
/*
int main() {
    
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge{ larry };            // copy constructor 

    empty.display();
    larry.display();
    stooge.display();
	
    // Overloading "=" operator (Implementation in MyString.cpp)
    Mystring a{ "Hello" };
    Mystring b;
    b = a;
    b.display();
    b = "This is a string";
    b.display();

    // Overloading "move" operator (Implementation in MyString.cpp)
    Mystring m;
    m = Mystring{ "Hola" };
    m.display();

    // Overloading other (+, -, ==) operators
    Mystring upper{ "HELLO" };
    Mystring added{ " and welcome!" };

    Mystring newString = -upper + added;
    newString.display();

    cout << boolalpha << endl;      //makes boolean as alpha when displaying
    cout << (a == upper) << endl;

    // Note: you can overload operators as NOT member functions of a class.
    // However, you will have to use getter functions of the class OR make the functions "friends" of the class
    
    // Overlading the extraction and insertion operators
    Mystring stooge1{ "Larry" };
    Mystring stooge2;

    cout << endl << "Enter the second stooge name: ";
    cin >> stooge2;
    cout << endl << "The stooges are " << stooge1 << ", " << stooge2 << ", and ..." << endl;

	cout << endl;
	return 0;
}
*/

/* SECTION CHALLENGE */
// Adding to the MyString class to overload other operators
int main() {
    

    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};

    cout << (a==b) << endl;         // true
    cout << (a!=b) << endl;          // false
    
    b = "george";
    cout << (a==b) << endl;         // false
    cout << (a!=b) << endl;          // true
    
    cout << (a<b) << endl;          // true
    cout << (a>b) << endl;           // false

    Mystring s1 {"FRANK"};
    s1 = -s1;
    cout << s1 << endl;               // frank

    s1 = s1 + "*****";
    cout << s1 << endl;               // frank*****
    
    s1 += "-----";                        // frank*****-----
    cout << s1 << endl;
    
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;              // 123451234512345
    
    Mystring s3{"abcdef"};
    s3 *= 5;
    cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef
    
    Mystring s = "Frank";
    ++s;
    cout << s << endl;                  // FRANK

    s = -s;
    cout << s << endl;                  // frank

    Mystring result;
    result = ++s;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl;                  // FRANK

    s = -s;
    cout << s << endl;                  // frank
    result = s++;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // frank

    
    return 0;
}