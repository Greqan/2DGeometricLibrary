#include "PlaneSet.h"

void PlaneSet::add_plane(const Plane a){
    planes.push_back(Plane(a));
}

void PlaneSet::delete_plane(int index){
    swap(planes[index], planes[planes.size()-1]);
    planes.pop_back();
}

void PlaneSet::planeset_in_console(){
    for(unsigned int i=0; i<this->planes.size(); i++){
        planes[i].plane_in_console();
    }
}
