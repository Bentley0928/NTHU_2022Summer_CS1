#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b){
    if(a<b){
        swap(a,b);
    }
    while(a%b!=0){
        long long int tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}
int main(){
    int n;
    cin >> n;
    long long int a,b;
    cin >> a >> b;
    n--;
    long long int now1=a,now2=b;
    while(n--){
        a=0;b=0;
        cin >> a >> b;
        now1=now1*b+a*now2;
        now2*=b;
        long long int gg=gcd(abs(now1),abs(now2));
        now1/=gg;
        now2/=gg;
        cout << now1 << " " << now2 << endl;
    }
    return 0;
}