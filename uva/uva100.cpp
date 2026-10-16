#include <cstdio>
#include <vector>

int cycLen(int x) {
    int cyc = 1;
    while (x != 1) {
        if (x % 2) {
            x = 3 * x + 1;
        } else {
            x = x / 2;
        }
        ++cyc;
    }
    return cyc;
}

int main() {
    std::vector<int> cycTime(1000001, -1);
    int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
        int l = std::min(i, j), r = std::max(i, j);
        int maxLen = 0;
        for (int k = l; k <= r; k++) {
            if (cycTime[k] = -1) {
                cycTime[k] = cycLen(k);
            }
            maxLen = std::max(cycTime[k], maxLen);
        }
        printf("%d %d %d\n", i, j, maxLen);
    }
    return 0;
}