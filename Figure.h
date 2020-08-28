#ifndef FIGURE_H
#define FIGURE_H
#include "Point.h"
#include <cmath>
#include <algorithm>
#include <fstream>
class Figure
{
    public:
        virtual ~Figure(){};
        virtual double field()=0;
        virtual Figure* clone(Figure*) = 0;
        virtual void coor_in_console()=0;
};

#endif // FIGURE_H
