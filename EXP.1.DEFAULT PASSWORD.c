//(A] Default Passwords: Using Online C Compiler
#include <stdio.h>
#include <string.h>
int main()
{
    char username[15];
    char password[12];
    printf("Enter your username:\n");
    scanf("%s", username);
    printf("Enter your password:\n");
    scanf("%s", password);
    if (strcmp(username, "MANGESH") == 0)
    {
        if (strcmp(password, "MUNDE") == 0)
        {
            printf("\nWelcome. Login Success!");
        }
        else
        {
            printf("\nWrong password");
        }
    }
    else
    {
        printf("\nUser doesn't exist");
    }
    return 0;
}

//B] Printed Passwords (using online C compiler)
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
int main() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    printf("Enter User name: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove trailing newline
    printf("Enter the password <any 8 characters>: ");
    scanf("%s", password);
    printf("********\n");
    printf("\nYour password is: ");
    printf("%s\n", password); 
    return 0;
}

//B] Printed Passwords (using online C++ compiler)
#include <iostream>
#include <string>
using namespace std;
int main() {
    string username;
    string password;
    cout << "Enter User name: ";
    getline(cin, username);
    cout << "Enter the password <any 8 characters>: ";
    cin >> password;
    cout << "********" << endl;
    cout << "\nYour password is: ";
    cout << password << endl;
    return 0;
}

