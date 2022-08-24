#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    while(a%b!=0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a*=d;
    c*=b;
    int moo=b*d;
    int zee=a+c;
    int gcda=gcd(zee,moo);
    moo/=gcda;
    zee/=gcda;
    cout << zee << "/" << moo << endl;
    return 0;
}