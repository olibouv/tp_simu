#pragma once

const int TAILLE_FILLE2 = 8;

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
	T_piece liste[9];
	int D;
	int F;
}T_file;

typedef struct T_file2
{
	T_piece liste[TAILLE_FILLE2+1];
	int D;
	int F;
}T_file2;

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

void initialiserFile2(T_file2 &uneFile2);
void deposer2(T_file2 &uneFile2, T_piece &unePiece);
void retirer2(T_file2 &uneFile2, T_piece &unePiece);
int estVide2(T_file2 uneFile2);
int estPleine2(T_file2 uneFile2);

void initialiserMachine(T_machine &uneMachine, int Duree_Traitement);
void deposerPieceSurMachine(T_machine &uneMachine, T_piece unePiece);
void retirerPieceMachine(T_machine &uneMachine, T_piece &unePiece);
void gererMachine1(T_machine &uneMachine1, T_machine &uneMachine2, T_file &uneFile1, T_file2 &uneFile2, int &Date_Simul);
void gererMachine2(T_machine &uneMachine2, T_machine &uneMachine1, T_file2 &uneFile2, T_puits &unPuits, int &Date_Simul);


void initialiserEntree(T_entree &uneEntree, int Duree_Int);
void gererEntree(T_entree &uneEntree, T_file &uneFile, T_machine &uneMachine, int &Date_Simul);

void initialiserPuits(T_puits &unPuits);
void deposerDansPuits(T_puits &unPuits, T_piece unePiece, int &Date_Simul);

void simuler(int Date_de_fin, int Duree_Int, int Duree_Traitement1, int Duree_Traitement2, System::Windows::Forms::RichTextBox^ zone);

