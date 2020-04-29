#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
	int n; // размер массива
	cout << "Введите размер массива=";
	cin >> n;
    int* mas = new int[n]; //Выделение памяти
	cout << "Введите эллементы массива:" << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> mas[i];//Ввод массива
	}
    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (mas[j] > mas[j + 1]) 
            {
                // меняем элементы местами
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    // Вывод отсортированного массива на экран
    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << mas[i] << " ";
    }
    cout << endl;

    delete[] mas; // освобождение памяти;
    system("pause>nul");
    return 0;
}