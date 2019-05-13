#include<iostream>

using namespace std;

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
    Rectangle R1,R2(2.0,2.0);
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
}
