#include <iostream>
#include <string>
#include <ctime>
using namespace std;

template <class K, class V>
class Map	//A mapping from one array to another array
{
private:
	K  *arr1;	//The first array
	V  *arr2;	//The second array
	int size;	//The size of the arrays (they have equal size)
public:
	Map();	//Default constructor. size = 0, pointers not initialized
	Map(const K *A, const V *B, const int &size);	//Non-default constructor. Deep copy A to arr1 and B to arr2
	Map(const Map<K, V> &m);	//Copy constructor. Deep copy m to *this
	
	Map<K, V>& operator = (const Map<K, V> &m);	//Assignment operator. Deep copy m to *this
	
	~Map();	//Destructor. Delete both arrays and set size = 0
	
	int getSize() const;					//Return the value of the size
	V& operator [](const K &key) const;		//Find an index j s.t. arr1[j] == key. Then return arr2[j]. Otherwise abort().
	K& operator [](const V &value) const;	//Find an index j s.t. arr2[j] == value. Then return arr1[j]. Otherwise abort().
	K& getKeyAtIndex(const int& index) const;		//If index is a valid index then return arr1[index] otherwise abort().
	V& getValueAtIndex(const int& index) const;		//If index is a valid index then return arr1[index] otherwise abort().
	void append(const K &key, const V &value);	//Append the key to arr1 and value to arr2 then increment size
	
	//Friend functions
	template <class K, class V>
	friend ostream& operator << (ostream &out, const Map<K, V> &m);	//Print the mapping vertically nicely
};

template <class K, class V>
Map<K, V> :: Map()
{
	this->size = 0;
}

template <class K, class V>
Map<K, V> :: Map(const K *A, const V *B, const int &size)
{
	this->size = size;
	if (this->size > 0)
	{
		arr1 = new K[this->size];
		arr2 = new V[this->size];
		for (int i = 0; i < this->size; i++)
		{
			arr1[i] = A[i];
			arr2[i] = B[i];
		}
	}
}

template <class K, class V>
Map<K, V>::Map(const Map<K, V> &m)
{
	this->size = m.size;
	if (this->size > 0)
	{
		arr1 = new K[this->size];
		arr2 = new V[this->size];
		for (int i = 0; i < this->size; i++)
		{
			arr1[i] = m.arr1[i];
			arr2[i] = m.arr2[i];
		}
	}
}

template <class K, class V>
Map<K, V>& Map<K, V>::operator = (const Map<K, V> &m)
{
	if (this == &m)
		return *this;
	else
	{
		this->~Map();
		this->size = m.size;
		if (this->size > 0)
		{
			arr1 = new K[this->size];
			arr2 = new V[this->size];
			for (int i = 0; i < this->size; i++)
			{
				arr1[i] = m.arr1[i];
				arr2[i] = m.arr2[i];
			}
		}
		return *this;
	}
}

template <class K, class V>
Map<K, V>::~Map()
{
	if (this->size > 0)
	{
		delete[] arr1;
		delete[] arr2;
		this->size = 0;
	}
}

template <class K, class V>
int Map<K, V>::getSize() const
{
	return size;
}

template <class K, class V>
V& Map<K, V>::operator [](const K &key) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (arr1[i] == key)
			return arr2[i];
	}
	//If we reach here, it means the key does not exist. Raise runtime error.
	abort();
}

template <class K, class V>
K& Map<K, V>::operator [](const V &value) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (arr2[i] == value)
			return arr1[i];
	}
	//If we reach here, it means the value does not exist. Raise runtime error.
	abort();
}

template <class K, class V>
K& Map<K, V> :: getKeyAtIndex(const int& index) const
{
	if (index >= 0 && index < size)
		return arr1[index];
	else
		abort();
}

template <class K, class V>
V& Map<K, V> :: getValueAtIndex(const int& index) const
{
	if (index >= 0 && index < size)
		return arr2[index];
	else
		abort();
}

template <class K, class V>
void Map<K, V>::append(const K &key, const V &value)
{
	//First create a temporary array whose size is this->size+1
	K *A = new K[this->size + 1];
	V *B = new V[this->size + 1];

	//Copy the elements of this->arr1 to A and this->arr2 to B
	for (int i = 0; i < this->size; i++)
	{
		A[i] = this->arr1[i];
		B[i] = this->arr2[i];
	}

	//Copy the key-value pair to be appended to A and B
	A[this->size] = key;
	B[this->size] = value;

	//Delete the existing arrays arra1 and arr2
	if (this->size > 0)
	{
		delete[] this->arr1;
		delete[] this->arr2;
	}

	//Make the array this->arr1 to point to A, this->arr2 to B, and increment the size
	this->arr1 = A;
	this->arr2 = B;
	this->size += 1;
}

template <class K, class V>
ostream& operator << (ostream &outputStream, const Map<K, V> &m)
{
	if (m.size == 0)
		outputStream << "Empty map" << endl;
	else
	{
		outputStream << endl;
		for (int i = 0; i < m.size; i++)
			outputStream << m.arr1[i] << " \t\t " << m.arr2[i] << endl;
	}
	return outputStream;
}
template <class K, class V>
int getIndexAtKey(const Map<K, V> &m,const K& k)
{
	for(int i=0;i<m.getSize();i++)
	{
		if(m.getKeyAtIndex(i)==k)
			return i;
	}
	return -1;
}

template <class K,class V>
void remove( Map<K, V> &m, const K &k)
{
	int index=getIndexAtKey(m,k);
    while (index != -1)
    {
		K* arr1 = new K[m.getSize()];
		V* arr2 = new V[m.getSize()];
        for (int i = 0; i < index; i++)
        {
			arr1[i] = m.getKeyAtIndex(i);
			arr2[i] = m.getValueAtIndex(i);
		}
		for (int i = index+1; i < m.getSize(); i++)
        {
			arr1[i-1] = m.getKeyAtIndex(i);
			arr2[i-1] = m.getValueAtIndex(i);
		}
		const int size=m.getSize()-1;
		m=Map<K,V>(arr1,arr2,size);
		index=getIndexAtKey(m,k);
    }
}
int main()
{
	srand(time(0));
	string citiesArray[]={"Victoria","Nanaimo","Calgary","Edmonton","Kamloops"};
	Map<string,int> m1;
	for(int i=0;i<10;i++)
	{
		string city=citiesArray[rand()%5];
		int distance = rand()%40+20;
		m1.append(city,distance);
	}
	cout<<"The map m1 is now..."<<m1<<endl;
	string key1=citiesArray[rand()%5];
	remove(m1,key1);
	cout<<"After removing all elements of m1 whose key is "<<key1<<", m1 becomes "<<m1<<endl;
	Map<int,string> m2;
	for(int i=0;i<10;i++)
	{
		string city=citiesArray[rand()%5];
		int distance = rand()%3+1;
		m2.append(distance,city);
	}
	cout<<"The map m2 is now..."<<m2<<endl;
	int key2=rand()%3+1;
	remove(m2,key2);
	cout<<"After removing all elements of m2 whose key is "<<key1<<", m2 becomes "<<m1<<endl;
	system("Pause");
	return 0;
}

