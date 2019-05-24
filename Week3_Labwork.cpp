#include <iostream>
#include <cmath>

using namespace std;
class RationalNumber
{
    /*
    This class is designed to represent Rational Number objects.
    A rational number is a number of the form a/b with integers
    a and b such that b is different from 0.
    */
private:
    int a, b;
public:
    //Constructors
    RationalNumber();
    RationalNumber(int, int);

    //Getters
    int getNumerator();
    int getDenominator();

    //Setters
    void setNumerator(int num);
    void setDenominator(int denom);

    //Additional member functions
    double toDouble() const;
    void standardize();
    void reduce();
    void print();
    //Overloading operator
    RationalNumber operator -(const RationalNumber& r2);
    RationalNumber operator -(const int& x);
    friend RationalNumber operator -(const int& x,const RationalNumber& r1);
    RationalNumber operator *(const RationalNumber& r2);
    RationalNumber operator *(const int& x);
    friend RationalNumber operator *(const int& x,const RationalNumber& r1);
    RationalNumber operator /(const RationalNumber& r2);
    RationalNumber operator /(int& x);
    friend RationalNumber operator /(const int& x,const RationalNumber& r1);
    // WQNMLGB Yonas
    // below this message It's alawys copy
    bool operator ==(const RationalNumber& r2);
    bool operator ==(const int& x);
    friend bool operator ==(const int& x,const RationalNumber& r1);
    bool operator !=(const RationalNumber& r2);
    bool operator !=(const int& x);
    friend bool operator !=(const int& x,const RationalNumber& r1);
    bool operator >(const RationalNumber& r2);
    bool operator >(const int& x);
    friend bool operator >(const int& x,const RationalNumber& r1);
    bool operator <(const RationalNumber& r2);
    bool operator <(const int& x);
    friend bool operator <(const int& x,const RationalNumber& r1);
    bool operator >=(const RationalNumber& r2);
    bool operator >=(const int& x);
    friend bool operator >=(const int& x,const RationalNumber& r1);
    bool operator <=(const RationalNumber& r2);
    bool operator <=(const int& x);
    friend bool operator <=(const int& x,const RationalNumber& r1);
    bool operator &&(const RationalNumber& r2);
    bool operator ||(const RationalNumber& r2);

    RationalNumber& operator --(){this->a-=this->b;return *this;}
    RationalNumber operator --(int DUMMY){RationalNumber temp=*this;--(*this);return temp;}

};
RationalNumber RationalNumber::operator-(const RationalNumber &r2)
{
    RationalNumber result(this->a*r2.b-this->b*r2.a,this->b*r2.b);
    return result;
}
RationalNumber RationalNumber::operator-(const int &x)
{
    RationalNumber result(x,1);
    return *this-result;
}
RationalNumber operator-(const int &x,const RationalNumber &r1)
{
    RationalNumber result(x,1);
    return result-r1;
}
RationalNumber RationalNumber::operator * (const RationalNumber &r2)
{
    RationalNumber result(this->a*r2.a,this->b*r2.b);
    return result;
}
RationalNumber RationalNumber::operator*(const int &x)
{
    RationalNumber result(x,1);
    return *this*result;
}
RationalNumber operator*(const int &x,const RationalNumber &r1)
{
    RationalNumber result(x,1);
    return result*r1;
}
RationalNumber RationalNumber::operator / (const RationalNumber &r2)
{
    RationalNumber result(this->b,this->a);
    return *this*result;
}
RationalNumber RationalNumber::operator / (int &x)
{
    if(x==0)
        return RationalNumber(0,1);
    RationalNumber result(1,x);
    return *this*result;
}
RationalNumber operator / (const int &x,const RationalNumber &r1)
{
    RationalNumber result(1,x);
    return result*r1;
}

bool RationalNumber::operator==(const RationalNumber &r2){return this->a==r2.a&&this->b==r2.b;}
bool RationalNumber::operator==(const int &x){return this->a==x&&this->b==1;}
bool operator==(const int& x,const RationalNumber& r1) {return r1.a==x&&r1.b==1;}

bool RationalNumber::operator!=(const RationalNumber &r2){return *this==r2;}
bool RationalNumber::operator!=(const int &x){return *this==RationalNumber(x,1);}
bool operator!=(const int& x,const RationalNumber& r1) {return x==r1;}

bool RationalNumber::operator > (const RationalNumber &r2){return this->toDouble()-r2.toDouble()>0;}
bool RationalNumber::operator > (const int &x) {return *this-x>0;}
bool operator > (const int &x, const RationalNumber &r1) {return x-r1>0;}

