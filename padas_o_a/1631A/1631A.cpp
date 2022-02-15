#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

bool comp(int a, int b) {
  return b < a;
}

int main() {
    int requests = 0;
    int size = 0;
    std::cin >> requests;
    for (int i = 0; i < requests; ++i) {
        std::cin >> size;
        std::vector<int> A(size);
        std::vector<int> B(size);
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
        std::sort(A.begin(), A.end(), comp);
        std::sort(B.begin(), B.end(), comp);
        std::cout << A[0] * B[0] << "\n";
    }
    return 0;
}