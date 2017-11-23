
#include "stdafx.h"

#include "Header.h"
#include <random>

float p = 0.6;
float q = 0.4;


void initialiserFile(T_file &uneFile)
{
	uneFile.D = 0;
	uneFile.F = 0;
}

void deposer(T_file &uneFile, T_piece &unePiece)
{
	uneFile.liste[uneFile.D] = unePiece;
	uneFile.D = (uneFile.D + 1) % 5000;
}

void retirer(T_file &uneFile, T_piece &unePiece)
{
	unePiece = uneFile.liste[uneFile.F];
	uneFile.F = (uneFile.F + 1) % 5000;
}

int estVide(T_file uneFile)
{
	return (uneFile.D == uneFile.F);
}
int estPleine(T_file uneFile)
{
	return ((uneFile.D + 1) % 5000 == uneFile.F);
}



void initialiserMachine(T_machine &uneMachine, int Duree_Traitement)
{
	uneMachine.etat = 0;
	uneMachine.Date_Prochain_Evenement = 9999;
	uneMachine.Duree_Traitement = Duree_Traitement;
}

void deposerPieceSurMachine(T_machine &uneMachine, T_piece unePiece)
{
	uneMachine.contenu = unePiece;
	uneMachine.etat = 1;
}

void retirerPieceMachine(T_machine &uneMachine, T_piece &unePiece)
{
	unePiece = uneMachine.contenu;
	uneMachine.etat = 0;
}

void gererMachineA(T_machine &uneMachineA, T_machine &uneMachineB, T_machine &uneMachineC, T_file &uneFileA, T_file &uneFileB, T_file &uneFileC, int &Date_Simul)
{
	T_piece unePiece;
	unePiece = uneMachineA.contenu;
	float x = (rand() + 0.0) / (float)RAND_MAX;
	if (x < q)
	{
		if (uneMachineB.etat)
		{
			deposerPieceSurMachine(uneMachineB, unePiece);
			uneMachineB.Date_Prochain_Evenement = Date_Simul + uneMachineB.Duree_Traitement;
		}
		else
		{
			deposer(uneFileB, unePiece);
		}
	}
	else
	{
		if (uneMachineC.etat)
		{
			deposerPieceSurMachine(uneMachineC, unePiece);
			uneMachineC.Date_Prochain_Evenement = Date_Simul + uneMachineC.Duree_Traitement;
		}
		else
		{
			deposer(uneFileC, unePiece);
		}
	}
	if (!estVide(uneFileA))
	{
		retirer(uneFileA, unePiece);
		uneMachineA.contenu = unePiece;
		uneMachineA.etat = 1;
		uneMachineA.Date_Prochain_Evenement = Date_Simul + uneMachineA.Duree_Traitement;
	}
	else
	{
		uneMachineA.etat = 0;
		uneMachineA.Date_Prochain_Evenement = 9999;
	}
}


void gererMachineBC(T_machine &uneMachineBC, T_machine &uneMachineA, T_file &uneFileBC, T_file &uneFileA, T_puits &unPuits, int &Date_Simul)
{
	T_piece unePiece;
	unePiece = uneMachineBC.contenu;
	float x = (rand() + 0.0) / (float)RAND_MAX;
	if (x < p)
	{
		deposerDansPuits(unPuits, unePiece, Date_Simul);
	}
	else
	{
		if (uneMachineA.etat)
		{
			deposerPieceSurMachine(uneMachineA, unePiece);
			uneMachineA.Date_Prochain_Evenement = Date_Simul + uneMachineA.Duree_Traitement;
		}
		else
		{
			deposer(uneFileA, unePiece);
		}
	}
	if (!estVide(uneFileBC))
	{
		retirer(uneFileBC, unePiece);
		uneMachineBC.contenu = unePiece;
		uneMachineBC.etat = 1;
		uneMachineBC.Date_Prochain_Evenement = Date_Simul + uneMachineBC.Duree_Traitement;
	}
	else
	{
		uneMachineBC.etat = 0;
		uneMachineBC.Date_Prochain_Evenement = 9999;
	}
}







void initialiserEntree(T_entree &uneEntree, int Duree_Int)
{
	uneEntree.Num_Derniere_Piece = 0;
	uneEntree.Nb_Clients_Perdus = 0;
	uneEntree.Date_Prochain_Evenement = 0;
	uneEntree.Duree_Int = Duree_Int;
}

void gererEntree(T_entree &uneEntree, T_file &uneFile, T_machine &uneMachine, int &Date_Simul)
{
	uneEntree.Num_Derniere_Piece++;
	T_piece unePiece;
	unePiece.Numero = uneEntree.Num_Derniere_Piece;
	unePiece.Date_Entree_Sys = Date_Simul;
	int etat = estPleine(uneFile);
	if (etat)
	{
		uneEntree.Nb_Clients_Perdus++;
		uneEntree.Date_Prochain_Evenement = Date_Simul + uneEntree.Duree_Int;
	}
	else
	{
		if (!(uneMachine.etat))
		{
			uneMachine.contenu = unePiece;
			uneMachine.etat = 1;
			uneMachine.Date_Prochain_Evenement = Date_Simul + uneMachine.Duree_Traitement;
		}
		else
		{
			deposer(uneFile, unePiece);
		}
		uneEntree.Date_Prochain_Evenement = Date_Simul + uneEntree.Duree_Int;
	}
}






