#include <iostream>
using namespace std;
const int Max = 500;
int mind(const string &world1, const string &world2)
{
    int m = world1.length();
    int n = world2.length();
    int dp[Max][Max];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (world1[i - 1] == world2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 0;
            }
            else
            {
                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 2);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string world1 = "kitten";
    string world2 = "sitting";
    int dis = mind(world1, world2);
    cout << "Edit distance is=" << dis << endl;
    return 0;
}