bool RationalNumber::operator < (const RationalNumber &r2){return this->toDouble()-r2.toDouble()<0;}
bool RationalNumber::operator < (const int &x) {return *this-x<0;}
bool operator < (const int &x, const RationalNumber &r1) {return x-r1<0;}

bool RationalNumber::operator >= (const RationalNumber &r2){return this->toDouble()-r2.toDouble()>=0;}
bool RationalNumber::operator >= (const int &x) {return *this-x>=0;}
bool operator >= (const int &x, const RationalNumber &r1) {return x-r1>=0;}

bool RationalNumber::operator <= (const RationalNumber &r2){return this->toDouble()-r2.toDouble()<=0;}
bool RationalNumber::operator <= (const int &x) {return *this-x<=0;}
bool operator <= (const int &x, const RationalNumber &r1) {return x-r1<=0;}

bool RationalNumber::operator&&(const RationalNumber &r2) {return this->toDouble()>0&&r2.toDouble()>0;}
bool RationalNumber::operator||(const RationalNumber &r2) {this->a>0||r2.a>0;}


//Constructors
RationalNumber::RationalNumber()
{
    //As a default object, let us construct 0/1 rational number
    a = 0;
    b = 1;
}
RationalNumber::RationalNumber(int num, int denom)
{
    //If the denominator parameter is 0, ignore it and use 1
    a = num;
    b = denom != 0 ? denom : 1;
    //Now that the object is created, standardize and reduce it
    standardize();
    reduce();
}
//Getters
int RationalNumber::getNumerator()
{
    return a;
}
int RationalNumber::getDenominator()
{
    return b;
}
//Setters
void RationalNumber::setNumerator(int num)
{
    a = num;
    //Now that numerator of an existing object is modified,
    //standardize it and reduce it
    standardize();
    reduce();
}
void RationalNumber::setDenominator(int denom)
{
    //If the denominator parameter is 0, ignore it and use 1
    b = denom != 0 ? denom : 1;
    //Now that denominator of an existing object is modified,
    //standardize it and reduce it
    standardize();
    reduce();
}
//Additional member functions
double RationalNumber::toDouble() const
{
    return static_cast<double>(a)/b;
}
void RationalNumber::standardize()
{
    if (b < 0)
    {
        a *= -1;
        b *= -1;
    }
}
void RationalNumber::reduce()
{
    if (a == 0)
    {
        b = 1;
        return;
    }
    else
    {
        //Remeber that the denominator is NEVER zero by design
        //Therefore here both numerator and denominator are non-zero.
        int m = abs(a);
        int n = abs(b);
        int gcd = m < n ? m : n;
        while (gcd > 0)
        {
            if (m % gcd == 0 && n % gcd == 0)
                break;
            gcd--;
        }
        a /= gcd;
        b /= gcd;
    }
}
void RationalNumber::print()
{
    cout << a << "/" << b;
}

int RationalNumber_Test()
{
    //Test constructors
    RationalNumber r1, r2(4, 6);
    RationalNumber *r3	= new RationalNumber();
    RationalNumber *r4;
    r4 = new RationalNumber(3, 6);
    bool isEqual=6==RationalNumber(6,4);
    cout<<isEqual<<endl;
    //Test getters
    cout << "r1 numerator is " << r1.getNumerator() << endl;
    cout << "r3 denominator is " << r3->getDenominator() << endl;
    //Test setters, standardize, reduce and print member functions
    r2.setDenominator(-10);
    cout << "r2 is now "; r2.print(); cout << endl;

    //Print all the objects
    cout << "r1 = "; r1.print(); cout << endl;
    cout << "r2 = "; r2.print(); cout << endl;
    cout << "r3 = "; r3->print(); cout << endl;
    cout << "r4 = "; r4->print(); cout << endl;

    //Test toDouble member function
    cout << "In double format, r4 = " << r4->toDouble() << endl;

    //Delete objects created on the heap
    delete r3;
    delete r4;

    //system("Pause");
    return 0;
}
class Complex
{

private:
    double m_r;
    double m_i;

public:
    Complex(const double r_=0, const double i_=0);
    bool operator==(const Complex);
    bool operator!=(const Complex);
    Complex operator+(const Complex);
    Complex operator-(const Complex);
    Complex operator*(const Complex);
    Complex operator/(const Complex);
    //getter
    double GetR()const;
    double GetI()const;
    //setter
    void SetR(const double);
    void SetI(const double);
    //function
    void print();
};
Complex::Complex(const double r_, const double i_){m_r=r_;m_i=i_;}
double Complex::GetR()const
{
    return m_r;
}

