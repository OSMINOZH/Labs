#include <cstdlib>
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

void F2(double x)
{
	x = F1(x);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double start, stop;
	cout << "¬ведите начальное = ";
	cin >> start;
	cout << "¬ведите конечное = ";
	cin >> stop;
	cout << endl;
	for (int i = start; i <= stop; i++)
	{
		cout << "i = " << i << ";" << endl;
		F2(i);
		cout << "i = " << i << " ; F2(i)=" << i << endl;
	}
	system("pause");
	return 0;
}