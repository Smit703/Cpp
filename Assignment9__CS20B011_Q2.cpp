//Smit Bagul
//CS20B011
#include <bits/stdc++.h>
using namespace std;

int max_power(int, int*);

int main()
{
    int n;
    cin>>n;

    int arr[n+2];
    arr[0]=1;
    arr[n+1]=1;
    for(int i=1;i<n+1;i++)
    {
        cin>>arr[i];
    }

    int p;
    cin>>p;

    int Max_powerup=max_power(n,arr);
    cout<<Max_powerup<<endl;

    if(Max_powerup>=p)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}

int max_power(int n,int *a)
{
    int ans[102][102];
    for(int i=0; i<n+2 ;i++)
    {
        ans[i][i]=0;
    }

    for(int i=2; i<n+2; i++)
    {
        for(int j=1; j<n-i+3; j++)
        {
            int l=i+j-1;
            ans[j][l]=0;
            for(int k=j; k<l; k++)
            {
                ans[j][l]=max(ans[j][l],ans[j][k]+ans[k+1][l]+(a[j-1]*a[k]*a[l]));
            }
        }
    }

    return ans[1][n+1];
}