#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("rucsac.in");
    ofstream fout("rucsac.out");

    int n, wMax;
    fin >> n >> wMax;

    vector<int> w(n), p(n);
    for(int i = 0; i < n; i++)
        fin >> w[i] >> p[i];

    vector<vector<int>> dp(2, vector<int>(wMax + 1));
    for(int i = 0; i < n; i++)
    {
        int curr = i % 2;
        int prec = 1 - curr;

        for(int j = 1; j <= wMax; j++)
        {
            dp[curr][j] = dp[prec][j];
            if(j >= w[i])
                dp[curr][j] = max(dp[curr][j], dp[prec][j - w[i]] + p[i]);
        }
    }

    fout << dp[(n-1) % 2][wMax] << '\n';

    fin.close();
    fout.close();
    return 0;
}