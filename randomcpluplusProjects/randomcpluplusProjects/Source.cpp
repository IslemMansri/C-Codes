/*#include <iostream>
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

/*#include <iostream>
#include "matrices.h"
#include  "default.h"
using namespace std;

void setEnableTMVPFlag(int a, int b);

int main()
{
int TMVPmode = 0;
int const frameNumber = 300;
int pocCurr[frameNumber];

for (int i = 0; i < frameNumber; ++i)
{
pocCurr[i] = i;
}

printVector(pocCurr, frameNumber);

for (int i = 0; i < frameNumber; ++i)
{
if (TMVPmode == 2)
{
cout << "tastk1" << endl;
}
else if (TMVPmode == 1)
{
setEnableTMVPFlag(TMVPmode, 1);
}
else //Silx: here we are implementing the TIDR
{
int TIDR = 8;
if (pocCurr[i] % TIDR == 0)
{
setEnableTMVPFlag(TMVPmode, 1); //the default value is 1 'activate for all slices'
}
else
setEnableTMVPFlag(TMVPmode, 0);
}
}

//findIn8x8array(mat, 76);

system("pause");
return 0;
}

void setEnableTMVPFlag(int a, int b)
{
a = b;

}*/