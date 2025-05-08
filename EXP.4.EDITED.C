#include <stdio.h>
#include <math.h>
#include <string.h>
int isPrime(int n) {
if (n < 2) return 0;
for (int i = 2; i <= sqrt(n); i++)
if (n % i == 0) return 0;
return 1;
}
int gcd(int a, int b) {
while (b) { int t = b; b = a % b; a = t; }
return a;
}
int modInverse(int e, int phi) {
for (int d = 2; d < phi; d++)
if ((e * d) % phi == 1) return d;
return -1;
}
int modExp(int base, int exp, int mod) {
int res = 1;
base %= mod;
while (exp) {
if (exp & 1) res = (res * base) % mod;
base = (base * base) % mod;
exp >>= 1;
}
return res;
}
int main() {
int p, q, n, phi, e[6], d[6], count = 0;
char msg[100], encrypted[100], decrypted[100];
printf("ENTER FIRST PRIME NUMBER\n");
scanf("%d", &p);
if (!isPrime(p)) { printf("WRONG INPUT\n"); return 1; }
printf("\nENTER ANOTHER PRIME NUMBER\n");
scanf("%d", &q);
if (!isPrime(q) || p == q) { printf("WRONG INPUT\n"); return 1; }
printf("\nENTER MESSAGE\n");
scanf("%s", msg);
n = p * q;
phi = (p - 1) * (q - 1);
for (int i = 2; i < phi && count < 6; i++) {
if (gcd(i, phi) == 1) {
int inv = modInverse(i, phi);
if (inv != -1) {
e[count] = i;
d[count++] = inv;
}
}
}
printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
for (int i = 0; i < count; i++)
printf("\n%d\t%d", e[i], d[i]);
int keyE = e[0], keyD = d[0];
printf("\nTHE ENCRYPTED MESSAGE IS\n");
for (int i = 0; msg[i]; i++) {
encrypted[i] = modExp(msg[i] - 96, keyE, n) + 96;
printf("%c", encrypted[i]);
}
encrypted[strlen(msg)] = '\0';
printf("\nTHE DECRYPTED MESSAGE IS\n");
for (int i = 0; encrypted[i]; i++) {
decrypted[i] = modExp(encrypted[i] - 96, keyD, n) + 96;
printf("%c", decrypted[i]);
}
decrypted[strlen(msg)] = '\0';
return 0;
}