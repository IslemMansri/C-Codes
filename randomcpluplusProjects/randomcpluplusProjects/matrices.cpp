#include "matrices.h"

//generate a random vector or random list from 0 to 255
void randVect(int vect[], int listSize)
{
	for (int i = 0; i < listSize; ++i)
	{
		vect[i] = 0 + rand() % 255;
	}
}

//init vector with value added by the user
void initVec(int vec[], int value, int size)
{
	for (int i = 0; i < size; ++i)
	{
		vec[i] = value;
	}
}

//print the values of a vector
void printVector(int vec[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << vec[i] << " ";

	}
	cout << "\n";
}

//search for item within a list (vector, 1D array) and return the index as well as the result in a stucture
returnV findInVect(const int list[], int v, int ListSize)
{
	returnV RetrunedValue;
	for (int i = 0; i < ListSize; ++i)
	{
		if (list[i] == v)
		{
			RetrunedValue.searchResult = true;
			RetrunedValue.indexVec = i;
			break;
		}
		else
		{
			RetrunedValue.searchResult = false;
		}
	}

	if (RetrunedValue.searchResult)
		cout << "The value " << v << " exists within the table in the position \"" << RetrunedValue.indexVec << "\" |\"start counting from 0 \"|" << "\n";
	else
		cout << "The value " << v << " doesn't exists within the table" << "\n";
	return RetrunedValue;

}

//find the Minimum value in a vector
int minVect(const int list[], int sizet)
{
	int minv;
	minv = list[0];
	for (int i = 0; i < sizet; ++i)
	{
		if (minv <= list[i])
			minv = minv;
		else
			minv = list[i];
	}
	return minv;
}

//find the Maximum value in a vector
int maxVect(const int list[], int sizet)
{
	int maxv;
	maxv = list[0];
	for (int i = 0; i < sizet; ++i)
	{
		if (maxv >= list[i])
			maxv = maxv;
		else
			maxv = list[i];
	}
	return maxv;
}

//generate a NxM array with random values from 0 to 255:
//note that you have to add the following line at the start of main
//srand(unsigned(time(NULL)));
//in order to allways start from different random values
void rand8x8Array(int mat[][8], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			mat[i][j] = 0 + rand() % 255;
		}

	}
}


vector<int> SADofVect(vector<int> vect1, vector<int>vect2)
{
	//calculating the SAD for a vector of size 1024
	vector<int>abdDiff;
	vector<int>sumM;

	for (size_t i = 0; i < vect1.size(); ++i)
	{
		abdDiff.push_back(abs(vect1[i] - vect2[i]));

	}
	for (int j = 0; j < vect1.size(); j += 64)
	{
		int sum = 0;
		for (int k = j; k < j + 64; k++)
		{
			sum = sum + abdDiff[k];
		}
		sumM.push_back(sum);
	}
	return sumM;
}

//generate random values for matrix od size HD frame 640x360
void rand32x32Array(int mat[][32], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			mat[i][j] = 0 + rand() % 255;
		}
	}
}

//function to print the values of a matrix of size 640x360
void print32x32Array(int arr[][32], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

}

//function to init matrix of size 8x8 with value added by the user
void init8x8Array(int arr[][8], int value, int rows) {
	for (int row = 0; row < rows; ++row)
	{
		for (int column = 0; column < 8; ++column)
		{
			arr[row][column] = value;
		}
	}

}

//function to print the values of a matrix of size 8x8
void print8x8Array(int arr[][8], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

}

//calculate the difference between two 8x8 arrays
void diffOf8x8Array(const int arr1[][8], const int arr2[][8], int arrDiff[][8], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			arrDiff[i][j] = arr1[i][j] - arr2[i][j];
		}
	}
}

//calculat the absolute of 8x8 arrays
void AbsOf8x8Array(const int arr[][8], int absArr[][8], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; j++)
		{
			absArr[i][j] = abs(arr[i][j]);
		}
	}

}

//function to calculate the sum of all items of a matrix of size 8x8
int sumOf8x8Array(const int arr[][8], int rows)
{
	int sum = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int column = 0; column < 8; ++column)
		{
			sum += arr[row][column];
		}
	}
	return sum;
}

//Calulate the SAD (Sum of absolute diferrence) between two 8x8 arrays
int SADof8x8array(int arrA[][8], int arrB[][8], int rows)
{
	int arrSAD[8][8];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			diffOf8x8Array(arrA, arrB, arrSAD);
			AbsOf8x8Array(arrSAD, arrSAD);
			return sumOf8x8Array(arrSAD);
		}
	}
}

//search for item within a matrix of size 8x8
returnV findIn8x8Array(const int array[][8], int value, int rows)
{
	returnV RetrunedValue;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (array[i][j] == value)
			{
				RetrunedValue.searchResult = true;
				RetrunedValue.indexArrayN = i;
				RetrunedValue.indexArrayM = j;
				break;
			}
			else
			{
				RetrunedValue.searchResult = false;
			}

		}
	}

	if (RetrunedValue.searchResult)
		cout << "The value \"" << value << "\" exists within the table in the [row \"" << RetrunedValue.indexArrayN << "\", column \"" << RetrunedValue.indexArrayM << "\"] |\"start counting from 0 \"|" << "\n";
	else
		cout << "The value \"" << value << "\" doesn't exists within the table" << "\n";
	return RetrunedValue;

}

//find the Minimum value within an array
int min_8x8Array(const int arr[][8], int rows)
{
	int minv;
	minv = arr[0][0];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (minv <= arr[i][j])
				minv = minv;
			else
				minv = arr[i][j];
		}
	}
	return minv;
}

//find the Maximum value within an array
int max_8x8Array(const int arr[][8], int rows)
{
	int maxv;
	maxv = arr[0][0];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (maxv >= arr[i][j])
				maxv = maxv;
			else
				maxv = arr[i][j];
		}
	}
	return maxv;
}