// Lab 6.4 rek

#include <iostream>
#include <vector>
#include <iomanip>

// Функція для генерації масиву
void generateArray(std::vector<double>& array, int index) {
    if (index < array.size()) {
        array[index] = static_cast<double>(rand()) / RAND_MAX * 10 - 5; // Генерація значень у діапазоні (-5, 5)
        generateArray(array, index + 1);
    }
}

// Функція для виведення масиву
void printArray(const std::vector<double>& array, int index) {
    if (index < array.size()) {
        std::cout << std::fixed << std::setprecision(2) << array[index] << " ";
        printArray(array, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

// Функція для знаходження номера мінімального елемента
int findMinIndex(const std::vector<double>& array, int index, int minIndex) {
    if (index >= array.size()) {
        return minIndex;
    }
    if (array[index] < array[minIndex]) {
        minIndex = index;
    }
    return findMinIndex(array, index + 1, minIndex);
}

// Функція для обчислення суми елементів між першим і другим від’ємними елементами
double sumBetweenNegatives(const std::vector<double>& array, int index, int& firstNegIndex, int& secondNegIndex) {
    if (index >= array.size()) {
        return 0;
    }
    if (array[index] < 0) {
        if (firstNegIndex == -1) {
            firstNegIndex = index;
        }
        else {
            secondNegIndex = index;
        }
    }

    if (firstNegIndex != -1 && secondNegIndex != -1) {
        double sum = 0;
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sum += array[i];
        }
        return sum;
    }

    return sumBetweenNegatives(array, index + 1, firstNegIndex, secondNegIndex);
}

// Функція для перетворення масиву
void rearrangeArray(std::vector<double>& array, int index, std::vector<double>& lessThanOne, std::vector<double>& greaterThanOne) {
    if (index >= array.size()) {
        array.clear();
        array.insert(array.end(), lessThanOne.begin(), lessThanOne.end());
        array.insert(array.end(), greaterThanOne.begin(), greaterThanOne.end());
        return;
    }

    if (std::abs(array[index]) <= 1) {
        lessThanOne.push_back(array[index]);
    }
    else {
        greaterThanOne.push_back(array[index]);
    }

    rearrangeArray(array, index + 1, lessThanOne, greaterThanOne);
}

// Головна функція
int main() {
    srand(static_cast<unsigned int>(time(0))); // Ініціалізація генератора випадкових чисел

    int n;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> n;

    std::vector<double> array(n);

    // Генерація масиву
    generateArray(array, 0);

    // Виведення оригінального масиву
    std::cout << "Оригінальний масив:\n";
    printArray(array, 0);

    // Знаходження номера мінімального елемента
    int minIndex = findMinIndex(array, 1, 0);
    std::cout << "Номер мінімального елемента: " << minIndex << std::endl;

    // Змінні для обчислення суми елементів між першим і другим від'ємними елементами
    int firstNegIndex = -1;
    int secondNegIndex = -1;
    double sumNegatives = sumBetweenNegatives(array, 0, firstNegIndex, secondNegIndex);
    std::cout << "Сума елементів між першим і другим від'ємними елементами: " << sumNegatives << std::endl;

    // Перетворення масиву
    std::vector<double> lessThanOne;
    std::vector<double> greaterThanOne;
    rearrangeArray(array, 0, lessThanOne, greaterThanOne);

    std::cout << "Модифікований масив:\n";
    printArray(array, 0);

    return 0;
}
