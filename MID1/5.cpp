#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, c;
    cin >> n >> t >> c;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    for (int i = 0; i < t; i++)
    {
        int p = pq.top();
        cout << p << endl;
        pq.pop();
        p = (p * 727 + c) % 1009;
        pq.push(p);
    }
    return 0;
}