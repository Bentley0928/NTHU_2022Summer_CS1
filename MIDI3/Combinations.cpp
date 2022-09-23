#include <bits/stdc++.h>
using namespace std;
int n, m;
int input[9];
int cnt = 0;
void comb(int n, int m);
bool cmp(vector<int> a, vector<int> b)
{
	if(a[0] != b[0]) return a[0] < b[0];
	if(a[1] != b[1]) return a[1] < b[1];
	if(a[2] != b[2]) return a[2] < b[2];
    if(a[3] != b[3]) return a[3] < b[3];
    if(a[4] != b[4]) return a[4] < b[4];
    if(a[5] != b[5]) return a[5] < b[5];
	if(a[6] != b[6]) return a[6] < b[6];
    if(a[7] != b[7]) return a[7] < b[7];
    if(a[8] != b[8]) return a[8] < b[8];
}

vector<int> ans[50000];
int main()
{
    cin >> m >> n; // cmn
    for (int i = 0; i < m; i++)
    {
        cin >> input[i];
    }
    sort(input,input+m);
    comb(n, m);
    sort(ans,ans+cnt,cmp);
    vector <int> prev;
    for(int i=0;i<cnt;i++){
        if(ans[i]==prev) continue;
        for(int j=0;j<n;j++){
            if(j!=n-1)cout << ans[i][j] << " ";
            else cout << ans[i][j];
        }
        prev=ans[i];
        cout << endl;
    }
    return 0;
}

void comb(int n, int m)
{
    vector<int> list;
    for (int i = 0; i < n; ++i)
    {
        list.push_back(i);
    }
    --list[n - 1];
    do
    {
        for (int i = n - 1; i >= 0; --i)
        {
            if (list[i] < m + i - n)
            {
                ++list[i];
                for (int j = i + 1; j < n; ++j)
                {
                    list[j] = list[i] + j - i;
                }
                break;
            }
        }
        /*for (int i = 0; i < n; ++i)
        {
            cout << list[i] + 1 << '\t';
        }
        cout << endl;*/
        int arr[9];
        for (int i = 0; i < n; i++)
        {
            arr[i] = input[list[i]];
        }
        for (int i = 0; i < n; i++)
        {
            ans[cnt].push_back(arr[i]);
        }
        cnt++;
        while (next_permutation(arr, arr + n))
        {
            for (int i = 0; i < n; i++)
            {
                ans[cnt].push_back(arr[i]);
            }
            cnt++;
        }
    } while (list[0] < (m - n));
}