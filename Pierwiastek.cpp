#include "pch.h"
#include "Pierwiastek.h"


Pierwiastek::Pierwiastek()
{
}


Pierwiastek::~Pierwiastek()
{
}

Dodatniadel::Dodatniadel(vector<double> dane, double del, double pdel)
{
	this->dane = dane;//
	delta = del;
	pdelta = pdel;
}

Dodatniadel::Dodatniadel()
{
}

void Dodatniadel::obliczpierwiastki()
{
  double x1r = (-dane.at(1) - pdelta) / (2 * dane.at(0));
  double x2r = (-dane.at(1) + pdelta) / (2 * dane.at(0));
	if (x1r > 0) {
		wyniki.push_back(sqrt({ wyniki[0].real()}));
		//x1r = sqrt(x1r);
		double x3r = -x1r;
		wyniki.push_back(complex<double>(x3r));
	}
	if (x1r < 0) {
		double x1u = sqrt(fabs(x1r));
		wyniki.push_back(complex<double>({0, x1u}));
		//x1r = 0;
		//wyniki.push_back(complex<double>(x1r));
		double x3u = -x1u;
		wyniki.push_back(complex<double>(x3u));
	}
	if (x2r > 0) {
		x2r = sqrt(x2r);
		wyniki.push_back(sqrt(complex<double>(x2r)));
		double x4r = -x2r;
		wyniki.push_back(sqrt(complex<double>(x4r)));
	}
	if (x2r < 0) {
		double x2u = sqrt(fabs(x2r));
		x2r = 0;
		wyniki.push_back(sqrt(complex<double>(x2u)));
		double x4u = -x2u;
		wyniki.push_back(sqrt(complex<double>(x4u)));

	}
	obliczroznice();
	obliczsume();
	wypiszpierwiastki();
}

void Dodatniadel::wypiszpierwiastki()
{
	printf("Rownanie posiada cztery rozwiazania: \n");
	cout << "x1="  << wyniki[0]<<"\n";
	cout << "x2=" << wyniki[1] << "\n";
	cout << "x3=" << wyniki[2] << "\n";
	cout << "x4=" << wyniki[3] << "\n";
}

void Dodatniadel::obliczsume()
{
	sumy.push_back(wyniki[0] + wyniki[1]+wyniki [2]+wyniki [3]);
	//double sr = wyniki.at(0).real + wyniki.at(1).real + wyniki.at(2).real + wyniki.at(3).real;
	//double su = wyniki.at(0).imag + wyniki.at(1).imag + wyniki.at(2).imag+ wyniki.at(3).imag;
	//sumy.push_back(sr);
	//sumy.push_back(su);
}

void Dodatniadel::obliczroznice()
{
	roznice.push_back(wyniki[0] - wyniki[1]-wyniki[2]-wyniki[3]);
	//double rr = wyniki.at(0).real - wyniki.at(1).real -wyniki.at(2).real -wyniki.at(3).real;
	//double ru = wyniki.at(0).imag - wyniki.at(1).imag - wyniki.at(2).imag- wyniki.at(3).imag;
	//roznice.push_back(rr);
	//roznice.push_back(ru);

}

Ujemndel::Ujemndel(vector<double> dane, double del, double pdel)
{
	this->dane = dane;//
	delta = del;
	pdelta = pdel;
}

Ujemndel::Ujemndel()
{
}

void Ujemndel::obliczpierwiastki()
{
 double x1r, x1u = 0;
	x1r = (-1.0 *dane[1]) / (2 * dane[0]);
	x1u = -pdelta / (2 * dane[0]);
	

	double tempX1R = x1r, tempX1U = x1u, tempX2R = x1r, tempX2U = -x1u;
	x1r = sqrt((sqrt(tempX1R* tempX1R + tempX1U * tempX1U) + tempX1R) / 2);
	x1u = sqrt((sqrt(tempX1R* tempX1R + tempX1U * tempX1U) - tempX1R) / 2);
	wyniki.push_back(complex<double>({ x1r, x1u }));
	double x2r = sqrt((sqrt(tempX2R* tempX2R + tempX2U * tempX2U) + tempX2R) / 2);
	double x2u = sqrt((sqrt(tempX2R* tempX2R + tempX2U * tempX2U) - tempX2R) / 2);
	wyniki.push_back(complex<double>({ x2r, x2u }));
	x2r = -x2r;
	double x3r = x1r;
	double x3u = -x1u;
	wyniki.push_back(complex<double>({ x3r, x3u }));
	double x4r = x2r;
	double x4u = -x2u;
	wyniki.push_back(complex<double>({ x4r, x4u }));
	obliczroznice();
	obliczsume();
	wypiszpierwiastki();
}

