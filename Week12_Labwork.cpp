#include<iostream>

using namespace std;

template <class T>
T maximum(T a,T b)
{
    if (a>b)
        return a;
    return b;
}
template <class T>
T absolute(T a)
{
    if(a<0)
        return a*-1;
    else
        return a;
}
template <class T>
int binnary_search(const T *arr, const T &value,int start, int end)
{
    int mid,ret=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]<value)
            start=mid+1;
        else if(arr[mid]>value)
            end=mid-1;
        else
        {
            ret=mid;
            break;
        }
    }
    return ret;
}
template <class T>
int binnary_search_r(const T *arr, const T &value,int start, int end)
{
    if(start>end)
        return -1;
    int mid=start+(end-start)/2;
    if(arr[mid]>value)
        return binnary_search_r(arr,value,start,mid-1);
    else if(arr[mid]<value)
        return binnary_search_r(arr,value,mid+1,end);
    else
        return mid;
}
template <class T>
void Merge(T *arr,int start, int mid, int last)
{
    int i=start;
    int j=mid+1;
    int t=0;
    T *temp=new T[last-start+1];
    while (i<=mid && j<=last){
        if(arr[i]<=arr[j]){
            temp[t++] = arr[i++];
        }else {
            temp[t++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[t++] = arr[i++];
    }
    while(j<=last){
        temp[t++] = arr[j++];
    }
    t = 0;
    while(left <= right){
        arr[start++] = temp[t++];
    }
    delete [] temp;
}
template <class T>
void sort(T *arr,int start,int last)
{
    if(start>last)
        return ;
    int mid=(start+last)/2;
    sort(arr,start,mid);
    sort(arr,mid+1,last);
    Merge(arr,start,mid,last);
}
template <class K, class V>
class Map //A mapping from one array to another array
{
private:
    K *arr1;    //The first array
    V *arr2;    //The second array
    int size;   //The size of the arrays (they have equal size)
public:
    Map(){this->size=0;} //Default constructor. size = 0, pointers not initialized
    Map(const K *A, const V *B, const int &size)
    {
        this->size=size;
        if(size>0)
        {
            this->arr1=new K[size];
            this->arr2=new V[size];
            for (int i = 0; i < this->size; ++i) {
                this->arr1[i]=A[i];
                this->arr2[i]=B[i];
            }
        }
    }
    //Non- default constructor
    //Deep copy A to arr1 and B to arr2
    Map(const Map<K, V> &m)
    {
        if(*this==m)
            return m;
        this->size=m.size;
        if(size>0)
        {
            this->arr1=new K[size];
            this->arr2=new V[size];
            for (int i = 0; i < this->size; ++i) {
                this->arr1[i]=m.arr1[i];
                this->arr2[i]=m.arr2[i];
            }
        }
    }
    //Copy constructor
    Map<K, V>& operator = (const Map<K, V> &m)
    {
        if(this==&m)
            return *this;
        this->~Map();
        this->size=m.size;
        if(size>0)
        {
            this->arr1=new K[size];
            this->arr2=new V[size];
            for (int i = 0; i < this->size; ++i) {
                this->arr1[i]=m.arr1[i];
                this->arr2[i]=m.arr2[i];
            }
        }
        return *this;

    }//Assignment operator
    ~Map()
    {
        this->arr1=new K[1];
        this->arr2=new V[1];
    }//Destructor. Delete both arrays and set size =I
    V& operator [](const K &key) const
    {
        for (int i = 0; i < this->size; ++i) {
            if(arr1[i]==key)
                return arr1[i];
        }
        cout<<"Error"<<endl;
    }
    //Find an index value s.t. arr1[index] == key.
    //If such index exists then return arr2 [index]. Otherwise system("exit")
    K& operator [](const V &value) const
    {
        for (int i = 0; i < this->size; ++i) {
            if(arr2[i]==value)
                return arr2[i];
        }
        cout<<"Error"<<endl;
    }
    //Find an index value s.t. arr2[index] == value.
    //If such index exists then return arr1[index]. Otherwise system("exit" )
    void append(const K &key, const V &value)
    {
        K *temp1=new K [this->size+1];
        V *temp2=new V [this->size+1];
        for (int i = 0; i < this->size; ++i) {
            temp1[i]=this->arr1[i];
            temp2[i]=this->arr2[i];
        }
        temp1[size]=key;
        temp2[size]=value;
        if (this->size>0)
        {
            delete[] this->arr1;
            delete[] this->arr2;
        }
        this->arr1=temp1;
        this->arr2=temp2;
        this->size=this->size+1;
    }//Append key to arr1 and value to arr2
    //Friend functions
    //template <class K, class V>
    friend ostream& operator <<(ostream &out, const Map<K, V> &m);
};
int main()
{

    return 0;
}
