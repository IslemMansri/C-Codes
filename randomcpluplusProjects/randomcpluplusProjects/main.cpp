#include <iostream>
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

int separer_chiffre_gauche(int& nombre)
{
	int dix(1);
	int temp(nombre);
	while (temp >= 10) {
		dix *= 10;
		temp /= 10;
	}
	nombre %= dix;
	return temp;
}

/*****************************************************
* Compléter le code à partir d'ici
*****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
}

int lire_et_dire(int nombre)
{
	return 0;
}

/*******************************************
* Ne rien modifier après cette ligne.
*******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
	while (fois-- > 0) {
		nombre = lire_et_dire(nombre);
	}
}

int main()
{
	int nombre(1);
	int fois(1);
	cin >> nombre >> fois;
	repeter_lire_et_dire(nombre, fois);
	cout << nombre << endl;
	system("pause");
	return 0;
}