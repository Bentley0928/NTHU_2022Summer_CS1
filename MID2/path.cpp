#include <bits/stdc++.h>
using namespace std;

void solve(int*,const int);
int nowmin=0;
int m[16][16];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int *x=new int[n];
	for(int i=0;i<n;i++)
	{
		x[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> m[i][j];
        }
    }
    solve(x,n);
    cout << nowmin << endl;
    return 0;
}

void solve(int *A,const int n)
{
	for(int i=0;i<n-1;i++)
	{
		nowmin+=m[A[i]][A[i+1]];
	}
	while(next_permutation(A,A+n))
	{
        int temp=0;
		for(int i=0;i<n-1;i++)
	    {
		    temp+=m[A[i]][A[i+1]];
            if(temp>=nowmin){
                break;
            }
	    }
		if(temp<nowmin)
		{
			nowmin=temp;
		}
	}
}