// Poprawa JiPP labo 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
int a = 2;
int b = 3;
int c = 2;
double delta = 0;
double pdelta = 0;
double err = 0.000001;
double temp = 0;
double x1r = 0;
double x2r = 0;
double x1u = 0;
double x2u = 0;

int main()
{
	//////////////////////////////////////////////////////////////////////////////////
	///wypisywanie 
	printf("Rozwiazywanie rownania: ");
	if (a == 0 && b == 0 && c == 0)
		printf("0 ");
	if (a != 0)
		printf("%d%s ", a, a != 0 ? "xx" : "");
	if (b != 0) {
		if (b < 0)
			printf("%s (%d)x ", (a != 0) ? "+" : "", b);
		else
			printf("%s %dx ", (a != 0) ? "+" : "", b);
	}
	if (c != 0) {
		if (c < 0)
			printf("%s (%d) ", (a != 0 || b != 0) ? "+" : "", c);
		else
			printf("%s %d ", (a != 0 || b != 0) ? "+" : "", c);
	}
	printf_s("= 0\n");

	/////////////////////////////////////////////////////////////////////////////////
	
	if (a!=0)
	{
		delta = ((b*b) - (4 * (a*c)));
		if (delta >0)
		{
			printf_s("Delta: %f", delta);

			pdelta = delta;
		

///pierwiastkowanie delty
		et1:
			temp = (delta / pdelta + pdelta) / 2.0;
			if (pdelta != temp)
			{
				if (pdelta - temp < err)
					goto et2;
				else
					pdelta = temp;
			}
			else
			{
				if (temp == pdelta)
					goto et2;
			}
			goto et1;
		et2:
			printf("Sqrt delty wynosi: %f\n", pdelta);
			//znajdowanie miejsc zerowych
			x1r = 1.0 * (-b - pdelta) / (2 * a);
			x2r = 1.0 * (-b + pdelta) / (2 * a);
			printf("Rozwiazanie ma dwa rozwiazania: ");
			if (x1r >= 0)
				printf(" %f oraz ", x1r);
			else
				printf(" (%f) oraz", x1r);
			if (x2r >= 0)
				printf(" %f.\n", x2r);
			else
				printf(" (%f).\n", x2r);
			
			//wypisywanie pdelty  printf("%f",pdelta);

		}
		if (delta < 0)
		{
			printf_s("Delta: (%f)" ,delta);


			pdelta = -1 * delta;
			delta = pdelta;
		et3:
			temp = (delta / pdelta + pdelta) / 2.0;
			if (pdelta != temp)
			{
				if (pdelta - temp < err)
					goto et4;
				else
					pdelta = temp;
			}
			else
			{
				if (temp == pdelta)
					goto et4;
			}
			goto et3;
		et4:
			printf("Sqrt delty wynosi: %f\n", pdelta);
			//znajdowanie miejsc zerowych
			x1r = 1.0*(-b ) / (2 * a);
			x2r = x1r;
			x1u = 1.0*(-pdelta) / (2 * a);
			x2u = -x1u;
			printf("Rozwiazanie ma rozwiazania: ");
			if (x1r >= 0)
				printf(" %f oraz ", x1r);
			else
				printf(" (%f) oraz", x1r);
			if (x1u >= 0)
				printf(" %f oraz ", x1u);
			else
				printf(" (%f) oraz", x1u);
			if (x2r >= 0)
				printf(" %f.\n", x2r);
			else
				printf(" (%f).\n", x2r);
			if (x2u >= 0)
				printf(" %f.\n", x2u);
			else
				printf(" (%f).\n", x2u);


		}
		if (delta == 0)
		{
			x1r = 1.0*(-b) / (2 * a);
			// printf x1r
			printf("Posiada tylko jedno rozwiązanie : %f",x1r);
		}
	}
	else

	{
		if (b != 0)
		{
			x1r = (-1.0*c)/b;
			//ładne wypisywanie ujemne liczby w nawiasach 
			if (x1r < 0)
			{
				printf("Rozwiazanie: (%f)\n",x1r);
			}
			else
			{
				printf("Rozwiazanie: %f\n", x1r);
			}
		}
		else
		{
			if (c != 0)
				printf("Rownanie sprzeczne ");
			else
			{
				printf("Równanie tozsamosciowe");
			}
		}
	}
		
	
		printf("Koniec programu");

	}



