#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dp[5010][10010];

int main()
{
    ifstream fin("rucsac.in");
    ofstream fout("rucsac.out");

    int n, wMax;
    fin >> n >> wMax;

    vector<int> w(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++)
        fin >> w[i] >> p[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= wMax; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + p[i]);
        }
    }

    fout << dp[n][wMax] << '\n';

    fin.close();
    fout.close();
    return 0;
}