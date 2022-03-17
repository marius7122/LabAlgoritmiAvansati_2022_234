#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("date.in");
ofstream out("date.out");

int main()
{
    int n, x[101], y[101];
    float A[101][101];
    vector<int> nodes, solution;

    in >> n;
    for (int i = 0; i < n; i++)
    {
        nodes.push_back(i);
        in >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == j)
                A[i][j] = 0;
            else
                A[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    }

    float minPath = 100000;
    do 
    {
        float currentPath = 0;
        int s = 0;

        for (int i = 0; i < n; i++)
        {
            currentPath += A[s][nodes[i]];
            s = nodes[i];
        }

        currentPath += A[s][0];
        if (minPath > currentPath)
        {
            solution = nodes;
            solution.push_back(0);
            minPath = currentPath;
        }
    } while (next_permutation(nodes.begin(), nodes.end()));
    
    for (auto node : solution)
        out << node << " ";
    out << endl << minPath;
}