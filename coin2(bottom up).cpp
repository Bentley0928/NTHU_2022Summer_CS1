#include <bits/stdc++.h>
using namespace std;
int coins[10];
int dp[50001];
void cal(int k,int cos){
    dp[0]=0;
    for(int i=1;i<=cos;i++){
        int best=INT_MAX;
        for(int j=0;j<k;j++){
            if(i<coins[j]) continue;
            if(best>(dp[i-coins[j]]+1)){
                best=dp[i-coins[j]]+1;
            }
        }
        dp[i]=best;
    }
}
int main(){
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> coins[i];
    }
    memset(dp,0,sizeof(dp));
    int t=0;
    cin >> t;
    cal(k,50000);
    while(t--){
        int cos;
        cin >> cos;
        cout << dp[cos] << endl;
    }
    return 0;
}