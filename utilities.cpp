
#include <iostream>
#include <fstream>
#include <vector>
#include "utilities.h"

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
	int pere[n];
	vector<int> C_barre;

	for(int i=0; i<n-1; i++) C_barre[i] = i+1;
	d[0] = 0;
	for(int i=0; i<n-1; i++) d[i] = -1;
	for(int i=0; i<n-1; i++) pere[i] = 0;
	int j = 0;
	for(int l=0; l<n-1; l++){
		for(int i=0; i<n-1; i++){
			if(appartient(C_barre,i) && c[j][i] != 0){
				if(d[j] + c[i][j] < d[i])
				{
					d[i] = d[j] + c[j][i];
					pere[i] = j;
				}
			}
		}
		int argmin ;
			for(int j=0; j<n; j++) if(appartient(C_barre, j)) {
				argmin = j;
				break;
			}
		// Recherche de C_barre, de l'indice j de plus petite valeur d[i]
		for(int j=0; j<n; j++) if(d[j] < d[argmin]) argmin = j;

		// Suppression de l'indice j de la liste C_barre
		C_barre.erase()

	}
}

bool appartient(int T[], int x){
	for(int i=0; i < T.size(); i++) if(T[n] == x) return true;
		return false;
}
