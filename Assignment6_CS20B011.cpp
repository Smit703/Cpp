#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Trie{
    private:
    bool isEnd = false;
    vector<Trie *> next;

    public:
    Trie()
    {
        for(int i=0;i<26;i++)
        {
            next.push_back(NULL);
        }
    }
    void insert(Trie*,string);
    string search(Trie*,string);
};

void Trie::insert(Trie* root,string s)
{
    Trie *ptr=root;
    for(int i=0;i<(int)s.length();i++)
    {
        int alphabet= s[i]-'a';
        if(ptr->next[alphabet]==NULL)
        {
            Trie *newTrie= new Trie();
            ptr->next[alphabet]=newTrie;
        }
        ptr=ptr->next[alphabet];
    }
    ptr->isEnd=true;
}

string Trie::search(Trie *root,string s)
{
    Trie *ptr=root;
    string output="";
    for(long unsigned int i=0;i<s.length();i++)
    {
        int alphabet=s[i]-'a';
        if(ptr->next[alphabet]==NULL)
        {
            break;
        }
        if((ptr->next[alphabet])->isEnd==true)
        {
            output=s.substr(0,i+1);
        }
        ptr=ptr->next[alphabet];
    }
    return output;
}

int main() 
{
    int p;
    cin>>p;

    Trie *root=new Trie();
    for(int i=0;i<p;i++)
    {
        string prefix;
        cin>>prefix;
        root->insert(root,prefix);
    }

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string word;
        cin>>word;
        string s = root->search(root,word);
        if(s=="")
        {
            cout<<word<<" ";
        }
        else
        {
            cout<<s<<" ";
        }
    }

    return 0;
}