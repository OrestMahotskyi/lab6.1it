#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 26;
const int MIN_VALUE = 3;
const int MAX_VALUE = 92;

// Функція для генерації випадкового масиву в заданому діапазоні
void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

// Функція для форматного виведення масиву
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

// Функція для обчислення кількості та суми елементів, які відповідають критерію
void countAndSum(const int arr[], int size, int &count, int &sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && i % 7 != 0) {
            count++;
            sum += arr[i];
        }
    }
}

// Функція для заміни елементів, що відповідають критерію, на нулі
void replaceWithZeros(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && i % 7 != 0) {
            arr[i] = 0;
        }
    }
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    int arr[SIZE];

    // Генерація масиву
    generateArray(arr, SIZE);

    // Виведення початкового масиву
    cout << "Initial array:" << endl;
    printArray(arr, SIZE);

    // Підрахунок кількості та суми елементів, що відповідають критерію
    int count = 0, sum = 0;
    countAndSum(arr, SIZE, count, sum);

    // Виведення кількості та суми
    cout << "Count of elements matching the condition: " << count <<endl;
    cout << "Sum of elements matching the condition: " << sum <<endl;

    // Заміна елементів на нулі
    replaceWithZeros(arr, SIZE);

    // Виведення модифікованого масиву
    cout << "Modified array:" << endl;
    printArray(arr, SIZE);

    return 0;
}
