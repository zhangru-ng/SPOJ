// http://www.spoj.com/problems/PES16STR/

#include <stdio.h>

int brute_force_substr(char* text, char* ptn) {
    int i, j, k;
    for(i = 0; text[i] != '\0'; i++){
        k = i;
        j = 0;
        while (text[k] != '\0' && ptn[j] != '\0' && text[k] == ptn[j]) {
            k++;
            j++;
        }
        if (ptn[j] == '\0') {
            return i;
        }
    }
    return -1;
}

int main(void) {
    char text[1000000];
    char ptn[1000000];
    int t;
    scanf("%d\n", &t);
    while (t--) {
        gets(text);
        gets(ptn);
        printf("%d\n", brute_force_substr(text, ptn));
    }
    return 0;
}
