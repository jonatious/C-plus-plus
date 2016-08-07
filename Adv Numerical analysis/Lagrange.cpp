/*
Author : Jonatious Joseph Jawahar
PSID   : 1416103
*/

#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;

int n;
bool duplicates = true;

double lagrange(double x[], double y[], double find){
	double interpolation = 0, temp_prod = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < i; j++)
			duplicates = duplicates & x[i] != x[j];

	if (duplicates) {
		interpolation = 0;
		for (int i = 0; i < n; i++) {
			temp_prod = y[i];
			for (int j = 0; j < n; j++) {
				if (i != j)
					temp_prod *= (find - x[j])/(x[i] - x[j]);
			}
			interpolation += temp_prod;
		}
	}
	else {
		cout << "Data cannot be interpolated.";
		return 0;
	}

	return interpolation;
}

void main() {
	double find;
	double x[50], y[50];

	cout << "enter number of points available...";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "enter point " << i + 1 << endl << "x: ";
		cin >> x[i];
		cout  << "y: ";
		cin >> y[i];
		cout << endl ;
	}

	cout << "enter the point for which y is to be computed...";
	cin >> find;

	int value = lagrange(x, y, find);
	if(duplicates)
		cout << "The y value for the point " << find << " = " << value;

	_getch();
}