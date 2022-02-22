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

    vector<int> dp(wMax + 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = wMax; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        }
    }

    fout << dp[wMax] << '\n';

    fin.close();
    fout.close();
    return 0;
}