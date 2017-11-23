
#include "stdafx.h"

#include "Header.h"


int NB_PIECES_PERIMEES = 0;

void initialiserFile(T_file &uneFile)
{
	uneFile.D = 0;
	uneFile.F = 0;
}

void deposer(T_file &uneFile, T_piece &unePiece)
{
	uneFile.liste[uneFile.D] = unePiece;
	uneFile.D = (uneFile.D + 1) % 9;
}

void retirer(T_file &uneFile, T_piece &unePiece)
{
	unePiece = uneFile.liste[uneFile.F];
	uneFile.F = (uneFile.F + 1) % 9;
}

int estVide(T_file uneFile)
{
	return (uneFile.D == uneFile.F);
}
int estPleine(T_file uneFile)
{
	return ((uneFile.D + 1) % 9 == uneFile.F);
}



void initialiserFile2(T_file2 &uneFile2)
{
	uneFile2.D = 0;
	uneFile2.F = 0;
}

void deposer2(T_file2 &uneFile2, T_piece &unePiece)
{
	uneFile2.liste[uneFile2.D] = unePiece;
	uneFile2.D = (uneFile2.D + 1) % (TAILLE_FILLE2 + 1);
}

void retirer2(T_file2 &uneFile2, T_piece &unePiece)
{
	unePiece = uneFile2.liste[uneFile2.F];
	uneFile2.F = (uneFile2.F + 1) % (TAILLE_FILLE2 + 1);
}

int estVide2(T_file2 uneFile2)
{
	return (uneFile2.D == uneFile2.F);
}
int estPleine2(T_file2 uneFile2)
{
	return ((uneFile2.D + 1) % (TAILLE_FILLE2 + 1) == uneFile2.F);
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

void gererMachine1(T_machine &uneMachine1, T_machine &uneMachine2, T_file &uneFile1, T_file2 &uneFile2, int &Date_Simul)
{
	int arret;
	T_piece unePiece;
	unePiece = uneMachine1.contenu;
	int etat = estPleine2(uneFile2);
	if (etat)
	{
		uneMachine1.etat = 1;
		uneMachine1.Date_Prochain_Evenement = 9999;
	}
	else
	{
		if (!uneMachine2.etat)
		{
			deposerPieceSurMachine(uneMachine2, unePiece);
			uneMachine2.Date_Prochain_Evenement = Date_Simul+uneMachine2.Duree_Traitement;
		}
		else
		{
			deposer2(uneFile2, unePiece);
		}
		if (!estVide(uneFile1))
		{
			retirer(uneFile1, unePiece);
			/*arret = 0;
			while (!estVide(uneFile1) && !arret)
			{
				if ((Date_Simul - unePiece.Date_Entree_Sys) < 30)
				{*/
					uneMachine1.contenu = unePiece;
					uneMachine1.etat = 1;
					uneMachine1.Date_Prochain_Evenement = Date_Simul + uneMachine1.Duree_Traitement;
					/*arret = 1;
				}
				else
				{
					retirer(uneFile1, unePiece);
					NB_PIECES_PERIMEES++;
				}
			}
			if (!arret)
			{
				uneMachine1.Date_Prochain_Evenement = 9999;
				uneMachine1.etat = 0;
			}*/
		}
		else
		{
			uneMachine1.etat = 0;
			uneMachine1.Date_Prochain_Evenement = 9999;
		}
	}
}


void gererMachine2(T_machine &uneMachine2, T_machine &uneMachine1, T_file2 &uneFile2, T_puits &unPuits, int &Date_Simul)
{
	T_piece unePiece;
	unePiece = uneMachine2.contenu;
	deposerDansPuits(unPuits, unePiece, Date_Simul);
	int etat = estVide2(uneFile2);
	if (etat)
	{
		uneMachine2.etat = 0;
		uneMachine2.Date_Prochain_Evenement = 9999;
	}
	else
	{
		retirer2(uneFile2, unePiece);
		uneMachine2.contenu = unePiece;
		uneMachine2.etat = 1;
		uneMachine2.Date_Prochain_Evenement = Date_Simul + uneMachine2.Duree_Traitement;
		if (uneMachine1.Date_Prochain_Evenement == 9999 && uneMachine1.etat == 1)
		{
			uneMachine1.Date_Prochain_Evenement = Date_Simul;
		}
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








void simuler(int Date_de_fin, int Duree_Int, int Duree_Traitement1, int Duree_Traitement2, System::Windows::Forms::RichTextBox^ zone)
{
	T_entree uneEntree;
	T_machine uneMachine1;
	T_machine uneMachine2;
	T_file uneFile1;
	T_file2 uneFile2;
	T_puits unPuits;
	//int i;
	int rafraichissement = 0;
	initialiserEntree(uneEntree, Duree_Int);
	initialiserMachine(uneMachine1, Duree_Traitement1);
	initialiserMachine(uneMachine2, Duree_Traitement2);
	initialiserFile(uneFile1);
	initialiserFile2(uneFile2);
	initialiserPuits(unPuits);
	

	int TempsMoyenDeSejourDansLeSyteme = 0;
	int TempsMoyenDeSejourDansLaFile = 0;
	int TempsMoyenDeSejourSurLaMachine = Duree_Traitement1;

	int Date_Simul = 0;
	while (Date_Simul < Date_de_fin)
	{
		if (uneEntree.Date_Prochain_Evenement < uneMachine2.Date_Prochain_Evenement) // entrée < machine2
		{
			if (uneEntree.Date_Prochain_Evenement < uneMachine1.Date_Prochain_Evenement) //entrée < machine2,machine1
			{
				Date_Simul = uneEntree.Date_Prochain_Evenement;
				gererEntree(uneEntree, uneFile1, uneMachine1, Date_Simul);
			}
			else //machine1 <= entrée < machine2
			{
				Date_Simul = uneMachine1.Date_Prochain_Evenement;
				gererMachine1(uneMachine1, uneMachine2, uneFile1, uneFile2, Date_Simul);
			}
		}
		else // machine2 <= entrée
		{
			if (uneMachine2.Date_Prochain_Evenement <= uneMachine1.Date_Prochain_Evenement) //machine2 <= entrée,machine1
			{
				Date_Simul = uneMachine2.Date_Prochain_Evenement;
				gererMachine2(uneMachine2, uneMachine1, uneFile2, unPuits, Date_Simul);
			}
			else //machine1 < machine2 <= entrée
			{
				Date_Simul = uneMachine1.Date_Prochain_Evenement;
				gererMachine1(uneMachine1, uneMachine2, uneFile1, uneFile2, Date_Simul);
			}
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
		TempsMoyenDeSejourDansLaFile += (unePiece.Date_Sortie_Sys - unePiece.Date_Entree_Sys) - Duree_Traitement1;

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
	zone->AppendText("NbDePiecesPerimees = ");
	zone->AppendText((NB_PIECES_PERIMEES).ToString());
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
}