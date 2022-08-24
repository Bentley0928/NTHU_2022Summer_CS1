#include <bits/stdc++.h>
using namespace std;

void solve(double*,double*,const int);
double temp=0,temp1=0,temp2=0;
int main()
{
    std::cout << std::fixed << std::setprecision(2); 
	int n;
	cin>>n;
	double *x=new double[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	double *y=new double[n];
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
	}
    solve(x,y,n);
    cout << temp1 << " " << temp2 << endl;
    return 0;
}

void solve(double* A,double *B,const int n)
{
	for(int i=0;i<n;i++)
	{
		temp1+=A[i]*B[i];
        temp2=temp1;
	}
	sort(A,A+n);
	while(next_permutation(A,A+n))
	{
		for(int i=0;i<n;i++)
		{
			temp+=A[i]*B[i];
		}
		if(temp<temp1)
		{
			temp1=temp;
		}
        if(temp>temp2){
            temp2=temp;
        }
		temp=0;
	}
    //cout << temp1 << " " << temp2 << endl;
}