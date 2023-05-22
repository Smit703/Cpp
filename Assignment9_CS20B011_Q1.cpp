//Smit Bagul
//CS20B011
#include <bits/stdc++.h>
using namespace std;

int dist(string,string);
string LCS(string,string ,int ,int);

int main() 
{
    int n;
    cin>>n;
    vector<string> sentence;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        sentence.push_back(temp);
    }
    
    int d;
    cin>>d;
    vector<string> dictionary;
    for(int i=0;i<d;i++)
    {
        string temp;
        cin>>temp;
        dictionary.push_back(temp);
    }
    
    vector<string> close[n];
    int A[n];

    for(int i=0;i<n;i++)
    {
        close[i].clear();
    }

    for(int i=0;i<n;i++)
    {
        A[i]=sentence[i].size();
        for(int j=0;j<d;j++)
        {
            int D=dist(sentence[i],dictionary[j]);
            if(D<A[i])
            {
                A[i]=D;
                close[i].clear();
                close[i].push_back(dictionary[j]);
            }
            else if(D==A[i])
            {
                close[i].push_back(dictionary[j]);
            }
        }
    }

    vector<string>Long[n];
    int LLCS[n];
    for(int i=0;i<n;i++)
    {
        LLCS[i]=0;
        for(auto it=close[i].begin();it!=close[i].end();it++)
        {
            string lcs=LCS(sentence[i],*it,sentence[i].size(),it->size());
            if(lcs.size()>LLCS[i])
            {
                LLCS[i]=lcs.size();
                Long[i].clear();
                Long[i].push_back(*it);
            }
            else if(lcs.size()==LLCS[i])
            {
                Long[i].push_back(*it);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(auto it=Long[i].begin();it!=Long[i].end();it++)
        {
            cout<<sentence[i]<<endl;

            cout<<*it<<endl;

            string lcs=LCS(sentence[i],*it,sentence[i].size(),it->size());

            cout<<lcs<<endl<<A[i]<<endl;
        }
    }

    return 0;
}

int dist(string s1, string s2)
{
    int m=s1.length();
    int n=s2.length();

    int temp[m+1][n+1];
    for(int i=0; i<m+1; i++)
    {
        temp[i][0]=i;
    }
    for(int i=0; i<n+1; i++)
    {
        temp[0][i]=i;
    }

    for(int i=1; i<m+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                temp[i][j] = temp[i-1][j-1];
            }
            else
            {
                temp[i][j] = 1+min(temp[i][j - 1], min(temp[i - 1][j], temp[i - 1][j - 1]));
            }
        }
    }
    return temp[m][n];
}


string LCS(string s1,string s2, int m,int n)
{
    int LCSuff[m + 1][n + 1];
    int result=0,row,col;
    string lcs;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (s1[i - 1] == s2[j - 1]) 
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if(result<LCSuff[i][j])
                {
                    result=LCSuff[i][j];
                    row=i;
                    col=j;
                }
            }
            else
                LCSuff[i][j] = max(LCSuff[i-1][j],LCSuff[i][j-1]);
        }
    }
    if(result==0)
    {
        return("EMPTY");
    }

    int i=m,j=n;
    while(i>0 && j>0)
    {
        if (s1[i - 1] == s2[j - 1]) 
        {
            string let;
            let.push_back(s1[i - 1]); 
            lcs.insert(0,let);
            i--;
            j--;
        }
        else if (LCSuff[i - 1][j] > LCSuff[i][j - 1])
        {
            i--;
        }    
        else
        {
            j--;
        }    
    }
    return lcs;
}