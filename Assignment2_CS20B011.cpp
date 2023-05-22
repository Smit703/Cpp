//SMIT BAGUL
//CS20B011
#include <iostream>
#include <string>
using namespace std;

class Book
{
  public:
  string title;
  string author;
  int year;
  int price;

  Book()
  {
    title="";
    author="";
    year=0;
    price=0;
  }

  Book(string title,string author, int year, int price)
  {
    this->title=title;
    this->author=author;
    this->year=year;
    this->price=price;
  }

  void print();
};

class Node
{
  public:
  Book Bk;
  Node* next;
  int flag;

  Node()
  {
    next=NULL;
    flag=0;
  }
};

class Bookshelf
{
  Node *BS;
  
  public:
  bool checkempty();
  virtual void addbook(string,string,int,int)=0;
  virtual int removebook()=0;
  virtual void list()=0;
  virtual void findcheap()=0;
  virtual void reverseunique()=0;
};

class HorizontalBookShelf : public Bookshelf  //STACK
{
  Node *HBS_top;
  
  public:
  HorizontalBookShelf()
  {
    HBS_top=NULL;
  }
  
  Node* gettop();
  void addbook(string,string,int,int);
  int removebook();
  void list();
  void findcheap();
  void reverseunique();
};

class VerticalBookShelf : public Bookshelf    //QUEUE
{
  public:
  Node *VBS_top;

  VerticalBookShelf()
  {
    VBS_top=NULL;
  }
  
  Node* gettop();
  void addbook(string,string,int,int);
  int removebook();
  void list();
  void findcheap();
  void reverseunique();
};

void Book::print()
{
  cout<<title<<","<<author<<","<<year<<","<<price<<endl;
}

