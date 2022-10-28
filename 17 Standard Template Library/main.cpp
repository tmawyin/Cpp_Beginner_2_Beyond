/* The Standard Template Library - STL
*	Library contains: Containers, Iterators, Algorithms that are adaptable and reusable
*	Containers - collection of objects or primitive types. Examples: array, vectors, list, maps, set, stacks, queue, etc.
*	Algorithms - functions for processing sequence of elements from containers
*	Iterators - generate sequence of elements from containers
* 
*	Macros are a way of making generic code but it's not great to use it. Always wrap it in brackets. Example of macro:
*		#define SQUARE(a) ((a)*(a))
* 
*	Templates are a better way to make a generic program. All operators must be supported by the parameters types. Example:
*		template <typename T>
*		T square(T a) {return a*a;}		If the type of "a" does not support "*" then it won't work. Overload operators when needed
*	You can generate Templates Classes
*/

#include <iostream>
#include <vector>		// Vector is one of the STL containers
#include <string>
#include <algorithm>	// STL algorithm library: sort, reverse, etc.
#include <utility>		// Cointer for "pair" template - holds two data values of any type
#include <set>	
#include <map>
#include <list>			// Double linked-list - can be traverse in both directions 
#include <forward_list>	// Single linked-list - can only be traverse in one direction (only front methods available)
#include <array>
#include <deque>
#include <cctype>
#include <iomanip>
#include <iterator>		// Allows the use of the "advance" function
#include <limits>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

/* COURSE MATERIAL */
// Creating a function template 
template <typename T>			// Defining this is a template (works with classes too)
T find_max(T a, T b) {
	return (a > b) ? a : b;
}

// Creating a class template
template <typename T, int N>				// We can create a template with data as parameter. In this case the size of the array
class Array {
	int size{ N };
	T values[N];
public:
	Array() = default;
	Array(T init_val) {
		for (auto& item : values)
			item = init_val;
	}
	
	// Overiding the [] Operator:
	T& operator[](int index) {
		return values[index];
	}
};

