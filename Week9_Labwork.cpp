#include <iostream>
#include<string>
#include <cmath>

using namespace std;
/*
 Consider a class named BankAccount. A BankAccount class may have two member variables:
accountholder (string data type), balance (double data type). Implement the class BankAccount with all
the design concepts you learned during the lectures.
 */
class BankAccount
{
private:
    string accountholder;
    double balance;
public:
    BankAccount(){accountholder="";balance=0;}
    BankAccount(const string &name,const double &balance){this->accountholder=name;this->balance=balance;}
    BankAccount(const BankAccount &B){this->balance=B.balance;this->accountholder=B.accountholder;}

    BankAccount&operator =(const BankAccount &B)
    {
        if (this==&B)
            return *this;
        this->accountholder=B.accountholder;
        this->balance=B.balance;
        return *this;
    }

    string getAccountholder() const{return this->accountholder;}
    double getBalance() const {return this->balance;}

    void setAccountholder(const string name){this->accountholder=name;}
    void setBalance(const double balance){this->balance=balance;}

    friend istream& operator >>(istream& in,BankAccount &B)
    {
        cout<<"Reading this accountholder";
        in>>B.accountholder;
        cout<<"Reading this balance";
        in>>B.balance;
        return in;
    }
    friend ostream& operator <<(ostream& out, const BankAccount &B)
    {
        out<<"The accountholder is"<< B.getAccountholder()<<" and the balance is "<<B.getBalance()<<endl;
        return out;
    }

};
/*
 * Next consider a class named ChequingAccount. Clearly a ChequingAccount is a BankAccount. A
ChequingAccount may have one additional member variable which is the number of transactions per
month (numTransactions int data type). Implement a ChequingAccount class by extending it from
BankAccount class. Make sure to have the following two member functions for this class
 void deposit(const double &amount);
 void withdraw(const double &amount);
 */
class ChequingAccount: public BankAccount
{
private:
    int numTransactions=0;
public:
    ChequingAccount():BankAccount(){this->numTransactions=0;}
    ChequingAccount(string &name,double &balance):BankAccount(name,balance){this->numTransactions=0;}
    void deposit(const double &amount)
    {
        this->setBalance(this->getBalance()+amount);
        numTransactions++;
    }
    void withdraw(const double &amount)
    {
        this->setBalance(this->getBalance()-amount);
        numTransactions++;
    }
    int getNumTransactions(){return numTransactions;}
    double getBalance(){return this->getBalance();}
};
/*Finally consider SavingAccount which is a BankAccount again. SavingAccount may have two more
additional member variables which are daily interest rate (interestRate double data type) and the number
of days since the account was opened (numDays int data type). Implement a SavingAccount class by
extending it from BankAccount class. SavingAccount does not allow deposit or withdraw operations.*/
class SavingAccount:public BankAccount
{
private:
    double interestRate;
    int numDays;
public:
    void setInterestRate(const double &rate){this->interestRate=rate;}
    void setNumDays(const int &days){this->numDays=days;}
    double getInterestRate() const{return this->interestRate;}
    int getNumDays() const {return this->numDays;}
    double getBalance()
    {
        return this->getBalance()*(1+this->getInterestRate())*this->getNumDays();
    }
};
//Design a class named Ellipse that has two double member
//variables: minorAxis, majorAxis. Provide a default
//constructor (sets both member variables to 0.0), non-default
//constructor that takes two double arguments and sets the
//member variables to the parameter values, copy constructor,
//assignment operator, two getter member functions that
//return the values of the member variables, two setter
//member functions that set the values of the two member
//variables, and the functions getArea that returns 𝝅𝒂𝒃 and getCircumference that returns
//where a and b are the values of the minor and major axis. Provide also overloaded input/output streaming
//operators. In addition give overloaded input/output streaming operators.
#define PI acos(-1)
class Ellipse
{
private:
    double minorAxis, majorAxis;
public:
    Ellipse(){this->majorAxis=0;this->minorAxis=0;}
    Ellipse(const double &min,const double &maj){this->minorAxis=min;this->majorAxis=maj;}
    Ellipse(const Ellipse &E){this->minorAxis=E.minorAxis;this->majorAxis=E.majorAxis;}

