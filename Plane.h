#ifndef PLANE_H
#define PLANE_H
#include <vector>
#include "Polygon.h"

using namespace std;

class Plane
{
    private:
        vector<Figure*> figures;
    public:
        Plane();
        Plane(const Plane &a);
		Plane operator=(const Plane &b);
        ~Plane();
        void add_figure(Figure *a);
        void plane_in_console();
        void delete_figure(int index);
};

#endif // PLANE_H
