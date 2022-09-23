#include <bits/stdc++.h>
using namespace std;
bool board[8][8];
int ways=0;
void place(int n,int a,int b){
    if(a>=n){
        return;
    }
    if(b>=n){//換下一行
        return;
    }
    if(board[a][b]){
        place(n,a,b+1);
        return;
    }
    place(n,a,b+1);
    int count=0;
    bool flag=0;
    for(int i=0;i<n;i++){
        if(board[a][i]==1){
            count++;
        }
    }
    if(count>=2){
        flag=1;
    }
    count=0;
    for(int i=0;i<n;i++){
        if(board[i][b]==1){
            count++;
        }
    }
    if(count>=2){
        flag=1;
    }
    if(flag) return;
    board[a][b]=1;
    place(n,a,b+1);
    board[a][b]=0;
}
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        board[x][y]=1;
    }
    place(n,0,0);
    cout << ways << endl;
    return 0;
}