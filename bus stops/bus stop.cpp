#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

void read(int &n, int stop[], int day[], int income[], int outcome[]) { //scanning
	ifstream fd("U1.txt");
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> stop[i] >> day[i] >> income[i] >> outcome[i];
	}
	fd.close();
}

void first(int n,int stop[],int stoptemp[], int& b) { //first line output
	
	for (int i = 0; i < n; i++) {
		stoptemp[i] = stop[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (stoptemp[i] == stoptemp[j] && i != j) {
				stoptemp[j]=-1;
			}
		}
	}
	ofstream fr("U1rez.txt", ios::app);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (stoptemp[i] < stoptemp[j]) {
				swap(stoptemp[i], stoptemp[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if(stoptemp[i] != -1) fr << setw(6) << stoptemp[i];
	}
	fr << endl;
	b = n;
	for (int i = 0; i < b; i++) {
		if (stoptemp[i] == -1) {
			b--;
			for (int j = i; j < b; j++) {
				stoptemp[j] = stoptemp[j + 1];
			}
			i--;
		}
		
	}
	fr.close();
}

void second(int n, int income[],int outcome[],int stop[], int stoptemp[],int b,int temp[]) { //second line output
	ofstream fr("U1rez.txt", ios::app);
	for (int i = 0; i < b; i++) {
		temp[i] = 0;
		for (int j = 0; j < n; j++) {
			if (stoptemp[i] == stop[j]) {
				temp[i] += income[j] + outcome[j];
			}
		}
	}
	for (int i = 0; i < b; i++) {
		fr << setw(6) << temp[i];
	}
	fr << endl;
	fr.close();
}

void third(int b,int temp[],int stoptemp[]) { //third line output
	int did = -1;
	int didnr;
	for (int i = 0; i < b; i++) {
		if (temp[i] > did) {
			did = temp[i];
			didnr = stoptemp[i];
		}
	}
	ofstream fr("U1rez.txt", ios::app);
	fr << setw(6) << didnr << endl;
	fr.close();
}

void fourth(int n, int income[]) { //fourth line output
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += income[i];
	}
	ofstream fr("U1rez.txt", ios::app);
	fr << setw(6) << suma;
	fr.close();
}

int main()
{
	ofstream fr("U1rez.txt");
	int n; //number of bus stops
	int b; //selected bus stops number
	int stop[1000]; //bus stop numbers
	int stoptemp[100]; //selected bus stops numbers
	int day[1000]; //days of week
	int income[1000]; //humans inside the bus
	int outcome[1000]; //humans leaving the buss
	int temp[1000]; //humans entering the buss
	read(n, stop, day, income, outcome);
	first(n, stop,stoptemp,b);
	second(n, income, outcome, stop, stoptemp, b,temp);
	third(b, temp, stoptemp);
	fourth(n, income);
	fr.close();
}