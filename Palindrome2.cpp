#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int num = s.length() - 1;
        string ss = s;
        int j = 0;
        for (int i = num; i >= 0; i--)
        {
            ss[i] = s[j];
            j++;
        }
        if (s == ss)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}