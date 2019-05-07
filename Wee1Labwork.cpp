#include <iostream>

using namespace std;

struct RationalNumber
{
    int a,b;
};

double Q6_toDouble(RationalNumber n)
{
    return n.b/n.a;
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
