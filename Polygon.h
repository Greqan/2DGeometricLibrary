#ifndef POLYGON_H
#define POLYGON_H
#include "Figure.h"

using namespace std;

class Polygon: public Figure
{
    private:
        Point *coor_angles;
        int amount_angles;
        bool doublecomparer(double a, double b);
        static bool comparer(Point a, Point b);
        void anglesort();
    public:
        Polygon();
        Polygon(const Polygon &a);
        Polygon(int amount_angles);
        virtual ~Polygon();
        Figure* clone(Figure*);
        bool set_by_file(string &file_name);
        void coor_in_console();
        virtual Polygon operator+(const Polygon &b);
        Polygon & operator=(const Polygon& b);
        double field();
};

#endif // POLYGON_H