int main() {

	// Function template
	cout << find_max(10, 20) << endl;
	cout << find_max<char>('a', 'A') << endl;
	cout << find_max(50.6,30.5) << endl;

	// Class template
	Array<int, 3> arr1{ 1 };
	cout << arr1[1] << endl;
	Array<string, 5> arr2{ "Hello" };
	cout << arr2[3] << endl;

	// Iterators
	vector<int> nums {1, 2, 3, 4, 5};
	auto it = nums.begin();
	cout << *it << endl;
	it = nums.end()-1;						// end() function points to the element after the end of the data
	cout << *it << endl;

	list<string> names{ "Larry", "Curly", "Moe" };
	auto list_it = names.crbegin();			// constant reverse iterator - goes in reverse order and can't modify the list
	cout << *list_it << endl;				// prints Moe - if we advance the iterator it will go to Curly and then Larry
	list_it++;
	cout << *list_it << endl;
	cout << endl;

	// Algorithms
	vector<int> numbers{1,2,3,4,5 };
	
	// for_each applies the given lambda expression to each element
	for_each(numbers.begin(), numbers.end(), [] (int val) { cout << val*val << " "; });
	cout << endl;

	// Checking if element 3 is in the vector, returns an interator
	auto loc = find(numbers.begin(), numbers.end(), 3);
	if (loc != numbers.end())
		cout << "The number was found" << endl;
	else
		cout << "Couldn't find the number" << endl;
	cout << endl;

	// Other algorithms include: 
	//		count(begin, end, value to count)
	//		count_if(begin, end, lambda_expression): counts only if the condition by the expression is met
	//		replace(begin, end, value to be replaced, replace with value)
	//		all_of(begin, end, lambda_expression): returns T/F based if the lambda expression applies to all the elements
	//		copy or copy_if()

	// Array Container
	array <int, 5> arr{ 5,3,1,2,4 };
	cout << arr.front() << endl;
	cout << arr.at(4) << endl;
	sort(arr.begin(), arr.end());		// sorts the array from lower to higher values
	auto min_num = min_element(arr.begin(), arr.end());		// find the lowest value element (min)
	auto max_num = max_element(arr.begin(), arr.end());		// finds the highest value element (max)
	cout << "The max number is: " << *max_num << " and the min number is: " << *min_num << endl << endl;
 	
	// Vector Container
	vector<int> vec{ 1,5,6,3,7,8,10 };
	auto vec_it = find(vec.begin(), vec.end(), 3);
	vec.insert(vec_it, 10);				// inserts number 10 on the found iterator (after number 3)
	cout << vec.at(3) << endl;
	cout << endl;

	// Deque Container - similar to vectors but are not stored in the same memory block
	deque<int> d{ 1,2,3,4,5,6,7,8,9,10 };
	d.pop_front();
	d.push_front(1);
	d.emplace_front(11);
	cout << d.at(0) << endl;
	cout << endl;

	// List & Fwd List Containers
	list<int> l = { 1,2,3,4,5,6 };
	l.push_back(7);					// pushes number 7 to the back of the list
	l.pop_front();					// takes the front element from the list
	l.resize(10);					// resizes the list to size of 10, all new elements are initialized to 0

	forward_list<int> fl{ 4,3,1,2,0,9,7,8 };
	auto l_it = find(fl.begin(), fl.end(), 2);
	fl.insert_after(l_it, 5);				// insert element after a value pointed by an iterator
	std::advance(l_it, 2);					// advances the iterator 2 steps forward (use negative number to move back)
	fl.erase_after(l_it);					// removes the element after the value pointer by an iterator	
	cout << endl;

	// Set Containers
	set<int> s{ 1,2,3,3,4,5,5,5,6 };		// Sets are ordered and can't have duplicates. Use multi_set if repeated values are needed
	s.insert(7);							// inserts an element on the set: returns a pair with iterator to the item and T/F if insertion was successful
	s.erase(3);								// removes an element from the set
	cout << s.count(4) << endl;				// determines if an element is in the set
	s.find(6);								// finds the position of the given number - returns iterator

	// Maps Containers
	map<std::string, int> m1{ { "Bob", 20 } };	// Consist of pair objects of the type {key, value)
	cout << m1.size() << endl;
	m1["James"] = 15;						// One way to insert elements
	m1.insert({ "John", 25 });				// Using insert requires a pair object {key, value}
	m1.insert(make_pair("Rob", 30));		// using make_pair to build the pair object

	cout << m1["James"] << endl;			// values are casted by using the "key"
	auto m_it = m1.find("Rob");				// using the map find funtion - returns an iterator
	if (m_it != m1.end())
		cout << m_it->first << " is " << m_it->second << " years old" << endl;		// iterator access to key (first) and value (second) 
	cout << endl;

	// Stack Container - Last-in, First-out
	// methods: push, pop, top, empty, size
	stack<int> stk;						// uses deque container by default
	stack<int, list<int>> stk2;			// other ways to initialize stacks (specifing the container)
	stack<int, vector<int>> stk3;
	stk.push(10);
	stk.push(20);
	stk.pop();							// removes the top
	cout << stk.top() << endl;			// shows the top but does not remove it

	// Queue Container - First-in, First-out
	queue<int> q;						// uses the deque container by default
	queue<int, list<int>> q_list;		// uses the list container
	q.push(10);							// pushes element
	q.push(20);
	q.push(30);
	q.pop();							// removes the first element that was pushed
	cout << q.front() << " "
		<< q.back() << endl;			// shows the front/back without removing them

	// Priority Queue - insert elements with a priority - priority value goes at top
	priority_queue<int> pq;
	pq.push(10);
	pq.push(15);
	pq.push(5);
	pq.push(0);
	cout << pq.top() << endl;			// Shows the top of the priority (the largest element goes to the top)

	cout << endl;
	return 0;
}

/* SECTION CHALLENGE: DEQUE */
//bool is_palindrome_alternative(const std::string& s)    // Using iterators
//{
//    // You must implement this function.
//    // Since we are learning the STL - use a deque to solve the problem.
//    deque<char> d;
//    for (auto l : s) {
//        if (isalpha(l))
//            d.push_back(tolower(l));
//    }
//    auto r_it = d.rbegin();
//    auto it = d.begin();
//    for (int i = 0; i < d.size(); i++) {
//        if (*r_it != *it)
//            return false;
//        else {
//            it++;
//            r_it++;
//        }
//    }
//    return true;
//}
//
//bool is_palindrome(const std::string& s) {
//    deque<char> d;
//    for (auto l : s) {
//        if (isalpha(l))
//            d.push_back(tolower(l));
//    }
//    while (d.size() > 1) {
//        if (d.front() != d.back())
//            return false;
//        d.pop_front();
//        d.pop_back();
//    }
//    return true;
//
//}
//
//int main()
//{
//    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
//        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
//        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
//
//    std::cout << std::boolalpha;
//    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
//    for (const auto& s : test_strings) {
//        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
//    }
//    std::cout << std::endl;
//    return 0;
//}

