/* Pointers and References 
*  Pointers hold addresses to a variable of a specific type
*  Pointers and Arrays behave the same way
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//* COURSE MATERIAL */
//void double_value(int* int_ptr) {
//	*int_ptr *= 2;	//dereferencing pointer and doubling the value
//}
//
//int* largest_num(int* val_1, int* val_2) {
//	if (*val_1 >= *val_2)
//		return val_1;
//	else
//		return val_2;
//}
//
//int* create_array(size_t size, int init_value = 0) {
//	int* new_storage{ nullptr };
//	new_storage = new int[size];
//	for (size_t i = 0; i < size; i++)
//		*(new_storage + i) = init_value;
//	return new_storage;
//}
//
//int main() {
//	
//	//pointer declaration and initialization
//	int value{ 0 };
//	int* value_ptr{ nullptr };
//	value_ptr = &value;	//assign the address of the variable to a pointer
//	cout << "The value of pointer is: " << value_ptr << endl;
//	
//	//dereferencing: access the data where the pointer is pointing to - using "*"
//	value = 10;
//	cout << "What is pointing to: " << * value_ptr << endl;
//	
//	//changing the value using the pointer dereferencing
//	*value_ptr = 20;
//	cout << "The new value is: " << *value_ptr << endl;
//
//	//Pointers and Vectors -------
//	cout << endl;
//	vector <string> stooges{ "larry","moe","curly" };
//	vector<string>* vector_prt{ &stooges };
//
//	cout << "First stooge: " << (*vector_prt).at(0) << endl;
//	
//	//looping through vector pointer
//	for (auto stooge : *vector_prt)
//		cout << stooge << " ";
//	cout << endl << endl;
//
//	//====== Dynamic Memory Allocation =====
//	//use the keyword "new"
//	int* int_prt{ nullptr };
//	int_prt = new int;
//
//	double* double_ptr{ nullptr };
//	double_ptr = new double[5];	//creates a pointer to an array of doubles
//
//	delete int_prt;	//frees allocated memory
//	delete[] double_ptr;
//
//	//====== Pointers, Arrays, and Arithmetic =====
//	// You can add/substract numbers to a pointer to increase/decrease the address they point to
//	// You can compare pointers using "==" operators
//	int scores[]{ 100,90,95,-1 };
//	int* score_ptr{ scores };
//	cout << "First element: " << score_ptr[0] << endl;
//	cout << "Second element: " << *(score_ptr + 1) << endl;	//using dereferencing
//	cout << "Third element: " << *(scores + 2) << endl; //using the array name
//
//	while (*score_ptr != -1) {
//		cout << *score_ptr++ << endl;	// Use ++ to increase the address of the pointer
//	}
//	cout << endl;
//
//	//===== Pointers and "const" ====
//	const int* ptr1{ nullptr };	//Pointer to a const integer, can't change the variable value but we can point to any int
//	int* const ptr2{ nullptr };	//Pointer itself can't be changed, the dereferencing can change
//	const int* const ptr3{ nullptr };	//Nor the pointer or the value can change in this case
//
//	//===== Pointers and Functions =====
//	int data{ 10 };
//	int* data_ptr{ &data };
//	cout << "Value before: " << *data_ptr << endl;
//	double_value(&data);	//pass by reference 
//	double_value(data_ptr);	//pass the pointer
//	cout << "Value after: " << *data_ptr << endl << endl;
//	
//	int a{ 100 }, b{ 200 };
//	int* largest{ largest_num(&a,&b) };	//function returns a pointer (an adress to the largest integer)
//	cout << "Largest value is: " << *largest << endl;
//	cout << endl;
//	
//	//Returning dynamically allocated memory
//	int* new_array = create_array(5);
//	cout << "First element of new array: " << new_array[4] << endl;
//	delete[] new_array;
//
//	//===== References =====
//	//Using references with the symbol "&". References are more efficient since you don't need to make a copy of the variable
//	int num{ 100 };
//	int& ref{ num }; //reference to num
//
//	cout << "Reference value: " << ref << endl;
//	num = 200; //changing variable value
//	cout << "Reference value after change: " << ref << endl;
//
//	cout << endl;
//	return 0;
//}

/* SECTION CHALLENGE */
void print(const int* const array, size_t size){
	cout << "[ ";
	for (size_t i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << "]" << endl;
}

int* apply_all(const int* const array1, size_t size1, const int* const array2, size_t size2) {
	int* new_array{ nullptr };
	new_array = new int[size1 * size2];

	//generating new array of multiplied values
	int k = 0;
	for (size_t j = 0; j < size2; j++) {
		for (size_t i = 0; i < size1; i++) {
			new_array[k] = array2[j] * array1[i];
			k++;
		}
	}

	return new_array;
}

int main() {
	const size_t array1_size{ 5 };
	const size_t array2_size{ 3 };

	int array1[]{ 1,2,3,4,5 };
	int array2[]{ 10,20,30 };

	cout << "Array 1: ";
	print(array1, array1_size);

	cout << "Array 2: ";
	print(array2, array2_size);

	int* results = apply_all(array1, array1_size, array2, array2_size);
	constexpr size_t results_size{ array1_size * array2_size };

	cout << "Result: ";
	print(results, results_size);
	
	delete[] results;
	cout << endl;

	return 0;
}