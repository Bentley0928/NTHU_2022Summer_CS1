#include <bits/stdc++.h>
int k;
int coins[10], dp[50001];
using namespace std;
int cal(int kinds, int tar)
{
    if (dp[tar] == 0)
    {
        for(int i=0;i<kinds;i++){
            for(int j=coins[i];j<=tar;j++){
                dp[j]+=dp[j-coins[i]]%1000000007;
                dp[j]%=1000000007;
            }
        }
    }
    return dp[tar]%1000000007;
}
int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> coins[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int t;
    cin >> t;
    cal(k, 50000);
    while (t--)
    {
        int mon;
        cin >> mon;
        cout << dp[mon] << endl;
    }
    return 0;
}