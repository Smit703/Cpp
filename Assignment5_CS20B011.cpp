//SMIT BAGUL
//CS20B011
#include <iostream>
using namespace std;

class Node
{
  public:
  int value;
  Node* next;

  Node() 
  {
    value = 0;
    next = NULL;
  }
  Node(int c) 
  {
    value = c;
    next = NULL;
  }
};

class Stack
{
  private:
  int Stack_size;
  Node *head;
  Node *tail;

  public:
  Stack()
  {
    Stack_size=0;
    head= NULL;
    tail= NULL;
  }

  void push(int value);
  int pop();
  int Top();
  int size();
  bool isEmpty();
};

class Graph
{
  int **Mtrx;
  int vertices;

  public:
  Graph(int n)
  {
    vertices=n;
    Mtrx=new int*[n];
    for(int i=0;i<n;i++)
    {
      Mtrx[i]=new int[n];
      for(int j=0;j<n;j++)
      {
        Mtrx[i][j]=0;
      }
    }
  }

  void operator += (pair<int,int> &addedge)
  {
    Mtrx[addedge.first][addedge.second]=1;
    Mtrx[addedge.second][addedge.first]=1;
  }
  void operator -= (pair<int,int> &removeedge)
  {
    Mtrx[removeedge.first][removeedge.second]=0;
    Mtrx[removeedge.second][removeedge.first]=0;
  }

  friend ostream& operator << (ostream &output,Graph &G)
  {
    for(int i=0; i<G.vertices; i++)
    {
      for(int j=0;j<G.vertices; j++)
      {
        output<<G.Mtrx[i][j]<<" ";
      }
      output<<"\n";
    }
    return output;
  }

  int detectcycle();
  bool iscyclic(int vertex, int parent, bool* visited);
  int reach(int,int);
};

void Stack::push(int value)
{
  Stack_size++;
  Node *newnode= new Node(value);

  if(head == NULL && tail == NULL) 
  {
    head = newnode;
    tail = newnode;
  }
  else 
  {
    newnode->next = head;
    head = newnode;
  }
}

int Stack::pop()
{
  if(Stack_size==0)
  {
    return -1;
  }
  Stack_size--;
  Node *temp=head;
  int ret=temp->value;

  if(Stack_size==0)
  {
    head=NULL;
    tail=NULL;
  }
  else
  {
    head=head->next;
    delete temp;
  }
  return ret;
}

int Stack::Top()
{
  if(Stack_size==0)
  {
    return -1;
  }
  int temp=pop();
  push(temp);
  return temp;
}

int Stack::size()
{
  return Stack_size;
}

bool Stack::isEmpty()
{
  if(Stack_size==0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


int Graph::detectcycle()
{
  bool visited[vertices];
  for(int i=0;i<vertices;i++)
  {
    visited[i]=false;
  }

  for(int i=0;i<vertices;i++)
  {
    if(visited[i]==false)
    {
      if(iscyclic(i,-1,visited)==true)
      {
        return 1;
      }
    }  
  }
  return 0;
}

bool Graph::iscyclic(int vertex,int parent, bool* visited)
{
  visited[vertex]=true;

  for(int i=0;i<vertices;i++)
  {
    if(Mtrx[vertex][i]==1)
    {
      if(visited[i]==false)
      {
        if(iscyclic(i,vertex,visited)==true)
        {
          return true;
        }
      }
      else if(i!=parent)
      {
        return true;
      }
    }
  }
  return false;
}

int Graph::reach(int u,int v)
{
  bool visited[vertices];
  for(int i=0;i<vertices;i++)
  {
    visited[i]=false;
  }

  Stack S;
  S.push(u);
  while(S.isEmpty()==false)
  {
    int temp=S.pop();
    for(int i=0;i<vertices;i++)
    {
      if(Mtrx[temp][i]==1)
      {
        if(visited[i]==false)
        {
          S.push(i);
        }
      }
    }
    visited[temp]=true;
    if(temp==v)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  Stack S;
  int Q;
  cin>>Q;
  while(Q--)
  {
    string str;
    cin>>str;
    if(str=="push")
    {
      int val;
      cin>>val;
      S.push(val);
    }
    
    if(str=="pop")
    {
      int temp=S.pop();
      cout<<temp<<endl;
    } 

    if(str=="top")
    {
      int temp=S.Top();
      cout<<temp<<endl;
    }

    if(str=="empty")
    {
      int temp=S.isEmpty();
      cout<<temp<<endl;
    }
  }

  int n,m;
  cin>>n>>m;
  Graph G(n);

  for(int i=0;i<m;i++)
  {
    string str;
    cin>>str;
    int u,v;
    
    if(str=="add")
    {
      cin>>u>>v;
      pair<int,int> addedge= make_pair(u,v);
      G+=addedge;
    }
    if(str=="del")
    {
      cin>>u>>v;
      pair<int,int> removeedge= make_pair(u,v);
      G-=removeedge;
    }
    if(str=="cycle")
    {
      cout<<G.detectcycle()<<endl;
    }
    if(str=="print")
    {
      cout<<G;
    }
    if(str=="reach")
    {
      cin>>u>>v;
      cout<<G.reach(u,v)<<endl;
    }
  }
}