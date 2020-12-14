#pragma once
#include <vector>
#include <complex>
#include <iostream>

using namespace std;

class Pierwiastek
{
public:
	Pierwiastek();
	~Pierwiastek();
	virtual void obliczpierwiastki() = 0;
	virtual void wypiszpierwiastki() = 0;
	virtual void obliczsume() = 0;
	virtual void obliczroznice() = 0;
	std::vector<double>dane;
	std::vector<std::complex<double>>wyniki;
	std::vector<std::complex<double>>sumy;
	std::vector<std::complex<double>>roznice;
	double delta;
	double pdelta;
};

class Dodatniadel: public Pierwiastek
{
public:
	Dodatniadel(vector<double> dane,double del, double pdel);
	Dodatniadel();
	void obliczpierwiastki();
	void wypiszpierwiastki();
	void obliczsume();
	void obliczroznice();

};
class Ujemndel :public Pierwiastek
{
public:
	Ujemndel(vector<double> dane, double del, double pdel);
	Ujemndel();
	void obliczpierwiastki();
	void wypiszpierwiastki();
	void obliczsume();
	void obliczroznice();


};
class Zerodel :public Pierwiastek
{
public:
	Zerodel(vector<double> dane, double del, double pdel);
	Zerodel();
	void obliczpierwiastki();
	void wypiszpierwiastki();
	void obliczsume();
	void obliczroznice();

};
class Rownanielin : public Pierwiastek
{
public:
	Rownanielin(vector<double> dane,double del, double pdel);
	Rownanielin();
	void obliczpierwiastki();
	void wypiszpierwiastki();
	void obliczsume();
	void obliczroznice();
};