#include <iostream>
#include <vector>

// v1, v2 must have same size
std::pair<int, int> match(std::vector<int>& v1, std::vector<int>& v2) {
    int strong = 0, weak = 0;
    int numStat1[10] = {0}, numStat2[10] = {0};
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] == v2[i]) {
            ++strong;
        }
    }
    for (auto i : v1) {
        numStat1[i]++;
    }
    for (auto i : v2) {
        numStat2[i]++;
    }
    for (int i=0; i<=9; i++) {
        weak += std::min(numStat1[i], numStat2[i]);
    }
    weak -= strong;
    return {strong, weak};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int gameNo = 1;
    while (1) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::vector<int> key(n), guess(n);
        for (auto& i : key) {
            std::cin >> i;
        }

        std::cout << "Game " << gameNo << ":\n";
        ++gameNo;
        while (1) {
            for (auto& i : guess) {
                std::cin >> i;
            }
            if (guess[0] == 0) {
                break;
            }
            auto hint = match(key, guess);
            std::cout << "    " << '(' << hint.first << ',' << hint.second << ')' << '\n';
        }
    }
}