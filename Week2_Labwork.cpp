#include<iostream>
#include <cmath>

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
    cout<<"The Triangle is "<<side1<<", "<<side2<<", "<<side3<<" and the area is "<<getArea()<<" and the circumference is "<<getPerimeter()<<" ";
    
}

int main()
{
    Q7_Test();

    system("Pause");
    return 0;
}
