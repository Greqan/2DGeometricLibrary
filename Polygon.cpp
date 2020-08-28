#include "Polygon.h"

using namespace std;

Polygon::Polygon(){
    coor_angles=nullptr;
    amount_angles=0;
};

Polygon::Polygon(int amount_angles)
{
    this->amount_angles=amount_angles;
    coor_angles=new Point[amount_angles];
}

Polygon::~Polygon()
{
    if(coor_angles != nullptr)delete [] coor_angles;
    coor_angles = nullptr;
}

bool Polygon::set_by_file(string &file_name)
{
    fstream file;
    file.open(file_name, ios::in);
    if(!file.good()){cout << "Wrong file." << endl; return false;}
    int i=0;
    while(true)
    {
        if(file.good()){
            file >> coor_angles[i];
            ++i;
            file >> coor_angles[i];
            ++i;
        }
        else{
             break;
        }
    }
    file.close();
    return true;
}


void Polygon::coor_in_console()
{
    cout << amount_angles << "-kat" << endl;
    for(int i=0; i<amount_angles; i++){
        coor_angles[i].writePoint();
    }
}

Polygon Polygon::operator+(const Polygon &b)
{
    int to_return_amount_angles=this->amount_angles+b.amount_angles;
    Polygon to_return(to_return_amount_angles);
    int i;
    for(i=0; i<this->amount_angles; i++){
        to_return.coor_angles[i]=this->coor_angles[i];
    }
    int counter=0;
    for(int l=i; l<to_return_amount_angles; l++){
        to_return.coor_angles[l]=b.coor_angles[counter];
        counter++;
    }
    to_return.anglesort();
    return to_return;
}

Figure* Polygon::clone(Figure* figure){
    return new Polygon(*(Polygon*)figure);
}

Polygon & Polygon::operator=(const Polygon& b)
{
    if(this->coor_angles!=nullptr)delete coor_angles;

        this->amount_angles=b.amount_angles;
        this->coor_angles=new Point[this->amount_angles];
        for(int i=0; i<b.amount_angles; i++){
            coor_angles[i]=Point(b.coor_angles[i]);
        }

    return *this;
}

bool Polygon::doublecomparer(double a, double b){
    if(fabs(a - b) < 0.0001) return 1;
    else return 0;
}

bool Polygon::comparer(Point a, Point b){
    if(a.angleratio != b.angleratio) return a.angleratio < b.angleratio;
    else {
        return a.proximity < b.proximity;
    }
}


void Polygon::anglesort(){
    //znajduje punkt odniesienia
    #define a coor_angles
    #define table_size amount_angles //uzywam define poniewaz sortowanie katowe napisalem wczesniej - strukturalnie
    int indexbegin=0;
    double minimum_x=a[0].x;
    double minimum_y=a[0].y;
    for(int i=0; i<table_size; i++){
        if(minimum_y > a[i].y){
            minimum_x = a[i].x;
            minimum_y = a[i].y;
            indexbegin = i;
        }
        else if(doublecomparer(minimum_y, a[i].y) && minimum_x > a[i].x){
            minimum_x = a[i].x;
            indexbegin = i;
        }
    }
    swap(a[0], a[indexbegin]);

//obliczam odleglosci wierzcholkow od punktow odniesienia
    for(int i=1; i<table_size; i++){
        a[i].proximity=sqrt(pow((a[i].x-minimum_x),2)+pow((a[i].y-minimum_y),2));
        a[i].angleratio=(a[i].y-minimum_y)/a[i].proximity;
        if(a[i].x-minimum_x<0)a[i].angleratio=3-a[i].angleratio;
    }
    sort(a+1,a+table_size,comparer);
}

double Polygon::field(){
    double sum=0;
    double x_beginning=coor_angles[0].x;
    double y_beginning=coor_angles[0].y;
    int i;
    for(i=0; i<amount_angles-2; i++){
        sum+=(coor_angles[i].x*coor_angles[i+1].y-coor_angles[i+1].x*coor_angles[i].y);
    }
    sum+=(-(coor_angles[i].x*x_beginning)+y_beginning*coor_angles[i].y);
    return sum;
}

Polygon::Polygon(const Polygon &b){
    amount_angles=b.amount_angles;
    coor_angles=new Point[amount_angles];
    for(int i=0; i<b.amount_angles; i++){
        coor_angles[i]=b.coor_angles[i];
    }
}
