#include <iostream>
#include <fstream>

using namespace std;

ofstream wypisz;
//wypisz.open("wynik.txt");

double tablica[5][4];

double f(double x)
{
	if (x < 1.0) return ((tablica[0][3] * x + tablica[0][2]) * x + tablica[0][1]) * x + tablica[0][0];
	if (x < 2.0) return ((tablica[1][3] * x + tablica[1][2]) * x + tablica[1][1]) * x + tablica[1][0];
	if (x < 3.0) return ((tablica[2][3] * x + tablica[2][2]) * x + tablica[2][1]) * x + tablica[2][0];
	if (x < 4.0) return ((tablica[3][3] * x + tablica[3][2]) * x + tablica[3][1]) * x + tablica[3][0];
	return	((tablica[4][3] * x + tablica[4][2]) * x + tablica[4][1]) * x + tablica[4][0];
}

double zadanie1()
{
		cout << "Wynik - zadanie 1:\n";
		return f(1.5);
}

void maksimum(double from, double to, double step)
{
	double mx, mfx;
	double x = from;
	mx = x; mfx = f(mx);
	for (x = from + step; x < to; x += step)
	{
		double fx = f(x);
		if ( fx > mfx )
		{
			mx = x;
			mfx = fx;
		}
	}
	cout << "Max x: " << mx << "\nMax F(x): " << mfx << endl;
	wypisz << "Max x: " << mx << "\nMax F(x): " << mfx << endl;
}

double zadanie2(){
	cout << "Wynik - zadanie 2:\n";
	maksimum(4.0, 4.5, 0.001);
}

void miejscaZer(double lewy, double prawy)
{
	double fl = f(lewy);
	while ( prawy - lewy > 0.000000001 )
	{
		double middle = (lewy + prawy) / 2.0, fm = f(middle);
		if ( fl * fm < 0.0 )
		{
			prawy = middle;
		}
		else
		{
			lewy = middle; 
			fl = fm;
		}
	}
	cout << "Miejsce zerowe : " << (lewy + prawy) / 2.0 << endl;
//	wypisz >
}

double zadanie3(){
	cout << "Wynik - zadanie 3:\n";
	for (double x = 0; x < 5; x += 1){
		if ( f(x) * f(x + 1) < 0 )
		miejscaZer(x, x + 1);
	}
}

int main()
{
	ifstream plik;
	plik.open("funkcja.txt");
	
	double a, c, b, d;
	int i, j;
	
	while(plik >> d >> c >> b >> a){
		cout << i+1 << ". A: " << a << ", B: " << b << ", C: " << c << ", D: " << d << endl;
		
		tablica[i][0] = d;
		tablica[i][1] = c;
		tablica[i][2] = b;
		tablica[i][3] = a;
		i++;
	}
	plik.close();
	
	cout << zadanie1() << endl;
	cout << zadanie2() << endl;
	cout << zadanie3();
	
	wypisz.close();
}
