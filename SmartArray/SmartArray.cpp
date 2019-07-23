#include "SmartArray.h"

template <class T>
SmartArray<T>::SmartArray(void)
{
	this->size=0;
}

template <class T>
SmartArray<T>::~SmartArray(void)
{
	if(this->getSize()>0)
	{
		delete[] this->A;
		this->size=0;
	}
}
template <class T>
SmartArray<T>::SmartArray(const T *A, const int &size)
{
    this->size=size;
    if(this->getSize()>0)
    {
        this->A=new T [this->getSize()];
        for(int i=0;i<size;i++)
        {
            this->A[i]=A[i];
        }
    }
}
template <class T>
SmartArray<T>::SmartArray(const SmartArray<T> &L)
{
    this->size=L.getSize();
    if(this->getSize()>0)
    {
        this->A=new T [this->getSize()];
        for(int i=0;i<size;i++)
        {
            this->A[i]=L[i];
        }
    }
}
template <class T>
int SmartArray<T>::getSize() const{return this->size;}
template <class T>
T &SmartArray<T>::operator[](const int &index) const
{
    if(index>=0&&index<this->getSize())
        return this->A[index];
    return this->A[index];
}
template <class T>
SmartArray<T> &SmartArray<T>::operator =(const SmartArray<T> &L)
{
    if(this==&L)
        return *this;
    this->~SmartArray();
    int size=L.getSize();
    this->size=size;
    if(size>0)
    {
        this->A=new T[size+1];
        for(int i=0;i<size;i++)
        {
            this->A[i]=L[i];
        }
        A[size]=5;
    }
    return *this;
}
template <class T>
int SmartArray<T>::findElement(const T &e) const
{
    for (int i = 0; i < size; i++)
        if (A[i] == e)
            return i;
    return -1;
}
template <class T>
void SmartArray<T>::append(const T &e)
{
    T *temp=new T [this->getSize()+1];
    for(int i=0;i<this->getSize();i++)
        temp[i]=this->A[i];
    temp[this->getSize()]=e;
    if(this->getSize()>0)
        delete[] this->A;
    this->A=temp;
    this->size+=1;
}
template <class T>
bool SmartArray<T>::remove(const T &e)
{
    int index = findElement (e);
    if (index != -1)
    {
        T *B = new T[size-1];
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
template <class T>
SmartArray<T> SmartArray<T>::operator-( SmartArray<T> &L)
{
    SmartArray<T> ans;
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
template <class T>
ostream &operator<<(ostream &out, const SmartArray<T> &L)
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
