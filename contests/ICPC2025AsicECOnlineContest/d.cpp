#include <algorithm>
#include <iostream>
#include <vector>

using llong = long long;

const int mod = 998244353;
const int inv2 = 499122177;

llong fast_pow(llong a, llong b) {
    llong res = 1;
    while (b) {
        if (b % 2) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<llong> vec(n);
        for (int i = 0; i < n; i++) {
            std::cin >> vec[i];
        }
        std::sort(vec.begin(), vec.end());

        std::vector<llong> seq(n);
        int k = 1;
        llong a = fast_pow(2, n-2);
        llong b = 1;
        for (int i=0; i<n; i++) {
            seq[i] = a * (b+1) % mod;
            a = a * inv2 % mod;
            b = b * 3 % mod;
        }

        llong ans = 0;
        for (int i=0; i<n; i++) {
            ans = (ans + seq[i] * vec[i]) % mod;
        }
        std::cout << ans << std::endl;
    }

}