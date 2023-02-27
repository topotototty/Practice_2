#include <iostream>
#include <time.h>
using namespace std;

void randArray()
{
    cout << "Введите длину массива: ";
    int size;
    int sum = 0;
    
    cin >> size;
    int* array = new int[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++) 
    {
        *(array + i) = 1 + rand() % 100;
        cout << array[i] << " ";
    }

    int min = array[0];
    for (int i = 0; i < size; ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    cout << "\nНаименьший элемент массива: " << min << endl;
}

void matrix() 
{
    int N;
    int M;
    int sum = 0;

    cout << "Введите количество строк в матрице: ";
    cin >> N;

    cout << "Введите количество столбцов в матрице: ";
    cin >> M;

    srand(time(NULL));

    int* pline = new int[N];
    for (int i = 0; i < N; i++)
    {
        int* pcolumn = new int[M];
        for (int j = 0; j < M; j++)
        {
            *(pcolumn + j) = 1 + rand() % 100;
            cout << pcolumn[j] << " ";
            sum = sum + *(pcolumn + j);
        }
        *(pline + i) = *pcolumn;
        cout << "\n";
    }
    cout << "Сумма всех элементов матрицы: " << sum << endl;
}

void viewArray(int* parr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << parr[i] << " ";
    }
    cout << "\n";
}

void averageArray(int size, int sum)
{
    int average = sum / size;
    cout << "Среднее арифметическое элементов массива = " << average << endl;
}

void massive()
{
    cout << "Введите длину массива: ";
    int size;
    int sum = 0;

    cin >> size;

    int* parr = new int[size];
    cout << "Заполните массив значениями \n";

    for (int i = 0; i < size; i++)
    {
        cin >> *(parr + i);
    }

    for (int i = 0; i < size; i++) 
    {
        sum = sum + *(parr + i);
    }

    cout << "Cумма элементов массива = " << sum << endl;
    viewArray(parr, size);
    averageArray(size, sum);
}

void changeNum(int* point_x, int* point_y)
{
    int address = *point_x;
    *point_x = *point_y;
    *point_y = address;
}

int factorial(int n) 
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    setlocale(LC_ALL, "");

    int choice;

    while (true)
    {
        cout << "\nВыберите действие: \n1. Вычисление факториала\n2. Поменять значения переменных\n3. Массивы\n4. Матрицы\n5. Рандомный массив" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int n;

            cout << "\nВведите число, чтобы вычислить его факториал: \n";
            cin >> n;
            cout << "Факториал числа " << n << " = " << factorial(n) << endl;
            break;
        case 2:
            int x;
            int y;

            cout << "Введите числа, счас поменяем их значение: ";
            cin >> x;
            cin >> y;

            cout << "До изменений " << x << " " << y << endl;
            changeNum(&x, &y);
            cout << "После изменений " << x << " " << y << endl;
            break;
        case 3:
            massive();
            break;
        case 4:
            matrix();
            break;
        case 5:
            randArray();
            break;
        default:
            cout << "Такой операции нет, попробуйте еще раз";
            break;
        }
    }
    
}
