#include <bits/stdc++.h>
using namespace std;
int land[501][501];
int sav[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int H,W;
void findl(int f,int b){
    land[f][b]=-1;
    
    for(int i=0;i<4;i++){
        int ff=f+sav[i][0];
        int bb=b+sav[i][1];
        if(ff<0 || ff>=H){
            continue;
        }
        if(bb<0 || bb>=W){
            continue;
        }
        if(land[ff][bb]==1){
            findl(ff,bb);
        }
    }
}
int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> land[i][j];
        }
    }
    int count=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(land[i][j]==1){
                count++;
                findl(i,j);
            }
        }
    }
    cout << count << endl;
    return 0;
}