double Complex::GetI()const
{
    return m_i;
}

void Complex::SetR(const double r_)
{
    m_r = r_;
}
void Complex::SetI(const double i_)
{
    m_i = i_;
}

bool Complex::operator==(const Complex b_)
{
    return (this->GetR() == b_.GetR() && this->GetI() == b_.GetI());
}

bool Complex::operator!=(const Complex b_)
{
    return (this->GetR() != b_.GetR() && this->GetI() != b_.GetI());
}

Complex Complex::operator+( const Complex b_)
{
    Complex ret(this->GetR()+b_.GetR(), this->GetI()+b_.GetI());
    return ret;
}

Complex Complex::operator-(const Complex b_)
{
    Complex ret(this->GetR()-b_.GetR(), this->GetI()-b_.GetI());
    return ret;
}
Complex Complex::operator*(const Complex b_)
{
    double a=this->GetR(), b=this->GetI();
    double c=b_.GetR(), d=b_.GetI();

    Complex ret(a*c-b*d, b*c+a*d);

    return ret;
}

Complex Complex::operator/(const Complex b_)
{
    double a=this->GetR(), b=this->GetI();
    double c=b_.GetR(), d=b_.GetI();
    assert(c || d);

    Complex ret((a*c+b*d)/(c*c+d*d), (b*c-a*d)/(c*c+d*d));

    return ret;
}
void Complex::print() {cout<<GetR()<<"+"<<GetI()<<"i"<<endl;}
class Money {

public:

    Money();
    Money(int withDollars, int withCents);

    Money operator +( const Money& amount2);
    Money operator -( const Money& amount2);
    bool operator ==(const Money& amount2);
    friend ostream& operator <<(ostream& outputStream, const Money& amount);
    friend istream& operator >>(istream& inputStream, Money& amount);

    int getDollars() const { return dollars; }
    int getCents() const { return cents; }

    void setDollars(int);
    void setCents(int);

    Money percent(const Money& amount, double percentage) const;

private:

    int dollars;
    int cents;
};

