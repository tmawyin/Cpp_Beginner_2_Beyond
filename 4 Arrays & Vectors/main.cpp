/* Arrays and Vectors
* Array are fixed in size (can't grow or shrink) and all of the same type (all int/double/char)
* Array elements are indexed and start at 0
* 
* Vectors are dynamic arrays that can change size
*/

#include <iostream>
#include <vector>

using namespace std;

/* COURSE MATERIAL
int main() {

	// Arrays ------
	int scores[5]{ 100,90,85,99,97 };
	cout << "The first score is: " << scores[0] << endl;
	scores[2] = 98;
	cout << "The third score was changed to: " << scores[2] << endl;

	const int days_in_year{ 365 };
	double temperature[days_in_year]{ 0 }; //initializes all elements to 0

	// Multidimensional Arrays -----
	int movie_ratings[3][4]{
		{0,4,3,5},{0,0,4,4},{1,3,5,2}
	};
	cout << "The second reviewer's score for last movie is: " << movie_ratings[1][3] << endl;

	// Vectors ------
	vector <int> test_scores(10);	//creates a vector of size 10
	vector <double> temp{ 15, 20, 18, 17 }; //creates a vector of size 4 that's initialized
	vector <double> distances(15, 5); //creates a vector of size 15 and initializes everything to 5

	test_scores[5] = 100;	//changing the 6th element to 100
	test_scores.at(0) = 90; //another way to access/modify elements

	test_scores.push_back(85); //adds a new element at the end of the vector
	test_scores.size();		//shows the size of the vector

	return 0;
}
*/

/* SECTION CHALLENGE */
int main() {

	//Declare 2 vectors of integers
	vector <int> vector1;
	vector <int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	cout << "1st Element: " << vector1.at(0) << endl;
	cout << "2nd Element: " << vector1.at(1) << endl;
	cout << "Vector 1 size: " << vector1.size() << endl;

	vector2.push_back(100);
	vector2.push_back(200);

	cout << "1st Element: " << vector2.at(0) << endl;
	cout << "2nd Element: " << vector2.at(1) << endl;
	cout << "Vector 2 size: " << vector2.size() << endl;

	vector <vector <int>> vector_2d;
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	vector1.at(0) = 1000;	//changing vector1 elements do not change 2D vector

	cout << "2D Vector (0,0) Element: " << vector_2d.at(0).at(0) << endl;
	cout << "2D Vector (0,1) Element: " << vector_2d.at(0).at(1) << endl;
	cout << "2D Vector (1,0) Element: " << vector_2d.at(1).at(0) << endl;
	cout << "2D Vector (1,1) Element: " << vector_2d.at(1).at(1) << endl;

	return 0;
}