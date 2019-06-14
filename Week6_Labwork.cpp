#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

void Q1()
{
    string fname,lname;
    double exercises,projects,exam,total;
    char grade;
    ofstream fout("Result.txt");
    ifstream fin("ClassList.txt");
    if (fout.fail()) {
        cout<<"Output stream is fail"<<endl;
        return;
    }
    if (fin.fail()) {
        cout<<"Input stream is fail"<<endl;
        return;
    }
    while (fin.eof()==false) {
        fin>>fname>>lname>>exercises>>projects>>exam;
        total=exercises+projects+exam;
        if (total>=90) {
            grade='A';
        }
        else if(total>=75)
        {
            grade='B';
        }
        else if (total>=65)
        {
            grade='C';
        }
        else if (total>=50)
        {
            grade='D';
        }
        else
            grade='F';
        fout<<fname<<" "<<lname<<"\t"<<exercises<<"\t"<<projects<<"\t"<<exam<<"\t"<<grade<<endl;
    }
    fout.close();
    fin.close();
}
struct Student
{
    string fname,lname;
    double exercises,projects,exam,total;
    char grade;
};
void Q2()
{
    ifstream fin("ClassList.txt");
    if (fin.fail()) {
        cout<<"Input stream is fail"<<endl;
        return;
    }
    int count;
    string temp;
    while (fin.eof()==false)
    {
        fin>>temp;
        count++;
    }
    fin.close();
    if (count==0) {
        return;
    }
    fin.open("ClassList.txt");
    Student * arr_s=new Student[count];
    count=0;
    while (fin.eof()==false)
    {
        fin>>arr_s[count].fname>>arr_s[count].lname>>arr_s[count].exercises>>arr_s[count].projects>>arr_s[count].exam;
        arr_s[count].total=arr_s[count].exercises+arr_s[count].projects+arr_s[count].exam;
        if (arr_s[count].total>=90) {
            arr_s[count].grade='A';
        }
        else if(arr_s[count].total>=75)
        {
            arr_s[count].grade='B';
        }
        else if (arr_s[count].total>=65)
        {
            arr_s[count].grade='C';
        }
        else if (arr_s[count].total>=50)
        {
            arr_s[count].grade='D';
        }
        else
            arr_s[count].grade='F';
        count++;
    }
    fin.close();
    ofstream fout("ClassList.txt");
    for (int i=0; i<count; i++) {
        fout<<arr_s[i].fname<<" "<<arr_s[i].lname<<"\t"<<arr_s[i].exercises<<"\t"<<arr_s[i].projects<<"\t"<<arr_s[i].exam<<"\t"<<arr_s[i].grade<<endl;
    }
    fout.close();
    delete [] arr_s;
    return;
}
void Q3()
{
    /*
     Write a C++ program that generates a random integer n in the range [50, 100] and that writes n random
     integers in the range [0, 999] to an output text file named randomNumbers.txt.
     */
    int a=50,b=100,count,n;
    count=b-a+1;
    n=rand()%count+a;
    a=0;b=999;count=b-a+1;
    ofstream fout("randomNumbers.txt");
    for (int i=0; i<n; i++) {
        fout<<rand()%count+a<<endl;
    }
    fout.close();
    return;
}
void Q4()
{
    /*
     Write a C++ program that reads the file randomNumbers.txt you created in Q3 above and prints the minimum and maximum integers in the file. Your output should be printed to the console output screen. Remark: You are not allowed to declare any array. Moreover remember that you don't know how many numbers are on the input file which means you must read until the end of file is reached.
     */
    ifstream fin("randomNumbers.txt");
    int min,max,a;
    fin>>min;
    max=min;
    while (fin.eof()==false) {
        fin>>a;
        if (a>max) {
            max=a;
        }
        if (a<min) {
            min=a;
        }
    }
    cout<<"The minimum and maximum integers is "<<min<<" , "<<max<<endl;
}
void Q5()
{
    /*
     Write a C++ program that reads a positive integer n from the keyboard and then creates a new file named multiplicationTable.txt that contains the following information
     Note that you are not allowed to declare any array here.
     */
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    ofstream fout("multiplicationTable.txt");
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            fout<<i*j<<" ";
        }
        fout<<endl;
    }
    fout.close();
    return;
}
void Q6()
{
    /*
     Consider a file similar to ClassList.txt you manually created in Q1. Write a C++ program that reads the file and prints the top student (i.e. maximum total marks). Your program must print the full name, the marks, and the letter grade of the top student only. Again, you are not allowed to use any array to answer this question.
     */
    string fname,lname,Max_fname,Max_lname;
    double exercises,projects,exam,total,Max_exercises,Max_projects,Max_exam,Max_total;
    char grade;
    ifstream fin("ClassList.txt");
    if (fin.fail()) {
        cout<<"Input stream is fail"<<endl;
        return;
    }
    fin>>Max_fname>>Max_lname>>Max_exercises>>Max_projects>>Max_exam;
    Max_total=Max_exercises+Max_projects+Max_exam;
    while (fin.eof()==false) {
        fin>>fname>>lname>>exercises>>projects>>exam;
        total=exercises+projects+exam;
        if(total>Max_total)
        {
            Max_total=total;
            Max_exam=exam;
            Max_fname=fname;
            Max_lname=lname;
            Max_projects=projects;
            Max_exercises=exercises;
        }
    }
    if (Max_total>=90) {
        grade='A';
    }
    else if(Max_total>=75)
    {
        grade='B';
    }
    else if (Max_total>=65)
    {
        grade='C';
    }
    else if (Max_total>=50)
    {
        grade='D';
    }
    else
        grade='F';
    fin.close();
    cout<<"The top student is "<<Max_fname<<" "<<Max_lname<<"\t"<<Max_exercises<<"\t"<<Max_projects<<"\t"<<Max_exam<<"\t"<<grade<<endl;
}
void Q7()
{
    /*
     Write
     a C++ program that does the following:
     a. Create an output file stream and connect it to a file "RandomFloats.txt"
     b. Generates a random integer n in the range [900, 1000]
     c. Print in the file n random floats in the range [0.0, 100.0)
     d. Close the output stream
     e. Create an input stream and connect it to your file "RandomFloats.txt"
     f. Read all the n floats in the file into an array
     g. Close the input file stream
     h. Sort your array with a bubble or selection or insertion sort algorithm
     i. Create an output stream and connect it to a file "SortedRandomFloats.txt"
     j. Write the sorted array of floats into the output file stream
     k. Close the output file stream
     l. Check your file " SortedRandomFloats.txt" in Notepad to see indeed it is sorted.
     */
    ofstream fout("RandomFloats.txt");
    int n=rand()%(1000-900+1)+900;
    for (int i=0; i<n; i++) {
        float n=rand()*1.0/RAND_MAX*100;
        fout<<n<<endl;
    }
    fout.close();
    ifstream fin("RandomFloats.txt");
    float arr_n[1000];
    float num;
    int i=0;
    for (i=0; fin.eof()==false; i++) {
        fin>>num;
        arr_n[i]=num;
    }
    fin.close();
    for (int j=0; j<i; j++) {
        for (int k=0; k<i-j-1; k++) {
            if (arr_n[k]>arr_n[k+1]) {
                float temp=arr_n[k];
                arr_n[k]=arr_n[k+1];
                arr_n[k+1]=temp;
            }
        }
    }
    fout.open("SortedRandomFloats.txt");
    for (int j=0; j<i; j++)
    {
        fout<<arr_n[j]<<endl;
    }
    fout.close();
    return;
}
void printFile(ifstream fin)
{
    if(fin.eof())
        return;
    else
    {
        int x;
        fin>>x;
        printFile(fin);
        cout<<x<<endl;
    }
}
void Q8()
{
    /*
    Write a C++ program that reads the randomNumbers.txt file you created in Q3 above and that prints the
data in the file to the console output screen in reverse order; that is the first integer read will be printed
last and the last integer read will be printed first. Remark: You are not allowed to use any array when you
answer this question. Moreover remember that you don't know how many numbers are on the input file
which means you must read until the end of file is reached.
    */
    ifstream fin("randomNumbers.txt");
    if(fin.fail())
    {
        cout<<"Input stream fail"<<endl;
        return;
    }
    printFile(fin);
    return;
}
int main()
{
    srand((unsigned)time(NULL));
    Q7();
    system("Pause");
    return 0;
}
