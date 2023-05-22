//Smit Bagul
//CS20B011
#include <bits/stdc++.h>
using namespace std;

#define max_level 10

template <typename T>
class Node
{
   public:
   T key;
   T value;
   Node *next;
   Node *prev;
   Node *up;
   Node *down;

   Node(T k, T v)
   {
      key=k;
      value=v;
      next=NULL;
      prev=NULL;
      up=NULL;
      down=NULL;
   }
};

template <typename T>
class SkipList
{
   private:
   int size;
   int level;
   T min;
   T max;
   Node<T> *head;
   Node<T> *tail;

   public:
   void SkipList_constructor(T min,T max)
   {
      size=0;
      head=new Node<T>(min,min);
      tail=new Node<T>(max,max);
      head->next=tail;
      tail->prev=head;
      for(int i=1;i<max_level;i++)
      {
         Node<T> *htemp= new Node<T>(min,min);
         Node<T> *ttemp= new Node<T>(max,max);

         htemp->next=ttemp;
         ttemp->prev=htemp;

         head->up=htemp;
         htemp->down=head;
         head=htemp;

         tail->up=ttemp;
         ttemp->down=tail;
         tail=ttemp;
      }
   }

   void insert(T k,T v);
   void delet(T k);
   Node<T>* search(T k);
   int get_size();
};

template <typename T>
class dict : private SkipList<T>
{
   public:
   dict(T max,T min)
   {
      SkipList<T> :: SkipList_constructor(max,min);
   }
   void isempty();
   void dict_insert(T k,T v);
   void dict_delet(T k);
   void find(T k);
   void size();
};

int main()
{
   srand(time(0));

   string s;
   cin>>s;

   int p;
   cin>>p;

   if(s=="INTEGERDICT")
   {
      dict<int> D(INT_MIN,INT_MAX);
      while(p)
      {
         string str;
         cin>>str;
         int k,v;

         if(str=="ISEMPTY")
         {
            D.isempty();  
         }
         if(str=="INSERT")
         {
            cin>>k>>v;
            D.dict_insert(k,v);
         }
         if(str=="DELETE")
         {
            cin>>k;
            D.dict_delet(k);
         }
         if(str=="FIND")
         {
            cin>>k;
            D.find(k);
         }
         if(str=="SIZE")
         {
            D.size();
         }
         p--;
      }
   }
   else
   {
      dict<string> D("A","{");
      while(p)
      {
         string str;
         cin>>str;
         string k,v;

         if(str=="ISEMPTY")
         {
            D.isempty();  
         }
         if(str=="INSERT")
         {
            cin>>k>>v;
            D.dict_insert(k,v);
         }
         if(str=="DELETE")
         {
            cin>>k;
            D.dict_delet(k);
         }
         if(str=="FIND")
         {
            cin>>k;
            D.find(k);
         }
         if(str=="SIZE")
         {
            D.size();
         }
         p--;
      }
   }

   return 0;
}

template <typename T>
Node<T>* SkipList<T>::search(T k)
{
   Node<T>* ptr = head;
   while(ptr->down)
   {
      ptr=ptr->down;
      while(k>=(ptr->next)->key)
      {
         ptr=ptr->next;
      }
   }
   return ptr;
}

template <typename T>
void SkipList<T>::insert(T k,T v)
{
   size++;
   level=0;
   Node<T> *ptr= search(k);
   if(ptr->key==k)
   {
      size--;
      return;
   }
   
   Node<T>* q=NULL;
   Node<T>* newnode= new Node<T>(k,v);

   newnode->next=ptr->next;
   newnode->prev=ptr;
   (ptr->next)->prev=newnode;
   ptr->next=newnode;

   q=newnode;

   while(((int)rand())%2 && level<(max_level-1))
   {
      level++;
      while(ptr->up==NULL)
      {
         ptr=ptr->prev;
      }
      ptr=ptr->up;

      Node<T>* newtemp= new Node<T> (k,v);
      q->up=newtemp;
      newtemp->down=q;

      newtemp->next=ptr->next;
      newtemp->prev=ptr;
      (ptr->next)->prev=newtemp;
      ptr->next=newtemp;

      q=newtemp;
   }
}

template <typename T>
void SkipList<T>::delet(T k)
{
   size--;
   Node<T> *ptr= search(k);
   if(ptr->key!=k)
   {
      size++;
      return;
   }

   while(ptr!=NULL)
   {
      Node<T> *q=ptr;
      ptr=ptr->up;

      (q->prev)->next=q->next;
      (q->next)->prev=q->prev;
      delete q;
   }
}

template <typename T>
int SkipList<T>::get_size()
{
   return size;
}

template <typename T>
void dict<T>::isempty()
{
   if(this->get_size()==0)
   {
      cout<<"True"<<endl;
   }
   else
   {
      cout<<"False"<<endl;
   }
}

template <typename T>
void dict<T>::dict_insert(T k,T v)
{
   this->insert(k,v);
}

template <typename T>
void dict<T>::dict_delet(T k)
{
   this->delet(k);
}

template <typename T>
void dict<T>::find(T k)
{
   Node<T> *temp= this->search(k);
   if((temp->key)!=k)
   {
      cout<<"NOT FOUND"<<endl;
   }
   else
   {
      cout<<temp->value<<endl;
   }
   
}

template <typename T>
void dict<T>::size()
{
   cout<<this->get_size()<<endl;
}