#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

bool check(int n, std::vector<int>& vec) {
    std::vector<int> seq(n);
    std::stack<int> st;

    for (int i = 0; i < n; i++) {
        seq[i] = n - i;
    }

    for (auto b : vec) {
        while (st.empty() || st.top() != b) {
            if (seq.empty())
                goto fuck;
            st.push(seq.back());
            seq.pop_back();
        }
        st.pop();
    }
    return true;
fuck:
    return false;
}

int main() {
    int n;
    while (1) {
        std::cin >> n;
        bool flag;
        if (n == 0)
            break;

    shit:
        std::vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            std::cin >> vec[i];
            if (vec[i] == 0)
                goto blockend;
        }

        flag = check(n, vec);
        std::cout << (flag ? "Yes" : "No");
        std::cout << '\n';
        goto shit;

    blockend:
        std::cout << '\n';
        continue;
    }
}