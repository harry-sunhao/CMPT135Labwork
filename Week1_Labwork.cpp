#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
struct Point
{
    double x,y;
};
struct RationalNumber
{
    int a,b;
};
struct StringStat
{
    string s;
    int lower, upper, digit;
};
struct StudentRecord
{
    string name;
    float test, midterm, final; //test (20%), midterm (30%) and final (50%)
    char letterGrade;
};
string CreateRandomName(int length)
{
    string name;
    char a=rand()%('Z'-'A')+'A';
    name=name+a;
    for (int i = 1; i < length; ++i) {
        char a=rand()%('z'-'a')+'a';
        name=name+a;
    }
    return name;
}
double Q6_toDouble(RationalNumber n)
{
    return (n.a)*1.0/n.b;
}

void Q7_standardize(RationalNumber &n)
{
    if(n.b<0)
    {
        n.b=n.b*-1;
        n.a=n.a*-1;
    }
}
int getGcd(RationalNumber n)
{
    int small;
    if(n.a==0)
        return n.b;
    if(n.a>n.b)
        small=n.b;
    else
        small=n.a;
    for(int i=small;i>=1;i--)
    {
        if(n.a%i==0&&n.b%i==0)
            return i;
    }
}
RationalNumber Q8(RationalNumber n)
{
    while(getGcd(n)!=1)
    {
        int GCD=getGcd(n);
        n.a=n.a/GCD;
        n.b=n.b/GCD;
    }
    return n;
}
int getNumberOfChar(StringStat s,char a,char b)
{
    int len=s.s.length(),count=0;
    for (int i = 0; i < len; ++i) {
        if(s.s[i]>=a&&s.s[i]<=b)
            count++;
    }
    return count;
}
void Q9()
{
    StringStat S[5];
    for (int i = 0; i < 5; ++i) {
        cout<<"Enter a string :";
        cin>>S[i].s;
    }
    for (int j = 0; j < 5; ++j) {
        int len=S[j].s.length();
        S[j].upper=getNumberOfChar(S[j],'A','Z');
        S[j].lower=getNumberOfChar(S[j],'a','z');
        S[j].digit=getNumberOfChar(S[j],'0','9');
        for (int i = 0; i < len; ++i) {
            cout<<S[j].s[i]<<" ";
        }
        cout<<"It have "<<S[j].digit<<" digit ,";
        cout<<"It have "<<S[j].upper<<" upper ,";
        cout<<"It have "<<S[j].lower<<" lower. ";
        cout<<endl;

    }

}
void Q10()
{
    cout<<"Enter a array size"<<endl;
    int size;
    cin>>size;

    StringStat *S=new StringStat[size];
    for (int i = 0; i < 5; ++i) {
        cout<<"Enter a string :";
        cin>>S[i].s;
    }
    for (int j = 0; j < 5; ++j) {
        int len=S[j].s.length();
        S[j].upper=getNumberOfChar(S[j],'A','Z');
        S[j].lower=getNumberOfChar(S[j],'a','z');
        S[j].digit=getNumberOfChar(S[j],'0','9');
        for (int i = 0; i < len; ++i) {
            cout<<S[j].s[i]<<" ";
        }
        cout<<"It have "<<S[j].digit<<" digit ,";
        cout<<"It have "<<S[j].upper<<" upper ,";
        cout<<"It have "<<S[j].lower<<" lower. ";
        cout<<endl;

    }
    delete []S;
}
char getGrade(StudentRecord s)
{
    double g=s.test*0.2+s.midterm*0.3+s.test*0.5;
    if(g<50)
        return 'F';
    else if(g<60)
        return 'D';
    else if(g<75)
        return 'C';
    else if(g<90)
        return 'B';
    return 'A';

}
void viewRecord(StudentRecord s)
{
    cout<<"The student name is ";
    cout<<s.name;
    cout<<", the test grade is ";
    cout<<s.test;
    cout<<", the midterm grade is ";
    cout<<s.midterm;
    cout<<", the Final grade is ";
    cout<<s.final;
    cout<<", the grade is "<<s.letterGrade<<endl;
}
void Q11()
{
    StudentRecord s;
    cout<<"Enter the student name";
    cin>>s.name;
    cout<<"Enter the test grade";
    cin>>s.test;
    cout<<"Enter the midterm grade";
    cin>>s.midterm;
    cout<<"Enter the Final grade";
    cin>>s.final;
    s.letterGrade=getGrade(s);
    viewRecord(s);
}
void Q12()
{
    int size;
    cout<<"Enter a array size";
    cin>>size;
    StudentRecord *s=new StudentRecord[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter the student name";
        //cin >> s[i].name;
        s[i].name=CreateRandomName(5);
        cout << "Enter the test grade";
        //cin >> s[i].test;
        s[i].test=rand()%100;
        cout << "Enter the midterm grade";
        //cin >> s[i].midterm;
        s[i].midterm=rand()%100;
        cout << "Enter the Final grade";
        //cin >> s[i].final;
        s[i].final=rand()%100;
        s[i].letterGrade = getGrade(s[i]);
    }
    for (int j = 0; j < size; ++j) {
        viewRecord(s[j]);
    }
    delete []s;
}
void Q13_ViewRecord(StudentRecord s[],int size,char g)
{
    for (int i = 0; i < size; ++i) {
        if(s[i].letterGrade==g)
            viewRecord(s[i]);
    }
}
StudentRecord Q14_searchName(StudentRecord s[],int size,string name)
{
    for (int i = 0; i < size;  ++i) {
        if(s[i].name==name)
            return s[i];
    }
}

