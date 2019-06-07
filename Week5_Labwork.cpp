//
//  main.cpp
//  Labwork
//
//  Created by Harry on 2019/6/6.
//  Copyright © 2019 Harry. All rights reserved.
//
#include<iostream>
using namespace std;

class SmartArray
{
private:
    int *A;
    int size;
public:
    SmartArray();
    ~SmartArray();
    SmartArray(const int *A, const int &size);
    SmartArray(const SmartArray &L);
    int getSize() const;
    int & operator [](const int &index) const;
    void append(const int &e);
    friend ostream &operator<<(ostream &out, const SmartArray &L);
    SmartArray &operator=(const SmartArray &L);
    SmartArray operator+(const SmartArray &L);
    bool operator==(const SmartArray &L);
    bool operator!=(const SmartArray &L);
    SmartArray &operator++();
    SmartArray operator++(int D);
    SmartArray &operator--();
    SmartArray operator--(int D);
    SmartArray operator-();
    SmartArray operator-( SmartArray &L);
    int findElement(int e);
    bool remove(int e);
    void removeAll(int e);
};
void Q14()
{
    int a=15,b=25;
    int count=b-a+1;
    int n=rand()%count+a;
    SmartArray ans;
    a=-15;b=15;count=b-a+1;
    for (int i=0; i<n; i++) {
        ans.append(rand()%count+a);
    }
    int max=ans[0],min=ans[0];
    for (int i=0; i<ans.getSize(); i++) {
        if(max<ans[i])
            max=ans[i];
        if (min>ans[i]) {
            min=ans[i];
        }
    }
    cout<<"The max element is "<<max<<endl<<"The min element is "<<min<<endl;
}
void Q15()
{
    int a=15,b=25;
    int count=b-a+1;
    int n=rand()%count+a;
    SmartArray ans;
    for (int i=0; i<n; i++) {
        cout<<"Enter a number";
        int input;
        cin>>input;
        ans.append(input);
    }
    int max=ans[0],min=ans[0];
    for (int i=0; i<ans.getSize(); i++) {
        if(max<ans[i])
            max=ans[i];
        if (min>ans[i]) {
            min=ans[i];
        }
    }
    cout<<"The max element is "<<max<<endl<<"The min element is "<<min<<endl;
}
bool isPrime(int num)
{
    for (int i=2; i<num; i++) {
        if(num%i==0)
            return false;
    }
    return true;
}
void Q16()
{
    int a=15,b=25;
    int count=b-a+1;
    int n=rand()%count+a;
    SmartArray ans;
    a=5;b=25;count=b-a+1;
    for (int i=0; i<n; i++) {
        ans.append(rand()%count+a);
    }
    for (int i=0; i<ans.getSize(); i++) {
        if (isPrime(ans[i])) {
            cout<<ans[i]<<",";
        }
    }
    cout<<endl;
}
SmartArray SmartArray::operator-( SmartArray &L)
{
    SmartArray ans;
    for (int i=0; i<this->getSize(); i++) {
        if(L.findElement(A[i])==-1&&ans.findElement(A[i])==-1)
                ans.append(A[i]);
    }
    for (int i=0; i<L.getSize(); i++) {
        if(this->findElement(L[i])==-1&&ans.findElement(L[i])==-1)
            ans.append(L[i]);
    }
    return ans;
}
SmartArray SmartArray::operator-()
{
    SmartArray temp=*this;
    for (int i=0; i<this->getSize(); i++) {
        temp[i]*=-1;
    }
    return temp;
}
SmartArray SmartArray::operator--(int D)
{
    SmartArray temp=*this;
    for (int i=0; i<this->getSize(); i++) {
        A[i]--;
    }
    return temp;
}

SmartArray& SmartArray::operator--()
{
    for (int i=0; i<this->getSize(); i++) {
        A[i]--;
    }
    return *this;
}

SmartArray SmartArray::operator++(int D)
{
    SmartArray temp=*this;
    for (int i=0; i<this->getSize(); i++) {
        A[i]++;
    }
    return temp;
}

SmartArray& SmartArray::operator++()
{
    for (int i=0; i<this->getSize(); i++) {
        A[i]++;
    }
    return *this;
}

