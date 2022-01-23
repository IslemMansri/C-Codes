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
	// Réduire le format d'affichage
	cout << setprecision(4);

	// Paramètres
	double taux_croissance_lapins(0.3);
	double taux_attaque(0.01);
	double taux_croissance_renards(0.008);
	double taux_mortalite(0.1);
	int duree(50);

	double renards_i(0.0);
	double lapins_i(0.0);

	/*****************************************************
	* Compléter le code à partir d'ici
	*****************************************************/

	// ===== PARTIE 1 =====
	// Saisie des populations initiales

	do
	{
		cout << "Combien de renards au départ (>= 2) ? ";
		cin >> renards_i;
	} while (renards_i < 2.0);

	do
	{
	cout << "Combien de lapins au départ  (>= 5) ? ";
	cin >> lapins_i;
	} while (lapins_i < 5.0);

	// ===== PARTIE 2 =====
	// Première simulation
	cout << endl << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;
	double nb_lapins = lapins_i;
	double nb_renards = renards_i;

	for (int i = 1; i <= duree; ++i)
	{
		nb_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);
		if (nb_lapins < 0)
			nb_lapins = 0;

		nb_renards *= (1.0 + taux_attaque * lapins_i * taux_croissance_renards - taux_mortalite);
		if (nb_renards < 0)
			nb_renards = 0;

		lapins_i = nb_lapins; //this is so important in order to get the same values as in the example.
		cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
	}

	

	// ===== PARTIE 3 =====
	// Variation du taux d'attaque
	cout << endl;

	cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";

	cout << "taux d'attaque à la fin  en % (entre ";
	cout << " et 6) ? ";

	cout << "Les renards ont été en voie d'extinction" << endl;
	cout << "mais la population est remontée ! Ouf !" << endl;
	cout << "et les renards ont disparu :-(" << endl;
	cout << "Les lapins ont été en voie d'extinction" << endl;
	cout << "mais la population est remontée ! Ouf !" << endl;
	cout << "et les lapins ont disparu :-(" << endl;
	cout << "Les lapins et les renards ont des populations stables." << endl;

	/*******************************************
	* Ne rien modifier après cette ligne.
	*******************************************/


	system("pause");
	return 0;
}