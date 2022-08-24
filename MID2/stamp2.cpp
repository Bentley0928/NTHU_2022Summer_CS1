#include <bits/stdc++.h>
using namespace std;
int price[10];
bool c[50001];
int k;
void change(int m)
{
    memset(c, false, sizeof(c));
    c[0] = true;
    for (int i = 0; i < k; ++i)
        for (int j = price[i]; j <= m; ++j)
            c[j] |= c[j-price[i]];

    if (c[m])
        cout << "yes\n";
    else
        cout << "no\n";
}
int main(){
    int n;
    cin >> n;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> price[i];
    }
    change(n);
    return 0;
}