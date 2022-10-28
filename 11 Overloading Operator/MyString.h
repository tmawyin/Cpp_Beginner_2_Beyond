#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    // *** Overloading operators as non-members of the class (make them friends and implement in class cpp file) ***
    //friend bool operator==(const Mystring& source1, const Mystring& source2);
    //friend Mystring operator-(const Mystring& source);

private:
    char* str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                             // No-args contstructor
    Mystring(const char* s);                                // Overloaded contstructor              
    Mystring(const Mystring& source);                       // Copy constructor
    ~Mystring();                                            // Destructor
    void display() const;
    int get_length() const;                                 // getters
    const char* get_str() const;

   /* Overloading the assignment operator "="
   *  Do not confuse assignment with initialization. Returns a reference value  */
    Mystring &operator=(const Mystring& source);

    /* Overloading the Move operator (r-values) 
    *   this is a more efficient way to do a deep copy assignment */
    Mystring &operator=(Mystring&& source);

    /* Overloading other operators:
    * "-" will make string lowercase
    * "==" will compare if strings are the same
    * "+" will concatinate strings objects    */
    Mystring operator-() const;
    Mystring operator+(const Mystring &source) const;
    bool operator==(const Mystring& source) const;


    /* Overloading the insertion and extraction (<<, >>) operators 
    *  Implement them as non-member functions. Return a reference to the "ostream"/"istream"  */
    friend std::ostream& operator<<(std::ostream& os, const Mystring& source);
    friend std::istream& operator>>(std::istream& in, Mystring& source);

    // ******** SECTION CHALLENGE ********
    // Adding other members for overloading operators

    // != operator: returns true if strings are not the same
    bool operator!=(const Mystring& source) const;

    // > operator: compares if string is lexically greater
    bool operator>(const Mystring& source) const;

    // < operator: compares if string is lexically smaller
    bool operator<(const Mystring& source) const;

    // += operator: appends new string to existing string
    Mystring operator+=(const Mystring& source);

    // * operator: repeats string given times
    Mystring operator*(const int number) const;

    // *= operator: repeats string and stores it back 
    Mystring operator*=(const int number);

    // ++ pre-increment operator: sets all letters to uppercase
    Mystring& operator++();

    // ++ post-increment operator: sets all letters to uppercase (after assignment)
    Mystring operator++(int);
};

#endif // _MYSTRING_H_