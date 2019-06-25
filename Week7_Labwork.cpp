#include<vector>
#include <iostream>
#include<cmath>
#include<algorithm>

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
        return ans;
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
void insertIncreasing(vector<int> &a, const int x)
{
    a.push_back(x);
    sort(a.begin(),a.end());
}
void insertGrouped(vector<int> &a, const int x)
{
    vector<int>::iterator it;
    // even location
    for (it=a.begin(); it<a.end(); it++) {
        if (*it%2==0) {
            break;
        }
    }
    if (x%2==0) {
        a.insert(it, x);
    }
    else
    {
        a.insert(it-1, x);
    }
    
}
void insertGroupedIncreasing(vector<int> &a, const int x)
{
    if (a.empty()) {
        a.push_back(x);
        return;
    }
    vector<int>::iterator it;
    // even location
    for (it=a.begin(); it<a.end(); it++) {
        if (*it%2==0) {
            break;
        }
    }
    if (x%2==0) {
        a.insert(it, x);
    }
    else
    {
        a.insert(it, x);
    }
    if (a.size()<3) {
        return;
    }
    sort(a.begin(), it-1);
    sort(it, a.end()-1);
    
    
}
void Q10()
{
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        insertIncreasing(a, pow(-1.0, i)*i);
        printVector(a);
    }
}
void Q11()
{
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        insertGrouped(a, i);
        printVector(a);
    }
}
void Q12()
{
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        insertGroupedIncreasing(a, i);
        printVector(a);
    }
}
struct Vehicle
{
	string make;
	int year;
	double hp; //horse power of the vehicle
};
void printVector(vector<Vehicle> X)
{
    for (int i=0; i<X.size(); i++) {
		cout<<X[i].make<<" "<<X[i].year<<" "<<X[i].hp;
		cout<<endl;
    }
    cout<<endl;
}
void swap(vector<Vehicle> &a,vector<Vehicle> &b)
{
    vector<Vehicle> temp;
    temp=a;
    a=b;
    b=temp;
}
vector <Vehicle> readVehicleInventory(string path)
{
	ifstream fin;
	fin.open(path);
	if(fin.fail())
		cout<<"Input file not found"<<endl;
	Vehicle temp;
	vector<Vehicle> ans;
	while(fin.eof()==false)
	{
		fin>>temp.make;
		fin>>temp.year;
		fin>>temp.hp;
		ans.push_back(temp);
		//cout<<temp.make<<" "<<temp.year<<" "<<temp.hp<<endl;
	}
	fin.close();

	return ans;
}
vector <Vehicle> reOrderObjects(vector<Vehicle> X)
{
	for(int i=0;i<X.size();i++)
	{
		for(int j=0;j<X.size()-1-i;j++)
		{
			if(X[j].make>X[j+1].make)
			{
				swap(X[j],X[j+1]);
			}
		}
	}
	return X;
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
    Q11();
    system("Pause");
    return 0;
}
