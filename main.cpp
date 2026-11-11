#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 1. Factorial
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1); // Recursion step
}
// 2. Fibonacci numbers (recursion)
long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursion step
}
// 3. Search for the maximum in an array
int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxOfRest = findMax(arr, n - 1); // Recursive call for the rest
    return max(arr[n - 1], maxOfRest); // Ñompare the element with the maximum
}
// 4. Hanoi towers (5 disks)
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to); // Move n-1 discs to an aux rod.
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi(n - 1, aux, to, from); // Move n-1 disks to the rod
}
// Insertion sort with counting
void insertionSort(int arr[], int n, long long& comparisons, long long& swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Calculate the comparisons in the loop condition
        while (j >= 0 && (++comparisons && arr[j] > key)) {
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        if (j + 1 != i) {
            arr[j + 1] = key;
            swaps++; // Considering the transfer of the element
        }
    }
}
// Selection sort with counting
void selectionSort(int arr[], int n, long long& comparisons, long long& swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}
// Function for outputting an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    cout << "Part 1: Recursion" << endl;
    cout << "\n1. Factorial 5: " << factorial(5) << endl;
    cout << "2. Fibonacci numbers (the first 10): ";
    for (int i = 0; i < 10; i++) cout << fibonacci(i) << " ";
    cout << endl;
    int arr1[] = { 3, 8, 1, 9, 4, 7, 2 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "3. Maximum in the array: " << findMax(arr1, n1) << endl;
    cout << "4. Hanoi towers (5 disks):" << endl;
    hanoi(5, 'A', 'C', 'B');

    cout << "\nPart 2: Sortings" << endl;
    int arr2[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arrInsertion[7];
    copy(arr2, arr2 + n2, arrInsertion);
    long long compInsert = 0, swapInsert = 0;
    insertionSort(arrInsertion, n2, compInsert, swapInsert);
    cout << "\nInsertion sort:" << endl;
    printArray(arrInsertion, n2);
    cout << "Comparisons: " << compInsert << ", swap (transfers): " << swapInsert << endl;

    int arrSelection[7];
    copy(arr2, arr2 + n2, arrSelection);
    long long compSelect = 0, swapSelect = 0;
    selectionSort(arrSelection, n2, compSelect, swapSelect);
    cout << "\nSelection sort:" << endl;
    printArray(arrSelection, n2);
    cout << "Comparisons: " << compSelect << ", swap: " << swapSelect << endl;

    return 0;
}