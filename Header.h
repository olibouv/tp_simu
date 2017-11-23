#pragma once


typedef struct T_entree
{
	int Duree_Int;
	int Num_Derniere_Piece;
	int Nb_Clients_Perdus;
	int Date_Prochain_Evenement;
}T_entree;

typedef struct T_piece
{
	int Numero;
	int Date_Entree_Sys;
	int Date_Sortie_Sys;
}T_piece;

typedef struct T_file
{
	T_piece liste[5000];
	int D;
	int F;
}T_file;



typedef struct T_machine
{
	int etat;
	T_piece contenu;
	int Date_Prochain_Evenement;
	int Duree_Traitement;
}T_machine;

typedef struct puits
{
	T_piece Ensemble[1000];
	int Nb_Sortie;
}T_puits;

void initialiserFile(T_file &uneFile);
void deposer(T_file &uneFile, T_piece &unePiece);
void retirer(T_file &uneFile, T_piece &unePiece);
int estVide(T_file uneFile);
int estPleine(T_file uneFile);

void initialiserMachine(T_machine &uneMachine, int Duree_Traitement);
void deposerPieceSurMachine(T_machine &uneMachine, T_piece unePiece);
void retirerPieceMachine(T_machine &uneMachine, T_piece &unePiece);
void gererMachineA(T_machine &uneMachineA, T_machine &uneMachineB, T_machine &uneMachineC, T_file &uneFileA, T_file &uneFileB, T_file &uneFileC, int &Date_Simul);
void gererMachineBC(T_machine &uneMachineBC, T_machine &uneMachineA, T_file &uneFileBC, T_file &uneFileA, T_puits &unPuits, int &Date_Simul);


void initialiserEntree(T_entree &uneEntree, int Duree_Int);
void gererEntree(T_entree &uneEntree, T_file &uneFile, T_machine &uneMachine, int &Date_Simul);

void initialiserPuits(T_puits &unPuits);
void deposerDansPuits(T_puits &unPuits, T_piece unePiece, int &Date_Simul);

void simuler(int Date_de_fin, int Duree_Int, int Duree_TraitementA, int Duree_TraitementB, int Duree_TraitementC, System::Windows::Forms::RichTextBox^ zone);

