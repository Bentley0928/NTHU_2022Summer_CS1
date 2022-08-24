#include <bits/stdc++.h>
using namespace std;
int coins[10];
bool dp[50001];
int cal(int k,int cos){
    if(cos==0){
        dp[cos]=1;
        return 1;
    }
    for(int i=0;i<k;i++){
        if(cos>=coins[i]){
            dp[cos] |= cal(k,cos-coins[i]);
        }
    }
    return dp[cos];
}
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> coins[i];
    }
    memset(dp,0,sizeof(dp));
    cal(k,n);
    if(dp[n]==1) cout << "yes\n";
    else cout << "no\n";
    return 0;
}