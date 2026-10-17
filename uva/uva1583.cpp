#include <iostream>
#include <vector>

const int maxN = 100000;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

std::vector<int> pre_gen() {
    std::vector<int> vec(maxN + 1, 0);
    for (int i = 0; i <= maxN; i++) {
        int j = i + digitSum(i);
        if (j > maxN) {
            continue;
        }
        if (vec[j] == 0) {
            vec[j] = i;
        }
    }
    return vec;
}

int main() {
    auto generator = pre_gen();

    int t;
    std::cin >> t;

    int n;
    while (t--) {
        std::cin >> n;
        std::cout << generator[n] << '\n';
    }
    return 0;
}