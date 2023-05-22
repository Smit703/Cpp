#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    private:
    int rows;
    int columns;
    int** mat;

    public:
    Matrix() 
    {
      rows=0;
      columns=0;
      mat=NULL;
    }

    Matrix(int r, int c)
    {
      rows=r;
      columns=c;
      mat=new int*[rows];
      for(int i=0;i<rows;i++)
      {
        mat[i]=new int[columns];
        for(int j=0;j<columns;j++)
        {
          mat[i][j]=0;
        }
      }
    }

    Matrix(int r, int c, int** matrix)
    {
      rows=r;
      columns=c;
      mat=new int*[rows];
      for(int i=0;i<rows;i++)
      {
        mat[i]=new int[columns];
        for(int j=0;j<columns;j++)
        {
          mat[i][j]=matrix[i][j];
        }
      }
    }

    void setValue(int, int, int);
    int getValue(int row,int col);
    int getNoRows();
    int getNoColumns();

    void printSpiral();
    int trace();
    bool checkTriangular();
    bool UpperTriangular();
    bool LowerTriangular();
    bool isSpecialMatrix();
};

void Matrix::setValue(int row, int col, int val)
{
  mat[row][col]=val;
}

int Matrix::getValue(int row, int col)
{
  return mat[row][col];
}

int Matrix::getNoRows()
{
  return rows;
}

int Matrix::getNoColumns()
{
  return columns;
}


void Matrix::printSpiral()
{
  int i=0;
  int k=0, l=0;
  int r=rows,c=columns;

  while(k<r && l<c)
  {
    for(i=l;i<c;i++)
    {
      std::cout<<getValue(k,i)<<" ";
    }
    k++;
    for(i=k;i<r;i++)
    {
      std::cout<<getValue(i,c-1)<<" ";
    }
    c--;
    if(k<r)
    {
      for(i=c-1;i>=l;i--)
      {
        std::cout<<getValue(r-1,i)<<" ";
      }
      r--;
    }
    if(l<c)
    {
      for(i=r-1;i>=k;i--)
      {
        std::cout<<getValue(i,l)<<" ";
      }
      l++;
    }
  }  
  std::cout<<endl;
}

int Matrix::trace()
{
  int sum=0;
  if(rows==columns)
  {
    for(int i=0;i<rows;i++)
    {
      sum+=mat[i][i];
    }
    return sum;
  }
  else
  {
    return -1;
  }
}

bool Matrix::LowerTriangular()
{
  for(int i=0;i<rows;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(mat[i][j]!=0)
        {
          return false;
        }
      }
    }
  return true;  
}

bool Matrix::UpperTriangular()
{
  for(int i=0;i<rows;i++)
    {
      for(int j=i+1;j<rows;j++)
      {
        if(mat[i][j]!=0)
        {
          return false;
        }
      }
    }
    return true;
}

bool Matrix::checkTriangular()
{
  int chk=0;

  if(rows==columns)
  {
    if(rows==1)
    {
      return false;
    }

    if(UpperTriangular()==false && LowerTriangular()==false)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  else
  {
    return false;
  }

}

bool Matrix::isSpecialMatrix()
{
  if(rows==1 && columns==1)
  {
    return true;
  }
   if(rows==1)
  {
    int sum=0;
    for(int i=0;i<columns;i++)
    {
      sum+=mat[0][i];
    }
    if(sum==0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  if(columns==1)
  {
    int sum=0;
    for(int i=0;i<rows;i++)
    {
      sum+=mat[i][0];
    }
    if(sum==0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  int rsum,csum;
  int sum=0;
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<columns;j++)
    {
      sum+=mat[i][j];
    }
    
    if(i==0)
    {
      rsum=sum;
    }
    else
    {
      if(rsum!=sum)
      return false;
    }
    sum=0;
  }

  for(int i=0;i<columns;i++)
  {
    for(int j=0;j<rows;j++)
    {
      sum+=mat[j][i];
    }
    if(i==0)
    {
      csum=sum;
    }
    else
    {
      if(csum!=sum)
      return false;
    }

    sum=0;
  }

  if(rsum!=csum)
  {
    return false;
  }

  return true;
}

int main() {  

    int N, M;
    std::cin>>N>>M;

    Matrix mtx(N,M);
    int val;
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        std::cin>>val;
        mtx.setValue(i,j,val);
      }
    }
    
    int Q;
    std::cin>>Q;
    
    for(int i=0;i<Q;i++)
    {
      int opcode,temp;
      std::cin>>opcode;

      switch (opcode)
      {
        case 1: mtx.printSpiral();
              break;

        case 2: temp=mtx.trace();
              std::cout<<temp<<std::endl;
              break;

        case 3: if(mtx.checkTriangular()==true)
              {
                std::cout<<"true"<<std::endl;
              }
              else
              {
                std::cout<<"false"<<std::endl;
              }  
              break;

        case 4: if(mtx.isSpecialMatrix()==true)
              {
                std::cout<<"true"<<std::endl;
              }
              else
              {
                std::cout<<"false"<<std::endl;
              }  
              break;                       
      }  
    }

    return 0;
}