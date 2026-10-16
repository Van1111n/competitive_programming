#include <iostream>
#include <vector>

struct Vertex {
    int wt;
    int beginTime, finishTime;
    std::vector<int> req;

    Vertex() {
        wt = 0;
        beginTime = finishTime = -1;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<Vertex> aov(n + 1);
    int no, len, prev;
    for (int i = 1; i <= n; i++) {
        std::cin >> no >> len >> prev;
        auto& v = aov[no];
        v.wt = len;
        while (prev != 0) {
            v.req.push_back(prev);
            std::cin >> prev;
        }
    }

    std::vector<bool> arranged(n + 1, false);
    int arrangedCount = 0;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (aov[i].req.empty()) {
            arranged[i] = true;
            aov[i].beginTime = 0;
            aov[i].finishTime = aov[i].wt;
            ans = std::max(ans, aov[i].finishTime);
            ++arrangedCount;
        }
    }
    while (arrangedCount < n) {
        for (int i=1; i<=n; i++) {
            auto& v = aov[i];
            bool prevFinish = true;
            for (auto r : v.req) {
                if (arranged[r] == false) {
                    prevFinish = false;
                    break;
                }
            }
            if (prevFinish) {
                arranged[i] = true;
                int lastFinishTime = 0;
                for (auto r : v.req) {
                    lastFinishTime = std::max(lastFinishTime, aov[r].finishTime);
                }
                v.beginTime = lastFinishTime;
                v.finishTime = v.beginTime + v.wt;
                ans = std::max(ans, v.finishTime);
                ++arrangedCount;
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}