#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b ,c;
    cin >> a >> b >> c;
    b=b+c;
    while(b>=60){
        a++;
        b-=60;
    }
    while(a>=24){
        a-=24;
    }
    cout << a << " " << b << endl;
    return 0;
}