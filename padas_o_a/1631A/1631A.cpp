#include <iostream>
#include <stdlib.h>

int comp(const void * a, const void * b) {
  return ( - *(int*)a + *(int*)b );
}

int main() {
    int requests = 0;
    int size = 0;
    std::cin >> requests;
    for (int i = 0; i < requests; ++i) {
        std::cin >> size;
        int* A = new int[size];
        int* B = new int[size];
        for (int j = 0; j < size; ++j) {
            std::cin >> A[j];
        }
        for (int j = 0; j < size; ++j) {
            std::cin >> B[j];
        }
        for (int j = 0; j < size; ++j) {
            if (A[j] > B[j]) {
                int swap = A[j];
                A[j] = B[j];
                B[j] = swap;
            }
        }
        qsort(A, size, sizeof(int), comp);
        qsort(B, size, sizeof(int), comp);
        std::cout << A[0] * B[0] << "\n";
    }
    return 0;
}