/* SECTION CHALLENGE: LIST */
//class Song {
//    friend std::ostream& operator<<(std::ostream& os, const Song& s);
//    std::string name;
//    std::string artist;
//    int rating;
//public:
//    Song() = default;
//    Song(std::string name, std::string artist, int rating)
//        : name{ name }, artist{ artist }, rating{ rating } {}
//    std::string get_name() const {
//        return name;
//    }
//    std::string get_artist() const {
//        return artist;
//    }
//    int get_rating() const {
//        return rating;
//    }
//
//    bool operator<(const Song& rhs) const {
//        return this->name < rhs.name;
//    }
//
//    bool operator==(const Song& rhs) const {
//        return this->name == rhs.name;
//    }
//};
//
//std::ostream& operator<<(std::ostream& os, const Song& s) {
//    os << std::setw(20) << std::left << s.name
//        << std::setw(30) << std::left << s.artist
//        << std::setw(2) << std::left << s.rating;
//    return os;
//}
//
//void display_menu() {
//    std::cout << "\nF - Play First Song" << std::endl;
//    std::cout << "N - Play Next song" << std::endl;
//    std::cout << "P - Play Previous song" << std::endl;
//    std::cout << "A - Add and play a new Song at current location" << std::endl;
//    std::cout << "L - List the current playlist" << std::endl;
//    std::cout << "===============================================" << std::endl;
//    std::cout << "Enter a selection (Q to quit): ";
//}
//
//void play_current_song(const Song& song) {
//    // This function should display 
//    // Playing: followed by the song that is playing
//    std::cout << "\nPlaying......." << std::endl;
//    std::cout << song << std::endl;
//    std::cout << setw(52) << std::setfill('-') << " " << std::endl ;
//    // reset setfill
//    std::cout << std::setfill(' ') << " " << std::endl;
//}
//
//void display_playlist(const std::list<Song>& playlist, const Song& current_song) {
//    // This function should display the current playlist and then the current song playing
//    // Displaying the playlist
//    std::cout << std::endl;
//    std::cout << ":::: Your Playlist :::: " << std::endl;
//    for_each(playlist.begin(), playlist.end(), [](Song x) {cout << x << endl; });
//    
//    // Displaying the current song
//    std::cout << std::endl;
//    std::cout << "Currently Playing: " << std::endl;
//    std::cout << current_song << std::endl << std::endl;
//    
//}
//
//int main() {
//
//    std::list<Song> playlist{
//            {"God's Plan",        "Drake",                     5},
//            {"Never Be The Same", "Camila Cabello",            5},
//            {"Pray For Me",       "The Weekend and K. Lamar",  4},
//            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
//            {"Wait",              "Maroone 5",                 4},
//            {"Whatever It Takes", "Imagine Dragons",           3}
//    };
//
//    std::list<Song>::iterator current_song = playlist.begin();
//
//    char input;
//    bool player_on = true;
//    std::string new_song;
//    std::string new_artist;
//    int new_rating;
//
//    display_playlist(playlist, *current_song);
//
//    while (player_on) {
//        display_menu();
//        cin >> input;
//
//        // Quit option
//        if ((input == 'q') || (input == 'Q')) {
//            player_on = false;
//        }   // Play first song 
//        else if ((input == 'f') || (input == 'F')) {
//            current_song = playlist.begin();
//            play_current_song(*current_song);
//        }   // Move to the next song
//        else if ((input == 'n') || (input == 'N')) {
//            current_song++;
//            if (current_song == playlist.end())
//                current_song = playlist.begin();            // loop pointer to the beginning of playlist
//            play_current_song(*current_song);
//        }   // Move to the previous song
//        else if ((input == 'p') || (input == 'P')) {
//            if (current_song == playlist.begin())
//                current_song = playlist.end();              // loop pointer to the end of playlist
//            current_song--;
//            play_current_song(*current_song);
//        }   // Displaying playlist
//        else if ((input == 'l') || (input == 'L')) {
//            display_playlist(playlist, *current_song);
//        }   // Insert a song before the song it's currently playing
//        else if ((input == 'a') || (input == 'A')) {
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // ignores older items on the stream
//            std::cout << "\nAdding and Playing a new song!! " << std::endl;
//            std::cout << "Enter the name of the song: ";
//            std::getline(std::cin, new_song);
//            std::cout << "Enter the artist of the song: ";
//            std::getline(std::cin, new_artist);
//            std::cout << "Enter the rating (1 - 5): ";
//            std::cin >> new_rating;
//
//            playlist.emplace(current_song, new_song, new_artist, new_rating );
//            current_song--;
//            play_current_song(*current_song);
//        }
//    }
//
//    std::cout << std::endl;
//    std::cout << "Thanks for listening!" << std::endl;
//    return 0;
//}

