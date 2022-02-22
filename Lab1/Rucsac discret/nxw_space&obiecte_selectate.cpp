#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("rucsac.in");
ofstream g("rucsac.out");

struct obiect
{
    int greutate;
    int pret;
} obiecte[5001];

int profit[5001][10001];
int n, W;

int main()
{
    f >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        f >> obiecte[i].greutate;
        f >> obiecte[i].pret;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j - obiecte[i].greutate < 0)
            {
                profit[i][j] = profit[i - 1][j];
            }
            else
            {
                profit[i][j] = max(profit[i - 1][j], profit[i - 1][j - obiecte[i].greutate] + obiecte[i].pret);
            }
        }
    }
    g << profit[n][W];
    int w = W;
    for (int i = n; i >= 1; i--)
    {
        if (profit[i][w] != profit[i - 1][w])
        {
            g << obiecte[i].greutate << " " << obiecte[i].pret << '\n';
            w = w - obiecte[i].greutate;
        }
        if (w == 0)
        {
            break;
        }
    }
    return 0;
}