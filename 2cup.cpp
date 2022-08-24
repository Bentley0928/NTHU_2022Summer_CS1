#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin >> a >> b >> c;
    if(c==0) cout << 0 << endl;
    else if(a==c || b==c){
        cout << 1 << endl;
    }
    else{
        int s=a,t=0,count=1;
        while(s!=c && t!=c){
            if(s==0 && t==0){
                count=0;
                break;
            }
            else if(t==b){
                t=0;
                count++;
            }
            else if(s!=0){
                if(s>(b-t)){
                    s-=(b-t);
                    t=b;
                }
                else{
                    t+=s;
                    s=0;
                }
                count++;
            }
            else if(s==0){
                s=a;
                count++;
            }
        }
        int one=count;
        count=1;
        s=b;
        t=0;
        while(s!=c && t!=c){
            if(s==0 && t==0){
                count=0;
                break;
            }
            else if(t==a){
                t=0;
                count++;
            }
            else if(s!=0){
                if(s>(a-t)){
                    s-=(a-t);
                    t=a;
                }
                else{
                    t+=s;
                    s=0;
                }
                count++;
            }
            else if(s==0){
                s=b;
                count++;
            }
        }
        int two=count;
        if(one == 0 && two == 0){
            cout << "NO ANSWER" << endl;
        }
        else if(one == 0 || two == 0) cout << max(one,two) << endl;
        else cout << min(one,two) << endl;
    }
    return 0;
}