#include <string>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string original;
        std::cin >> original;

        int n = original.length();
        std::string min = original;
        std::string perm;
        for (int i = 0; i < n; i++) {
            perm = original.substr(i) + original.substr(0, i);
            min = std::min(perm, min);
        }

        std::cout << min << '\n';
    }
    return 0;
}