#pragma once
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

//note: matrix = array = table/ 
//A vector is a 1D matrix

//generate a random vector or random list from 0 to 255
void randVect(int mat[], int listSize);

//init a vector (1D matrix) with a value added by the user
void initVec(int vec[], int value, int size);

//print a vector
void printVector(int vec[], int size);

//calculate the SAD between two vectors
vector<int>SADofVect(vector<int> vect1, vector<int>vect2);

//generate a NxM array with random values
//note that you have to add the following line at the start of main
//srand(unsigned(time(NULL)));
//in order to allways start from different random values
void rand8x8Array(int mat[][8], int rows = 8);

//generate random values for matrix of size 32x32
void rand32x32Array(int mat[][32], int rows = 32);

//function to print the values of a matrix of size 32x32
void print32x32Array(int arr[][32], int rows = 32);

//function to init matrix of size 8x8 with a value added by the user
void init8x8Array(int arr[][8], int value, int size = 8);

//print the value of matrix of size 8x8
void print8x8Array(int arr[][8], int columns = 8);

//calculate the sum of all items of a matrix of size 8x8
int sumOf8x8Array(const int arr[][8], int rows = 8);

//calculate the difference between two 8x8 arrays
void diffOf8x8Array(const int arr1[][8], const int arr2[][8], int arrDiff[][8], int rows = 8);

//calculate the abs of 8x8 array
void AbsOf8x8Array(const int arr[][8], int absArr[][8], int rows = 8);

//Calulate the SAD (Sum of absolute diferrence) between two 8x8 arrays
int SADof8x8array(int arrA[][8], int arrB[][8], int rows = 8);

//search for item within a list (vector, 1D array)
struct returnV {
public:
	int indexVec;
	int indexArrayN;
	int indexArrayM;
	bool searchResult;
};

returnV findInVect(const int list[], int v, int Lsize);

//search for item within a matrix
returnV findIn8x8Array(const int array[][8], int value, int rows = 8);

//find the Minimum value in a vector
int minVect(const int list[], int sizet);

//find the Maximum value in a vector
int maxVect(const int list[], int sizet);

//find the Minimum value within an array
int min_8x8Array(const int arr[][8], int rows = 8);

//find the Maximum value within an array
int max_8x8Array(const int arr[][8], int rows = 8);