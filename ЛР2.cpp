#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
	int n; // ������ �������
	cout << "������� ������ �������=";
	cin >> n;
    int* mas = new int[n]; //��������� ������
	cout << "������� ��������� �������:" << endl;
	for (int i = 0; i < n; i++) 
	{
		cin >> mas[i];//���� �������
	}
    int temp; // ��������� ���������� ��� ������ ��������� �������

    // ���������� ������� ���������
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (mas[j] > mas[j + 1]) 
            {
                // ������ �������� �������
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    // ����� ���������������� ������� �� �����
    cout << "��������������� ������:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << mas[i] << " ";
    }
    cout << endl;

    delete[] mas; // ������������ ������;
    system("pause>nul");
    return 0;
}