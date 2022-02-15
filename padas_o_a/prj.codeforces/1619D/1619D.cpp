#include <iostream>
#include <vector>
#include <utility>

void complete(std::vector<std::vector<int>>& enjoy, int shops, int friends) {
    for (int i = 0; i < shops; ++i) {
        for (int j = 0; j < friends; ++j) {
            int current = 0;
            std ::cin >> current;
            enjoy[i].push_back(current);
        }
    }
}

bool possible(std::vector<std::vector<int>> enjoy, int value) {
    std::vector<int> shops_fit_for(enjoy.size(), 0);
    std::vector<bool> frieds_satisfied(enjoy[0].size(), false);
    for (int i = 0; i < enjoy.size(); ++i) {
        for (int j = 0; j < enjoy[i].size(); ++j) {
            if (enjoy[i][j] >= value) {
                frieds_satisfied[j] = true;
                ++shops_fit_for[i];
            }
        }
    }
    for (int i = 0; i < enjoy[0].size(); ++i) {
        if (!frieds_satisfied[i]) {
            return false;
        }
    }
    for (int j = 0; j < enjoy.size(); ++j) {
        if (shops_fit_for[j] >= 2 ) {
            return true;
        }
    }
    return false;
}

int main() {
    int request = 0;
    std::cin >> request;
    for (int i = 0; i < request; ++i) {
        int friends = 0;
        int shops = 0;
        std::cin >> shops >> friends;
        std::vector<std::vector<int>> enjoy(shops);
        complete(enjoy, shops, friends);
        int left = 1, right = 2;
        while (possible(enjoy, right)) {
            left = right;
            right *= 2;
        }
        while (right - left > 1){
            int middle = (right + left) / 2;
            if(possible(enjoy, middle)) {
                left = middle;
            } else {
                right = middle; 
            }
        }
        std::cout << left << "\n";
    }
    return 0;
}