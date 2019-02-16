#include "stdafx.h"
#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex()
{
}

Complex::Complex(int real, int imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

Complex Complex::operator+(Complex complex) {
	cout << "+++ Adding (" << this->real << "," << this->imaginary << "i) AND (" << complex.real << "," << complex.imaginary << "i)" << endl;
	Complex sum;
	sum.real = this->real + complex.real;
	sum.imaginary = this->imaginary + complex.imaginary;
	return sum;
}

Complex Complex::operator-(Complex complex) {
	cout << "--- Subtracting (" << this->real << "," << this->imaginary << "i) AND (" << complex.real << "," << complex.imaginary << "i)" << endl;
	Complex sum;
	sum.real = this->real - complex.real;
	sum.imaginary = this->imaginary - complex.imaginary;
	return sum;
}

void Complex::Display() {
	cout << "Real : " << this->real << " | Imaginary : " << this->imaginary << "i" << endl;
}

Complex::~Complex()
{
}
