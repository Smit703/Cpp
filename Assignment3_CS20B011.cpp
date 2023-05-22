//SMIT BAGUL
//CS20B011
#include <iostream>
using namespace std;

template <typename T>
class Node
{
  public:
  T value;
  Node* prev;
  Node* next;

  Node() 
  {
    value = 0;
    prev = NULL;
    next = NULL;
  }
  Node(T c) 
  {
    value = c;
    prev = NULL;
    next = NULL;
  }
};

template <typename T>
class DLL
{
  private:
  int DLL_size;
  Node<T> *head;
  Node<T> *tail;

  public:
  DLL()
  {
    DLL_size=0;
    head=NULL;
    tail=NULL;
  }

  void push_front(T value);
  void push_end(T value);
  T pop_front();
  T pop_end();
  int size();
};

template <typename T>
class Stack
{
  private:
  DLL<T> S;
  
  public:
  void push(T value);
  T pop();
  T top();
  int Ssize();
  bool compare(T n);
};

template <typename T>
void DLL<T>::push_front(T value)
{
  DLL_size++;
  Node<T> *newnode= new Node<T>(value);

  if(head == NULL && tail == NULL) 
  {
    head = newnode;
    tail = newnode;
  }
  else 
  {
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
  }
}

template <typename T>
void DLL<T>::push_end(T value)
{
  DLL_size++;
  Node<T> *newnode= new Node<T>(value);

  if(head == NULL && tail == NULL) 
  {
    head = newnode;
    tail = newnode;
  }
  else 
  {
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
  }
}

template <typename T>
T DLL<T>::pop_front()
{
  DLL_size--;
  Node<T> *temp=head;
  T ret=temp->value;

  if(DLL_size==0)
  {
    head=NULL;
    tail=NULL;
  }
  else
  {
    head=head->next;
    head->prev=NULL;
    
    delete temp;
  }
  return ret;
}

template <typename T>
T DLL<T>::pop_end()
{
  DLL_size--;
  Node<T> *temp=tail;
  T ret=temp->value;
  
  if(DLL_size==0)
  {
    head=NULL;
    tail=NULL;
  }
  else
  {
    tail=tail->prev;
    tail->next=NULL;
    delete temp;
  }
  return ret;
}

template <typename T>
int DLL<T>::size()
{
  return DLL_size;
}

template <typename T>
void Stack<T>::push(T value)
{
  S.push_front(value);
}

template <typename T>
T Stack<T>::pop()
{
  T ret=S.pop_front();
  return ret;
}

template <typename T>
T Stack<T>::top()
{
  T ret=S.pop_front();
  S.push_front(ret);
  return ret;
}

template <typename T>
int Stack<T>::Ssize()
{
  return S.size();
}

template <typename T>
bool Stack<T>::compare(T n)
{
  if(n>top())
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
void encrypt(int N, T arr[],Stack <T> Se)
{
  int i=0;
  while(i!=N)
  {
    if(Se.Ssize()==0)
    {
      Se.push(arr[i]);
      i++;
    }
    else
    {
      if(Se.compare(arr[i])==true)
      {
        Se.push(arr[i]);
        i++;
      }
      else
      {
        cout<<Se.top();
        Se.pop();
      }
    }
  }
  while(Se.Ssize()!=0)
  {
    cout<<Se.top();
    Se.pop();
  }
}

int main() 
{
  int N;
  char T;

  cin>>N>>T;
  
  if(T=='I')
  {
    Stack <int> SI;
    int arrI[N];
    for(int i=0;i<N;i++)
    {
      cin>>arrI[i];
    }
    encrypt<int>(N,arrI,SI);
  }

  if(T=='C')
  {
    Stack <char> SC;
    char arrC[N];
    for(int i=0;i<N;i++)
    {
      cin>>arrC[i];
    }
    encrypt<char>(N,arrC,SC);
  }

  if(T=='F')
  {
    Stack <float> SF;
    float arrF[N];
    for(int i=0;i<N;i++)
    {
      cin>>arrF[i];
    }
    encrypt<float>(N,arrF,SF);
  }
  return 0;
}