#include <iostream>
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
        Cents=Cents-99;
        setDollars(this->dollars+1);
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
int main()
{
    Money yourAmount, myAmount(10, 9);
    cout << "Enter an amount of money: ";
    cin >> yourAmount;
    cout<<yourAmount<<endl;
    cout<<myAmount<<endl;
}
