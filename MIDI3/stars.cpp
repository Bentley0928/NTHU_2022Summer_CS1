#include <bits/stdc++.h>
using namespace std;
struct store{
    int num,cost;
};
bool comp(store a, store b){
    double ac=(double)a.cost/double(a.num),bc=double(b.cost)/double(b.num);
    return ac<bc;
}
int main(){
    int n,w;
    cin >> n >> w;
    store st[50000];
    for(int i=0;i<n;i++){
        cin >> st[i].num >> st[i].cost;
    }
    sort(st,st+n,comp);
    int cnt=0;
    double ans=0.0;
    while(w>0){
        if(cnt==n){
            break;
        }
        if(w>=st[cnt].num){
            ans+=st[cnt].cost;
            w-=st[cnt].num;
        }
        else{
            double tmp=double(st[cnt].cost)/double(st[cnt].num);
            ans+=w*tmp;
            w=0;
        }
        cnt++;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}