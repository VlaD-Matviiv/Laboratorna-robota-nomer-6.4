// Lab 6.4 iter

#include <iostream>
#include <vector>
#include <iomanip>

// Функція для генерації масиву
void generateArray(std::vector<double>& array) {
    for (double& num : array) {
        num = static_cast<double>(rand()) / RAND_MAX * 10 - 5; // Генерація значень у діапазоні (-5, 5)
    }
}

// Функція для виведення масиву
void printArray(const std::vector<double>& array) {
    for (const double& num : array) {
        std::cout << std::fixed << std::setprecision(2) << num << " ";
    }
    std::cout << std::endl;
}

// Функція для знаходження номера мінімального елемента
int findMinIndex(const std::vector<double>& array) {
    int minIndex = 0;
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Функція для обчислення суми елементів між першим і другим від’ємними елементами
double sumBetweenNegatives(const std::vector<double>& array) {
    int firstNegIndex = -1;
    int secondNegIndex = -1;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = i;
            }
            else {
                secondNegIndex = i;
                break;
            }
        }
    }

    // Якщо знайдено два від'ємні елементи
    if (firstNegIndex != -1 && secondNegIndex != -1) {
        double sum = 0;
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sum += array[i];
        }
        return sum;
    }
    return 0; // Якщо немає двох від'ємних елементів
}

// Функція для перетворення масиву
void rearrangeArray(std::vector<double>& array) {
    std::vector<double> lessThanOne;
    std::vector<double> greaterThanOne;

    for (const double& num : array) {
        if (std::abs(num) <= 1) {
            lessThanOne.push_back(num);
        }
        else {
            greaterThanOne.push_back(num);
        }
    }

    array.clear();
    array.insert(array.end(), lessThanOne.begin(), lessThanOne.end());
    array.insert(array.end(), greaterThanOne.begin(), greaterThanOne.end());
}

// Головна функція
int main() {
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел

    int n;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> n;

    std::vector<double> array(n);

    // Генерація масиву
    generateArray(array);

    // Виведення оригінального масиву
    std::cout << "Оригінальний масив:\n";
    printArray(array);

    // Знаходження номера мінімального елемента
    int minIndex = findMinIndex(array);
    std::cout << "Номер мінімального елемента: " << minIndex << std::endl;

    // Обчислення суми елементів між першим і другим від'ємними елементами
    double sumNegatives = sumBetweenNegatives(array);
    std::cout << "Сума елементів між першим і другим від'ємними елементами: " << sumNegatives << std::endl;

    // Перетворення масиву
    rearrangeArray(array);
    std::cout << "Модифікований масив:\n";
    printArray(array);

    return 0;
}