    Ellipse&operator =(Ellipse&E)
    {
        if (this==&E)
            return *this;
        this->minorAxis=E.minorAxis;
        this->majorAxis=E.majorAxis;
        return *this;
    }

    void setminorAxis(const double& minorAxis){this->minorAxis=minorAxis;}
    void setmajorAxis(const double& majorAxis){this->majorAxis=majorAxis;}
    double getmajorAxis() const {return this->majorAxis;}
    double getminorAxis() const {return this->minorAxis;}
    double getArea(){return minorAxis*majorAxis*PI;}
    double getCircumference(){return 2*PI*sqrt((minorAxis*minorAxis+minorAxis*minorAxis)/2);}
    friend istream& operator >>(istream& in,Ellipse &E)
    {
        cout<<"Reading this minorAxis";
        in>>E.minorAxis;
        cout<<"Reading this majorAxis";
        in>>E.majorAxis;
        return in;
    }
    friend ostream& operator <<(ostream& out, const Ellipse &E)
    {
        out<<"The majorAxis is"<< E.getmajorAxis()<<" and the minorAxis is "<<E.getminorAxis()<<endl;
        return out;
    }
};
/*Design a class named Circle that inherits from the class Ellipse you
created above. The Circle class should not add any new member
variable; instead it must add additional behavior which is the
values of the member variables minorAxis and majorAxis must
always be the same. Provide default constructor that sets both the
values of both member variables to zero, non-default constructor
that takes one double argument and sets both member variables
to the value of the parameter, a copy constructor and an
assignment operator. Provide a member function named getRadius
that returns the radius of the circle and setRadius that takes one
double argument which sets both member variables to the value of
the parameter. Override (re-define) the setter functions defined
in the Ellipse class so that the Circle class will always have valid minor and major axis values. Provide also
the overloaded input/output streaming operators.*/
class Circle:public Ellipse
{
public:
    Circle():Ellipse(){}
    Circle(const double &r):Ellipse(r,r){}
    Circle(const Circle& C):Ellipse(C){}

    Circle&operator =(const Circle& C)
    {
        if(this==&C)
            return *this;
        Ellipse temp(C);
        this->Ellipse::operator=(temp);
        return *this;
    }
    double getRadius() const{return this->getmajorAxis();}
    void setRadius(const double&r){this->setminorAxis(r);this->setmajorAxis(r);}
    void setminorAxis(const double& r){this->setminorAxis(r);this->setmajorAxis(r);}
    void setmajorAxis(const double& r){this->setminorAxis(r);this->setmajorAxis(r);}
    friend istream& operator >>(istream& in,Circle &E)
    {
        cout<<"Reading this Radius";
        double r;
        in>>r;
        E.setRadius(r);
        return in;
    }
    friend ostream& operator <<(ostream& out, const Circle &E)
    {
        out<<"The Radius is"<< E.getRadius()<<endl;
        return out;
    }
};
/*
 * Consider a Cylinder object. A cylinder has a radius and a height.
 * A Cylinder IS-A Circle. Create a Cylinder class by inheriting the Circle class we created above.
 * A cylinder class adds one more member variable named height.
 * Provide a default constructor that sets both the radius and height of the cylinder to 0.0,
 * non-default constructor that takes two double arguments and sets the radius and the height of the cylinder,
 * a copy constructor and an assignment operator.
 * Provide getter and setter member functions to get and set the height of the cylinder.
 * Override (redefine) the getArea member function so that it returns the surface area of the Cylinder.
 * The surface area of a cylinder is given by 𝛑𝐫 𝟐 + 𝟐𝛑𝐫𝐡 where r is the radius of the cylinder and h is the height of the cylinder.
 * Provide additional member function named getVolume that takes no argument and returns the volume of the cylinder.
 * The volume of a cylinder is given by 𝛑𝐫 𝟐𝐡 where r is the radius of the cylinder and h is its height.
 * Provide also the overloaded input/output streaming operators.
Write a test main program to test your inheritance lineage
 */
class Cylinder:public Circle
{
private:
    double height;
public:
    Cylinder():Circle(){this->height=0;}
    Cylinder(const double&r, const double& h):Circle(r){this->height=h;}
    Cylinder(const Cylinder& C):Circle(C.getRadius()){this->height=C.getHeight();}