bool SmartArray::operator !=(const SmartArray &L)
{
    if (*this==L) {
        return false;
    }
    return true;
}
bool SmartArray::operator ==(const SmartArray &L)
{
    if (this->getSize()!=L.getSize()) {
        return false;
    }
    for (int i=0; i<this->getSize(); i++) {
        if(this->A[i]!=L[i])
            return false;
    }
    return true;
}
SmartArray SmartArray::operator +(const SmartArray &L)
{
    SmartArray ans=*this;
    for (int i=0; i<L.getSize(); i++) {
        ans.append(L.A[i]);
    }
    return ans;
}
int SmartArray::findElement(int e)
{
    for (int i = 0; i < size; i++)
        if (A[i] == e)
            return i;
    return -1;
}
bool SmartArray::remove(int e)
{
    int index = findElement (e);
    if (index != -1)
    {
        int *B = new int[size-1];
        for (int i = 0; i < index; i++)
            B[i] = A[i];
        for (int i = index+1; i < size; i++)
            B[i-1] = A[i];
        if(size>0)
            delete [] A;
        size--;
        A = B;
        return true;
    }
    else
    {
        return false;
    }
}
void SmartArray::removeAll(int e)
{
    if(remove(e))
        remove(e);
}
SmartArray::SmartArray(){this->size=0;}
SmartArray ::~ SmartArray()
{
    if (this->getSize() > 0)
    {
        delete[] this->A;
        this->size= 0;
    }
}

SmartArray::SmartArray(const int *A, const int &size)
{
    this->size=size;
    if(this->getSize()>0)
    {
        this->A=new int [this->getSize()];
        for(int i=0;i<size;i++)
        {
            this->A[i]=A[i];
        }
    }
}
SmartArray::SmartArray(const SmartArray &L)
{
    this->size=L.getSize();
    if(this->getSize()>0)
    {
        this->A=new int [this->getSize()];
        for(int i=0;i<size;i++)
        {
            this->A[i]=L[i];
        }
    }
}
int SmartArray::getSize() const{return this->size;}
int &SmartArray::operator[](const int &index) const
{
    if(index>=0&&index<this->getSize())
        return this->A[index];
    return this->A[index];
}
SmartArray &SmartArray::operator =(const SmartArray &L)
{
    if(this==&L)
        return *this;
    this->~SmartArray();
    int size=L.getSize();
    this->size=size;
    if(size>0)
    {
        this->A=new int[size+1];
        for(int i=0;i<size;i++)
        {
            this->A[i]=L[i];
        }
        A[size]=5;
    }
    return *this;
}
void SmartArray::append(const int &e)
{
    int *temp=new int [this->getSize()+1];
    for(int i=0;i<this->getSize();i++)
        temp[i]=this->A[i];
    temp[this->getSize()]=e;
    if(this->getSize()>0)
        delete[] this->A;
    this->A=temp;
    this->size+=1;
}
ostream &operator<<(ostream &out, const SmartArray &L)
{
    out<<"[";
    int i=0;
    for(i=0;i<L.getSize()-1;i++)
    out<<L[i]<<", ";
    if(L.getSize()>0)
    out<<L[i];
    out<<"]";
    return out;
    }
int main()
{
    SmartArray L1;

    L1.append(3);
    L1.append(9);
    L1.append(5);
    L1.append(8);
    L1.append(9);
    cout<<"Default SmartArray: "<<L1<<endl;
    int *x=new int [6];
    x[0]=5;x[1]=1;x[2]=3;x[3]=2;x[4]=4;x[5]=2;
    SmartArray L2(x,6);
    cout<<"Non-Default SmartArray: "<<L2<<endl;
    
    cout<<"Printing the SmartArray L2 elements: ";
    for(int i=0;i<L2.getSize();i++)
        cout<<L2[i]<<" ";
    cout<<endl;
    //L2.removeAll(2);
    //L2=L1+L2;
    L2=L2-L1;
    cout<<"Printing the SmartArray L2 elements: ";
    for(int i=0;i<L2.getSize();i++)
        cout<<L2[i]<<" ";
    cout<<endl;
    system("Pause");
    return 0;
}