void Ujemndel::wypiszpierwiastki()
{
	printf("Rownanie posiada cztery rozwiazania: \n");
	cout << "x1=" << wyniki[0] << "\n";
	cout << "x2=" << wyniki[1] << "\n";
	cout << "x3=" << wyniki[2] << "\n";
	cout << "x4=" << wyniki[3] << "\n";
}

void Ujemndel::obliczsume()
{

	sumy.push_back(wyniki[0] + wyniki[1] + wyniki[2] + wyniki[3]);
	
}

void Ujemndel::obliczroznice()
{
	roznice.push_back(wyniki[0] - wyniki[1] - wyniki[2] - wyniki[3]);

}

Zerodel::Zerodel(vector<double> dane, double del, double pdel)
{
	this->dane = dane;
	delta = del;
	pdelta = pdel;
}

Zerodel::Zerodel()
{
}

void Zerodel::obliczpierwiastki()
{
	double x1r, x1u,x2r,x2u= 0;
    x1r = -dane[1] / (2 * dane[0]);
	if (x1r > 0) {
		x1r = sqrt(x1r);
		wyniki.push_back(complex<double>({ x1r, x1u }));
	    x2r = -x1r;
		double x2u = 0;
		wyniki.push_back(complex<double>({ x2r, x2u }));
	}
	else if (x1r < 0) {
		x1u = sqrt(fabs(x1r));
		x1r = 0;
		x2u = -x1u;
		x2r = 0;
		wyniki.push_back(complex<double>({ x1r, x1u }));
		wyniki.push_back(complex<double>({ x2r, x2u }));
	}
	obliczroznice();
	obliczsume();
	wypiszpierwiastki();
}

void Zerodel::wypiszpierwiastki()
{
	printf("Równanie ma dwa rozwiazania :");
	cout << "x1=" << wyniki[0] << "\n";
	cout << "x2=" << wyniki[1] << "\n";
}

void Zerodel::obliczsume()
{
	sumy.push_back(wyniki[0] + wyniki[1]);

}

void Zerodel::obliczroznice()
{
	roznice.push_back(wyniki[0] - wyniki[1]);
}

Rownanielin::Rownanielin(vector<double> dane, double del, double pdel)
{
	this->dane = dane;//
	delta = del;
	pdelta = pdel;
}

Rownanielin::Rownanielin()
{
}

void Rownanielin::obliczpierwiastki()
{
	double x1r,x2r,x1u,x2u;
	if (dane[1] != 0 && dane[2] != 0) {
		double t, pt;
		t = (-1.0*dane[2]) / dane[1];
		pt = sqrt(fabs(t));
		if (t > 0) {
			x1r = pt;
			x2r = -pt;
			x1u = 0;
			x2u = 0;
			wyniki.push_back(complex<double>({ x1r, x1u }));
			wyniki.push_back(complex<double>({ x2r, x2u }));
		}
		else if (t < 0) {
		
			x1u = pt;
			x2u = -pt;
			wyniki.push_back(complex<double>({ 0, x1u }));
			wyniki.push_back(complex<double>({ 0, x2u }));
		}
	}
	else if (dane[1] != 0 && dane[2] == 0)
		x1r = 0;
	wyniki.push_back(complex<double>({ x1r, 0 }));
	obliczroznice();
	obliczsume();
	wypiszpierwiastki();
}

void Rownanielin::wypiszpierwiastki()
{
	printf("Równanie ma dwa rozwiazania :");
	cout << "x1=" << wyniki[0] << "\n";
	cout << "x2=" << wyniki[1] << "\n";
}

void Rownanielin::obliczsume()
{

	sumy.push_back(wyniki[0] + wyniki[1]);
}

void Rownanielin::obliczroznice()
{
	
	roznice.push_back(wyniki[0] - wyniki[1]);
}
