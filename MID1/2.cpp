#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    unsigned long long int i, n;
    cin >> n;
    for (i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << "\n";
            while (n % i == 0)
                n = n / i;
        }
    }
    return 0;
}