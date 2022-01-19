/*#include <iostream>
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
}
*/

#include <iostream>
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
