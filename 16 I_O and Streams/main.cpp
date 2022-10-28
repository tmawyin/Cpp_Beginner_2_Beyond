/* I/O and Streams 
*/

#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

/* COURSE MATERIAL */
int main()
{
	// ----- I/O Manipulators -----
	// 1. Booleans - by default booleans display as 1 or 0
	cout << noboolalpha;		// Sets boolean type to 1/0... Alternatively, use: cout.setf(std::ios::noboolalpha);
	cout << boolalpha;			// Sets boolean type to True/False strings. Alternatively use: cout.setf(std::ios::boolalpha);
	cout << (10 == 10) << endl;
	cout << (10 == 20) << endl;

	// 2. Integers - by default integers are displayed in base 10 (optionally base 8/16 are available)
	int num{ 255 };
	cout << showbase << uppercase;		// shows the type of base system used AND in uppercase
	cout << showpos;					// shows the + sign when used
	cout << std::hex << num << endl;	// hexadecimal: starts with 0x
	cout << std::oct << num << endl;	// octal : starts with 0
	cout << std::dec << num << endl;	// default - decimal
	cout << noshowpos;					// removing + sign 
	
	// 3. Floating Point - default precision is 6 digits with no trailing zeros
	double val{ 12341234.567856789 };
	cout << val << endl;			// Displayes 6 digits rounding the ending: 1234.57
	cout << setprecision(10);		// Precision to 10 digits
	cout << fixed;					// Displayes precision for decimals (adds trailing zeros)
	cout << scientific;				// Uses scientific notation
	cout << val << endl;
	cout << resetiosflags(ios::floatfield);		// Resets configuration for floating points

	// Align & Fill
	double n{ 1234.5678 };
	string h{ "Hello" };
	cout << setw(10);					// Sets width to 10 (right justified for first item on stream only)
	cout << n << endl;
	cout << setw(10) << left;			// Sets the next item on stream as Left justified (right justified is default)
	cout << h << endl;
	cout << right << setfill('-');		// Fills out space with given character
	cout << setw(15) << h << endl;

	cout << "==========================" << endl << endl;

	// ----- File Manipulation -----
	// Use #include <fstream> and the std::ifstream class to handle files. Always close the file when done!
	
	// Reading single words to variables 
	int number;
	double total;
	string line;
	std::ifstream in_file;			// Creates an object to work with files
	in_file.open("test1.txt");		// Opens file 'test.txt' 
	
	if (!in_file) {					// Testing if file opened correctly
		std::cerr << "File could not be open or doesn't exist" << endl;
		return 1;
	}
	cout << "File was open successfully" << endl;

	in_file >> line;				// Reads first word until blank space or char return is found
	cout << line << endl;
	
	in_file >> number >> total;		// Reads the next two words
	cout << number << endl << total << endl;

	in_file.close();				// Closing the file 
	cout << endl;

	// Using Loop to read variables
	ifstream next_file;
	next_file.open("test2.txt");
	
	cout << setfill(' ');
	while (!next_file.eof()) {		// Looping until we reach file's end of line
		next_file >> line >> number >> total;
		cout << setw(10) << left << line
			<< setw(10) << number
			<< setw(10) << total << endl;
	}
	next_file.close();
	cout << endl;

	// Reading entire lines of text
	ifstream poem_file;
	poem_file.open("poem.txt");
	if (!poem_file) {
		cerr << "Can't open file" << endl;
		return 1;
	}

	cout << "--Shakespeare Poem--" << endl;
	while (getline(poem_file, line)) {		// Use getline( file, variable)... Alternative: use get(character) to read each character at a time
		cout << line << endl;
	}
	
	cout << "==========================" << endl << endl;
	
	// Writing text files - Use ofstream object
	cout << "Writint to Files" << endl << endl;

	//ofstream out_file {"output.txt", ios::trunc};		// Creates the out stream object. Use ios::app to open in "append" mode, ios::truc is default
	//if (!out_file) {
	//	cerr << "Error creating file" << endl;
	//	return 1;
	//}
	//cout << "File created successfully" << endl<< endl;
	//string out_line;
	//cout << "Enter something to go to the file: ";
	//getline(cin, out_line);							// Gets the line from std output

	//out_file << out_line << endl;					// Writing to file
	//
	//out_file.close();
	cout << endl;

	cout << "==========================" << endl << endl;
	
	// Using String Streams - Use #include <sstream>
	int s_num{};
	double s_val{};
	string name{};
	string info{ "Moe 100 123.45" };

	istringstream iss{ info };						// Treats the string as a normal stream. Use "ostringstream" to write to string
	iss >> name >> s_num >> s_val;
	cout << name << " " << s_num << " " << s_val << endl<<endl;
	
	// Data validation example
	int value;
	string from_screen;
	
	cout << "Please enter your data: ";
	cin >> from_screen;
	istringstream validator{ from_screen};
	if (validator >> value)
		cout << "We found an integer" << endl;
	else
		cout << "No integer was found" << endl;

	//removing everything else from buffer if needed
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;
	return 0;
}