bool Bookshelf::checkempty()
{
  if(BS==NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Node* HorizontalBookShelf::gettop()
{
  return HBS_top;
}

Node* VerticalBookShelf::gettop()
{
  return VBS_top;
}

void HorizontalBookShelf::addbook(string title,string author,int year,int price)
{
  Book B(title,author,year,price);
  Node *newbook= new Node();
  newbook->Bk=B;
  newbook->next=NULL;

  if(HBS_top==NULL)
  {
    HBS_top=newbook;
  }
  else
  {
    Node *ptr;
    for(ptr=HBS_top;ptr->next!=NULL;ptr=ptr->next)
    {
      if((newbook->Bk).title==(ptr->Bk).title)
      {
        newbook->flag=1;
      }
    }
    if((newbook->Bk).title==(ptr->Bk).title)
    {
      newbook->flag=1;
    }
    ptr->next=newbook;
  }
}

void VerticalBookShelf::addbook(string title,string author,int year,int price)
{
  Book B(title,author,year,price);
  Node *newbook= new Node();
  newbook->Bk=B;

  if(VBS_top!=NULL)
  {
    Node *ptr;
    for(ptr=VBS_top;ptr->next!=NULL;ptr=ptr->next)
    {
      if((newbook->Bk).title==(ptr->Bk).title)
        {
          newbook->flag=1;
        }
    }
    if((newbook->Bk).title==(ptr->Bk).title)
    {
      newbook->flag=1;
    }
  }  

  newbook->next=VBS_top;
  VBS_top=newbook;
}

int HorizontalBookShelf::removebook()
{
  if(HBS_top==NULL)
  {
    cout<<"e";
    return -1;
  }
  Node *remove=HBS_top;
  HBS_top=HBS_top->next;
  delete remove;
  return 1;
}

int VerticalBookShelf::removebook()
{
  if(VBS_top==NULL)
  {
    cout<<"e";
    return -1;
  }
  Node *remove=VBS_top;
  VBS_top=VBS_top->next;
  delete remove;
  return 1;
}

void HorizontalBookShelf::list()
{
  if(HBS_top==NULL)
  {
    cout<<"e"<<endl;
  }
  else
  {
    Node *ptr;
    for(ptr=HBS_top;ptr!=NULL;ptr=ptr->next)
    {
      (ptr->Bk).print();
    }
  }
}

void VerticalBookShelf::list()
{
   if(VBS_top==NULL)
  {
    cout<<"e"<<endl;
  }
  else
  {
    Node *ptr;
    for(ptr=VBS_top;ptr!=NULL;ptr=ptr->next)
    {
      (ptr->Bk).print();
    }
  }
}

void HorizontalBookShelf::findcheap()
{
  if(HBS_top==NULL)
  {
    cout<<"e"<<endl;
  }
  else
  {
    int cheapest=(HBS_top->Bk).price;
    Node *ptr;
    for(ptr=HBS_top;ptr!=NULL;ptr=ptr->next)
    {
      if((ptr->Bk).price<=cheapest)
      {
        cout<<"-1";
        cheapest=(ptr->Bk).price;
      }
      else
      {
        cout<<cheapest; 
      }
      if(ptr->next!=NULL)
      {
        cout<<",";
      }
    }
    cout<<endl;
  }
}

void VerticalBookShelf::findcheap()
{
  if(VBS_top==NULL)
  {
    cout<<"e"<<endl;
  }
  else
  {
    int cheapest=(VBS_top->Bk).price;
    Node *ptr;
    for(ptr=VBS_top;ptr!=NULL;ptr=ptr->next)
    {
      if((ptr->Bk).price<=cheapest)
      {
        cout<<"-1";
        cheapest=(ptr->Bk).price;
      }
      else
      {
        cout<<cheapest; 
      }
      if(ptr->next!=NULL)
      {
        cout<<",";
      }
    }
    cout<<endl;
  }
}

void HorizontalBookShelf::reverseunique()
{
  VerticalBookShelf temp;

  while(HBS_top)
  {
    if(HBS_top->flag!=1)
    {
      temp.addbook((HBS_top->Bk).title ,(HBS_top->Bk).author ,(HBS_top->Bk).year ,(HBS_top->Bk).price);
    }
    Node *remove=HBS_top;
    HBS_top=HBS_top->next;
    delete remove;
  }

  Node *ptr;
  for(ptr=temp.gettop();ptr!=NULL;ptr=ptr->next)
  {
    this->addbook((ptr->Bk).title ,(ptr->Bk).author ,(ptr->Bk).year ,(ptr->Bk).price);
  }
}

void VerticalBookShelf::reverseunique()
{
  HorizontalBookShelf temp;

  while(VBS_top)
  {
    if(VBS_top->flag!=1)
    {
      temp.addbook((VBS_top->Bk).title ,(VBS_top->Bk).author ,(VBS_top->Bk).year ,(VBS_top->Bk).price);
    }
    Node *remove=VBS_top;
    VBS_top=VBS_top->next;
    delete remove;
  }

  Node *ptr;
  for(ptr=temp.gettop();ptr!=NULL;ptr=ptr->next)
  {
    this->addbook((ptr->Bk).title ,(ptr->Bk).author ,(ptr->Bk).year ,(ptr->Bk).price);
  }

}

int main() 
{
  int Q;
  cin>>Q;

  HorizontalBookShelf h;
  VerticalBookShelf v;

  while(Q--)
  {
    string s1;
    cin>>s1;

    char bookshelf;

    if(s1=="ADD")
    {
      cin>>bookshelf;

      string title;
      string author;
      int year;
      int price;
      cin>>title>>author>>year>>price;

      if(bookshelf=='h')
      {
        h.addbook(title,author,year,price);
      }
      else
      {
        v.addbook(title,author,year,price);
      }
    }

    if(s1=="REMOVE")
    { 
      int n;
      int empty=1;   //if -1 thn bs is empty
      cin>>n;
      cin>>bookshelf;

      if(bookshelf=='h')
      {
        while(n--)
        {
          empty=h.removebook();
        }
      }
      else
      {
        while(n--)
        {
          empty=v.removebook();
        }
      }
      if(empty==-1)
      {
        cout<<endl;
      }
    }

    if(s1=="LIST")
    {
      cin>>bookshelf;
      if(bookshelf=='h')
      {
        h.list();
      }
      else
      {
        v.list();
      }
    }

    if(s1=="FINDC")
    {
      cin>>bookshelf;
      if(bookshelf=='h')
      {
        h.findcheap();
      }
      else
      {
        v.findcheap();
      }
    }

    if(s1=="REVUNI")
    {
      cin>>bookshelf;
      if(bookshelf=='h')
      {
        h.reverseunique();
      }
      else
      {
        v.reverseunique();
      }
    }
  }
  return 0;
}