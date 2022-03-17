#include <iostream>
#include <cmath>
using namespace std;
float distanta[101][101], lgMin = 1e9, lg;
int  traseu[101], nrOrase, traseuMin[102];
bool vis[101];

struct oras {
    int x, y;
};

float calculeazaDistanta(oras a, oras b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int generareDistante(oras orase[]) {
    for(int i = 1; i <= nrOrase; i ++) {
        for(int j = 1; j <= nrOrase; j ++) {
            if(i == j)
                distanta[i][j] = 0;
            else {
                distanta[i][j] = calculeazaDistanta(orase[i], orase[j]);
            }
        }
    }
}

int verificaSolutie(int pos) {
    if (pos == nrOrase + 1) {
        if (!distanta[traseu[nrOrase]][1])
            return 1 ;
        lg += distanta[traseu[nrOrase]][1];
        if (lg < lgMin) {
            lgMin = lg;
            for (int i = 1; i <= nrOrase; i++)
                traseuMin[i] = traseu[i];
        }
        lg -= distanta[traseu[nrOrase]][1];
        return 1;
    }
}

void bkt(int pos) {
    if (lg >= lgMin)
        return;
    verificaSolutie(pos);

    for (int i = 2; i <= nrOrase; i++)
        if (!vis[i] && distanta[traseu[pos - 1]][i]) {
            vis[traseu[pos] = i] = true;
            lg += distanta[traseu[pos - 1]][i];
            bkt(pos + 1);
            vis[i] = false;
            lg -= distanta[traseu[pos - 1]][i];
        }
}

int main(){
    cin >> nrOrase;
    oras orase[nrOrase + 1];

    for(int i = 1; i <= nrOrase; i ++) {
        cin >> orase[i].x >> orase[i].y;
    }

    generareDistante(orase);

    vis[traseu[1] = 1] = true;
    bkt(2);

    for(int i = 1; i <= nrOrase; i ++)
        cout << traseuMin[i] << " ";

    cout << endl;
    cout << lgMin;
    return 0;
}
//4
//0 0
//-1 1
//0 1
//0 2