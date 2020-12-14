#include "pch.h"
#include "Rownanie.h"


Rownanie::Rownanie()
{
	int a, b, c;
	cout << "Wpisz liczby do rownania\n";
	cin >> a;
	dane.push_back(a);
	cout << "\n";
	cin >> b;
	dane.push_back(b);
	cout << "\n";
	cin >> c;
	dane.push_back(c);
	obliczdelte();
}


Rownanie::~Rownanie()
{
}

void Rownanie::wypiszrownanie()
{
	if (dane[0] == 0 && dane[1] == 0 && dane[2] == 0)
		cout << "0";
	if (dane[0] != 0)
		cout << dane[0] << "x^4";
	if (dane[1] != 0) {
		if (dane[1]< 0)
			if (dane[0]!= 0)
			{
				cout << "+" << dane[0] << "x^2";
			}
			else
			{
				cout << dane[1] << "x^2";
			}
		else
		{
			if (dane[0] != 0)
			{
				cout << "+" << dane[1] << "x^2";
			}
			else
			{
				cout << dane[1] << "x^2";
			}

		}

	}
	if (dane[2] != 0) {
		if (dane[2]< 0)
		{
			if ((dane[0] != 0) || (dane[1]!= 0))
			{
				cout << "+" << "(" << dane[2] << ")";
			}
			else
			{
				cout << dane[2];
			}
		}
		else
		{
			if ((dane[0] != 0) || (dane[1] != 0))
			{
				cout << "+" << dane[2];
			}
			else
			{

				cout << dane[2];
			}
		}

	}

	cout << "=0\n\n";
	if (dane[0] == 0 && dane[1] == 0 && dane[2] != 0) {
		printf("Rownanie sprzeczne\n");
		return;
	}
	if (dane[0] == 0 && dane[1] == 0 && dane[2] == 0) {
		printf("Rownanie tozsamosciowe\n");
		return;
	}
	if (dane[0]!= 0 && dane[1]== 0 && dane[2]== 0)
	{
		return;
	}
}

void Rownanie::obliczdelte()
{
	delta = 1.0* ((dane[1] * dane[1]) - (4 * (dane[0] * dane[2])));
	pdelta = sqrt(fabs(delta));
}

void Rownanie::obliczrownanie()
{
	obliczdelte();


	if (dane[0] != 0)
	{


		if (delta > 0)
		{

			pierwiastki = new Dodatniadel(dane, delta, pdelta);


		}
		if (delta < 0)
		{
			pierwiastki = new  Ujemndel(dane, delta, pdelta);


		}
		if (delta == 0)
		{
			pierwiastki = new Zerodel(dane,delta, pdelta);

		}

	}
	else

	{
		if (dane[1] != 0)
		{
			pierwiastki= new  Rownanielin (dane, delta, pdelta);
		}
		else
		{
			if (dane[2] != 0)
			{
				cout << "Poprostu " << dane[2];
				return;
			}
			else
			{
				return;
			}
		}
	}
	pierwiastki->obliczpierwiastki();
}
