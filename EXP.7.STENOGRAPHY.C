#include <stdio.h>
#include <string.h>
int main() {
FILE *in, *out;
int choice, i = 0, bit;
char msg[1000], ch;
printf("1. Encode + Decode\nEnter: ");
scanf("%d", &choice);
if (choice == 1) {
in = fopen("input.bmp", "rb");
out = fopen("output.bmp", "wb");
if (!in || !out) return 1;
printf("Enter message to hide: ");
getchar();
scanf("%[^\n]", msg);
for (int j = 0; j < 54; j++) fputc(fgetc(in), out);
while ((ch = msg[i++]) != '\0')
for (int b = 7; b >= 0; b--) {
int pixel = fgetc(in);
bit = (ch >> b) & 1;
fputc((pixel & 0xFE) | bit, out);
}
for (int b = 7; b >= 0; b--) {
int pixel = fgetc(in);
fputc(pixel & 0xFE, out); // end mark
}
while ((ch = fgetc(in)) != EOF) fputc(ch, out);
fclose(in); fclose(out);
printf("\nMessage encoded to output.bmp\n");
// Decode from output.bmp
FILE *decode = fopen("output.bmp", "rb");
if (!decode) return 1;
fseek(decode, 54, SEEK_SET);
printf("Decoded Text: ");
while (1) {
ch = 0;
for (int b = 7; b >= 0; b--)
ch |= ((fgetc(decode) & 1) << b);
if (ch == '\0') break;
putchar(ch);
}
printf("\n");
fclose(decode);
}
return 0;
}