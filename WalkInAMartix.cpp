#include <bits/stdc++.h>
using namespace std;
int main(){
    int martix[51][51],n,cycle=0,cc=1;;
    cin >> n;
    while(cc<=(n*n)){
        for(int i=cycle;i<n-cycle;i++){
            martix[cycle][i]=cc;
            cc++;
        }
        if(cc<=(n*n)){
            for(int i=cycle+1;i<n-cycle;i++){
                martix[i][n-1-cycle]=cc;
                cc++;
            }
        }
        if(cc<=(n*n)){
            for(int i=n-1-cycle-1;i>=cycle;i--){
                martix[n-1-cycle][i]=cc;
                cc++;
            }
        }
        if(cc<=(n*n)){
            for(int i=n-1-cycle-1;i>=cycle+1;i--){
                martix[i][cycle]=cc;
                cc++;
            }
        }
        cycle++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << martix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}