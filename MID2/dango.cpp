#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    char graph[501][501];
    int r,c;
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            graph[i][j]='.';
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        char tmp;
        cin >> tmp;
        int tmp1=b-3,tmp2=b+3;
        if(tmp1<0) tmp1=0;
        if(tmp2>c-1) tmp2=c-1;
        for(int i=tmp1;i<=tmp2;i++){
            if(a>r-1) break;
            graph[a][i]=tmp;
        }
        tmp1=b-2,tmp2=b+2;
        if(tmp1<0) tmp1=0;
        if(tmp2>c-1) tmp2=c-1;
        for(int i=tmp1;i<=tmp2;i++){
            if(a-1>=0)graph[a-1][i]=tmp;
            if(a-2>=0)graph[a-2][i]=tmp;
            if(a+1<=r-1)graph[a+1][i]=tmp;
            if(a+2<=r-1)graph[a+2][i]=tmp;
        }
        if(a-3>=0)graph[a-3][b]=tmp;
        if(a+3<=r-1)graph[a+3][b]=tmp;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << graph[i][j];
        }
        cout << '\n';
    }
    return 0;
}