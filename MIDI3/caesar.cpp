#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    string ss;
    cin >> ss;
    int len=ss.length();
    for(int i=0;i<len;i++){
        if(ss[i]>='A' && ss[i]<='Z'){
            if((ss[i]+k)<='Z'){
                ss[i]+=k;
            }
            else{
                ss[i]=(ss[i]-26+k);
            }
        }
    }
    cout << ss << endl;
    return 0;
}