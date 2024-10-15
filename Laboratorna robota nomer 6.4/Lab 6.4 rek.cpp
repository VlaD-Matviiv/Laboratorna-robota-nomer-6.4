// Lab 6.4 rek

#include <iostream>
#include <vector>
#include <iomanip>

// ������� ��� ��������� ������
void generateArray(std::vector<double>& array, int index) {
    if (index < array.size()) {
        array[index] = static_cast<double>(rand()) / RAND_MAX * 10 - 5; // ��������� ������� � ������� (-5, 5)
        generateArray(array, index + 1);
    }
}

// ������� ��� ��������� ������
void printArray(const std::vector<double>& array, int index) {
    if (index < array.size()) {
        std::cout << std::fixed << std::setprecision(2) << array[index] << " ";
        printArray(array, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

// ������� ��� ����������� ������ ���������� ��������
int findMinIndex(const std::vector<double>& array, int index, int minIndex) {
    if (index >= array.size()) {
        return minIndex;
    }
    if (array[index] < array[minIndex]) {
        minIndex = index;
    }
    return findMinIndex(array, index + 1, minIndex);
}

// ������� ��� ���������� ���� �������� �� ������ � ������ �䒺����� ����������
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

// ������� ��� ������������ ������
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

// ������� �������
int main() {
    srand(static_cast<unsigned int>(time(0))); // ����������� ���������� ���������� �����

    int n;
    std::cout << "������ ������� �������� ������: ";
    std::cin >> n;

    std::vector<double> array(n);

    // ��������� ������
    generateArray(array, 0);

    // ��������� ������������ ������
    std::cout << "����������� �����:\n";
    printArray(array, 0);

    // ����������� ������ ���������� ��������
    int minIndex = findMinIndex(array, 1, 0);
    std::cout << "����� ���������� ��������: " << minIndex << std::endl;

    // ���� ��� ���������� ���� �������� �� ������ � ������ ��'������ ����������
    int firstNegIndex = -1;
    int secondNegIndex = -1;
    double sumNegatives = sumBetweenNegatives(array, 0, firstNegIndex, secondNegIndex);
    std::cout << "���� �������� �� ������ � ������ ��'������ ����������: " << sumNegatives << std::endl;

    // ������������ ������
    std::vector<double> lessThanOne;
    std::vector<double> greaterThanOne;
    rearrangeArray(array, 0, lessThanOne, greaterThanOne);

    std::cout << "������������� �����:\n";
    printArray(array, 0);

    return 0;
}
