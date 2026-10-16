#include <cstdio>

int main() {
    bool left = true;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            if (left) {
                putchar('`');
                putchar('`');
            } else {
                putchar('\'');
                putchar('\'');
            }
            left = !left;
        } else {
            putchar(c);
        }
    }
}