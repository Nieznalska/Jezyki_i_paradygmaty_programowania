#pragma once
#include "Pierwiastek.h"
#include <iostream>
#include <cmath>
#include <vector>

class Rownanie
{
public:
	Rownanie();
	~Rownanie();
	Pierwiastek*pierwiastki;
	std::vector<double> dane;
	double delta;
	double pdelta;

	void wypiszrownanie();
	void obliczdelte();
	void obliczrownanie();

};

