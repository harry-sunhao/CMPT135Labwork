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
        cout<<"This rectangle's length is "<<length<<" and width is "<<width<<" , the area is "<<getArea()<<" and perimeter is "<<getPerimeter()<<endl;
    }
};
Rectangle::Rectangle(double newLength, double newWidth)
{
    setLength(newLength);
    setWidth(newWidth);
}

int main()
{
    /*Rectangle R1,R2(2.0,2.0);
    R1.print();
    R2.print();
    if(R1.getPerimeter()<R2.getPerimeter())
    {
        R1.setWidth(R2.getWidth()*2);
        R1.setLength(R2.getLength()*2);
    }
    cout<<"After modify...."<<endl;
    R1.print();
    R2.print();
    if(R1.getArea()>R2.getArea())
        cout<<"Rectangle 1 has the largest area."<<endl;
    else
        cout<<"Rectangle 2 has the largest area."<<endl;
		*/
	//Point arr_p[10];
	//for(int i=0;i<10;i++)
	//{
	//	cout<<"Point p["<<i<<"] = ";
	//	arr_p[i].print();
	//	cout<<endl;
	//}
	//Point *arr_pPtr=new Point[10];
	//for(int i=0;i<10;i++)
	//{
	//	cout<<"Point p["<<i<<"] = ";
	//	arr_pPtr[i].print();
	//	cout<<endl;
	//}
	//delete [] arr_pPtr;
	//Point p1,p2(1.0,2.0);
	//Point p;
	//Point &pRef=p;
	//Point *pPtr=&p;
	//p.setX(3.6);
	//pRef.setY(-3.6);
	//pPtr->setX(2.5);
	//cout<<"The point you created is ";
	//p.print();
	//pRef.print();
	//pPtr->print();
	//cout<<"The x-coordinate of opint p1 is "<<p1.getX()<<endl;
	//cout<<"The y-coordinate of opint p1 is "<<p1.getY()<<endl;
	//cout<<"The x-coordinate of opint p2 is "<<p2.getX()<<endl;
	//cout<<"The y-coordinate of opint p2 is "<<p2.getY()<<endl;
	//cout<<"Point p1 = ";
	//p1.print();
	//cout<<endl;
	//cout<<"Point p2 = ";
	//p2.print();
	//cout<<endl;
	Line_Test();
	system("Pause");
	return 0;
}
