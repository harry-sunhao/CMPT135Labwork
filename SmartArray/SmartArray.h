#pragma once
#include<iostream>
#include<string>
using namespace std;
template <class T>
class SmartArray
{
private:
	T *A;
	int size;
public:
	SmartArray(void);

	SmartArray(const T *A, const int &size);
    SmartArray(const SmartArray<T> &L);
	SmartArray<T> &operator=(const SmartArray<T> &L);
    int getSize() const;
    T& operator [](const int &index) const;
    void append(const T &e);
	bool remove(const T &e);
	template <class T>
    friend ostream &operator<<(ostream &out, const SmartArray<T> &L);
    SmartArray<T> operator-( SmartArray<T> &L);
    int findElement(const T &e) const;
	virtual ~SmartArray(void);
};

