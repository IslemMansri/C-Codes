/*Resources_and_Code_Snippets*/
/***************************/
//	https://pastebin.com/QYWkRRxD
//
/*	cin.ignore();
	cin.get();
	system("pause");
*/


/*Code Snippets*/
/******************/
//important for RPS works
/*#include <iostream>
#include <vector>
#include "matrices.h"
#include "default.h"
using namespace std;

#include <iostream>
using namespace std;

int main()
{
	const int frameNumber = 300;
	int stepSize_I = 32;
	int stepSize_TMVP = 4;

	cout << "StepSize I = " << stepSize_I << endl;
	for (int i = 0; i < frameNumber; ++i)
	{
		if ((i % stepSize_I) == 0)
		{
			cout << i << "\t";
		}
	}
	cout << endl;
	cout << endl;

	cout << "StepSize NoTMVP = " << stepSize_TMVP << endl;
	for (int i = 0; i < frameNumber; ++i)
	{
		if ((i % stepSize_TMVP) == 0)
		{
			cout << ++i << "\t";
		}
	}
	cout << endl;


	system("pause");
	return 0;
}
*/


////SAD of a frame final version:
/*
#include <iostream>
#include <vector>
#include "matrices.h"
#include "default.h"
using namespace std;

//vector<int> SADofVect(vector<int> vect1, vector<int>vect2);


//this program calculates the SAD8x8 for a frame of size 64x64 and print the values of the SAD to a Vector
int main()
{
	const int height = 32;
	const int width = 32;
	int frame1[height][width];
	int frame2[height][width];

	//generate random 64x64x arrays
	rand32x32Array(frame1);
	rand32x32Array(frame2);

	//temporal blocks block8x8_frame1 and block8x8_frame2
	vector<int>frame1Vector;
	vector<int>frame2Vector;


	///////////////////////////////////////////////////////
	//vector to store the SAD results
	vector<int>sumM;

	//loop through the number of blocks from (0 to height/8) and (from 0 to width/8)
	for (int block8x8Rowindex = 0; block8x8Rowindex < height; block8x8Rowindex += 8)
	{
		for (int block8x8Colindex = 0; block8x8Colindex < width; block8x8Colindex += 8)
			{
			//put the curretn 8x8 block in a temporal 8x8 block in order to use it to calculate the SAD
			for (int row = block8x8Rowindex; row < (block8x8Rowindex + 8); row++)
			{
			for (int column = block8x8Colindex; column < (block8x8Colindex + 8); column++)
				{
					frame1Vector.push_back(frame1[row][column]);
					frame2Vector.push_back(frame2[row][column]);
				}
			}
			}
	}
	//calulate the SAD of 8x8 block for whole frame in a form of vector and return the result as a vector
	sumM = SADofVect(frame1Vector, frame2Vector);
	////////////////////////////////////////////////////////////////



	//print the vector values
	for (size_t i = 0; i < sumM.size(); i++)
	{
		cout << sumM[i] << "\t";
	}
	cout << endl;

	system("pause");
	return 0;
}*/


//SAD of a frame first attemt:
/*
#include <iostream>
#include <vector>
#include "matrices.h"
#include "default.h"
using namespace std;



//this program calculates the SAD8x8 for a frame of size 64x64 and print the values of the SAD to a Vector
int main()
{
const int height = 32;
const int width = 32;
int frame1[height][width];
int frame2[height][width];

//generate random 64x64x arrays
rand32x32Array(frame1);
rand32x32Array(frame2);

//temporal blocks block8x8_frame1 and block8x8_frame2
int block8x8_frame1[8][8];
int block8x8_frame2[8][8];

//vector to store the SAD results
vector<int>SADResults;

//loop through the number of blocks from (0 to height/8) and (from 0 to width/8)
for (int block8x8Rowindex = 0; block8x8Rowindex < height; block8x8Rowindex += 8)
{
for (int block8x8Colindex = 0; block8x8Colindex < width; block8x8Colindex += 8)
{
//put the curretn 8x8 block in a temporal 8x8 block in order to use it to calculate the SAD
for (int row = block8x8Rowindex; row < (block8x8Rowindex + 8); row++)
{
for (int column = block8x8Colindex; column < (block8x8Colindex + 8); column++)
{
block8x8_frame1[row][column] = frame1[row][column];
block8x8_frame2[row][column] = frame2[row][column];
}
}
//calulate the SAD of 8x8 block
SADResults.push_back(SADof8x8array(block8x8_frame1, block8x8_frame2));
}
}
//print the vector values
for (size_t i = 0; i < SADResults.size(); ++i)
{
cout << SADResults[i] << "\t";
}
cout << endl;


system("pause");
return 0;
}*/

//poniters
/*#include <iostream>
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
	}*/


