#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include "MyString.h"

// No-args constructor
Mystring::Mystring()
    : str{ nullptr } {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char* s)
    : str{ nullptr } {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring& source)
    : str{ nullptr } {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete[] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char* Mystring::get_str() const { return str; }

// Overloading assignment operator
Mystring& Mystring::operator=(const Mystring& source) {
    // Check if we are assignning ourself, example p1 = p1;
    if (this == &source)
        return *this;
    
    // re-allocating memory and copying source.str
    delete[] this->str;
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(this->str, source.str);

    return *this;
}

// Overloading the Move operator
Mystring& Mystring::operator=(Mystring&& source) {  
    if (this == &source)
        return *this;
    
    // moving the pointer 
    delete[] this->str;
    this->str = source.str;
    source.str = nullptr;       //important step: when source is destroyed it won't remove the pointer
    return *this;
}

// Overloading the "-" operator: makes string lowercase
Mystring Mystring::operator-() const {
    // creating a new buffer to hold the string
    char* buffer = new char[std::strlen(this->str) + 1];
    std::strcpy(buffer, str);
    // iterating through the string to lowe case
    for (size_t i = 0; i < std::strlen(buffer); i++) {
        buffer[i] = std::tolower(buffer[i]);
    }
    // create an object to return
    Mystring temp{ buffer };
    delete[] buffer;
    return temp;
}

// Overloading the "==" operator: compares two strings, returns true if the same
bool Mystring::operator==(const Mystring& source) const {
    return (std::strcmp(this->str, source.str) == 0);
}

// Overloading the "+" operator: concatinates string
Mystring Mystring::operator+(const Mystring& source) const {
    // create memory for the new string, copy firs, and concatinate the second
    char* buffer = new char[std::strlen(this->str) + std::strlen(source.str) + 1];
    std::strcpy(buffer, this->str);
    std::strcat(buffer, source.str);
    Mystring temp{ buffer };
    delete[] buffer;
    return temp;
}

// Overloading the insertion "<<" operator
std::ostream& operator<<(std::ostream& os, const Mystring& source) {
    os << source.str;
    return os;
}
// Overloading the extraction ">>" operator
std::istream& operator>>(std::istream& in, Mystring& source) {
    char* buffer = new char[1000];
    in >> buffer;
    source = Mystring{ buffer };
    delete[] buffer;
    return in;
}


//******* SECTION CHALLENGE *******

// Overloading != operator
bool Mystring::operator!=(const Mystring& source) const {
    return (std::strcmp(this->str, source.str) != 0);
}

// Overloading > operator
bool Mystring::operator>(const Mystring& source) const {
    return (std::strcmp(this->str, source.str) > 0);
}

// Overloading < operator
bool Mystring::operator<(const Mystring& source) const {
    return (std::strcmp(this->str, source.str) < 0);
}

// Overloading += operator
Mystring Mystring::operator+=(const Mystring& source) {
    *this =  * this + source;
    return *this;
}

// Overloading * operator
Mystring Mystring::operator*(const int number) const {
    char* buffer = new char[number * std::strlen(str) + 1];
    // initial copy and looping to concatinate string
    std::strcpy(buffer, this->str);
    for (size_t i = 1; i < number; i++)
        std::strcat(buffer, this->str);
    Mystring temp{ buffer };
    delete[] buffer;
    return temp;
}

// Overloading *= operator
Mystring Mystring::operator*=(const int number) {
    *this = *this * number;
    return *this;
}

// Overloading ++ pre-increment operator
Mystring& Mystring::operator++() {
    for (size_t i = 0; i < std::strlen(str); i++)
        this->str[i] = std::toupper(str[i]);
    return *this;
}

// Overloading ++ post-increment operator
Mystring Mystring::operator++(int) {
    Mystring temp{ *this };
    ++* this;
    return temp;
}