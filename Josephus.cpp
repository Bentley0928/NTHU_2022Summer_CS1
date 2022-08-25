#include <bits/stdc++.h>
using namespace std;
int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}
 
// Driver Program to test above function
int main()
{
    int n,k;
    while(cin >> n >> k){
        printf("%d\n", josephus(n, k));
    }
    return 0;
}