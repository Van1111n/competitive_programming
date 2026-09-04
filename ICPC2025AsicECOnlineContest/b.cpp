#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int L, W, H;
        std::cin >> L >> W >> H;

        std::vector<std::vector<std::vector<int>>> cube(L, std::vector<std::vector<int>>(W, std::vector<int>(H)));
        std::vector<std::vector<std::vector<int>>> stat(L, std::vector<std::vector<int>>(W, std::vector<int>(H, 0)));  // -1: 不准选择, 0:未定, 1:当前被选择, 2:负权肯定得选.
        std::vector<std::vector<int>> A(H, std::vector<int>(L));
        std::vector<std::vector<int>> B(H, std::vector<int>(W));
        std::vector<std::vector<int>> C(W, std::vector<int>(L));
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < W; j++) {
                for (int k = 0; k < H; k++) {
                    std::cin >> cube[i][j][k];
                }
            }
        }
        getchar();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < L; j++) {
                A[i][j] = getchar() - '0';
                if (A[i][j] == 0) {
                    for (int k = 0; k < W; k++) {
                        stat[j][k][i] = -1;
                    }
                }
            }
            getchar();
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                B[i][j] = getchar() - '0';
                if (B[i][j] == 0) {
                    for (int k = 0; k < L; k++) {
                        stat[k][j][i] = -1;
                    }
                }
            }
            getchar();
        }
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < L; j++) {
                C[i][j] = getchar() - '0';
                if (C[i][j] == '0') {
                    for (int k=0; k<H; k++) {
                        stat[j][i][k] = -1;
                    }
                }
            }
            getchar();
        }

        for (int i=0; i<L; i++) {
            for (int j=0; j<W; j++) {
                for (int k=0; k<H; k++) {
                    if ()
                }
            }
        }

        return 0;
    }
}