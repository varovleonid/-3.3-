#include <iostream>
#include <algorithm>
using namespace std;

// Структура для узла дерева
struct Node {
    double data;
    Node* left;
    Node* right;
};
// Функция для создания нового узла дерева
Node* Create_Node(double data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Ошибка при выделении памяти!" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Функция для построения идеально сбалансированного бинарного дерева
Node* Build_Balanced_Tree(double arr[], double start, double end) {
    // Проверка базового случая
    if (start > end) {
        return NULL;
    }
    // Находим середину массива и делаем её корнем нового узла дерева
    int mid = (start + end) / 2;
    Node* root = Create_Node(arr[mid]);
    // Рекурсивно строим левое и правое поддерево
    root->left = Build_Balanced_Tree(arr, start, mid - 1);
    root->right = Build_Balanced_Tree(arr, mid + 1, end);
    return root;
}
// Функция для печати дерева
void Print_Tree(Node* root, int space) {
    const int INDENTATION = 4;
    if (root == NULL) {
        return;
    }
    space += INDENTATION;
    // Вывод правого поддерева
    Print_Tree(root->right, space);
    // Вывод текущего узла
    for (int i = INDENTATION; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    // Вывод левого поддерева
    Print_Tree(root->left, space);
}

int main()
{
    setlocale(0, "");
    int n;
    double min = DBL_MAX;
    cout << "Введите количество элементов: ";
    cin >> n;

    double* arr = new double[n];
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    sort(arr, arr + n);

    Node* root = Build_Balanced_Tree(arr, 0, n - 1);

    cout << "Идеально сбалансированное бинарное дерево:\n";
    Print_Tree(root, 0);

    cout << "\nМинимальный элемент в дереве: " << min << "\n";
}

