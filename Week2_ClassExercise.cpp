#include<iostream>

using namespace std;
class Point
{
private:
	float x,y;
public:
	Point();
	Point(float newX,float newY);
	float getX();
	float getY();
	void setX(float newX);
	void setY(float newY);
	void print();
};
Point::Point(){x=0.0;y=0.0;}
Point::Point(float newX,float newY){x=newX;y=newY;}
float Point::getX(){return x;}
float Point::getY(){return y;}
void Point::setX(float newX){x=newX;}
void Point::setY(float newY){y=newY;}
void Point::print(){cout<<"("<<x<<", "<<y<<")";}
class Line
{
private:
	Point start, end;
public:
	Line();
	Line(Point s, Point e);

	Point getStartPoint();
	Point getEndPoint();

	void setStartPoint(Point s);
	void setEndPoint(Point e);

	float getLength();
	void print();
};
Line::Line()
{

}
Line::Line(Point s, Point e)
{
	setStartPoint(s);
	setEndPoint(e);
}

Point Line::getStartPoint()
{
	return start;
}
Point Line::getEndPoint()
{
	return end;
}

void Line::setStartPoint(Point s)
{
	start = s;
}
void Line::setEndPoint(Point e)
{
	end = e;
}
float Line::getLength()
{
	float distance1=end.getX() - start.getX();
	float distance2=end.getY() - start.getY();
	return sqrt(distance1*distance1+distance2*distance2);
}
void Line::print()
{
	start.print();
	cout << "-->";
	end.print();
}
void Line_Test()
{
	Line l1;
	Point p1,p2(1,2);
	Line l2(p1,p2);
	cout<<"Line 1 is ";l1.print();cout<<endl;
	cout<<"Line 2 is ";l2.print();cout<<endl;
	cout<<"Start Point of l1 is ";
	l1.getStartPoint().print();
	cout<<endl;
	cout<<"The length of l2 is "<<l2.getLength()<<endl;
	l1.setEndPoint(Point(3,5));
	cout<<"After modified l1 is ";
	l1.print();
	cout<<endl;
	cout<<"The length of l1 is now "<<l1.getLength()<<endl;
}
class Rectangle
{
    private:
        double length,width;
    public:
    Rectangle()
    {
        length=1.0;
        width=1.0;
    };
    Rectangle(double newLength,double newWidth);

    double getLength()
    {
        return length;
    }
    double getWidth()
    {
        return width;
    }
    void setLength(double newLength)
    {
        length=newLength;
    }
    void setWidth(double newWidth)
    {
        width=newWidth;
    }
    double getArea()
    {
        return length*width;
    }
    double getPerimeter()
    {
        return 2*length+2*width;
    }
    void print()
    {
        cout<<"length is "<<length<<" and width is "<<width<<" , the area is "<<getArea()<<" and perimeter is "<<getPerimeter()<<endl;
    }
};
Rectangle::Rectangle(double newLength, double newWidth)
{
    setLength(newLength);
    setWidth(newWidth);
}
void Rectangle_Test()
{
	Rectangle r1,r2(3,4),r3(1,2);
	Rectangle r4=r2;
	cout<<"r1 length = "<<r1.getLength()<<endl;
	cout<<"r2 width = "<<r2.getWidth()<<endl;
	cout<<"r3 area = "<<r3.getArea()<<endl;
	cout<<"r4 perimeter = "<<r4.getPerimeter()<<endl;

	cout<<"Rectangle r1 is ";
	r1.print();cout<<endl;
	
	cout<<"Rectangle r2 is ";
	r2.print();cout<<endl;

	r1.setLength(5);
	r1.setWidth(9);
	cout<<"After modifying its length and width, r1 is now ";
	r1.print();cout<<endl;

}
int main()
{
	Rectangle_Test();
	//Line_Test();
	system("Pause");
	return 0;
}