/* SECTION CHALLENGE #1: Format Text to Screen */
//struct City {
//    std::string name;
//    long population;
//    double cost;
//};
//
//// Assume each country has at least 1 city
//struct Country {
//    std::string name;
//    std::vector<City> cities;
//};
//
//struct Tours {
//    std::string title;
//    std::vector<Country> countries;
//};
//
//int main()
//{
//    Tours tours
//    { "Tour Ticket Prices from Miami",
//        {
//            {
//                "Colombia", {
//                    { "Bogota", 8778000, 400.98 },
//                    { "Cali", 2401000, 424.12 },
//                    { "Medellin", 2464000, 350.98 },
//                    { "Cartagena", 972000, 345.34 }
//                },
//            },
//            {
//                "Brazil", {
//                    { "Rio De Janiero", 13500000, 567.45 },
//                    { "Sao Paulo", 11310000, 975.45 },
//                    { "Salvador", 18234000, 855.99 }
//                },
//            },
//            {
//                "Chile", {
//                    { "Valdivia", 260000, 569.12 },
//                    { "Santiago", 7040000, 520.00 }
//            },
//        },
//            { "Argentina", {
//                { "Buenos Aires", 3010000, 723.77 }
//            }
//        },
//    }
//    };
//
//    const int total_width{ 70 };
//    const int field1_width{ 20 };    // Country name
//    const int field2_width{ 20 };    // City name
//    const int field3_width{ 15 };    // Population
//    const int field4_width{ 9 };    // Cost
//
//    // Display the Report title header centered in width of total_width
//    // You could make this a function for practice
//    int title_length = tours.title.length();
//    std::cout << std::setw((total_width - title_length) / 2) << "" << tours.title << std::endl;
//    std::cout << std::endl;
//    std::cout << std::setw(field1_width) << std::left << "Country"
//        << std::setw(field2_width) << std::left << "City"
//        << std::setw(field3_width) << std::right << "Population"
//        << std::setw(field4_width) << std::right << "Price"
//        << std::endl;
//
//    std::cout << std::setw(total_width)
//        << std::setfill('-')
//        << ""
//        << std::endl;   // display total_width dashes
//
//    std::cout << std::setfill(' '); // reset setfill to blank spaces
//    std::cout << std::setprecision(2) << std::fixed;                // for displaying the cost with 2 decimal digits
//
//    // Note the use of the conditional operator to display the country name or "" for the first country
//
//    for (Country country : tours.countries) {
//        for (size_t i = 0; i < country.cities.size(); ++i) {
//            std::cout << std::setw(field1_width) << std::left << ((i == 0) ? country.name : "") // conditional operator
//                << std::setw(field2_width) << std::left << country.cities.at(i).name
//                << std::setw(field3_width) << std::right << country.cities.at(i).population
//                << std::setw(field4_width) << "$" << std::right << country.cities.at(i).cost
//                << std::endl;
//        }
//    }
//
//    std::cout << std::endl << std::endl;
//    return 0;
//}

/* SECTION CHALLENGE #2: Read file - Automatic Grader */
//int check_score(const string answer, const string response) {
//	int score{ 0 };
//	for (int i = 0; i < answer.length(); i++) {
//		if (response[i] == answer[i])
//			score += 1;
//	}
//	return score;
//}
//int main() {
//	// Open the file
//	ifstream in_file;
//	in_file.open("responses.txt");
//
//	// Check if file opened correctly;
//	if (!in_file) {
//		cerr << "Error opening file" << endl;
//		return 1;
//	}
//
//	// Setting up variables
//	string answer_key;
//	string student_name;
//	string student_response;
//	int score{ 0 };
//	int total_score{ 0 };
//	int num_students{ 0 };
//
//	// Get answer key first
//	in_file >> answer_key;
//
//	// Write to screen
//	cout << setw(10) << left << "Students"
//		<< setw(10) << right << "Score" << endl;
//	cout << setw(20) << setfill('-') << "" << endl;
//	cout << setfill(' ');
//
//	// Loop through the students
//	while (in_file >> student_name >> student_response) {
//		// Check for student score & average
//		score = check_score(answer_key, student_response);
//		total_score += score;
//		
//		// Formating output
//		cout << setw(10) << left << student_name
//			<< setw(8) << right << score << endl;
//		
//		// Counting number of students
//		num_students++;
//	}
//	
//	cout << setw(20) << setfill('-') << "" << endl;
//	cout << setw(15) << left << setfill(' ') << "Average score";
//	cout << setw(4) << setprecision(2) << right << (1.0*total_score) / num_students << endl;
//
//	// Closing the file
//	in_file.close();
//
//	cout << endl;
//	return 0;
//}

/* SECTION CHALLENGE #3: Read file - Count number of time a word appears*/
//int main() {
//	// Open the file
//	ifstream in_file;
//	in_file.open("romeoandjuliet.txt");
//	
//	// Check if file opened correctly;
//	if (!in_file) {
//		cerr << "Error opening file" << endl;
//		return 1;
//	}
//
//	// Ask the user for a word
//	int word_count{ 0 };
//	string text_word;
//	string word_to_search;
//	cout << "Please enter a word to search: ";
//	cin >> word_to_search;
//
//	// Finding the word
//	while (in_file >> text_word) {
//		if (text_word.find(word_to_search) != string::npos)
//			word_count += 1;
//	}
//	cout << "The substring " << word_to_search << " was found " << word_count << " times" << endl;
//
//	in_file.close();
//
//	cout << endl;
//	return 0;
//}

/* SECTION CHALLENGE #4: Write file - Add line numbers to a document */
//int main() {
//
//	// Opening file
//	ifstream in_file{ "romeoandjuliet.txt" };
//	if(!in_file){
//		cerr << "Can't open file!" << endl;
//		return 1;
//	}
//
//	// Creating output file
//	ofstream out_file{ "romeoandjuliet_lines.txt" };
//	if (!out_file) {
//		cerr << "Can't create output file!" << endl;
//		return 2;
//	}
//
//	// Looping through the file and creating a copy
//	int counter{ 1 };		// Need a counter to keep track of the line
//	string in_line;
//
//	while (getline(in_file, in_line)) {
//		if (in_line.size() > 0) {
//			out_file << counter << "\t" << in_line << endl;
//			counter++;
//		}
//		else {
//			out_file << in_line << endl;
//		}
//	}
//
//	cout << "Copy Completed!" << endl;
//	out_file.close();
//	in_file.close();
//
//	return 0;
//}