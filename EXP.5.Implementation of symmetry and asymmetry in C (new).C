#include <stdio.h>
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}
int main() {
    int g = 2, p = 101;
    int x = 3;  // Alice's private key
    int y = 6;  // Bob's private key
    int R1 = mod_exp(g, x, p);  // Alice's public value
    int R2 = mod_exp(g, y, p);  // Bob's public value
    int K_Alice = mod_exp(R2, x, p);
    int K_Bob = mod_exp(R1, y, p);
    int K_Final = K_Alice;
    printf("Result:\n");
    printf("\nThe results are as follows:\n\n");
    printf("1) Alice choose x=%d & calculates R1=%d\n", x, R1);
    printf("2) Bob chooses y=%d & calculates R2=%d\n", y, R2);
    printf("3) Alice sends the number %d to Bob\n", R1);
    printf("4) Bob sends the number %d to Alice\n", R2);
    printf("5) Alice calculates the symmetric key k=%d\n", K_Alice);
    printf("6) Bob calculates the symmetric key k=%d\n", K_Bob);
    printf("7) K_Final=%d\n", K_Final);
    return 0;
}