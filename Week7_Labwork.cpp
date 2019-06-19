#include<vector>
#include <iostream>
using namespace std;

void printVector(vector<int> X)
{
    for (int i=0; i<X.size(); i++) {
        cout<<X[i]<<" ";
    }
    cout<<endl;
}
void printVector(vector<char> X)
{
    for (int i=0; i<X.size(); i++) {
        cout<<X[i]<<" ";
    }
    cout<<endl;
}
void pop_front(vector<int>& X)
{
    X.erase(X.begin());
}
vector<double> operator +(vector<double> a,vector<double> b)
{
    vector<double> ans;
    for (int i=0; i<a.size(); i++) {
        ans.push_back(a[i]);
    }
    for (int i=0; i<b.size(); i++) {
        ans.push_back(a[i]);
    }
    return ans;
}
vector<int> operator *(vector<int> X,int n)
{
    vector<int> ans;
    if (X.size()==0||n==0) {
        return X;
    }
    int index=0;
    for (int i=0; i<abs(n)*X.size(); i++) {
        ans.push_back(X[index]);
        if (index==X.size()-1) {
            index=0;
        } else {
            index++;
        }
    }
    return ans;
}
void swap(vector<char> &a,vector<char> &b)
{
    vector<char> temp;
    temp=a;
    a=b;
    b=temp;
}
int isFound_count(vector<int> X,int n)
{
    int count=0;
    for (int i=0; i<X.size(); i++) {
        if(X[i]==n)
            count++;
    }
    return count;
}
bool isDistinct(vector<int> X)
{
    bool ans=false;
    for (int i=0; i<X.size(); i++) {
        if (isFound_count(X, X[i])==1) {
            ans=true;
        }
    }
    return ans;
}
vector<int> distinctElements(vector<int> X)
{
    vector<int> ans;
    if (isDistinct(X)==false) {
        return  ans;
    }
    ans.push_back(X[0]);
    for (int i=1; i<X.size(); i++) {
        if (isFound_count(ans, X[i])==0&&X[i]!=X[i-1]) {
            ans.push_back(X[i]);
        }
    }
    return ans;
}

vector<int> operator -(vector<int> a,vector<int> b)
{
    b=distinctElements(b);
    vector<int> ans=a;
    vector<int>::iterator it;
    for (it=ans.begin(); it<ans.end(); it++) {
        if (isFound_count(b, *it)>0) {
            ans.erase(it);
        }
    }
    return ans;
}
void removeDuplicates(vector<int> &X)
{
    X=distinctElements(X);
}
void Q9()
{
    vector<int> X,ans;
    
    for (int i=0; i<5; i++) {
        int n=rand()%6;
        X.push_back(n);
    }
     printVector(X);
    for (int i=0; i<5; i++) {
        for (int j=0; j<X[i]; j++) {
            ans.push_back(X[i]);
        }
    }
    printVector(ans);
}

int main()
{
//    vector<int> test;
//    test.push_back(1);
//    test.push_back(2);
//    test.push_back(2);
//    test.push_back(1);
//    test.push_back(3);
//    vector<int> test1;
//    test1.push_back(2);
//    removeDuplicates(test);
//    printVector(test);
    Q9();
    system("Pause");
    return 0;
}
