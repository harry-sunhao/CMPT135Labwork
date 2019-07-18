#include <iostream>
#include<string>
#include <cmath>

using namespace std;

void swap(int& a, int& b )
{
    int temp = a;
    a = b;
    b = temp;
}

void bubblesort(int arr[],int first,int last) {
    if (first < last && last > 0) {
        if (arr[first] > arr[first + 1]) {
            int temp = arr[first];
            arr[first] = arr[first + 1];
            arr[first + 1] = temp;
        }
        bubblesort(arr, first + 1, last);
        bubblesort(arr, first, last - 1);
    } else
        return;
}
void selectionsort(int arr[],int first,int last)
{
    // find the minimum element in the unsorted subarray[i..n-1]
    // and swap it with arr[i]
    int min = first;
    for (int j = first + 1; j < last; j++)
    {
        // if arr[j] element is less, then it is the new minimum
        if (arr[j] < arr[min])
            min = j;	// update index of min element
    }

    // swap the minimum element in subarray[i..n-1] with arr[i]
    int temp = arr[min];
    arr[min] = arr[first];
    arr[first] = temp;
    if (first + 1 < last) {
        selectionsort(arr, first + 1, last);
    }
}
void towersofhanoi(int n,char a,char b,char c)
{
    if (n==1)
        cout<<"The disk #"<<n<<" from "<<a<<" to "<<c<<endl;
    else
    {
        towersofhanoi(n-1,a,c,b);
        cout<<"The disk #"<<n<<" from "<<a<<" to "<<c<<endl;
        towersofhanoi(n-1,b,a,c);
    }
}
int power(int x,int y)
{
    if(y==0)
        return 1;
    else
        return x*pow(x,y-1);
}
void printPermutations(char a[],int start,int last)
{
    if(start == last)
    {
        for(int i=0; i < last;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    for(int i= start; i < last; i++)
    {
        swap(a[start],a[i]);
        cout<<start<<" [1] "<<i<<endl;
        printPermutations(a,start + 1,last);
        swap(a[i],a[start]);
        cout<<start<<" [2] "<<i<<endl;

    }

}
void print_subset1(int *A, int *used, int N, int cur) {
    if( cur == N ) {
        for(int i=0; i<N; i++) {
            if( used[i] ) {
                cout<<A[i]<<" ";
            }
        }
        cout<<endl;
        return ;
    }
    used[cur] = 0;
    print_subset1(A, used, N, cur+1);
    used[cur] = 1;
    print_subset1(A, used, N, cur+1);
}
void allSubsets(int n)
{
    int *a=new int [n];
    int *b=new int [n];
    for (int i = 0; i < n; ++i) {
        a[i]=i+1;
    }
    print_subset1(a,b,n,0);
}
bool isvalid(int **a,int x,int y)
{
    int i=0,j=0;
    for (i=0; i < 9; i++) {
        if(i!=x&&a[i][y]==a[x][y])
            return false;
    }
    for (j=0; j < 9; j++) {
        if(j!=x&&a[x][j]==a[x][y])
            return false;
    }
    for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++) {
        for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++) {
            if (i != x && j != y && a[i][j] == a[x][y])
                return false;
        }
    }
    return true;
}
bool fillSudokuBorad(int ** a,int n=9,int x=0,int y=0)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (a[i][j]==0)
            {
                for (int k = 1; k < 9; ++k) {
                    a[i][j]=k;
                    if(isvalid(a,i,j)&&fillSudokuBorad(a))
                        return true;
                    a[i][j]=0;
                }
                return false;
            }
        }
    }
    return true;
}
void f9(int x)
{
    //cout<<" "<<x<<endl;
    if (x > 0)
    {
        f9(x-1);
        cout<< x <<" ";
        f9(x-1);
    }
}
int main()
{
    const int n = 9;
    int **sudoku = new int*[n];
    for (int i = 0; i < n; i++)
        sudoku[i] = new int[n];
    fillSudokuBorad(sudoku, n);
    cout << "An example an nxn sudoku board such that" << endl;
    cout << "\tEach row contains the integers 1,2,3,...,n" << endl;
    cout << "\tEach column contains the integers 1,2,3,...,n" << endl;
    cout << "is the following" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << sudoku[i][j] << " ";
        cout << endl;
    }

    //allSubsets(5);
}
