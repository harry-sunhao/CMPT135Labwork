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

void insertionSort(int *arr,int start,int last)
{
    if(start>last)
        return;

    int key=arr[start];
    int j=start-1;
    while((j>=0) && (key<arr[j])){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    insertionSort(arr,start+1,last);
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
bool isvalid (int **a,int i,int j)
{
    for(int col=0;col<9;++col)
    {
        if(col!=j&&a[i][j]==a[i][col]) return false;
    }
    for(int row=0;row<9;++row)
    {
        if(row!=i&&a[i][j]==a[row][j]) return false;
    }
    for(int l=i/3*3;l<i/3*3+3;++l)
        for(int m=j/3*3;m<j/3*3+3;++m)
        {
            if(l!=i&&m!=j&&a[i][j]==a[l][m]) return false;
        }
    return true;
}
bool sloveSudokuBorad(int **a,int x,int y)
{
    //cout<<x<<", "<<y<<" "<<a[x][y]<<" "<<boolalpha<<isvalid(a,x,y)<<endl;
    if(x==9)
        return true;
    if(y>=9)
        return sloveSudokuBorad(a,x+1,0);
    if(a[x][y]==0)
    {
        for (int i = 1; i <= 9; ++i) {
            a[x][y]=i;
            if(isvalid(a,x,y))
            {
                if (sloveSudokuBorad(a,x,y+1))
                    return true;
            }
            a[x][y]=0;
        }
    }
    else
        return sloveSudokuBorad(a,x,y+1);
    return false;
}
void fillSudokuBorad(int **a,int n)
{
    sloveSudokuBorad(a,0,0);
}

int main()
{
    int size = 6;
    int *A = new int [size];
    for (int i = 0; i < size; i++)
        A[i] = rand() % 25;
    cout << "Original Array\n\t";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
    insertionSort(A, 0, size-1);
    cout << "Sorted Array Array\n\t";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
    int x;
    do
    {
        cout << "Enter the number of elements (positive number please): ";
        cin >> x;
    } while (x <= 0);
    cout << "All the subsets of the set {1,2,3,...,n} are" << endl;
    allSubsets(x);

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