/* SECTION CHALLENGE: SET & MAPS */
//// Used for Part1: Display the word and count from the std::map<std::string, int>
//void display_words(const std::map<std::string, int>& words) {
//    std::cout << std::setw(12) << std::left << "\nWord"
//        << std::setw(7) << std::right << "Count" << std::endl;
//    std::cout << "===================" << std::endl;
//    for (auto pair : words)
//        std::cout << std::setw(12) << std::left << pair.first
//        << std::setw(7) << std::right << pair.second << std::endl;
//}
//
//// Used for Part2: Display the word and occurences from the std::map<std::string, std::set<int>>
//void display_words(const std::map<std::string, std::set<int>>& words)
//{
//    std::cout << std::setw(12) << std::left << "\nWord"
//        << "Occurrences" << std::endl;
//    std::cout << "=====================================================================" << std::endl;
//    for (auto pair : words) {
//        std::cout << std::setw(12) << std::left << pair.first
//            << std::left << "[ ";
//        for (auto i : pair.second)
//            std::cout << i << " ";
//        std::cout << "]" << std::endl;
//    }
//}
//
//// This function removes periods, commas, semicolons and colon in a string and returns the clean version
//std::string clean_string(const std::string& s) {
//    std::string result;
//    for (char c : s) {
//        if (c == '.' || c == ',' || c == ';' || c == ':')
//            continue;
//        else
//            result += c;
//    }
//    return result;
//}
//
//// Part1 process the file and builds a map of words and the number of times they occur in the file
//void part1() {
//    std::map<std::string, int> words;
//    std::string line;
//    std::string word;
//    std::ifstream in_file{ "words.txt" };
//    if (in_file) {
//
//        while (getline(in_file,line)) {
//            // Adding the line to a stringstream for easier access
//            std::stringstream ss{ line };
//            while (ss >> word) {
//                word = clean_string(word);
//                words[word]++;
//            }
//        }
//
//        in_file.close();
//        display_words(words);
//    }
//    else {
//        std::cerr << "Error opening input file" << std::endl;
//    }
//}
//
//// Part2 process the file and builds a map of words and a set of line numbers in which the word appears
//void part2() {
//    std::map<std::string, std::set<int>> words;
//    std::string line;
//    std::string word;
//    std::ifstream in_file{ "words.txt" };
//    int line_number{ 1 };
//    if (in_file) {
//
//        while (getline(in_file, line)) {
//            // Adding the line to a stringstream for easier access
//            std::stringstream ss{ line };
//            while (ss >> word) {
//                word = clean_string(word);
//                words[word].insert(line_number);
//            }
//            line_number++;
//        }
//
//        in_file.close();
//        display_words(words);
//    }
//    else {
//        std::cerr << "Error opening input file" << std::endl;
//    }
//}
//
//int main() {
//    part1();
//    part2();
//
//    return 0;
//}

/* SECTION CHALLENGE: STACK & QUEUE */
//bool is_palindrome(const std::string& s) {
//    stack<char> stk_c;
//	queue<char> que_c;
//	// Adding each letter to the stack and queue
//    for (auto l : s) {
//		if (isalpha(l)) {
//			stk_c.push(toupper(l));
//			que_c.push(toupper(l));
//		}
//    }
//	// Loop through the containers and compare letters
//    while (!stk_c.empty()) {
//		if (stk_c.top() != que_c.front())
//			return false;
//        stk_c.pop();
//        que_c.pop();
//    }
//    return true;
//
//}
//
//int main()
//{
//    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
//        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
//        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
//
//    std::cout << std::boolalpha;
//    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
//    for (const auto& s : test_strings) {
//        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
//    }
//    std::cout << std::endl;
//    return 0;
//}