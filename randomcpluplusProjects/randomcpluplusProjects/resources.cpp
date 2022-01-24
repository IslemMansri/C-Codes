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


/*
////SAD of a frame final version:
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


/*
//SAD of a frame first attemt:
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

//Islem_Mansri_23/01/2022
/*week3 coursera exo2*/
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
	// Réduire le format d'affichage
	std::cout << setprecision(4);

	// Paramètres
	double taux_croissance_lapins(0.3);
	double taux_attaque(0.01);
	double taux_croissance_renards(0.008);
	double taux_mortalite(0.1);
	int duree(50);

	double renards_i(0.0);
	double lapins_i(0.0);

	// ===== PARTIE 1 =====
	// Saisie des populations initiales

do
{
	std::cout << "Combien de renards au départ (>= 2) ? ";
	cin >> renards_i;
} while (renards_i < 2.0);

do
{
	std::cout << "Combien de lapins au départ  (>= 5) ? ";
	cin >> lapins_i;
} while (lapins_i < 5.0);

// ===== PARTIE 2 =====
// Première simulation
std::cout << endl << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;
double nb_lapins = lapins_i;
double nb_renards = renards_i;

double nb_lapin_previous = lapins_i;	//this variable is defined in order to be used to calculate nb_renard based on the previous value of nb_lapin
for (int i = 1; i <= duree; ++i)
{
	nb_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);
	if (nb_lapins < 0)
		nb_lapins = 0;

	nb_renards *= (1.0 + taux_attaque * nb_lapin_previous * taux_croissance_renards - taux_mortalite);
	if (nb_renards < 0)
		nb_renards = 0;

	nb_lapin_previous = nb_lapins; //this is so important in order to get the same values as in the example.
	std::cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
}



// ===== PARTIE 3 =====
// Variation du taux d'attaque
std::cout << endl;

//ask the use to enter le taux d'attaque initiale
do
{
	std::cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
	cin >> taux_attaque;
	taux_attaque /= 100;
} while (taux_attaque < (0.5 / 100) || taux_attaque >(6.0 / 100));

//ask the use to enter le taux d'attaque finale
double taux_attaque_final = 0.1;
do
{
	std::cout << "taux d'attaque à la fin  en % (entre " << taux_attaque * 100;
	std::cout << " et 6) ? ";
	cin >> taux_attaque_final;
	taux_attaque_final /= 100;
} while (taux_attaque_final < taux_attaque || taux_attaque_final >(6.0 / 100));
cout << endl;

for (double taux = taux_attaque; taux < taux_attaque_final; taux += 0.01)
{
	double nb_lapins = lapins_i;
	double nb_renards = renards_i;

	double nb_lapin_previous = lapins_i;	//this variable is defined in order to be used to calculate nb_renard based on the previous value of nb_lapin

	cout << "***** Le taux d’attaque vaut " << taux * 100 << "%" << endl;
	bool is_number_lapins_below_five = false;
	bool is_number_lapins_below_two = false;
	bool is_number_lapins_below_five_and_numberof_lapinsabove5 = false;

	bool is_number_ranards_below_five = false;
	bool is_number_renards_below_two = false;
	bool is_number_lapins_below_five_and_numberof_renardsabove5 = false;

	int j = 0;
	//debut de boucle for
	for (int i = 1; i <= duree; ++i)
	{
		j = i;
		nb_lapins *= (1.0 + taux_croissance_lapins - taux * nb_renards);
		if (nb_lapins < 0)
			nb_lapins = 0;

		if (nb_lapins < 5)
		{
			is_number_lapins_below_five = true;
		}
		if (is_number_lapins_below_five && nb_lapins > 5)
		{
			is_number_lapins_below_five_and_numberof_lapinsabove5 = true;
		}

		if (nb_lapins < 2)
		{
			nb_lapins = 0;
			is_number_lapins_below_two = true;
		}


		nb_renards *= (1.0 + taux * nb_lapin_previous * taux_croissance_renards - taux_mortalite);
		if (nb_renards < 0)
			nb_renards = 0;

		if (nb_renards < 5)
		{
			is_number_ranards_below_five = true;
		}

		if (is_number_ranards_below_five && nb_renards > 5)
		{
			is_number_lapins_below_five_and_numberof_renardsabove5 = true;
		}
		if (nb_renards < 2)
		{
			nb_renards = 0;
			is_number_renards_below_two = true;
		}

		if (((nb_lapins && nb_renards) == 0) && (is_number_renards_below_two) && (is_number_lapins_below_two))
		{
			break;
		}

		nb_lapin_previous = nb_lapins; //this is so important in order to get the same values as in the example.
	}//fin de boucle for

	std::cout << "Après " << j << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;

	//dispaly alert messages when low nomber five
	if (is_number_ranards_below_five == true)
	{
		std::cout << "Les renards ont été en voie d'extinction" << endl;
	}

	if (is_number_lapins_below_five_and_numberof_renardsabove5 == true)
	{
		std::cout << "mais la population est remontée ! Ouf !" << endl;
	}

	//display alert message pour les renards
	if (is_number_renards_below_two == true)
	{
		std::cout << "et les renards ont disparu :-(" << endl;
	}

	//dispaly alert messages when low nomber five
	if (is_number_lapins_below_five == true)
	{
		std::cout << "Les lapins ont été en voie d'extinction" << endl;
	}

	if (is_number_lapins_below_five_and_numberof_lapinsabove5 == true)
	{
		std::cout << "mais la population est remontée ! Ouf !" << endl;
	}

	//display alert message pour les lapins
	if (is_number_lapins_below_two == true)
	{
		std::cout << "et les lapins ont disparu :-(" << endl;
	}


	//display alert message
	if (!(is_number_lapins_below_five) && !(is_number_ranards_below_five) && !(is_number_lapins_below_two) && !(is_number_renards_below_two))
	{
		std::cout << "Les lapins et les renards ont des populations stables." << endl;
	}

	cout << endl;
}

std::system("pause");
return 0;
}*/