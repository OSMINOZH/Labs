#include <iostream>
#include <cstdlib>

using namespace std;

struct ListElement
{
	int value;
	ListElement* pointer;

	ListElement()
	{
		value = 0;
		pointer = NULL;
	}
};
void InputList(ListElement*& first, int x)
{
	ListElement* l = NULL;
	int i = 0;
	cout << "Введите каждый элемент: " << endl;
	while (i < x)
	{
		ListElement* v = new ListElement();
		cin >> v->value;
		if (first == NULL)
		{
			first = v;
			l = v;
		}
		else
		{
			l->pointer = v;
			l = v;
		}
		i++;
	}
}
void AscendingSortList(ListElement* first)
{
	ListElement* l = first->pointer;
	ListElement* p = first;
	while (p->pointer != NULL)
	{
		while (l != NULL)
		{
			if (l->value < p->value)
			{
				int buf = l->value;
				l->value = p->value;
				p->value = buf;
			}
			l = l->pointer;
		}
		p = p->pointer;
		l = p->pointer;
	}

}
void OutputList(ListElement* l)
{
	while (l != NULL)
	{
		cout << l->value;
		l = l->pointer;
		if (l != NULL) cout << ", ";
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	ListElement* first = NULL;
	int x;
	cout << "Введите количество элементов списка = ";
	cin >> x;
	InputList(first, x);
	cout << "Введенный список:" << endl;
	OutputList(first);
	AscendingSortList(first);
	cout << "Готовый список:" << endl;
	OutputList(first);
	system("pause>nul");
	return 0;
}