void initialiserPuits(T_puits &unPuits)
{
	unPuits.Nb_Sortie = 0;
}

void deposerDansPuits(T_puits &unPuits, T_piece unePiece, int &Date_Simul)
{
	unePiece.Date_Sortie_Sys = Date_Simul;
	unPuits.Ensemble[unPuits.Nb_Sortie] = unePiece;
	unPuits.Nb_Sortie++;
}








void simuler(int Date_de_fin, int Duree_Int, int Duree_TraitementA, int Duree_TraitementB, int Duree_TraitementC, System::Windows::Forms::RichTextBox^ zone)
{
	T_entree uneEntree;
	T_machine uneMachineA;
	T_machine uneMachineB;
	T_machine uneMachineC;
	T_file uneFileA;
	T_file uneFileB;
	T_file uneFileC;
	
	T_puits *Ptr_unPuits = new T_puits;

	T_puits &unPuits=*Ptr_unPuits;
	int minimum=0;
	int i = 0;
	int rafraichissement = 0;
	initialiserEntree(uneEntree, Duree_Int);
	initialiserMachine(uneMachineA, Duree_TraitementA);
	initialiserMachine(uneMachineB, Duree_TraitementB);
	initialiserMachine(uneMachineB, Duree_TraitementC);
	initialiserFile(uneFileA);
	initialiserFile(uneFileB);
	initialiserFile(uneFileC);
	initialiserPuits(unPuits);
	

	int TempsMoyenDeSejourDansLeSyteme = 0;
	int TempsMoyenDeSejourDansLaFile = 0;
	int TempsMoyenDeSejourSurLaMachine = Duree_TraitementA;
	
	int Date_Simul = 0;
	while (Date_Simul < Date_de_fin)
	{
		minimum = uneEntree.Date_Prochain_Evenement;
		i = 1;

		if (uneMachineA.Date_Prochain_Evenement < minimum)
		{
			minimum = uneMachineA.Date_Prochain_Evenement;
			i = 2;
		}
		if (uneMachineB.Date_Prochain_Evenement < minimum)
		{
			minimum = uneMachineB.Date_Prochain_Evenement;
			i = 3;
		}
		if (uneMachineC.Date_Prochain_Evenement < minimum)
		{
			minimum = uneMachineC.Date_Prochain_Evenement;
			i = 4;
		}

		switch (i)
		{
		case 1:
			Date_Simul = uneEntree.Date_Prochain_Evenement;
			gererEntree(uneEntree, uneFileA, uneMachineA, Date_Simul);
			break;
		case 2:
			Date_Simul = uneMachineA.Date_Prochain_Evenement;
			gererMachineA(uneMachineA, uneMachineB, uneMachineC, uneFileA, uneFileB, uneFileC, Date_Simul);
			break;
		case 3:
			Date_Simul = uneMachineB.Date_Prochain_Evenement;
			gererMachineBC(uneMachineB, uneMachineA, uneFileB, uneFileA, unPuits, Date_Simul);
			break;
		case 4:
			Date_Simul = uneMachineC.Date_Prochain_Evenement;
			gererMachineBC(uneMachineC, uneMachineA, uneFileC, uneFileA, unPuits, Date_Simul);
			break;
		default:

			break;
		}

		rafraichissement++;
		if ((rafraichissement) % 10 == 0)
		{
			//Application.DoEvent();
		}
	}





	for (int k = 0; k<unPuits.Nb_Sortie; k++)
	{

		T_piece unePiece = unPuits.Ensemble[k];

		TempsMoyenDeSejourDansLeSyteme += (unePiece.Date_Sortie_Sys - unePiece.Date_Entree_Sys);
		TempsMoyenDeSejourDansLaFile += (unePiece.Date_Sortie_Sys - unePiece.Date_Entree_Sys) - Duree_TraitementA;

	}

	TempsMoyenDeSejourDansLeSyteme /= unPuits.Nb_Sortie;
	TempsMoyenDeSejourDansLaFile /= unPuits.Nb_Sortie;

	zone->AppendText("TempsMoyenDeSejourDansLeSyteme = ");
	zone->AppendText(TempsMoyenDeSejourDansLeSyteme.ToString());
	zone->AppendText("\n");
	zone->AppendText("TempsMoyenDeSejourDansLaFile = ");
	zone->AppendText(TempsMoyenDeSejourDansLaFile.ToString());
	zone->AppendText("\n");
	zone->AppendText("TempsMoyenDeSejourSurLaMachine = ");
	zone->AppendText(TempsMoyenDeSejourSurLaMachine.ToString());
	zone->AppendText("\n");
	zone->AppendText("NbDeClientsPerdus = ");
	zone->AppendText((uneEntree.Nb_Clients_Perdus).ToString());
	zone->AppendText("\n");
	zone->AppendText("\n");
	for (int k = 0; k<unPuits.Nb_Sortie; k++)
	{
		
		T_piece unePiece = unPuits.Ensemble[k];
		zone->AppendText("N° : ");
		zone->AppendText((unePiece.Numero).ToString());
		zone->AppendText("     Entrée : ");
		zone->AppendText((unePiece.Date_Entree_Sys).ToString());
		zone->AppendText("     Sortie : ");
		zone->AppendText((unePiece.Date_Sortie_Sys).ToString());

		zone->AppendText("\n");
	}


	free(Ptr_unPuits);

}