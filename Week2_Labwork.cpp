#include<iostream>
#include <cmath>
#include <string>
using namespace std;

/*
 * Point
 *
 * Labwork
 * */
class Point
{
private:
    float x, y;
public:
    //Constructor member function
    Point();
    Point(float newX, float newY);

    //Getter function
    float getX();
    float getY();

    //Setter functions
    void setX(float newX);
    void setY(float newY);

    //Additional member functions
    void print();
    int getQuadrant(Point p1);
    double getDistance();
};

Point getFurthesetPoint(Point arr_P[], int size)
{
    Point Max=arr_P[0];
    for (int i = 1; i < size; ++i) {
        if(arr_P[i].getDistance()>Max.getDistance())
            Max=arr_P[i];

    }
    return Max;
}
double Point::getDistance()
{
    return sqrt(x*x+y*y);
}

Point::Point()
{
    setX(0.0);
    setY(0.0);
}

Point::Point(float newX, float newY)
{
    setX(newX);
    setY(newY);
}

float Point::getX()
{
    return x;
}

float Point::getY()
{
    return y;
}

void Point::setX(float newX)
{
    x = newX;
}

void Point::setY(float newY)
{
    y = newY;
}

void Point::print()
{
    cout << "(" << getX() << ", " << getY() << ")";
}
int Point::getQuadrant(Point p1)
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
void Test_Q6()
{
    cout<<"Enter the array's size"<<endl;
    int size;
    cin>>size;
    Point *arr_P= new Point[size];
    for (int i = 0; i < size; ++i) {
        arr_P[i].setX(8.0*rand()/RAND_MAX-3.0);
        arr_P[i].setY(8.0*rand()/RAND_MAX-3.0);
    }
    for (int j = 0; j < size; ++j) {
        arr_P[j].print();
        cout<<" distance is "<<arr_P[j].getDistance()<<endl;
    }
    Point a;
    cout<<"The farest frome the origin is ";
    getFurthesetPoint(arr_P,size).print();

}
class RationalNumber
{
private:
    int A, B;
public:
    //Constructor member function
    RationalNumber();
    RationalNumber(int newA);
    RationalNumber(int newA,int newB);

    //Getter function
    int getA();
    int getB();

    //Setter functions
    void setA(int newA);
    void setB(int newB);
    //Additional member functions
    double toDouble();
    int getGcd();
    void standardize();
    void reduce();
    void print();
};
int RationalNumber::getA() {return A;}
int RationalNumber::getB() {return B;}
void RationalNumber::setA(int newA) {A=newA;}
void RationalNumber::setB(int newB) {B=newB;}
RationalNumber::RationalNumber() {setA(0);setB(1);}
RationalNumber::RationalNumber(int newA) {setA(newA);}
RationalNumber::RationalNumber(int newA, int newB) {setA(newA);setB(newB);}
double RationalNumber::toDouble() {return (A)*1.0/B;}
void RationalNumber::standardize()
{
    if(B<0)
    {
        B = B * -1;
        A = A * -1;
    }
}
int RationalNumber::getGcd()
{
    int small;
    if(A==0)
        return B;
    if(abs(B)>abs(B))
        small=B;
    else
        small=A;
    for(int i=abs(small);i>=1;i--)
    {
        if(A%i==0&&B%i==0)
            return i;
    }
}
void RationalNumber::reduce()
{
    int gcd=getGcd();
    A/=gcd;
    B/=gcd;
}
void RationalNumber::print()
{
    cout<<A<<"/"<<B<<endl;
}
void Q7_Test()
{
    RationalNumber n1=RationalNumber(),n2=RationalNumber(2),n3=RationalNumber(16,18);
    n1.setA(20);
    n1.setB(25);
    n1.reduce();
    n1.print();
    n3.setB((n2.getB()+10)*-1);
    n3.setA(n1.getA());
    n3.standardize();
    n3.print();
}
class Triangle
{
    private:
            float side1,side2,side3;
    public:
        Triangle();
        Triangle(float t_side);
        Triangle(float t_side1, float t_side2);
        Triangle(float t_side1, float t_side2,float t_side3);

        //getter
        float getSide1();
        float getSide2();
        float getSide3();
        //setter
        void setSide1(float newSide1);
        void setSide2(float newSide2);
        void setSide3(float newSide3);

