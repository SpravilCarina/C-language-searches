#include<stdio.h>
#include<time.h>
int c_liniara(int a[], int n, int x)
{
	int i = 0;
	while (i, n && a[i] != x)
		i++;
	return i;
}

int c_tehnicaFanionului(int a[], int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	return i;
}

int c_binara(int a[], int n, int x)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	do
	{
		m = (s + d) / 2;
		if (x > a[m]) s = m + 1;
		else
			d = m - 1;
	} while (s <= d && a[m] != x);
		return m;
}

int c_binarPerf(int a[], int n, int x)
{
	int s, d, m;
	s = 0; d = n - 1;
	do
	{
		m = (s + d) / 2;
		if (x > a[m])
			s = m + 1;
		else
			d = n;
	} while (s < d);
	return d;
}

int c_Interpolare(int a[], int n, int x)
{
	int s, d, m;
	s = 0; d = n - 1;
	if (x >= a[s] && x <= a[d])
	{
		do
		{
			m = s + (s - d) * (x - a[s]) / (a[d] - a[s])*(d-s);
			if (x > a[m]) s = m + 1;
			else
				d = m - 1;
		} while (s <= d && a[m] != x && x <= a[d] && x >= a[s] && a[d] != a[s]);
	}
	return d;

}

int main(void)
{
	int a[100] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	clock_t start, end;
	int poz, n=15, x=15,i;
	double Timp_executie;
	start = clock();
	for (i = 0; i < 1000; i++)
		poz = c_liniara(a, n, x);
	end = clock();
	Timp_executie = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nTimp_executie=%.12lf\n", Timp_executie);
	if (poz != n)
		printf("(cautare liniara) elementul %d a fost gasit pe pozitia %d\n", x, poz);
	else
		printf("(cautare liniara) elementul %d nu a fost gasit\n", x);
	poz = c_tehnicaFanionului(a, n, x);
	if (poz != n)
		printf("(cautare TF) elementul %d a fost gasit pe pozitia %d\n", x, poz);
	else
		printf("(cautare TF) elementul %d nu a fost gasit\n", x);
	poz = c_binara(a, n, x);
	if(a[poz]==x)
		printf("(cautare binara) elementul %d a fost gasit pe pozitia %d\n", x, poz);
	else
		printf("(cautare binara) elementul %d nu a fost gasit\n", x);
	poz = c_binarPerf(a, n, x);
	if (a[poz] == x)
		printf("(cautare performanta) elementul %d a fost gasit pe pozitia %d\n", x, poz);
	else
		printf("(cautare performanta) elementul %d nu a fost gasit\n", x);
	poz = c_Interpolare(a, n, x);
	if (a[poz] == x)
		printf("(cautare Interpolara) elementul %d a fost gasit pe pozitia %d\n", x, poz);
	else
		printf("(cautare Interpolara) elementul %d nu a fost gasit\n", x);
	return 0;
}
//tema. generare de numere aleatoare intr un fisier, cu functia RUN,finalul sa fie preluat din fisier