// Lab 6.4 iter

#include <iostream>
#include <vector>
#include <iomanip>

// ������� ��� ��������� ������
void generateArray(std::vector<double>& array) {
    for (double& num : array) {
        num = static_cast<double>(rand()) / RAND_MAX * 10 - 5; // ��������� ������� � ������� (-5, 5)
    }
}

// ������� ��� ��������� ������
void printArray(const std::vector<double>& array) {
    for (const double& num : array) {
        std::cout << std::fixed << std::setprecision(2) << num << " ";
    }
    std::cout << std::endl;
}

// ������� ��� ����������� ������ ���������� ��������
int findMinIndex(const std::vector<double>& array) {
    int minIndex = 0;
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// ������� ��� ���������� ���� �������� �� ������ � ������ �䒺����� ����������
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

    // ���� �������� ��� ��'��� ��������
    if (firstNegIndex != -1 && secondNegIndex != -1) {
        double sum = 0;
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sum += array[i];
        }
        return sum;
    }
    return 0; // ���� ���� ���� ��'����� ��������
}

// ������� ��� ������������ ������
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

// ������� �������
int main() {
    srand(static_cast<unsigned int>(time(0))); // ����������� ���������� ���������� �����

    int n;
    std::cout << "������ ������� �������� ������: ";
    std::cin >> n;

    std::vector<double> array(n);

    // ��������� ������
    generateArray(array);

    // ��������� ������������ ������
    std::cout << "����������� �����:\n";
    printArray(array);

    // ����������� ������ ���������� ��������
    int minIndex = findMinIndex(array);
    std::cout << "����� ���������� ��������: " << minIndex << std::endl;

    // ���������� ���� �������� �� ������ � ������ ��'������ ����������
    double sumNegatives = sumBetweenNegatives(array);
    std::cout << "���� �������� �� ������ � ������ ��'������ ����������: " << sumNegatives << std::endl;

    // ������������ ������
    rearrangeArray(array);
    std::cout << "������������� �����:\n";
    printArray(array);

    return 0;
}
