#include <stdio.h>
#include <stdlib.h>
unsigned int E_P_Box(unsigned int R) {
unsigned int res = 0;
int E[32] = {
31,0,1,2,3,4,3,4,
5,6,7,8,7,8,9,10,
11,12,11,12,13,14,15,16,
15,16,17,18,19,20,19,20
};
for (int i = 0; i < 32; i++) {
res |= ((R >> (31 - E[i])) & 1) << (31 - i);
}
return res;
}
unsigned int S_Box(unsigned int input) {
int S[4][16] = {
{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};
unsigned int output = 0;
for (int i = 0; i < 8; i++) {
unsigned char six_bits = (input >> (26 - 4 * i)) & 0x3F;
int row = ((six_bits & 0x20) >> 4) | (six_bits & 1);
int col = (six_bits >> 1) & 0x0F;
output |= (S[row][col] & 0x0F) << (28 - 4 * i);
}
return output;
}
void des_round(unsigned int *L, unsigned int *R, unsigned int K) {
unsigned int expanded = E_P_Box(*R);
unsigned int xored = expanded ^ K;
unsigned int substituted = S_Box(xored);
unsigned int temp = *L ^ substituted;
*L = *R;
*R = temp;
}
void des_encrypt(unsigned int *L, unsigned int *R, unsigned int K) {
des_round(L, R, K);
}
void des_decrypt(unsigned int *L, unsigned int *R, unsigned int K) {
unsigned int temp_L = *L, temp_R = *R;
unsigned int expanded = E_P_Box(temp_L); // Use L (was R before swap)
unsigned int xored = expanded ^ K;
unsigned int substituted = S_Box(xored);
*R = *L; // Swap back
*L = temp_R ^ substituted; // Undo XOR
}
int main() {
char plaintext_hex[17], key_hex[17];
unsigned int L, R, K;
printf("Enter 16-digit hexadecimal plaintext: ");
scanf("%16s", plaintext_hex);
printf("Enter 16-digit hexadecimal key: ");
scanf("%16s", key_hex);
// Split 64-bit plaintext into L and R (32 bits each)
sscanf(plaintext_hex, "%8x%8x", &L, &R);
sscanf(key_hex, "%8x", &K); // Use only 32 bits of key for one round
printf("\n=== Encryption ===\n");
printf("Plaintext: %08X %08X\n", L, R);
des_encrypt(&L, &R, K);
printf("Ciphertext: %08X %08X\n", L, R);
printf("\n=== Decryption ===\n");
des_decrypt(&L, &R, K);
printf("Decrypted Plaintext: %08X %08X\n", L, R);
return 0;
}