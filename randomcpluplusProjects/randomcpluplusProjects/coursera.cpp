//Islem_Mansri_23/01/2022
/*week3 coursera exo2*/
#include "coursera.h"


void LotkaVolterra_model()
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
}