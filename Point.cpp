#include "Point.h"
Point::Point()
{
    this->x=0;
    this->y=0;
}


Point::Point(double x, double y)
{
    this->x=x;
    this->y=y;
}


istream& operator>> (istream &input, Point& a)
{
   input >> a.x >> a.y;
   return input;
}

void Point::writePoint()
{
    cout << x << " " << y << endl;
}


Point & Point::operator=(const Point& b)
{
    x=b.x;
    y=b.y;
    proximity=b.proximity;
    angleratio=b.angleratio;
    return *this;
}
