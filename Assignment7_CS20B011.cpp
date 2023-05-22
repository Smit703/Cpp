//SMIT BAGUL
//CS20B011
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
using namespace std;

class Dictionary
{
    private:
    map<int,set<string>>  dict;

    public:
    void builddict(vector<string> words);
    void addwordstodict(string word);
    bool search(string target);
    set<string> getwordsafterreplace(string target);
    set<string> getwordsafterswap(string target);
    int maxChangeableword();
    int maxswappableword();
};

void Dictionary::builddict(vector<string> words)
{
    for(auto itr : words)
    {
        string word=itr;
        addwordstodict(word);
    }
}

void Dictionary::addwordstodict(string word)
{
    if(dict.find(word.length())==dict.end())
    {
        pair<int,set<string>> p;
        p.first=word.length();
        p.second.insert(word);
        dict.insert(p);
    }
    else
    {
        dict[word.length()].insert(word);
    }
}

bool Dictionary::search(string target)
{
    if(dict.find(target.length())==dict.end())
    {
        return false;
    }

    set<string> :: iterator it;

    it=dict[target.length()].find(target);

    if(it==dict[target.length()].end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

set<string> Dictionary::getwordsafterreplace(string target)
{
    set<string> S;
    int temp;

    if(dict.find(target.length())!=dict.end())
    {
        for(auto itr: dict[target.length()])
        {
            temp=0;
            for(long unsigned int i=0;i<target.length();i++)
            {
                if(itr[i]!=target[i])
                {
                    temp++;
                }
            }
            if(temp<=1)
            {
                S.insert(itr);
            }
        }
    }

    return S;
}

set<string> Dictionary::getwordsafterswap(string target)
{
    set<string> S;
    string str;

    if(dict.find(target.length())!=dict.end())
    {
        for(long unsigned int i=0;i<target.length()-1;i++)
        {
            str=target;
            swap(str[i],str[i+1]);
            if(search(str)==true)
            {
                S.insert(str);
            }
        }
    }

    return S;
}

int Dictionary::maxChangeableword()
{
    long unsigned int max = 0;
    set<string> S;
    for(int i = 1; i < 11; i++)                                         //max wordlength=10
    {
        for(auto iter = dict[i].begin(); iter != dict[i].end(); iter++)
        {
            S = getwordsafterreplace(*iter);
            if(S.size() > max)
            {
                max=S.size();
            }
        }
    }
    return max-1;
}

int Dictionary::maxswappableword()
{
    long unsigned int max = 0;
    set<string> S;
    for(int i = 1; i < 11; i++)                                       
    {
        for(auto iter = dict[i].begin(); iter != dict[i].end(); iter++)
        {
            S = getwordsafterswap(*iter);
            if(S.size() > max)
            {
                max=S.size();
            }
        }
    }
    return max;
}

int main()
{
    Dictionary D;

    int N;
    cin>>N;

    vector<string> words;
    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        words.push_back(s);
    }
    D.builddict(words);

    int Q;
    cin>>Q;

    for(int i=0;i<Q;i++)
    {
        int opcode;
        cin>>opcode;
        string word;
        set<string> S;
        int temp;

        switch(opcode)
        {
            case 1:cin>>word;
                   D.addwordstodict(word);
                   break;

            case 2:cin>>word;
                   if(D.search(word)==true)
                   {
                       cout<<"true"<<endl;
                   }
                   else
                   {
                       cout<<"false"<<endl;
                   }
                   break;

            case 3:cin>>word;
                   S=D.getwordsafterreplace(word);
                   if(S.empty()==true)
                   {
                       cout<<"-1"<<endl;
                   }
                   else
                   {
                       for(auto it=S.begin();it!=S.end();it++)
                       {
                           cout<<*it<<" ";
                       }
                       cout<<"\n";
                   }
                   break;

            case 4:cin>>word;
                   S=D.getwordsafterswap(word);
                   if(S.empty()==true)
                   {
                       cout<<"-1"<<endl;
                   }
                   else
                   {
                       for(auto it=S.begin();it!=S.end();it++)
                       {
                           cout<<*it<<" ";
                       }
                       cout<<"\n";
                   }
                   break;

            case 5:temp=D.maxChangeableword();
                   cout<<temp<<endl;
                   break;

            case 6:temp=D.maxswappableword();
                   cout<<temp<<endl;
                   break;
        }
    }

    return 0;
}