float getTotalGrade(StudentRecord s)
{
    return s.final+s.midterm+s.test;
}
StudentRecord Q15_getTopStudentRecord(StudentRecord s[],int size)
{
    float Max=0;
    int index=0;
    for (int i = 0; i < size; ++i) {
        if(getTotalGrade(s[i])>Max)
        {
            Max=getTotalGrade(s[i]);
            index=i;
        }
    }
    return s[index];
}
void Q16_printStudentRecordsSorted(StudentRecord s[],int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (s[j].letterGrade>s[j+1].letterGrade)
            {
                StudentRecord temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void Q17()
{
    int size;
    cout<<"Enter a array size";
    cin>>size;
    StudentRecord *s=new StudentRecord[size];
    for (int i = 0; i < size; ++i) {
        cout << "Enter the student name";
        //cin >> s[i].name;
        s[i].name=CreateRandomName(5);
        cout << "Enter the test grade";
        //cin >> s[i].test;
        s[i].test=rand()%90+10;
        cout << "Enter the midterm grade";
        //cin >> s[i].midterm;
        s[i].midterm=rand()%50+60;
        cout << "Enter the Final grade";
        //cin >> s[i].final;
        s[i].final=rand()%40+60;
        s[i].letterGrade = getGrade(s[i]);
    }
    for (int j = 0; j < size; ++j) {
        viewRecord(s[j]);
    }
    cout<<"Enter your need to find the grade ";
    char grade;
    cin>>grade;
    Q13_ViewRecord(s,size,grade);
    cout<<"Enter your need to find the name ";
    string name;
    cin>>name;
    viewRecord(Q14_searchName(s,size,name));
    cout<<"The Top studentRecord is ";
    viewRecord(Q15_getTopStudentRecord(s,size));
    cout<<endl;
    Q16_printStudentRecordsSorted(s,size);
    for (int j = 0; j < size; ++j) {
        viewRecord(s[j]);
    }
    delete []s;
}
Point operator + (const Point& p1, const Point& p2)
{
    Point ans;
    ans.x = p1.x + p2.x;
    ans.y = p1.y + p2.y;
    return ans;
}
void operator ++ (Point &p1)
{
    p1.x = p1.x+1;
    p1.y = p1.y+1;
}

Point operator - (const Point &p1, const Point& p2)
{
    Point ans;
    ans.x = p1.x - p2.x;
    ans.y = p1.y - p2.y;
    return ans;
}
bool operator == (const Point &p1, const Point& p2)
{

    return p1.x==p2.x&&p1.y==p2.y;
}
Point operator - (Point &p1)
{
    Point ans;
    ans.x = p1.x *-1;
    ans.y = p1.y *-1;
    return ans;
}
bool operator > (const Point &p1, const Point& p2)
{
    double distance1,distance2;
    distance1= sqrt(p1.x*p1.x+p1.y*p1.y);
    distance2= sqrt(p2.x*p2.x+p2.y*p2.y);
    return distance1>distance2;
}
int GetQuadrant(const Point p1)
{
    if(p1.x>0&&p1.y>0)
        return 1;
    if(p1.x>0&&p1.y<0)
        return 4;
    if(p1.x<0&&p1.y>0)
        return 2;
    if(p1.x<0&&p1.y<0)
        return 3;
}
bool operator && (const Point &p1, const Point& p2)
{
    return GetQuadrant(p1)==GetQuadrant(p2);

}

int main()
{
    RationalNumber n;
    n.a=1;
    n.b=3;
    Q17();
}

