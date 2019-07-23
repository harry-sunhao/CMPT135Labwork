#include<ctime>
#include<cstdlib>
#include"SmartArray.h"
#include"SmartArray.cpp"

template<typename T>
int sequentialSearch(const T *A,const int size, const T value)
{
	for(int i=0;i<size;i++)
	{
		if(A[i]==value)
			return i;
	}
	return -1;
}
template <class T1,class T2>
T1 sum_up(const T1 x,const T2 y)
{
	T1 result=x+static_cast<T1>(y);
	return result;
}
void Test()
{
	SmartArray<int> A1;
	double x[3]={2.4,1.2,5.8};
	SmartArray<double> A2(x,3);
	SmartArray<string> A3;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		if(rand()%2==0)
			A1.append(rand()%21+5);
		else
		{
			int random=rand()%5;
			A3.append(random==0?"Paul":(random==1?"Jannet":(random==2?"Kevin":(random==3?"Sara":"CMPT"))));
		}
	}
	cout<<"The SmartArray object A1 is "<<A1<<endl;
	cout<<"The SmartArray object A2 is "<<A2<<endl;
	cout<<"The SmartArray object A3 is "<<A3<<endl;
}
int main()
{
	Test();
	system("Pause");
	return 0;
}
