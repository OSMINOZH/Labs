/*#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

double F1(double x)
{
	double f = 0;
	if (x >= 0)
	{
		x = sin(x);
	}
	else
	{
		x = cos(x);
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double start, stop;
	cout << "¬ведите начальное = ";
	cin >> start;
	cout << "¬ведите конечное = ";
	cin >> stop;
	for (int i = start; i <= stop; i++)
	{
		double f = F1(i);
		cout << "i = " << i << "; F1(i) = " << f << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}*/