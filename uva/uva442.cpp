#include <iostream>
#include <stack>
#include <string>
#include <vector>

using llong = long long;

struct Matrix {
    int row;
    int column;

    Matrix(int a, int b) : row(a), column(b) {}

    Matrix() = default;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Matrix> matrices(128);
    for (int i = 0; i < n; i++) {
        char maName;
        std::cin >> maName;
        std::cin >> matrices[maName].row >> matrices[maName].column;
    }
    getchar();

    std::string s;
    while (1) {
        std::getline(std::cin, s);
        if (s.empty()) {
            break;
        }

        std::stack<Matrix> st;
        llong ans = 0;
        for (char c : s) {
            if (isupper(c)) {
                st.push(matrices[c]);
            }
            if (c == ')') {
                auto ma2 = st.top();
                st.pop();
                auto ma1 = st.top();
                st.pop();

                if (ma1.column != ma2.row) {
                    goto dimensionError;
                }
                int multCount = ma1.row * ma2.row * ma2.column;
                ans += multCount;
                st.push({ma1.row, ma2.column});
            }
        }
        std::cout << ans << '\n';
        goto clearSt;

    dimensionError:
        std::cout << "error\n";
        goto clearSt;

    clearSt:
        while (!st.empty()) {
            st.pop();
        }
    }
}