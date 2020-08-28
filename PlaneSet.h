#include <vector>
#include "Plane.h"
using namespace std;

class PlaneSet
{
    private:
        vector<Plane> planes;
    public:
        void add_plane(const Plane a);
        void planeset_in_console();
        void delete_plane(int index);
};
