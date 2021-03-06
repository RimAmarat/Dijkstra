
#include <iostream>
#include <fstream>
#include "utilities.h"
#include <limits.h>

using namespace std;



/****************************************/
/* Objectif : Affichage de la matrice d'adjacence
/****************************************/
void affichage(int *c[], int n)
{
	cout << "c = " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n-1); j++)
			cout << c[i][j] << "\t";
		cout << c[i][n-1] << endl;		
	}

	cout << endl;
}


/****************************************/
/* Objectif : Affichage du tableau des plus courts
chemins
/****************************************/
void affichage(int d[], int n)
{
	cout << "d = " << endl;
	for(int i = 0; i < n-1; i++)
		cout << d[i] << "\t";
	
	cout << d[n-1] << endl << endl;		
}

bool appartient(int T[], int x, int n){
	for(int i=0; i < n; i++) if(T[i] == x) return true;
		return false;
}

int argmin(int T[], int n){
	int argmin = 0;
	for(int j=1; j < n; j++) if(T[j] < T[argmin]) argmin = j;
	return argmin;
}

/****************************************/
/* Objectif : Algorithme de calcul des plus courts
dans un graphe dont les arcs ont des longueurs positives.
- c : matrice de longueur de chaque arc
- d : tableau des plus courts chemins
- pere : tableau donnant pour chaque sommet i son prédecesseur
pred[i] dans le plus court chemin.
- n : nombre de sommets du graphe
- s : sommet origine d'où les plus courts chemins sont calculés
/****************************************/
void mooredijkstra(int *c[], int d[], int n, int s)
{
	// A faire
	bool C_barre[n] = {};
	for(int i=0; i<n; i++) C_barre[i] = true;
	C_barre[s] = false;
	for(int i=0; i<n; i++)
		d[i] = INT_MAX;
	d[s] = 0;
	int pere[n] = {};
	int j = s;

	for(int l=0; l<n-1; l++){
		for(int i=0; i<n; i++){
			if(C_barre[i] && c[j][i] != 0){
				if(C_barre[i]) cout << C_barre[i] << endl;
				if(d[j] + c[j][i] < d[i])
				{
					cout << "d[j] + c[j][i] < d[i]" << endl;
					d[i] = d[j] + c[j][i];
					pere[i] = j;
				}
			}
		}
	// Recherche de C_barre, de l'indice j de plus petite valeur d[i]
	j = argmin(d, n);
	// Suppression de l'indice j de la liste C_barre
	C_barre[j] = false;

	}

	cout << "C_barre = " << endl;
	for(int i = 0; i < n-1; i++)
		cout << C_barre[i] << "\t";

	cout << C_barre[n-1] << endl << endl;

}
