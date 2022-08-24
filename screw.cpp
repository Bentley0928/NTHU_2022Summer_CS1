#include <bits/stdc++.h>
using namespace std;
double place[500][2];
int main(){
    cout << fixed << setprecision(2);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> place[i][0] >> place[i][1];
    }
    double nowx=0,nowy=0,nowmax=-100,nowsum=0;
    int nowpos=0;
    bool isused[500];
    for(int i=0;i<n;i++){
        isused[i]=0;
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
            if(isused[j]) continue;
            double dis=sqrt(((nowx-place[j][0])*(nowx-place[j][0]))+((nowy-place[j][1])*(nowy-place[j][1])));
            if(dis>nowmax){
                nowmax=dis;
                nowpos=j;
            }
       }
       nowsum+=nowmax;
       cout << nowsum << endl;
       nowx=place[nowpos][0];
       nowy=place[nowpos][1];
       nowmax=-100;
       isused[nowpos]=1;
    }
    return 0;
}