    Cylinder&operator=(Cylinder& C)
    {
        if(this==&C)
            return *this;
        Circle temp(C.getRadius());
        this->Circle::operator=(temp);
        this->setHeight(C.getHeight());
        return *this;
    }
    double getHeight()const {return this->height;}
    void setHeight(const double &h){this->height=h;}
    double getArea() const{return PI*this->getRadius()*this->getRadius()+2*PI*this->getRadius()*this->getHeight();}
    double getVolume() const {return PI*this->getRadius()*this->getRadius()*this->getHeight();}
    friend istream& operator >>(istream& in,Cylinder &E)
    {
        cout<<"Reading this Radius";
        double r,h;
        in>>r;
        E.setRadius(r);
        cout<<"Reading this Height";
        in>>h;
        E.setHeight(h);
        return in;
    }
    friend ostream& operator <<(ostream& out, const Cylinder &E)
    {
        out<<"The Radius is"<< E.getRadius()<<", the height is "<<E.getHeight()<<endl;
        return out;
    }
};
/*A Disk is a solid Cylinder. Disk object has the same member variables and
member functions as a Cylinder object except that it has both its top and
bottom sides closed and therefore its surface area is 𝟐𝛑𝐫
𝟐 + 𝟐𝛑𝐫𝐡. Create a
class named Disk that inherits the Cylinder class and overrides the getArea
member function. Provide default, non-default constructor, copy
constructors, and assignment operator. Provide also the overloaded
input/output streaming operators.
 */
class Disk: public Cylinder
{
public:
    Disk():Cylinder(){};
    Disk(const double&r,const double &h):Cylinder(r,h){}
    Disk(const Disk& D):Cylinder(D){};

    Disk&operator=(Disk& D)
    {
        if(this==&D)
            return *this;
        Cylinder C(D);
        this->Cylinder::operator=(C);
        return *this;
    }

    double getArea() const {return 2*PI*this->getRadius()*this->getRadius()+2*PI*this->getRadius()*this->getHeight();}
    friend istream& operator >>(istream& in,Disk &E)
    {
        cout<<"Reading this Radius";
        double r,h;
        in>>r;
        E.setRadius(r);
        cout<<"Reading this Height";
        in>>h;
        E.setHeight(h);
        return in;
    }
    friend ostream& operator <<(ostream& out, const Disk &E)
    {
        out<<"The Radius is"<< E.getRadius()<<", the height is "<<E.getHeight()<<endl;
        return out;
    }
};
/*Consider an Ellipsoid object. An Ellipsoid has a minor axis, a major axis, and a height. An Ellipsoid IS-A
Ellipse. Create an Ellipsoid class by inheriting the Ellipse class
we created above. An Ellipsoid class adds one more member
variable named height. Provide a default constructor that sets
all the minor axis, major axis and height of the Ellipsoid to 0.0,
non-default constructor that takes three double arguments
and sets the minor axis, major axis and the height of the
Ellipsoid, a copy constructor and assignment operator.
Provide getter and setter member functions to get and set the
height of the Ellipsoid. Override (redefine) the getArea
member function so that it returns the surface area of the
Ellipsoid. The surface area of an Ellipsoid is give by
where a,b,c are the minor axis,
major axis and height of the Ellipsoid and p has the value 1.6075. Provide additional member function
named getVolume that takes no argument and returns the volume of the Ellipsoid. The volume of an
Ellipsoid is given by
𝛑𝐚𝐛𝐡 where a is the minor axis of the Ellipsoid, b is its major axis, and h is its height.
Provide also the overloaded input/output streaming operators*/


