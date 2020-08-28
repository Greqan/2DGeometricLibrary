#include "Circle.h"
using namespace std;

Circle::Circle()
{
    s=Point(0,0);
    r=0;
}

Circle::Circle(Point center, double radius)
{
    s=center;
    r=radius;
}

Circle::Circle(const Circle &a)
{
    s=a.s;
    r=a.r;
}

Circle::~Circle()
{
}

double Circle::field(){
    return 3.14*pow(r,2);
}

void Circle::coor_in_console(){
    cout << "Kolo(wsp srodka i promien)" << endl;
    s.writePoint();
    cout << r << endl;
}

Figure* Circle::clone(Figure* figure){
    return new Circle((*(Circle*)figure));
}
