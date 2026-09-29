#include <iostream>
#include <vector>
#include <climits>
using namespace std;
long long matrixChain(const vector<int> &p)
{
    int n = p.size() - 1;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++)
            {
                long long cost = dp[i][k] + dp[k + 1][j] + 1LL * p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[1][n];
}
int main()
{
    vector<int> p = {4, 10, 3, 8};
    cout << matrixChain(p);
}