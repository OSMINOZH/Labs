#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeElement // Шаблонный класс дерева
{
    int value;
    TreeElement* right; // Задача ссылки "вправо"
    TreeElement* left; // Задача ссылки "влево"

    TreeElement() 
    {
        value = 0; // Данные = 0
        right = NULL; // Ссылка на правый элемент пустая
        left = NULL; // Ссылка на левый элемент пустая
    }
};
struct ListElement
{
    int value;
    ListElement* pointer;
    ListElement()
    {
        value = -1;
        pointer = NULL;
    }
};
void Input(TreeElement*& el, int v) // Функция ввода данных в элементы дерева (Параметры: Сам элемент и введенные данные) 
{
    if (el == NULL) // Если элемент ведёт в пустоту т.е пустой элемент
    {
        el = new TreeElement(); // Создание нового элемента дерева
        el->value = v; // Данные в новосозданном элементе равны введенному числу
    }
    else if (el->value > v) // Если же данные в элементе больше введенного числа, данные вводятся по ссылке в левую часть
    {
        Input(el->left, v); // Ввод введенного числа влево 
    }
    else if (el->value < v) // Если же данные в элементе  меньше введенного числа, данные вводятся по ссылке в правую часть
    {
        Input(el->right, v); // Ввод введенного числа вправо
    }
}
void Output(TreeElement* el) // Первичный вывод дерева (Параметры: Элемент дерева)
{
    if (el != NULL) // Если элемент не равен пустоте, то вывод дерева
    {
        Output(el->left);
        cout << el->value << " ";
        Output(el->right);

    }
}
void Detach(TreeElement* root, TreeElement* el) // Отщепление дерева (Параметры: Элемент root - корень; Сам элемент дерева)
{


    if (root == NULL || el == NULL) // Если корень дерева пустой или сам элемент равен пустоте
    {
        return; // Возвращение числа
    }
    else if (root->left == el) // Если же левый элемент дерева от корня равен запрашиваемому числу, то его отсоединяют от корня и делают самостоятельным деревом 
    {
        root->left = NULL; // Ссылка на левый элемент дерева от корня теперь будет указывать в пустоту
    }
    else if (root->right == el) // Если правый элемент дерева от корня равен запрашиваемому числу, то его отсоединяют от корня и делают самостоятельным деревом
    {
        root->right = NULL; // Ссылка на правый элемент дерева от корня теперь будет указывать в пустоте
    }
    {
        Detach(root->left, el); // 
        Detach(root->right, el); // 
    }
}
void Remove(TreeElement* el) // Удаление запрашиваемого элемента и ветви дерева
{
    if (el != NULL)  // Если элемент не равен пустоте, то перейти по ссылке и удалить левую и правую ветвь дерева (по ссылка влево и право, разумеется)
    {
        Remove(el->left);
        Remove(el->right);
        delete el; // Собстна само удаление 
    }
}
TreeElement* Find(TreeElement* el, int v) // Функция поиска запрашиваемого элемента
{
    TreeElement* result = NULL; // Результат равен пустоте
    if (el == NULL) // Если элемент равен пустоте, то результат не выводится т.к результат равен пустоте
    {
        result = NULL;
    }
    else if (el->value == v) // Если данные элемента дерева равны запрашиваемому, производится присуждение созданному дереву удаляемого элемента дерева
    {
        result = el; // Присуждение элементу новосозданного дерева найденного элемента в первоначальном дереве
    }
    else // В других случаях (Поиск по ветвям дерева, но по сути то же самое, только с переходами влево и вправо)
    {
        result = Find(el->left, v);
        if (result == NULL)
        {
            result = Find(el->right, v);
        }
    }
    return result; // Возвращение найденного дерева в int main 
}
void List(ListElement*& first, TreeElement* el, ListElement*& point) // Запись элементов из дерева в список
{
    if (el != NULL) // Если элемент дерева не равен пустоте, использовать функцию List (Парметры:
    {
        List(first, el->left, point); // Функция List ()
        ListElement* p1 = new ListElement(); 
        p1->value = el->value;
        if (point == NULL) 
        {
            first = p1;
            point = p1;
        }
        else 
        {
            point->pointer = p1;
            point = p1;
        }
        List(first, el->right, point); // Вызов функции List (Параметры: )
    }
}
void OutputList(ListElement* list) // Вывод списка (Параметры: Список - list)
{
    while (list != NULL) // Пока список не равен пустоте вписывать данные
    {
        cout << list->value << " ";
        list = list->pointer;
    }
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    TreeElement* root = NULL;
    ListElement* first = NULL;
    cout << "Введите колличество элементов дерева" << endl;
    int k, ch;
    cin >> k;
    cout << "Введите элементы дерева"<<endl;
    for (int i = 0; i < k; i++)
    {
        cin >> ch;
        Input(root, ch);
    } // Прошло

    Output(root); // Прошло
    cout << endl;
    int x; // Корень
    cout << "Введите корень,который хотите удалить = ";
    cin >> x;

    TreeElement* buffer = Find(root, x); // Прошло
    Detach(root, buffer); // Прошло
    Remove(buffer); // Прошло
    Output(root); // Прошло
    cout << endl; 

    cout << "Список" << endl; 
    ListElement * list = NULL; // Прошло
    List(first, root, list); // Прошло
    OutputList(first); // Прошло
    system("pause>nul");
    return 0;
}