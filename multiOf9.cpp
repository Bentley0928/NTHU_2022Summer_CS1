#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    cout << s << endl;
    int len=s.size();
    long long int sum=0;
    for(int i=0;i<len;i++){
        sum+=int(s[i]-'0');
    }
    if(len!=1) cout << sum << endl;
    while(sum>9){
        int tmp=0;
        while(sum>0){
            tmp+=sum%10;
            sum/=10;
        }
        sum=tmp;
        cout << sum << endl;
    }
    if(sum%9==0) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}