#include <iostream>
#include <cstring>

const int LEN = 256;

char revTable[LEN]; 

void initRevTable(char* table) {
    for (int i=0; i<LEN; i++) {
        table[i] = ' ';
    }
    table['A'] = 'A';
    table['E'] = '3';
    table['H'] = 'H';
    table['I'] = 'I';
    table['J'] = 'L';
    table['L'] = 'J';
    table['M'] = 'M';
    table['O'] = 'O';
    table['S'] = '2';
    table['T'] = 'T';
    table['U'] = 'U';
    table['V'] = 'V';
    table['W'] = 'W';
    table['X'] = 'X';
    table['Y'] = 'Y';
    table['Z'] = '5';
    table['1'] = '1';
    table['2'] = 'S';
    table['3'] = 'E';
    table['5'] = 'Z';
    table['8'] = '8';
}

// 0 - not palindrome; 1 - palindrome; 2 - mirrored; 3 - mirrored palindrome
int check(char *s) {
    int n = strlen(s);
    bool palindrome = true, mirror = true;
    char *p = s, *q = s + n - 1;

    while (q >= p) {
        if (*p != *q) {
            palindrome = false;
        }
        if (revTable[*p] != *q) {
            mirror = false;
        }

        if (palindrome == false && mirror == false) {
            break;
        }
        ++p, --q;
    }

    return (palindrome ? 1 : 0) + (mirror ? 2 : 0);
}

int main() {
    initRevTable(revTable);
    char s[32];
    while (scanf("%s", s) != EOF) {
        int stat = check(s);
        switch (stat)
        {
        case 0:
            printf("%s -- is not a palindrome.\n", s);
            break;
        case 1:
            printf("%s -- is a regular palindrome.\n", s);
            break;
        case 2:
            printf("%s -- is a mirrored string.\n", s);
            break;
        case 3:
            printf("%s -- is a mirrored palindrome.\n", s);
            break;
        default:
            break;
        }
        putchar('\n');
    }
}