//Smit Bagul
//CS20B011

#include <bits/stdc++.h>
using namespace std;

class Knapsack
{
    vector <int> K;
    int n;

    public:
    Knapsack(int N)
    {
        n=N;
    }
    virtual int Unbounded_knapsack(int,int,vector<int>,vector<int>) = 0;

};

class Derived: public Knapsack
{
    int W;
    vector <int> revenue;
    vector <int> weight;

    public:
    Derived(int N, int w, vector<int> rev, vector<int> wght): Knapsack(N)
    {
        W=w;
        revenue=rev;
        weight=wght;
    }
    int Unbounded_knapsack(int W,int n, vector<int> revenue, vector<int> weight);

};

int Derived::Unbounded_knapsack(int W, int n, vector<int> revenue,vector<int> weight)
{
    int K[W+1];
    K[0]=0;
    for(int i=1;i<=W;i++)
    {
        K[i]=0;
        for(int j=0;j<n;j++)
        {
            if(weight[j]<=i)
            {
                K[i]=max(K[i],K[i-weight[j]]+revenue[j]);
            }
        }
    }
    return K[W];
}

int main()
{
    int W;
    cin>>W;

    int n;
    cin>>n;

    vector<int> revenue(n);
    for(int i=0;i<n;i++)
    {
        cin>>revenue[i];
    }

    vector<int> weight(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }

    Derived D(W, n, revenue, weight);

    int ans=D.Unbounded_knapsack(W, n, revenue, weight);

    cout<<ans<<endl;
}
