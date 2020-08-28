#include "Plane.h"

void Plane::add_figure(Figure* a){
    Figure *tmp = a->clone(a);
    figures.push_back(tmp);
}

Plane::Plane(){}

Plane::~Plane(){ //destruktor zostal zaprojektowany tak aby zniszczyc figury po usunieciu plaszczyzny
	for(auto &i: figures){
        if(i != nullptr) delete i;
    }
}

void Plane::delete_figure(int index){
    swap(this->figures[index], this->figures[figures.size()-1]);
    if(figures[figures.size()-1] != nullptr) delete figures[figures.size()-1];
	figures[figures.size() - 1] = nullptr;

	figures.pop_back();
}

void Plane::plane_in_console(){
    for(unsigned int i=0; i<this->figures.size(); i++){
        this->figures[i]->coor_in_console();
        cout << endl;
    }
}

Plane::Plane(const Plane &a){
    for(auto i: a.figures){
        Figure* tmp = i->clone(i);
        this->figures.push_back(tmp);
    }
}

Plane Plane::operator=(const Plane &a) {
	return Plane(a);
}
