#include <iostream>
#include <iomanip> // pour setprecision()
	using namespace std;

	//problem analysis:
	//* what are the inputs,
	//* does the program require user interation
	//* does the program manipulates data
	//* what are the outputs

	//when creating a function always start by defining the prototype inputs and outputs.
	//* Each function should only do one thing.
	//* what are the inputs of the function (with types),
	//* what is the outputs of the function (return one value, several values, dosn't return a thing).
	//* does the function modify the inputs or not (passage par copie or par reference)?

	int main()
	{
		//pointers are sensitive to data types
		char stirngss[] = "silver";
		cout << stirngss << endl;	//print the content of the string and not the address of the first item (works only with type char)
		cout << &stirngss << endl;	//print the address of the firt elemt of the string that stirngss points to.
		cout << endl;
		
		char* ptrc = stirngss;
		cout << ptrc << endl; //prints the content as with stirngss
		cout << &ptrc << endl; //howver in here w print the address of the variable ptrc and not the address of the first item of the 'stirngss' 'array of char'

		ptrc++;
		*ptrc = 'L';
		cout << ptrc << endl;
		cout << *ptrc << endl;
		cout << &ptrc << endl;
		cout << stirngss << endl;

		int arr[] = { 1,2,3,4,5,6 };
		cout << arr << endl;	//print the address of the first item of the array 'arr' because the name 'arr' is a constant pointer to the first address 
		cout << &arr << endl;	//print as well the address of the first item of the array and not the address ofd the arr name 'speacial case when dealing with arrays'
		cout << endl;

		int* ptri = arr;		//the ptri variable (poniter) is as a reference to the arr (pointer) that points to the fisrt item of the array 'arr'
		cout << ptri << endl;	//print the address of the first item of the array
		cout << &ptri << endl;	//print the address of the variable ptri.
		return 0;
	}