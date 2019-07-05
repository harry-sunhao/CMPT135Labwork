#include <iostream>
#include<string>
#include <cmath>

using namespace std;

class Ellipse
{
private:
    double minorAxis, majorAxis;
public:
    //Constructors
    Ellipse(){this->majorAxis=0;this->minorAxis=0;}
    Ellipse(const double &mi, const double &ma){this->minorAxis=mi;this->majorAxis=ma;}
    Ellipse(const Ellipse &e){this->minorAxis=e.getMinorAxis();this->majorAxis=e.getMajorAxis();}

    //Getters
	double getMinorAxis() const	{return this->minorAxis;}
    double getMajorAxis() const {return this->majorAxis;}

    //Setters
    void setMinorAxis(const double &mi){this->minorAxis=mi;}
    void setMajorAxis(const double &ma){this->majorAxis=ma;}
    
    //Other member functions
    double getArea() const{return minorAxis*majorAxis*3.14;}        //Use 3.14 for the value of PI
    double getCircumference() const{return 2*3.14*sqrt((majorAxis*majorAxis+minorAxis*minorAxis)/2);}    //Use 3.14 for the value of PI

	friend ostream& operator << (ostream &outputStream, const Ellipse &e)
	{
		outputStream<<"Ellipse object: MinorAxis = "<< e.getMinorAxis()<<", MajorAxis = "<<e.getMajorAxis()<<", Area = "<<e.getArea()<<", Circumference = "<<e.getCircumference()<<endl;
        return outputStream;
    }
	//Ellipse object: MinorAxis = 0, MajorAxis = 0, Area = 0, Circumference = 0
    friend istream& operator >> (istream &inputStream, Ellipse &e)
	{
		double temp;
		cout<<"Reading ellipse object..."<<endl;
		cout<<"Enter minorAxis ";
		inputStream>>temp;
		e.setMinorAxis(temp);
		cout<<"Enter majorAxis ";
		inputStream>>temp;
		e.setMajorAxis(temp);
		return inputStream;
	}
};

class Circle: public Ellipse
{
public:
    //Constructors
	Circle(){}
    Circle(const double &r):Ellipse(r,r){}
	Circle(const Circle &c){this->setRadius(c.getRadius());}

    //Getters
	double getRadius() const{return this->getMajorAxis();}

    //Setters
    void setMinorAxis(const double &mi){Ellipse::setMinorAxis(mi);Ellipse::setMajorAxis(mi);}
    void setMajorAxis(const double &ma){Ellipse::setMinorAxis(ma);Ellipse::setMajorAxis(ma);}
    void setRadius(const double &r){Ellipse::setMinorAxis(r);Ellipse::setMajorAxis(r);}

    //Other member functions
    friend ostream& operator << (ostream &outputStream, const Circle &c)
	{
		outputStream<<"Circle  object: Radius  = "<< c.getRadius()<<", Area = "<<c.getArea()<<", Perimeter = "<<c.getCircumference()<<endl;
        return outputStream;
    }
    friend istream& operator >> (istream &inputStream, Circle &c)
	{
		double temp;
		cout<<"Reading circle object..."<<endl;
		cout<<"Enter radius ";
		inputStream>>temp;
		c.setRadius(temp);
		return inputStream;
	}
};
int main()
{
    //Test Constructors, getters and output streaming operator
    Ellipse e1;
    Ellipse e2(2, 3);
    Ellipse e3 = e2;
    cout << "e1: " << e1 << endl;
    cout << "e2: " << e2 << endl;
    cout << "e3: " << e3 << endl;

    Circle c1;
    Circle c2(3);
    Circle c3 = c2;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;

    //Test setters
    e2.setMinorAxis(1.2);
    e3.setMajorAxis(3.5);
    cout << "e2: " << e2 << endl;
    cout << "e3: " << e3 << endl;

    c1.setMinorAxis(8);
    c2.setMajorAxis(4);
    c3.setRadius(6);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;

    //Test input stream operators
    cin >> e1;
    cin >> c1;
    cout << "e1: " << e1 << endl;
    cout << "c1: " << c1 << endl;

    //Test type casting
    Ellipse e4 = c1;
    cout << "e4: " << e4 << endl;
    cout << "c2 casted to ellipse: " << static_cast<Ellipse>(c2) << endl;
    
    system("Pause");
    return 0;
}
