// Poprawa JiPP labo2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <stdio.h>
#include <math.h>


void wypisz(int*tab)
{
	printf("Rozwiazywanie rownania: ");
	if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0)
		printf("0 ");
	if (tab[0]!= 0)
		printf("%d%s ", tab[0], tab[0] != 0 ? "xx" : "");
	if (tab[1]!= 0) {
		if (tab[1] < 0)
			printf("%s (%d)x ", (tab[0] != 0) ? "+" : "", tab[1]);
		else
			printf("%s %dx ", (tab[0] != 0) ? "+" : "", tab[1]);
	}
	if (tab[2] != 0) {
		if (tab[2]< 0)
			printf("%s (%d) ", (tab[2] != 0 || tab[1] != 0) ? "+" : "", tab[2]);
		else
			printf("%s %d ", (tab[1] != 0 || tab[2] != 0) ? "+" : "",tab[2]);
	}
	printf_s("= 0\n");
}
void obliczdelte(int tab[3],double*delta,double*pdelta)
{
	*delta = 1.0* ((tab[1]*tab[1]) - (4 * (tab[0]*tab[2])));
	*pdelta = sqrt(fabs(*delta));
}
void rownanie(int*tab,double*delta,double*pdelta,double*x1r,double*x2r,double*x1u,double*x2u,double* x3r,double* x4r,double*x3u,double*x4u)
{

	if (tab[0] != 0)
	{

		obliczdelte(tab, delta, pdelta);
		//double temp1;
		if (*delta > 0)
		{
			
			*x1r = 1.0 * (-(tab[1]) - *pdelta) / (2 * tab[0]);
			*x2r = 1.0 * (-(tab[1]) + *pdelta) / (2 * tab[0]);
			if (*x1r < 0)
			{
				*x1u = sqrt(fabs(*x1r));
				*x2u = sqrt(fabs(*x1r))*(-1.0);
				*x1r = 0.0;
			}
			if (*x2r < 0)
			{
				*x3u = sqrt(fabs(*x2r));
				*x4u = sqrt(fabs(*x2r))*(-1.0);
				*x2r = 0.0;
			}
			if (*x2r > 0)
			{
				*x3r = sqrt(*x2r);
				*x4r = (-1.0)*(*x3r);
				*x2r = 0.0;
			}
			if (*x1r > 0)
			{
				*x2r = sqrt(*x1r)*(-1.0);
				*x1r = sqrt(*x1r);
			}
		}
		if (*delta < 0)
		{
			//znajdowanie miejsc zerowych
			*x1r = 1.0*(-1*(tab[1])) / (2 * tab[0]);
			*x2r = *x1r;
			*x1u = 1.0*(-*pdelta) / (2 * tab[0]);
			*x2u = -*x1u;
			
			*x3r = (sqrt((sqrt((*x2r)*(*x2r) + (*x2u)*(*x2u)) + (*x2r)) / 2))*(-1.0);
			*x4r = (sqrt((sqrt((*x2r)*(*x2r) + (*x2u)*(*x2u)) + (*x2r)) / 2));
			*x3u = (sqrt((sqrt((*x2r)*(*x2r) + (*x2u)*(*x2u)) - (*x2r)) / 2))*(-1.0);
			*x4u = (sqrt((sqrt((*x2r)*(*x2r) + (*x2u)*(*x2u)) - (*x2r)) / 2));
			double temp2 = (*x1r);
			*x2r = (sqrt((sqrt((temp2)*(temp2)+(*x1u)*(*x1u)) + (temp2)) / 2))*(-1.0);
			*x2u = (sqrt((sqrt((temp2)*(temp2)+(*x1u)*(*x1u)) - (temp2)) / 2));
			*x1r = (sqrt((sqrt((temp2)*(temp2)+(*x1u)*(*x1u)) + (temp2)) / 2));
			*x1u = (sqrt((sqrt((temp2)*(temp2)+(*x1u)*(*x1u)) - (temp2)) / 2))*(-1.0);

		}
		if (*delta == 0)
		{
			*x1r = 1.0*(-1*(tab[1]) )/ (2 * tab[0]);
			
			if (*x1r > 0)
			{
				*x2r = sqrt(*x1r)*(-1.0);
				*x1r = sqrt(*x1r);
			}
			if (*x1r < 0)
			{
				*x1u = sqrt(fabs(*x1r));
				*x2u = sqrt(fabs(*x1r))*(-1.0);
				*x1r = 0.0;
			}
		}

	}
	else

	{
		if (tab[1] != 0)
		{
			*x1r = (-1.0*(tab[2])) / (tab[1]);
			if (*x1r > 0)
			{
				*x2r = sqrt(*x1r)*(-1.0);
				*x1r = sqrt(*x1r);
			}
			if (*x1r < 0)
			{
				*x1u = sqrt(fabs(*x1r));
				*x2u = sqrt(fabs(*x1r))*(-1.0);
				*x1r = 0.0;
			}
		}
		
	}

}
void wypiszrozwiazanie(int*tab, double*delta, double*pdelta, double*x1r, double*x2r, double*x1u, double*x2u,double *x3r,double*x4r,double*x3u,double*x4u,double *rr,double *sr,double *su,double *ru)
{
	if (tab[0]!=0)
	{
		printf_s("Delta: %f", *delta );
		printf("Sqrt delty wynosi: %f\n",* pdelta);
		if (delta>0)
		{


			printf("Rownanie posiada cztery rozwiazania: \n");
			if (*x1r >= 0)
				printf(" %f + ", *x1r);
			else
				printf(" (%f) +", *x1r);
			if (*x1u >= 0)
				printf(" %fi oraz ", *x1u);
			else
				printf(" (%f)i oraz", *x1u);
			if (*x2r >= 0)
				printf(" %f + ", *x2r);
			else
				printf(" (%f) +", *x2r);
			if (*x2u >= 0)
				printf(" %fi oraz", *x2u);
			else
				printf(" (%f)i oraz", *x2u);
			if (*x3r >= 0)
				printf(" %f + ", *x3r);
			else
				printf(" (%f) +", *x3r);
			if (*x3u >= 0)
				printf(" %fi oraz", *x3u);
			else
				printf(" (%f)i oraz", *x3u);
			if (*x4r >= 0)
				printf(" %f + ", *x4r);
			else
				printf(" (%f) +", *x4r);
			if (*x4u >= 0)
				printf(" %fi.\n", *x4u);
			else
				printf(" (%f).\n", *x4u);
		}
		if (delta=0)
		{
			printf("Równanie ma dwa rozwiązania :");
			//printf("x1=%lf  \n", x1r);
			if (*x1r >= 0)
				printf(" %f + ", *x1r);
			else
				printf(" (%f) +", *x1r);
			if (*x1u >= 0)
				printf(" %fi oraz ", *x1u);
			else
				printf(" (%f)i oraz", *x1u);
			if (*x2r >= 0)
				printf(" %f + ", *x2r);
			else
				printf(" (%f) +", *x2r);
			if (*x2u >= 0)
				printf(" %fi oraz", *x2u);
			else
				printf(" (%f)i oraz", *x2u);
		}
		printf("\nSuma rozwiazan rzeczywistych: %f", *sr);
		printf("\nSuma rozwiazan urojonych: %f", *su);
		printf("\nRoznica rozwiazan rzeczywistych: %f", *rr);
		printf("\nRoznica rozwiazan urojonych: %f", *ru);
		if (delta<0)
		{
			printf("Rownanie posiada cztery rozwiazania: \n");
			if (*x1r >= 0)
				printf(" %f + ", *x1r);
			else
				printf(" (%f) +", *x1r);
			if (*x1u >= 0)
				printf(" %fi oraz ", *x1u);
			else
				printf(" (%f)i oraz", *x1u);
			if (*x2r >= 0)
				printf(" %f + ", *x2r);
			else
				printf(" (%f) +", *x2r);
			if (*x2u >= 0)
				printf(" %fi oraz", *x2u);
			else
				printf(" (%f)i oraz", *x2u);
			if (*x3r >= 0)
				printf(" %f + ", *x3r);
			else
				printf(" (%f) +", *x3r);
			if (*x3u >= 0)
				printf(" %fi oraz", *x3u);
			else
				printf(" (%f)i oraz", *x3u);
			if (*x4r >= 0)
				printf(" %f + ", *x4r);
			else
				printf(" (%f) +", *x4r);
			if (*x4u >= 0)
				printf(" %fi.\n", *x4u);
			else
				printf(" (%f).\n", *x4u);
		}

	}
	else
	{
	if (tab[1] != 0)
	{
		printf("Rownanie posiada dwa rozwiazania: \n");
		if (*x1r >= 0)
			printf(" %f + ", *x1r);
		else
			printf(" (%f) +", *x1r);
		if (*x1u >= 0)
			printf(" %fi oraz ", *x1u);
		else
			printf(" (%f)i oraz", *x1u);
		if (*x2r >= 0)
			printf(" %f + ", *x2r);
		else
			printf(" (%f) +", *x2r);
		if (*x2u >= 0)
			printf(" %fi.", *x2u);
		else
			printf(" (%f)i.", *x2u);
		printf("\nSuma rozwiazan rzeczywistych: %f", *sr);
		printf("\nSuma rozwiazan urojonych: %f", *su);
		printf("\nRoznica rozwiazan rzeczywistych: %f", *rr);
		printf("\nRoznica rozwiazan urojonych: %f", *ru);
	}
	else
	{
		if (tab[2] != 0)
			printf("Te rownanie jest rownaniem sprzecznym!\n");
		else
			printf("Te rownanie jest rownaniem tozsamosciowym!\n");
	}
	}
	

}
void dodaj(double*x1r, double*x2r, double*x1u, double*x2u,double*su,double*sr,double *x3r,double *x4r,double *x3u,double *x4u)
{
	*sr = *x1r + *x2r + *x3r + *x4r;
	*su = *x1u + *x2u + *x3u + *x4u;
	printf("Wynik dodawania liczb realnych %lf ",sr);
	printf("Wynik dodawania liczb realnych %lf ", su);
	
}

