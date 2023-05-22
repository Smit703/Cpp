//SMIT BAGUL
//CS20B011
#include <iostream>
using namespace std;

template <typename T>
class Node
{
  public:
  T value;
  Node* next;

  Node() 
  {
    value = 0;
    next = NULL;
  }
  Node(T c) 
  {
    value = c;
    next = NULL;
  }
};

template <typename T>
class Queue
{
  private:
  int Queue_size;
  Node<T> *head;
  Node<T> *tail;

  public:
  Queue()
  {
    Queue_size=0;
    head= NULL;
    tail= NULL;
  }

  void enqueue(T value);
  T dequeue();
  int size();
  bool isEmpty();
};

template <typename T>
class Printer
{
  private:
  Queue<T> Q;
  int capacity;
  int ink;

  public:
  Printer(int M,int N)
  {
    capacity=M;
    ink=N;
  }
  void addDocument(T Document);
  T printDocument();
  void fillink(int newink);

  class InsufficientInk
  {
    public:
    string str;
    InsufficientInk(string reason)
    {
      str=reason;
    }
  };

  class PrinterBusy
  {
    public:
    string str;
    PrinterBusy(string reason)
    {
      str=reason;
    }
  };

  class NoDocument
  {
    public:
    string str;
    NoDocument(string reason)
    {
      str=reason;
    }
  };
};

template <typename T>
void Queue<T>::enqueue(T value)
{
  Queue_size++;
  Node<T> *newnode = new Node<T>(value);

  if(head == NULL && tail == NULL) 
  {
    head = newnode;
    tail = newnode;
  }
  else 
  {
    tail->next = newnode;
    tail = newnode;
  }
}

template <typename T>
T Queue<T> :: dequeue()
{
  Queue_size--;
  Node<T> *temp=head;
  T ret=temp->value;

  if(Queue_size==0)
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

template <typename T>
int Queue<T>:: size()
{
  return Queue_size;
}

template <typename T>
bool Queue<T>::isEmpty()
{
  if(Queue_size==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
void Printer<T>::addDocument(T Document)
{
  if(Q.size()>capacity)
  {
    throw PrinterBusy("PRINTER_BUSY");
  }
  capacity--;
  Q.enqueue(Document);
}

template <typename T>
T Printer<T>::printDocument()
{
  if(Q.isEmpty()==true)
  {
    throw NoDocument("NO_DOCUMENT");
  }
  if(ink==0)
  {
    throw InsufficientInk("INSUFFICIENT_INK");
  }
  ink--;
  T doc=Q.dequeue();
  return doc;
}

template <typename T>
void Printer<T>::fillink(int newink)
{
  ink=newink;
}

int main() 
{
  int M,N;
  char T;
  cin>>M>>N>>T;                     //M=capacity, N=ink

  int Q;
  cin>>Q;

  int opcode;
  int newink;

  if(T=='I')
  {
    int doc;
    Printer <int> Pi(M,N);

    while(Q--)
    {
      cin>>opcode; 

      try
      {
        switch(opcode)
        {
          case 1:   cin>>doc;
                    Pi.addDocument(doc);
                    break;

          case 2:   cout<<Pi.printDocument()<<endl;
                    break;

          case 3:   cin>>newink;
                    Pi.fillink(newink);
                    break;
        }
      }
      catch(Printer<int>::PrinterBusy Pi)
      {
        cout<<Pi.str<<endl;
      }
      catch(Printer<int>::InsufficientInk Pi)
      {
        cout<<Pi.str<<endl;
      }
      catch(Printer<int>::NoDocument Pi)
      {
        cout<<Pi.str<<endl;
      }
    }
  }
      
  if(T=='C')
  {
    char doc;
    Printer <char> Pc(M,N);

    while(Q--)
    {
      cin>>opcode; 

      try
      {
        switch(opcode)
        {
          case 1:   cin>>doc;
                    Pc.addDocument(doc);
                    break;

          case 2:   cout<<Pc.printDocument()<<endl;
                    break;

          case 3:   cin>>newink;
                    Pc.fillink(newink);
                    break;
        }
      }
      catch(Printer<char>::PrinterBusy Pc)
      {
        cout<<Pc.str<<endl;
      }
      catch(Printer<char>::InsufficientInk Pc)
      {
        cout<<Pc.str<<endl;
      }
      catch(Printer<char>::NoDocument Pc)
      {
        cout<<Pc.str<<endl;
      }
    }  
  }

  if(T=='F')
  {
    float doc;
    Printer <float> Pf(M,N);

    while(Q--)
    {
      cin>>opcode; 

      try
      {
        switch(opcode)
        {
          case 1:   cin>>doc;
                    Pf.addDocument(doc);
                    break;

          case 2:   cout<<Pf.printDocument()<<endl;
                    break;

          case 3:   cin>>newink;
                    Pf.fillink(newink);
                    break;
        }
      }
      catch(Printer<float>::PrinterBusy Pf)
      {
        cout<<Pf.str<<endl;
      }
      catch(Printer<float>::InsufficientInk Pf)
      {
        cout<<Pf.str<<endl;
      }
      catch(Printer<float>::NoDocument Pf)
      {
        cout<<Pf.str<<endl;
      } 
    }
  }  
  
  return 0;
}