const int asCents(const Money& amount) {
    int amountAsCents = amount.getCents() + amount.getDollars() * 100;
    return amountAsCents;
}
Money::Money() {dollars=0;cents=0;}
Money::Money(int withDollars, int withCents){setDollars(withDollars);setCents(withCents);}
void Money::setDollars(int dollars) {this->dollars=dollars;}
void Money::setCents(int Cents)
{
    if(Cents>99)
    {
        Cents=Cents-(99*Cents%99);
        setDollars(this->dollars+(Cents%99));
    }
    this->cents=Cents;
}
Money Money::operator +(const Money& amount2) {
    int centsSum = asCents(*this) + asCents(amount2);
    int absAllCents = abs(centsSum);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;
    if (centsSum < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}

Money Money::operator -(const Money& amount2) {
    int centsDifference = asCents(*this) - asCents(amount2);
    int absAllCents = abs(centsDifference);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;
    if (centsDifference < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}

bool Money::operator ==(const Money& amount2) {
    return ((this->getDollars() == amount2.getDollars())
            && (this->getCents() == amount2.getCents()));
}
ostream& operator <<(ostream& outputStream, const Money& amount) {
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if (amount.dollars < 0 || amount.cents < 0)
        outputStream << "$-";
    else
        outputStream << '$';
    outputStream << absDollars;
    if (absCents >= 10)
        outputStream << '.' << absCents;
    else
        outputStream << '.' << '0' << absCents;
    return outputStream;
}

istream& operator >>(istream& inputStream, Money& amount) {
    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.setDollars((int)amountAsDouble);
    amount.setCents((amountAsDouble-amount.dollars)*100);
    return inputStream;
}
int Money_main()
{
    Money yourAmount, myAmount(10, 9);
    cout << "Enter an amount of money: ";
    cin >> yourAmount;
    cout<<yourAmount<<endl;
    cout<<myAmount<<endl;
}
/*
 * In the imperial system of measuring of weight, a Weight is represented by two integer values representing
pounds and ounces where one pound is equal to 16 ounces.

Write a C++ class named Weight that represents weight in the imperial system.
Have proper constructors, getters, setters, any additional functions and operators (binary arithmetic operators, binary relational operators, unary arithmetic operators and streaming operators).

 In your unary operators, let the increment and decrement operators increment/decrement the ounce value by 1.
 Remember for any Weight object at any time, you must keep the value of the pound greater or equal to zero and the value of the ounces between 0 and 15.
 */

class Weight{
private:
    int pounds,ounces;
public:
    Weight(){pounds=0;ounces=0;};
    Weight(int pounds,int ounces){setPounds(pounds);setOunces(ounces);};
    //getter
    int getPounds() const {return pounds;}
    int getOunces() const {return ounces;}
    //setters
    void setPounds(int pounds){this->pounds=pounds;}
    void setOunces(int ounces)
    {
        if(abs(ounces)>15)
        {
            if(ounces>0)
            {
                setPounds(this->pounds+ounces/16);
                ounces=ounces%16;
                this->ounces=ounces;
            }
            else
            {
                setPounds(this->pounds-(abs(ounces)/16));
                ounces=abs(ounces)%16;
                this->ounces=ounces;
            }
        }
        if(ounces<0)
        {
            setPounds(this->pounds-1);
            this->ounces=15;
        }
        this->ounces=ounces;


    }
    //addtional function
    void print() const {cout<<pounds<<"."<<ounces<<endl;}
    //operators
    Weight operator +(const Weight& w)
    {
        Weight Result;
        Result.setPounds(this->pounds+w.getPounds());
        Result.setOunces(this->ounces+w.getOunces());
        return Result;
    }
    Weight operator -(const Weight& w)
    {
        Weight Result;
        Result.setPounds(this->pounds-w.getPounds());
        Result.setOunces(this->ounces-w.getOunces());
        return Result;
    }
    bool operator ==(const Weight& w)
    {
        return this->pounds==w.pounds&&this->ounces==w.ounces;
    }
    bool operator >(const Weight& w)
    {
        return (this->pounds+this->ounces*16)>(w.pounds+w.ounces*16);
    }
    bool operator >=(const Weight& w)
    {
        return (this->pounds+this->ounces*16)>=(w.pounds+w.ounces*16);
    }
    bool operator <(const Weight& w)
    {
        return (this->pounds+this->ounces*16)<(w.pounds+w.ounces*16);
    }
    bool operator <=(const Weight& w)
    {
        return (this->pounds+this->ounces*16)<=(w.pounds+w.ounces*16);
    }
    Weight& operator ++(){setOunces(this->ounces+1);return *this;}
    Weight operator ++(int B){Weight Temp=*this;setOunces(this->ounces+1);return Temp;}
    Weight& operator --(){setOunces(this->ounces-1);return *this;}
    Weight operator --(int B){Weight Temp=*this;setOunces(this->ounces-1);return Temp;}
    friend istream& operator >>(istream &input, Weight &w){cout<<"Enter a pounds";input>>w.pounds;cout<<"Enter a ounces";input>>w.ounces;return input;}
    friend ostream& operator <<(ostream output,Weight &w){output<<w.pounds<<" Pounds "<<w.ounces<<"Ounces"<<endl;}
};

int Weight_main()
{
    Weight w1,w2(2,13);
    cin>>w1;

    w2.print();
    w1.print();
    cout<<(w1>=w2)<<endl;
}

/*
 * . In Linear algebra, a vector in 2D is represented by a directed straight line from the origin to a point in the
2D plane. Essentially, a vector is therefore described by a Point in a 2D plane.
 Write a C++ class named Vector2D that represents vectors in 2D space. Have proper constructors, getters, setters, any additional
functions and operators (binary arithmetic operators, binary relational operators, unary arithmetic
operators and streaming operators). Remark:
 For binary arithmetic operators implement only vector addition and subtraction
 For binary relational operators use the length of the vector for comparison. Therefore v1 > v2 is
true if and only if v1 is longer than v2; and so on so forth.
 For unary operators increment or decrement the vector by unit length. Example is v1 has length 3.2
then ++v1 should modify v1 so that the length of v1 becomes 4.2
 For the streaming operators, print the vector object in a nice format of your choice.
 */

class Vector2D{
private:
    double X,Y;
public:
    Vector2D(){X=0;Y=0;}
    Vector2D(double X,double Y){this->X=X;this->Y=Y;}
    //getters
    double getX() const {return X;}
    double getY() const {return Y;}
    //setters
    void setX(int X){this->X=X;}
    void setY(int Y){this->Y=Y;}
    //addtional function
    void print(){cout<<"(0,0) -->"<<"("<<X<<","<<Y<<")"<<endl;}
    double getDistance() const {return sqrt(this->X*this->X+ this->Y*this->Y);}
    //operator
    Vector2D operator + (const Vector2D &v2 ) const
    {
        Vector2D V;
        V.setX(this->getX()+v2.getX());
        V.setY(this->getY()+v2.getY());
        return V;
    }
    Vector2D operator - (const Vector2D &v2 ) const
    {
        Vector2D V;
        V.setX(this->getX()-v2.getX());
        V.setY(this->getY()-v2.getY());
        return V;
    }
    bool operator > (const Vector2D &v2 ) const {return this->getDistance()>v2.getDistance();}
    bool operator < (const Vector2D &v2 ) const {return this->getDistance()<v2.getDistance();}
    Vector2D& operator ++()
    {
        double distance=getDistance();
        setY(distance/Y*(distance+1));
        setY(distance/X*(distance+1));
        return *this;
    }
    Vector2D operator ++(int X)
    {
        Vector2D temp=*this;
        *this=++(*this);
        return temp;
    }
    Vector2D& operator --()
    {
        double distance=getDistance();
        setY(distance/Y*(distance-1));
        setY(distance/X*(distance-1));
        return *this;
    }
    Vector2D operator --(int X)
    {
        Vector2D temp=*this;
        *this=--(*this);
        return temp;
    }
    friend istream & operator >>(istream & input,Vector2D v){cout<<"Enter a X value";input>>v.X;cout<<"Enter a Y value";input>>v.Y;return input;}
    friend ostream & operator <<(ostream & output,Vector2D v){output<<"("<<v.X<<","<<v.Y<<")"<<endl;return output;}

};
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
    double getDistance(Point);
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
double Point::getDistance(Point p2)
{
    return sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y));
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
/*
 * Consider a Triangle object. A Tringle is simply described by three points in 2D space. We have already
implemented the Point class. We may therefore create a Triangle class by having three member variables
of type Point.
 Write a C++ Triangle class providing constructors, getters, setters, and any other functions
you deem necessary. Provide at least one overloaded operator making sure to write legible C++ comments
describing what you are doing in your overloaded operator. In particular provide getArea and
getCircumference member functions. Make sure to use the functions in the Point class and avoid rewriting code unnecessarily. Provide a test main program to test your Triangle class.
 */
class Triangle
{
private:
    Point p1,p2,p3;
    float side1,side2,side3;
public:
    Triangle();
    Triangle(Point,Point,Point);

    //getter
    Point getPoint1();
    Point getPoint2();
    Point getPoint3();
    //setter
    void setPoint1(Point p1);
    void setPoint2(Point p2);
    void setPoint3(Point p3);

    float getArea();
    float getPerimeter();
    void print();
    void updateSide(){side1=p1.getDistance(p2);side2=p1.getDistance(p3);side3=p2.getDistance(p3);}

    //operator
    /*
     * == operator if and only if Area and Perimeter is equal
     */
    bool operator ==(Triangle t){return this->getArea()==t.getArea()&&this->getPerimeter()==t.getPerimeter();}
};
Triangle::Triangle() {p1=Point(0,0);p2=Point(0,0);p3=Point(0,0);updateSide();}
Triangle::Triangle(Point p1, Point p2,Point p3) {this->p1=p1;this->p2=p2;this->p3=p3;updateSide();}
Point Triangle::getPoint1() {return p1;}
Point Triangle::getPoint2() {return p2;}
Point Triangle::getPoint3() {return p3;}
void Triangle::setPoint1(Point p1) {this->p1=p1;updateSide();}
void Triangle::setPoint2(Point p2) {this->p2=p2;updateSide();}
void Triangle::setPoint3(Point p3) {this->p3=p3;updateSide();}
float Triangle::getArea()
{
    float s=(side1+side2+side3)/2;
    return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}
float Triangle::getPerimeter() {return side1+side2+side3;}
void Triangle::print()
{
    cout<<"3 Points are ";
    p1.print();
    p2.print();
    p3.print();
    updateSide();
    if (side1 == side2 && side1 == side3)
        cout<<"This triangle is equilateral"<<endl;
    else if (side1 == side2 || side1 == side3 || side2 == side3)
        cout<<"This triangle is isosceles"<<endl;
    else
        cout<<"This triangle is scalene"<<endl;

}

void Triangle_test()
{
    Point p1(1,1),p2(2,2),p3(3,3);
    Triangle t1(p1,p2,p3),t2;
    t1.print();
    t2.setPoint2(Point(3,0));
    t2.setPoint3(Point(3,4));
    t2.print();
    cout<<"T2's area is "<<t2.getArea()<<endl;
    cout<<"T2's circumference is "<<t2.getPerimeter()<<endl;
    Triangle t3;
    t3.setPoint3(p1);
    t3.setPoint2(p2);
    t3.setPoint1(p1);
    if(t3==t1)
        cout<<"These two triangle have the same Area and Circumference"<<endl;
    else
        cout<<"These two triangle have the different Area and Circumference"<<endl;
}

int main()
{
    Triangle_test();
}
