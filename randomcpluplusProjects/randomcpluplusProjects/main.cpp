#include <iostream>
#include "coursera.h"

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
	cout << "Hello World!" << endl;
	LotkaVolterra_model();
	std::system("pause");
	return 0;
}