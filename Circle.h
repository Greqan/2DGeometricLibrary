#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"

class Circle: public Figure
{
    private:
        Point s;
        double r;
    public:
        Circle();
        Circle(const Circle &a);
        Circle(Point center, double radius);
        double field();
        Figure* clone(Figure*);
        void coor_in_console();
        ~Circle();
};

#endif // CIRCLE_H
