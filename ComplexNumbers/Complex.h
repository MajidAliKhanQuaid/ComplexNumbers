#pragma once
class Complex
{
public:
	Complex();
	Complex(int real, int imaginary);
	Complex operator+(Complex complex);
	Complex operator-(Complex complex);
	void Display();
	~Complex();

private:
	int real;
	int imaginary;
};