        float getArea();
        float getPerimeter();
        void print();
};
Triangle::Triangle() {side1=side2=side3=1.0;}
Triangle::Triangle(float t_side) {side1=side2=side3=t_side;}
Triangle::Triangle(float t_side1, float t_side2) {side1=side2=t_side1;side3=t_side2;}
Triangle::Triangle(float t_side1, float t_side2, float t_side3) {side1=t_side1;side2=t_side2;side3=t_side3;}
float Triangle::getSide1() {return side1;}
float Triangle::getSide2() {return side2;}
float Triangle::getSide3() {return side3;}
void Triangle::setSide1(float newSide1) {side1=newSide1;}
void Triangle::setSide2(float newSide2) {side2=newSide2;}
void Triangle::setSide3(float newSide3) {side3=newSide3;}
float Triangle::getArea()
{
    float s=(side1+side2+side3)/2;
    return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}
float Triangle::getPerimeter() {return side1+side2+side3;}
void Triangle::print()
{
    cout<<"3 sides are "<<side1<<", "<<side2<<", "<<side3<<" and the area is "<<getArea()<<" and the circumference is "<<getPerimeter()<<" ";
    if (side1 == side2 && side1 == side3)
        cout<<"This triangle is equilateral"<<endl;
    else if (side1 == side2 || side1 == side3 || side2 == side3)
        cout<<"This triangle is isosceles"<<endl;
    else
        cout<<"This triangle is scalene"<<endl;

}
void Q8_Test()
{
    Triangle t1,t2(2),t3(2,3),t4(3,4,5);
    cout<<"t1 is ";t1.print();
    cout<<"t1 side1 is "<<t1.getSide1()<<endl;
    cout<<"t2 is ";t2.print();
    cout<<"t2 side2 is "<<t2.getSide2()<<endl;
    cout<<"t3 is ";t3.print();
    cout<<"t3 side3 is "<<t3.getSide3()<<endl;
    cout<<"t4 is ";t4.print();
    cout<<"t4 arae is "<<t4.getArea()<<endl;
    Triangle t5(3,3,5);
    cout<<"t5 perimeter is "<<t5.getPerimeter();
    t1.setSide1(3);
    t1.setSide2(3);
    t1.setSide3(4);
    cout<<endl<<"After modifiy t1 is ";
    t1.print();


}
class Course
{
private:
    string name;
    float test, midterm, final; //test (20%), midterm (30%) and final (50%)
    char letterGrade;
    char getGrade()
    {
        double g=test*0.2+midterm*0.3+test*0.5;
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
public:
    Course();
    Course(string T_name);
    Course(string T_name,float T_test,float T_midterm,float T_final);
    string getName();
    float getTest();
    float getMidterm();
    float getFinal();
    char getLetterGrade();

    void setName(string newName);
    void setTest(float newTest);
    void setMidterm(float newMidterm);
    void setFinal(float newFinal);

    void print();
};
Course::Course()
{
    test=midterm=final=0;
    letterGrade='F';
    name="";
}
Course::Course(string T_name)
{
    name=T_name;
    test=midterm=final=0;
    letterGrade='F';
}
Course::Course(string T_name, float T_test, float T_midterm, float T_final)
{
    name=T_name;
    test=T_test;
    midterm=T_midterm;
    final=T_final;
    letterGrade=getGrade();
}
string Course::getName() {return name;}
float Course::getTest() {return test;}
float Course::getMidterm() {return midterm;}
float Course::getFinal() {return final;}
char Course::getLetterGrade() {return letterGrade;}

void Course::setName(string newName) {name=newName;}
void Course::setTest(float newTest) {test=newTest;letterGrade=getGrade();}
void Course::setMidterm(float newMidterm) {midterm=newMidterm;letterGrade=getGrade();}
void Course::setFinal(float newFinal) {final=newFinal;letterGrade=getGrade();}

void Course::print() {cout<<getName()<<" 's test grade is "<<test<<", the midterm grade is "<<midterm;
    cout<<", the Final grade is ";
    cout<<final;
    cout<<", the grade is "<<letterGrade<<endl;
}
void Q9_Test()
{
    Course s1,s2("Jlnki"),s3("Harry",100,100,100);
    s3.print();
    s3.setTest(10);
    cout<<"After modifiy s3 is ";
    s3.print();
    cout<<"Enter the s1 name, test, midtem, final"<<endl;
    string name;
    float test,mid,final;
    cin>>name>>test>>mid>>final;
    s1.setName(name);
    s1.setTest(test);
    s1.setMidterm(mid);
    s1.setFinal(final);
    cout<<"After modifiy s1 is ";
    s1.print();
}
int main()
{
    Q9_Test();

    system("Pause");
    return 0;
}
