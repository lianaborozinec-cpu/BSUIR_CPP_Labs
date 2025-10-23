#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool issimetric(int* rows, int cols) {
    int start = 0;
    int end = cols - 1;

    while (start < end) { // проверяем пары элементов
        if (rows[start] != rows[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    setlocale(LC_ALL, "RU");

    int rows, cols;
    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;

    // 2️⃣ Выбор способа заполнения
    int choice;
    cout << "Выберите способ заполнения матрицы:\n";
    cout << "1 - случайными числами\n";
    cout << "2 - ввод вручную\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    // 1️⃣ Выделение памяти 
    int** matrics = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrics[i] = new int[cols];
    }

    // 3️⃣ Заполнение матрицы
    if (choice == 1) {
        // случайное заполнение
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrics[i][j] = rand() % 100; 
            }
        }
    }
    else if (choice == 2) {
        // ручной ввод
        cout << "Введите элементы матрицы:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "matrix[" << i << "][" << j << "] = ";
                cin >> matrics[i][j];
            }
        }
    }
    else {
        cout << "Некорректный выбор! По умолчанию используется случайное заполнение.\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrics[i][j] = rand() % 100;
            }
        }
    }

    // 3️⃣ Вывод матрицы
    cout << "\nМатрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrics[i][j] << "\t";
        }
        cout << endl;
    }

    int* arr = new int[rows];
    for (int i = 0; i < rows; i++) {
        if (issimetric(matrics[i], cols)) {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }

    cout << "\nВектор B (симметричность строк):\n";
    for (int i = 0; i < rows; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    // 4️⃣ Освобождение памяти
    for (int i = 0; i < rows; i++)
        delete[] matrics[i];
    delete[] matrics;
    delete[] arr;

    cout << "\nПамять освобождена!" << endl;

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
