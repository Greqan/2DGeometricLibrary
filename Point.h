#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point{
    private:
        double x;
        double y;
        double proximity;
        double angleratio;
    public:
        Point();
        Point(double x, double y);
        friend istream& operator >> (istream&,Point&);
        Point & operator=(const Point& b);
        void writePoint();
        friend class Polygon;
};

#endif // POINT_H
