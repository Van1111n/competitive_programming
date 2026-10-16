#include <set>
#include <vector>
#include <iostream>

struct Ship{
    int time;
    int psgCount;
    std::set<int> countries;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Ship> ships(n);
    for (auto &it : ships) {
        std::cin >> it.time >> it.psgCount;
        for (int i = 0; i < it.psgCount; i++) {
            int crtCountry;
            std::cin >> crtCountry;
            it.countries.insert(crtCountry);
        }
    }

    auto f = ships.begin(), crt = ships.begin();
    while (crt < ships.end()) {
        while (f->time <= crt->time - 86400) {
            ++f;
        }

        std::set<int> res;
        for (auto it = f; it <= crt; ++it) {
            for (auto c : it->countries) {
                res.insert(c);
            }
        }
        std::cout << res.size() << '\n';

        ++crt;
    }
}