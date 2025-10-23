// тмоис 2 вари 1 ла.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n1, n2, element;
    set<int> X, Y;

    cout << "Введите количество элементов множества X: ";
    cin >> n1;
    cout << "Введите элементы множества X: ";
    for (int i = 0; i < n1; i++) {
        cin >> element;
        X.insert(element);
    }

    cout << "Введите количество элементов множества Y: ";
    cin >> n2;
    cout << "Введите элементы множества Y: ";
    for (int i = 0; i < n2; i++) {
        cin >> element;
        Y.insert(element);
    }

    // --- Пересечение ---
    set<int> intersection;
    set_intersection(X.begin(), X.end(), Y.begin(), Y.end(),
        inserter(intersection, intersection.begin()));

    // --- Объединение ---
    set<int> union_set;
    set_union(X.begin(), X.end(), Y.begin(), Y.end(),
        inserter(union_set, union_set.begin()));

    // --- Разность X \ Y ---
    set<int> difference_XY;
    set_difference(X.begin(), X.end(), Y.begin(), Y.end(),
        inserter(difference_XY, difference_XY.begin()));

    // --- Разность Y \ X ---
    set<int> difference_YX;
    set_difference(Y.begin(), Y.end(), X.begin(), X.end(),
        inserter(difference_YX, difference_YX.begin()));

    // --- Симметрическая разность ---
    set<int> sym_diff;
    set_symmetric_difference(X.begin(), X.end(), Y.begin(), Y.end(),
        inserter(sym_diff, sym_diff.begin()));

    // --- Универсум (X ∪ Y) ---
    set<int> universal = union_set;

    // --- Дополнения ---
    set<int> complement_X, complement_Y;
    set_difference(universal.begin(), universal.end(), X.begin(), X.end(),
        inserter(complement_X, complement_X.begin()));
    set_difference(universal.begin(), universal.end(), Y.begin(), Y.end(),
        inserter(complement_Y, complement_Y.begin()));

    

    // --- Вывод ---
    cout << "\nРезультаты операций:" << endl;

    cout << "X = {";
    for (auto it = X.begin(); it != X.end(); it++) {
        cout << *it;
        if (next(it) != X.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Y = {";
    for (auto it = Y.begin(); it != Y.end(); it++) {
        cout << *it;
        if (next(it) != Y.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Пересечение X и Y: {";
    for (auto it = intersection.begin(); it != intersection.end(); it++) {
        cout << *it;
        if (next(it) != intersection.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Объединение X и Y: {";
    for (auto it = union_set.begin(); it != union_set.end(); it++) {
        cout << *it;
        if (next(it) != union_set.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Разность X \\ Y: {";
    for (auto it = difference_XY.begin(); it != difference_XY.end(); it++) {
        cout << *it;
        if (next(it) != difference_XY.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Разность Y \\ X: {";
    for (auto it = difference_YX.begin(); it != difference_YX.end(); it++) {
        cout << *it;
        if (next(it) != difference_YX.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Симметрическая разность: {";
    for (auto it = sym_diff.begin(); it != sym_diff.end(); it++) {
        cout << *it;
        if (next(it) != sym_diff.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Дополнение X: {";
    for (auto it = complement_X.begin(); it != complement_X.end(); it++) {
        cout << *it;
        if (next(it) != complement_X.end()) cout << ", ";
    }
    cout << "}" << endl;

    cout << "Дополнение Y: {";
    for (auto it = complement_Y.begin(); it != complement_Y.end(); it++) {
        cout << *it;
        if (next(it) != complement_Y.end()) cout << ", ";
    }
    cout << "}" << endl;

    return 0;

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
