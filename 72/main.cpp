#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define TAB 200
ifstream in;
ofstream out;

int licznik = 0;

void zadanie1(string napis1, string napis2){
	bool wypisalem = false;
	int dlugosc1, dlugosc2;
	dlugosc1 = napis1.length();
	dlugosc2 = napis2.length();
	
	if (dlugosc1 >= (3 * dlugosc2) || dlugosc2 >= (3 * dlugosc1)){
		licznik++;
	}
}

void zadanie2(string napis1, string napis2){
	int dlugosc1, dlugosc2;
	bool dobry;
	dlugosc1 = napis1.length();
	dlugosc2 = napis2.length();
	
	if(dlugosc2 > dlugosc1){
		bool dobry = true;
		for(int i = 0; i < dlugosc1; i++){
			if(napis1[i] != napis2[i])
				dobry = false;
		}
		if(dobry == true){
			cout << "Napis pierwszy i drugi: " << napis1 << ", " << napis2; 
			out << "Napis pierwszy i drugi: " << napis1 << ", " << napis2;
			cout << "\nLitery ktore trzeba dopisac: ";
			out << "\nLitery ktore trzeba dopisac: ";
			for(int i = dlugosc1; i <= dlugosc2; i++){
				cout << napis2[i];
				out << napis2[i];
			}	
			cout << endl << endl;
			out << endl << endl;
		}
	}
}

int koncowka(string napis1, string napis2){
	int dlugosc1, dlugosc2, dluzszy;
	bool tesame;
	dlugosc1 = napis1.length();
	dlugosc2 = napis2.length();
	 
	int k = 0;
	while(k < dlugosc1 && k < dlugosc2 && napis1[dlugosc1 - 1 - k] == napis2[dlugosc2 - 1 - k]){
		k++;
		if(k > max)
			max = k;	
	}
	
	
	return max;
}

void zadanie3(string napis1, string napis2){
	
	cout << koncowka(napis1, napis2);
	
}

void dane(){
	string napis1, napis2, para1, para2;
	bool wypisalem;
	for(int i = 0; i < TAB; i++){
		in >> napis1;
		in >> napis2;
//		cout << napis1 << " " << napis2 << endl;
		int dlugosc1, dlugosc2;
		
		zadanie1(napis1, napis2);
		zadanie2(napis1, napis2);	
		zadanie3(napis1, napis2);
		
		if (!wypisalem)
		{
			para1 = napis1;
			para2 = napis2;
			wypisalem = true;
		} 
	}

	cout << "Liczba 3 razy dluzszych: " << licznik;
	out << "Liczba 3 razy dluzszych: " << licznik;
	cout << "\nPierwsza para: " << para1 << " " << para2 << endl;
	out << "\nPierwsza para: " << para1 << " " << para2 << endl;
	
}

//void

int main(){
	in.open("napisy.txt");
	out.open("wynik.txt");
	
	dane();
	
	return 0;	
}

