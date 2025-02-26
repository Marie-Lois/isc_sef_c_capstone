#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct account {
    char name[50];
    int mobileNumber; 
    int pin;
    float balance;
};

void welcomeScreen() {
    printf("Welcome!\n What will you like to do today\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Customer Support\n");
    printf("Enter your choice: ");

}
void createAccount() {
    struct account accounts;
    FILE *file;

    printf("Enter your name: \n");
    scanf("%s", accounts.name);

    printf("Enter your phone number: \n");
    scanf("%d", &accounts.mobileNumber);

    printf("Enter your pin: \n");
    scanf("%d", &accounts.pin);

    printf("Enter your initial balance: \n");
    scanf("%f", &accounts.balance);
    
    srand(time(NULL));
    int accountNumber = 1000 + rand() % 1000;

    char filename[50];
    sprintf(filename, "%d.txt", accountNumber);
    
    file = fopen(filename, "w");
    fprintf(file, "Account Number: %d\n", accountNumber);
    fprintf(file, "Account Name: %s\n", accounts.name);
    fprintf(file, "Mobile Number: %d\n", accounts.mobileNumber);
    fprintf(file, "PIN: %d\n", accounts.pin);
    fprintf(file, "%.2f\n", accounts.balance);

    fclose(file);

    printf("Account Created Successfully\n");
    printf("Your account Number is: %d\n", accountNumber);
}

void login() {
    printf("Login selected\n");
}
void customerSupport() {
    printf("Custumer support selected\n");
}

int main() {
   welcomeScreen();
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        createAccount();
        break;
    case 2:
        login();
        break;
    case 3:
        customerSupport();
        break;
    default:
    printf("Invalid choice. Please try again.\n");
        break;
    }

    return 0;
}