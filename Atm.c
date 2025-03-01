#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct account {
    char name[50];
    int mobileNumber; 
    int pin;
    int accountNumber;
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
    struct account accounts;
    int choice;
    char admin_name[] = {'M', 'a', 'r', 'i', 'e', '_', 'l', 'o', 'i', 's'};
    int admin_pin = 6615;

    printf("1. Login as User: \n");
    printf("2. Login as an Adim: \n");
    printf("Enter choice: \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter account number: \n");
        scanf("%d", &accounts.accountNumber);
        printf("Enter pin: \n");
        scanf("%d", &accounts.pin);
        break;
    case 2:
        printf("Enter admin name: \n");
        scanf("%s", &admin_name);
        printf("Enter admin pin: \n");
        scanf("%d", &admin_pin);
        break;
    default:
        printf("Invalid choice");
        break;
    }


}
void adminSection() {
    char admin_name = "Marie_Lois";
    int admin_pin = 6615;
    int choice;
    if(admin_name == "Marie_lois" && admin_pin == 6615) {
        printf("Admin Section\n");
        printf("1. View User Infomormation\n");
        printf("2. Delete User account\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            
            break;
        
        default:
            break;
        }

    }
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
    adminSection();
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        
        break;
    
    default:
        break;
    }

    return 0;
}