class Ellipsoid:public Ellipse
{
private:
    double height;
public:
    Ellipsoid():Ellipse(){this->height=0;}
    Ellipsoid(const double&major,const double &minor, const double& h):Ellipse(minor,major){this->height=h;}
    Ellipsoid(const Ellipsoid& C):Ellipse(C.getminorAxis(),C.getmajorAxis()){this->height=C.getHeight();}
    Ellipsoid&operator=(Ellipsoid& D)
    {
        if(this==&D)
            return *this;
        Ellipse C(D);
        this->Ellipse::operator=(C);
        return *this;
    }
    double getHeight()const {return this->height;}
    void setHeight(const double &H){this->height=H;}
    double getArea() const
    {
        double a=this->getminorAxis();
        double b=this->getmajorAxis();
        double c=this->getHeight();
        double p=1.6075;
        double temp=pow(a,p)*pow(b,p)+pow(a,p)*pow(c,p)+pow(c,p)*pow(b,p);
        temp/=3;
        temp=pow(temp,1/p);
        temp=4*PI*temp;
        return temp;
    }
    double getVolume() const {return 3/4*(PI*this->getmajorAxis()*this->getminorAxis()*this->getHeight());}
    friend istream& operator >>(istream& in,Ellipsoid &E)
    {
        double temp;
        cout<<"Reading this minorAxis";
        in>>temp;
        E.setminorAxis(temp);
        cout<<"Reading this majorAxis";
        in>>temp;
        E.setmajorAxis(temp);
        cout<<"Reading this height";
        in>>temp;
        E.setHeight(temp);
        return in;
    }
    friend ostream& operator <<(ostream& out, const Ellipsoid &E)
    {
        out<<"The majorAxis is"<< E.getmajorAxis()<<" and the minorAxis is "<<E.getminorAxis()<<" and the Height is "<<E.getHeight()<<endl;
        return out;
    }
};
class PFArray
{
private:
    double* arr; //Dynamic array of double data type
    int capacity; //The size of the array
    int used; //The actual number of elements in the array
public:
    PFArray(){this->arr=new double[50];this->capacity=50;this->used=0;} //Default constructor: capacity = 50, used = 0
    PFArray(int capacityValue){this->arr=new double [capacityValue];this->capacity=capacityValue;this->used=0;} //Non-default constructor: capacity = capacityValue, used = 0
    PFArray(PFArray& pfA)
    {
        this->capacity=pfA.getCapacity();
        this->used=pfA.getNumberUsed();
        this->arr=new double[this->getCapacity()];
        for (int i = 0; i < this->getCapacity(); ++i) {
            this->arr[i]=pfA[i];
        }
    }//Copy constructor
    PFArray& operator = (PFArray& pfA)
    {
        if (this==&pfA)
            return *this;
        this->capacity=pfA.getCapacity();
        this->used=pfA.getNumberUsed();
        this->arr=new double[this->getCapacity()];
        for (int i = 0; i < this->getCapacity(); ++i) {
            this->arr[i]=pfA[i];
        }
        return *this;
    }//Assignment operator
    ~PFArray()
    {
        if(this->getCapacity()>0)
            delete [] this->arr;
    }//Destructor
    void addElement(double e)
    {
        if(this->getNumberUsed()<this->getCapacity()-1)
            this->arr[this->getNumberUsed()]=e;
    }//Add an element to the array at the appropriate index
//If the array is full then don't add the element (do nothing)
    bool full() const
    {
        if(this->getNumberUsed()<this->getCapacity()-1)
            return false;
        return true;
    }//Returns true if the array is full, false otherwise.
    int getCapacity() const{return this->capacity;}
    int getNumberUsed( ) const{return this->used;}
    void emptyArray()
    {
        this->used=0;
        this->arr=new double[this->getCapacity()];
    }//Resets the member variable to zero (used = 0)
    double& operator[](int index)
    {
        if(index>=0&&index<this->getCapacity())
            return this->arr[index];
        system("exit");
    }//element at index (system exit if index is out of bound)
};
class PFArrayWBU : public PFArray
{
private:
    double* arr_B; //backup for the array in the base class
    int used_B; //backup for the number of elements in the base class.
public:
    PFArrayWBU():PFArray(){} //Initializes with a capacity of 50.
    PFArrayWBU(int capacityValue):PFArray(capacityValue){}
    PFArrayWBU(const PFArrayWBU& Object);
    PFArrayWBU& operator = (const PFArrayWBU& rightSide);
    ~PFArrayWBU();
    void backup(); //Makes a backup copy of the partially filled array base class
    void restore();//Restores the partially filled array to the last saved version
//If backup has never been invoked, this empties the partially filled array.
};
