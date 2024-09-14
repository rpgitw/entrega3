#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Función de ordenamiento Quicksort
void quicksort(std::vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

// Función de búsqueda binaria
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    // Generar números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> numbers(10);
    for (int& num : numbers)
        num = std::rand() % 100; // Generar números aleatorios entre 0 y 99

    std::cout << "Vector inicial: ";
    for (int num : numbers)
        std::cout << num << " ";
    std::cout << std::endl;

    // Ordenar el vector usando Quicksort
    quicksort(numbers, 0, static_cast<int>(numbers.size() - 1));

    std::cout << "Vector ordenado: ";
    for (int num : numbers)
        std::cout << num << " ";
    std::cout << std::endl;

    // Búsqueda binaria
    int target = 42;
    int index = binarySearch(numbers, target);
    if (index == -1)
        std::cout << "El elemento " << target << " no se encuentra en el vector." << std::endl;
    else
        std::cout << "El elemento " << target << " se encuentra en el índice " << index << "." << std::endl;

    return 0;
}
