/*
Author : Jonatious Joseph Jawahar
PSID   : 1416103
*/

#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
//edit accordingly 
//1.tangent (tan(x)-2x)
//2.algebra (x*x*x - 6*x*x*x + 12x - 8)
int question = 1;

int i = 1;
bool error = false;

//Function value
double function(double val) {
	if(question == 1)
		return tan(val) - (2 * val);
	else
		return val*val*val - 6 * val*val + 12 * val - 8;
}

//Differentiation
double differentiation(double val) {
	if (question == 1)
		return (1 / cos(val))*(1 / cos(val)) - 2;
	else
		return 3 * val*val - 12 * val + 12;
}

//Bisection method
double bisection(double a, double b, double limit) {
	
	//Checking intervals at first iteration
	double temp = function(b)*function(a);
	if (i == 1 && temp > 0) {
		cout << "Error: intervals are invalid.";
		error = true;
		return 0;
	}


	double mid = (a + b) / 2.0;
	cout << endl << "Iteration " << i++ << ":" << endl << "value = " << mid << endl << "Function value = " << function(mid) << endl;

	if (abs(function(mid)) < limit)
		return mid;

	if (function(b)*function(mid) < 0) {
		return bisection(mid, b, limit);
	}
	else
		return bisection(a, mid, limit);
}

//newton's method
double newton(double guess, double limit) {
	double new_guess = guess - (function(guess) / differentiation(guess));

	cout << endl << "Iteration " << i++ << ":" << endl << "value = " << new_guess << endl << "Function value = " << function(new_guess) << endl;

	double abs_err = abs((new_guess - guess) / new_guess) * 100;
	if (abs_err < limit)
		return new_guess;
	else
		return newton(new_guess, limit);
}

//main program
void main() {
	//comment and change intervals/guess accordingly
	double root = bisection(1.0, 1.4, 0.0001);
	//double root = newton(3, 0.0001);
	if (!error)
		cout << endl << "root = " << root << endl << "number of iterations = " << i - 1;
	_getch();
}