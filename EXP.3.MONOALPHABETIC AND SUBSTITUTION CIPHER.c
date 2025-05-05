// WRITE A PROGRAM TO PERFORM ENCRYPTION AND DECRYPTION USING THE FOLLOWING ALGORITHMS; CEASER CIPHER, SUBSTITUTION CIPHER
#include<stdio.h>
#include<string.h>
char dc[26]="XDGSZANYOBTMJCEVFHKWPLQURI";
char ec[26]="abcdefghijklnmopqrstuvwxyz";
void e(char*);
void d(char*);
void main(){
    char *p;
    printf("\n\nEnter plain text:");
    scanf("%s",p);
    printf("\nAfter Encryption:\n---\n");
    e(p);
    printf("\n%s",p);
    printf("\nAfter Decryption:\n---\n");
    d(p);
    printf("\n%s",p);
}
void e(char *p){
    int l=0;
    while(*(p+l) != '\0'){
        *(p+l)=dc[*(p+l)-97];
        l++;
    }
}
void d(char *p){
    int l=0;
    while(*(p+l) != '\0'){
        int i;
        for(i=0;i<26;i++) {
            if(dc[i]==*(p+l))
            break;
        }
        *(p+l)=ec[i];
        l++;
    }
}
