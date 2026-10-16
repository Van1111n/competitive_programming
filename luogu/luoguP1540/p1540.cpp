#include <algorithm>
#include <iostream>
#include <queue>

int main() {
    int m, n;
    std::cin >> m >> n;
    std::deque<int> mem;

    int memMissCount = 0;
    for (int i = 0; i < n; i++) {
        int crtWord;
        std::cin >> crtWord;
        if (std::find(mem.begin(), mem.end(), crtWord) == mem.end()) {
            ++memMissCount;
            mem.push_back(crtWord);
            if (mem.size() > m) {
                mem.pop_front();
            }
        } else {
            continue;
        }
    }
    std::cout << memMissCount << std::endl;
}