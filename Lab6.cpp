#include <iostream>
#include <limits>

using namespace std;

/* -----------------------------------------------------------
   Глобальні константи
   ----------------------------------------------------------- */
const int MAX = 20;   // максимальна кількість рядків / стовпців

/* -----------------------------------------------------------
   Прототипи допоміжних функцій з параметрами
   ----------------------------------------------------------- */
void    inputSize(int& m, int& n);
void    inputMatrix(int a[][MAX], int m, int n);
void    printMatrix(const int a[][MAX], int m, int n);
bool    isColumnAllOdd(const int a[][MAX], int m, int col);
int     firstOddOnlyColumn(const int a[][MAX], int m, int n);
void    mirrorMatrix(int a[][MAX], int m, int n);

/* -----------------------------------------------------------
   Завдання 1: пошук першого стовпця, що містить
   тільки непарні числа.
   Функція без параметрів, як вимагає умова.
   ----------------------------------------------------------- */
void task1()
{
    int m, n;
    int a[MAX][MAX];

    cout << "\n=== Завдання 1 ===\n";
    inputSize(m, n);
    inputMatrix(a, m, n);

    int col = firstOddOnlyColumn(a, m, n);

    if (col == 0)
        cout << "Немає стовпців, що складаються лише з непарних чисел\n";
    else
        cout << "Номер першого стовпця з лише непарними елементами: " << col << '\n';
}

/* -----------------------------------------------------------
   Завдання 2: дзеркальне відображення за вертикальною віссю.
   Функція без параметрів, як вимагає умова.
   ----------------------------------------------------------- */
void task2()
{
    int m, n;
    int a[MAX][MAX];

    cout << "\n=== Завдання 2 ===\n";
    inputSize(m, n);
    inputMatrix(a, m, n);

    mirrorMatrix(a, m, n);

    cout << "\nМатриця після дзеркального відображення:\n";
    printMatrix(a, m, n);
}

/* -----------------------------------------------------------
   Головне меню з можливістю багаторазового вибору
   ----------------------------------------------------------- */
int main()
{
    setlocale(0, "");                 // Коректне виведення кирилиці

    while (true)
    {
        cout << "\n*********************************\n";
        cout << " 1 – Виконати завдання 1\n";
        cout << " 2 – Виконати завдання 2\n";
        cout << " 0 – Вийти з програми\n";
        cout << "Ваш вибір: ";

        int choice;
        cin  >> choice;

        if (cin.fail()) {                         // якщо введено не число
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка введення. Спробуйте ще раз.\n";
            continue;
        }

        switch (choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 0: cout << "Завершення роботи.\n"; return 0;
            default: cout << "Неприпустимий вибір. Спробуйте ще раз.\n";
        }
    }
}

/* ===========================================================
   Реалізація допоміжних функцій
   =========================================================== */

/* ---- Введення розмірів матриці з перевіркою ---- */
void inputSize(int& m, int& n)
{
    while (true)
    {
        cout << "Введіть кількість рядків (2–20): ";
        cin  >> m;
        cout << "Введіть кількість стовпців (2–20): ";
        cin  >> n;

        if (cin.fail() || m < 2 || m > MAX || n < 2 || n > MAX)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Розміри матриці мають бути цілими числами у діапазоні 2–20. Спробуйте ще раз.\n";
        }
        else
            return;         // коректні дані
    }
}

/* ---- Введення матриці ---- */
void inputMatrix(int a[][MAX], int m, int n)
{
    cout << "Введіть елементи матриці (" << m << "×" << n << "):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            while (true)
            {
                cout << " a[" << i + 1 << "][" << j + 1 << "] = ";
                cin  >> a[i][j];

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Помилка введення. Спробуйте ще раз.\n";
                }
                else
                    break;
            }
        }
}

/* ---- Виведення матриці ---- */
void printMatrix(const int a[][MAX], int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << '\t';
        cout << '\n';
    }
}

/* ---- Перевірка, чи всі елементи стовпця непарні ---- */
bool isColumnAllOdd(const int a[][MAX], int m, int col)
{
    for (int i = 0; i < m; ++i)
        if (a[i][col] % 2 == 0)   // хоча б один парний – не підходить
            return false;
    return true;
}

/* ---- Пошук першого «непарного» стовпця; нумерація з 1 ---- */
int firstOddOnlyColumn(const int a[][MAX], int m, int n)
{
    for (int j = 0; j < n; ++j)
        if (isColumnAllOdd(a, m, j))
            return j + 1;     // +1, бо користувачу зручніше бачити з 1
    return 0;                 // не знайдено
}

/* ---- Дзеркальне відображення (обмін стовпців) ---- */
void mirrorMatrix(int a[][MAX], int m, int n)
{
    for (int jLeft = 0, jRight = n - 1; jLeft < jRight; ++jLeft, --jRight)
        for (int i = 0; i < m; ++i)
        {
            int temp      = a[i][jLeft];
            a[i][jLeft]   = a[i][jRight];
            a[i][jRight]  = temp;
        }
}
