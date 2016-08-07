/*
Author : Jonatious Joseph Jawahar
PSID   : 1416103
*/

#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;

static float pi = 3.14;
int prob;

double function(double x) {
	switch (prob) {
	case 1:
		return 1.0 / (1.0 + x * x);
		//return x*x;
		break;
	case 2:
		return x * x - 2 * x + 1;
		break;
	case 3:
		return x*x*x + 2 * x*x - 4 * x - 5;
		break;
	default:
		cout << "\ninvalid entry..\n";
	}
}

double integration(double x) {
	switch (prob) {
	case 1:
		return atan(x);
		//return x*x*x / 3;
		break;
	case 2:
		return  x*x*x / 3 - x*x + x;
		break;
	case 3:
		return x*x*x*x / 4 + 2 * x*x*x / 3 - 2 * x*x - 5 * x;
		break;
	default:
		cout << "\ninvalid entry..\n";
	}
}

double temp_diff_midpoint(double x) {
	return 2 * (3 * x*x - 1) / ((x*x + 1)*(x*x + 1)*(x*x + 1));
}

double error(double a, double b, double n) {
	double max;
	switch (prob) {
	case 1:
		max = (temp_diff_midpoint(b) > temp_diff_midpoint(a)) ? temp_diff_midpoint(b) : temp_diff_midpoint(a);
		return max * ((b - a)*(b - a)*(b - a)) / (24 * n*n);
		break;
	case 2:
		return 2 * (b-a)*(b-a)*(b-a)/(12*n*n);
		break;
	case 3:
		return 0;// since till cubic polynomials simpson's error is 0.
		break;
	default:
		cout << "\ninvalid entry..\n";
	}
}

double midpoint(double a, double b, double n) {

	double delta = (b - a) / n;
	double function_val = function((a + delta) / 2);

	for (int i = 0; i < n - 1; i++)
		function_val += function(((i + 1)*delta + (i + 2)*delta) / 2);
	function_val *= delta;

	return function_val;
}

double trapezoid(double a, double b, double n) {

	double delta = (b - a) / n;
	double function_val = function(a);

	for (int i = 1; i < n; i++)
		function_val += 2 * function(a + i * delta);
	function_val += function(b);
	function_val *= delta / 2;

	return function_val;
}

double simpson(double a, double b, double n) {

	double delta = (b - a) / (2 * n);
	double function_val = function(a);

	for (int i = 1; i < 2 * n; i++) {
		if(i%2 == 0)
			function_val += 2 * function(a + i * delta);
		else
			function_val += 4 * function(a + i * delta);
	}
	function_val += function(b);
	function_val *= delta / 3;

	return function_val;
}

void main() {
	double a, b, n;
	double output;

	cout << "\nenter your choice...\n1. midpoint\n2. trapezoid\n3. Simpson\n";
	cin >> prob;

	cout << "\nenter lower interval...";
	cin >> a;

	cout << "\nenter upper interval...";
	cin >> b;

	cout << "\nenter partition size...";
	cin >> n;

	switch (prob) {
	case 1:
		output = midpoint(a, b, n);
		break;
	case 2:
		output = trapezoid(a, b, n);
		break;
	case 3:
		output = simpson(a, b, n);
		break;
	default:
		cout << "\ninvalid entry..\n";
	}
	
	double original_val = integration(b) - integration(a);

	if (prob < 4) {
		cout << "\nIntegral Result = " << output;
		cout << "\nOriginal integral = " << original_val;
		cout << "\nError = " << error(a,b,n);
		cout << "\nError(absolute difference) = " << abs(original_val - output);
	}
	_getch();
}