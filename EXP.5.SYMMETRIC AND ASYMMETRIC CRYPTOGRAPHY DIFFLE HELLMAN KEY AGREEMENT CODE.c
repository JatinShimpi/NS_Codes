
// IMPLEMENTATION OF SYMMETRIC AND ASYMMETRIC CRYPTOGRAPHY / DIFFLE HELLMAN KEY AGREEMENT CODE

clc;
// Parameters
g =2;
p = 101;
// Private keys
x = 3;  // Alice's private key
y = 6;  // Bob's private key
// Calculate public values
R1 = modulo(g^x, p);  // Alice's public value
R2 = modulo(g^y, p);  // Bob's public value
// Calculate shared secret
K_Alice = modulo(R2^x, p);
K_Bob = modulo(R1^y, p);
K_Final = K_Alice;  // Both should be equal
// Display results
printf("Result:\n");
printf("\nThe results are as follows:\n\n");
printf("1) Alice choose x=%d & calculates R1=%d\n", x, R1);
printf("2) Bob chooses y=%d & calculates R2=%d\n", y, R2);
printf("3) Alice sends the number %d to Bob\n", R1);
printf("4) Bob sends the number %d to Alice\n", R2);
printf("5) Alice calculates the symmetric key k=%d\n", K_Alice);
printf("6) Bob calculates the symmetric key k=%d\n", K_Bob);
printf("7) K_Final=%d\n", K_Final);

