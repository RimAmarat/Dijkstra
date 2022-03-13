
#include <iostream>
#include "utilities.h"

using namespace std;

int main() {
    cout << "Écrire dans le main vos propres tests" << endl;
    int n = 8;
    int x[8][8] = {  {0,2,0,6,0,0,0,0},
                            {2,0,2,0,7,0,0,0},
                            {0,2,0,1,0,2,0,0},
                            {6,0,1,0,0,0,4,0},
                            {0,7,0,0,0,3,0,3},
                            {0,0,2,0,3,0,2,0},
                            {0,0,0,4,0,2,0,2},
                            {0,0,0,0,3,0,2,0}};
    int *c[n];
    for(int i=0; i<n; i++) c[i] = x[i];

    int d[n] = {};
    int s = 0;
    mooredijkstra(c, d, n, s);
    cout << "***************************************" << endl;
    affichage(d, n);
    cout << "***************************************" << endl;



}
