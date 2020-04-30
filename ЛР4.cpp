#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeElement // ��������� ����� ������
{
    int value;
    TreeElement* right; // ������ ������ "������"
    TreeElement* left; // ������ ������ "�����"

    TreeElement() 
    {
        value = 0; // ������ = 0
        right = NULL; // ������ �� ������ ������� ������
        left = NULL; // ������ �� ����� ������� ������
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
void Input(TreeElement*& el, int v) // ������� ����� ������ � �������� ������ (���������: ��� ������� � ��������� ������) 
{
    if (el == NULL) // ���� ������� ���� � ������� �.� ������ �������
    {
        el = new TreeElement(); // �������� ������ �������� ������
        el->value = v; // ������ � ������������� �������� ����� ���������� �����
    }
    else if (el->value > v) // ���� �� ������ � �������� ������ ���������� �����, ������ �������� �� ������ � ����� �����
    {
        Input(el->left, v); // ���� ���������� ����� ����� 
    }
    else if (el->value < v) // ���� �� ������ � ��������  ������ ���������� �����, ������ �������� �� ������ � ������ �����
    {
        Input(el->right, v); // ���� ���������� ����� ������
    }
}
void Output(TreeElement* el) // ��������� ����� ������ (���������: ������� ������)
{
    if (el != NULL) // ���� ������� �� ����� �������, �� ����� ������
    {
        Output(el->left);
        cout << el->value << " ";
        Output(el->right);

    }
}
void Detach(TreeElement* root, TreeElement* el) // ���������� ������ (���������: ������� root - ������; ��� ������� ������)
{


    if (root == NULL || el == NULL) // ���� ������ ������ ������ ��� ��� ������� ����� �������
    {
        return; // ����������� �����
    }
    else if (root->left == el) // ���� �� ����� ������� ������ �� ����� ����� �������������� �����, �� ��� ����������� �� ����� � ������ ��������������� ������� 
    {
        root->left = NULL; // ������ �� ����� ������� ������ �� ����� ������ ����� ��������� � �������
    }
    else if (root->right == el) // ���� ������ ������� ������ �� ����� ����� �������������� �����, �� ��� ����������� �� ����� � ������ ��������������� �������
    {
        root->right = NULL; // ������ �� ������ ������� ������ �� ����� ������ ����� ��������� � �������
    }
    {
        Detach(root->left, el); // 
        Detach(root->right, el); // 
    }
}
void Remove(TreeElement* el) // �������� �������������� �������� � ����� ������
{
    if (el != NULL)  // ���� ������� �� ����� �������, �� ������� �� ������ � ������� ����� � ������ ����� ������ (�� ������ ����� � �����, ����������)
    {
        Remove(el->left);
        Remove(el->right);
        delete el; // ������� ���� �������� 
    }
}
TreeElement* Find(TreeElement* el, int v) // ������� ������ �������������� ��������
{
    TreeElement* result = NULL; // ��������� ����� �������
    if (el == NULL) // ���� ������� ����� �������, �� ��������� �� ��������� �.� ��������� ����� �������
    {
        result = NULL;
    }
    else if (el->value == v) // ���� ������ �������� ������ ����� ��������������, ������������ ����������� ���������� ������ ���������� �������� ������
    {
        result = el; // ����������� �������� �������������� ������ ���������� �������� � �������������� ������
    }
    else // � ������ ������� (����� �� ������ ������, �� �� ���� �� �� �����, ������ � ���������� ����� � ������)
    {
        result = Find(el->left, v);
        if (result == NULL)
        {
            result = Find(el->right, v);
        }
    }
    return result; // ����������� ���������� ������ � int main 
}
void List(ListElement*& first, TreeElement* el, ListElement*& point) // ������ ��������� �� ������ � ������
{
    if (el != NULL) // ���� ������� ������ �� ����� �������, ������������ ������� List (��������:
    {
        List(first, el->left, point); // ������� List ()
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
        List(first, el->right, point); // ����� ������� List (���������: )
    }
}
void OutputList(ListElement* list) // ����� ������ (���������: ������ - list)
{
    while (list != NULL) // ���� ������ �� ����� ������� ��������� ������
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
    cout << "������� ����������� ��������� ������" << endl;
    int k, ch;
    cin >> k;
    cout << "������� �������� ������"<<endl;
    for (int i = 0; i < k; i++)
    {
        cin >> ch;
        Input(root, ch);
    } // ������

    Output(root); // ������
    cout << endl;
    int x; // ������
    cout << "������� ������,������� ������ ������� = ";
    cin >> x;

    TreeElement* buffer = Find(root, x); // ������
    Detach(root, buffer); // ������
    Remove(buffer); // ������
    Output(root); // ������
    cout << endl; 

    cout << "������" << endl; 
    ListElement * list = NULL; // ������
    List(first, root, list); // ������
    OutputList(first); // ������
    system("pause>nul");
    return 0;
}