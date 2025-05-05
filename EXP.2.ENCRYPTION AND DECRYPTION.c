// WRITE A PROGRAM FOR ENCRYPTION AND DECRYPTION (USING C COMPILER)
#include <stdio.h>
#include <string.h>
void encrypt(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + 3;
    }
}
void decrypt(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] - 3;
    }
}
int main() {
    char str[100];
    int choice;
    printf("Enter the string: ");
    scanf("%s", str);
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            encrypt(str);
            printf("Encrypted string: %s\n", str);
            break;
        case 2:
            decrypt(str);
            printf("Decrypted string: %s\n", str);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