void odejmij(double*x1r, double*x2r, double*x1u, double*x2u, double*ru, double*rr, double *x3r, double *x4r, double *x3u, double *x4u)
{
	*rr= *x1r - *x2r - *x3r - *x4r;
	*ru= *x1u - *x2u - *x3u - *x4u;

	printf("Wynik odejmowania liczb realnych %lf ", rr);
	printf("Wynik odejmowania liczb realnych %lf ", ru);
}
int main()
{
	double delta = 0;
	double pdelta = 0;
	double x1r = 0;
	double x2r = 0;
	double x3r = 0;
	double x4r = 0;
	double x1u = 0;
	double x2u = 0;
	double x3u = 0;
	double x4u = 0;
	double su = 0;
	double sr = 0;
	double rr = 0;
	double ru = 0;
	int tab[3];
	

	printf_s("Prosze podac dane: \n a:\n");
	scanf_s("%d", &tab[0]);
	printf_s("b:\n");
	scanf_s("%d", &tab[1]);
	printf_s("c:\n");
	scanf_s("%d", &tab[2]);
	
	rownanie(tab, &delta, &pdelta, &x1r, & x2r, &x1u, &x2u, &x3r, &x4r, &x3u, &x4u);
	wypiszrozwiazanie(tab, &delta, &pdelta, &x1r, &x2r, &x1u, &x2u, &x3r, &x4r, &x3u, &x4u, &rr, &sr, &su, &ru);


}





