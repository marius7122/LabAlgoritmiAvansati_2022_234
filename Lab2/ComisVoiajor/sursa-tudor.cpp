#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double matrice[18][18];
double minim = 32000;
int  n;
int sol[100];
int solutie_finala[100];

struct Oras{
    double x,y;

};
double dist(Oras o1, Oras o2)
{
    double res = (o2.x - o1.x)* (o2.x - o1.x) + (o2.y - o1.y)* (o2.y - o1.y);
    return sqrt(res);
}

double dist_sol()
{
    double suma = 0;
    for(int i = 1; i< n; i++)
    {
        suma += matrice[sol[i]][sol[i+1]];
    }
    suma += matrice[sol[1]][sol[n]];
    return suma;
}
bool OK(int k)
{
    for(int i = 1; i< k; i++)
    {
        if(sol[k] == sol[i])
            return false;
    }
    return true;
}

void backtracking(int k)
{
    if(k == n+1){
        double dist = dist_sol();
        if (dist < minim) {
            minim = dist;
            for(int i = 1;i <=n; i++) {
                solutie_finala[i] = sol[i];
            }
            solutie_finala[n+1] = sol[1];
        }
    }
    else {
        for(int i = 1; i<= n; i++)
        {
            sol[k] = i;
            if(OK(k)){
                backtracking(k+1);
            }
        }
    }
}
int main() {
    ifstream f("hamilton.in");
    ofstream g("hamilton.out");
        
    f >>  n;
    vector<Oras> orase(n+2);
    for(int i = 1; i<= n; i++)
    {
        f >> orase[i].x;
        f >> orase[i].y;
    }
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            matrice[i][j] = dist(orase[i], orase[j]);
        }

    }
    backtracking(1);
    for(int i = 1; i<= n+1; i++) {
        cout << solutie_finala[i] << " ";
    }
    cout << endl;
    cout << minim;

    return 0;
}

