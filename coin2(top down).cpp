#include <bits/stdc++.h>
using namespace std;
int coins[10];
int dp[50001];
int cal(int k,int cos){
    if(cos==0){
        dp[cos]=1;
        return 0;
    }
    if(dp[cos]!=0){
        return dp[cos];
    }
    int best=INT_MAX;
    for(int i=0;i<k;i++){
        if(cos>=coins[i]){
            if(best>(cal(k,cos-coins[i])+1)){
                best=cal(k,cos-coins[i])+1;
            }
        }
    }
    dp[cos]=best;
    return dp[cos];
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
    while(t--){
        int cos;
        cin >> cos;
        cout << cal(k,cos) << endl;
    }
    return 0;
}