#include "stdafx.h"
#include <stdlib.h>
#include "Complex.h"
int main()
{
	// Ye hasan code region hy
	Complex first(10, 2), second(20, 9), output;
	output = first + second;
	output.Display();
	output = first - second;
	output.Display();
	system("pause");
	return 0;
}