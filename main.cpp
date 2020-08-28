//[PROE] Grzegorz Kania - Geometric Library
#include "Polygon.h"
#include "Plane.h"
#include "Circle.h"
#include "PlaneSet.h"
using namespace std;

int main()
{
	Polygon *a = new Polygon(4);
	Polygon *b = new Polygon(3);
	Polygon *d = new Polygon(4);
	Circle *circle = new Circle(Point(2, 1), 2);
	string filee1 = "czworokat.txt";
	string filee2 = "trojkat.txt";
	string filee3 = "kwadrat.txt";
	a->set_by_file(filee1);
	b->set_by_file(filee2);
	d->set_by_file(filee3);
	//test dodawania obiektow metoda otoczki wkleslej
	Polygon *c = new Polygon();
	(*c) = (*a) + (*b);
	c->coor_in_console();
	//koniec testu dodawania

	//test obliczania pola
	cout << "Pole wynosi " << c->field() << endl << endl;
	//koniec obliczania pola
	cout << "KONIEC TESTU FIGUR" << endl << endl;
	cout << "POCZATEK TESTU PRZECHOWYWANIA" << endl << endl;
	//test dodawania na i usuwania figur z plaszczyzny
	Plane plaszczyzna1;
	plaszczyzna1.add_figure(c);
	plaszczyzna1.add_figure(a);
	plaszczyzna1.add_figure(b);
	plaszczyzna1.add_figure(circle);
	plaszczyzna1.delete_figure(0);
	plaszczyzna1.plane_in_console();
	//koniec testu dodawania i usuwania instancji na plaszczyzne

	cout << "TEST ZBIORU PLASZCZYZN" << endl << endl;
	//test dodawania i usuwania plaszczyzn ze zbioru plaszczyzn
	PlaneSet zbior1;
	Plane plaszczyzna2;
	plaszczyzna2.add_figure(c);
	zbior1.add_plane(plaszczyzna1);
	zbior1.add_plane(plaszczyzna2);
	zbior1.planeset_in_console();
	zbior1.add_plane(plaszczyzna2);
	zbior1.delete_plane(0);
	//koniec testu

	//czyszczenie pozostalosci w pamieci
    delete a;
	delete b;
	delete circle;
	delete c;
	delete d;
	return 0;
}
