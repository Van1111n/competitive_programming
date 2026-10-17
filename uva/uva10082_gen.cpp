#include <iostream>

const char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    FILE *fp = fopen("uva10082_table.txt", "w");
    for (int i=1; i<47; i++) {
        fprintf(fp, "s['%c'] = '%c';\n", s[i], s[i-1]);
    }
}