#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define FILE_NAME "accounts.csv"

struct account
{
    char name[50];
    int mobileNumber;
    int pin;
    int accountNumber;
    float balance;
};
void customerSupport();
void adminSection();
void login();
void createAccount();
void welcomeScreen();
void user_section(struct account *user_account);
void deposit(struct account *u);
void check_balance(struct account *user_account);
void withdraw (struct account *user_account);

int main()
{
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
        printf("\nInvalid choice. Please try again.\n");
        break;
    }

printf("\n\n\n\t\tGoodbye! Thanks for trusting Ispark Inno\n");
printf("****************************************************************************");
   
return 0;
}

void welcomeScreen()
{   system("clear");
    printf("****************************************************************************");
    printf("\n\t\tWelcome to Ispark Inno Mini ATM system!\n\n ");
    printf("****************************************************************************");
    printf("\nWhat will you like to do today\n");
    printf("\n1. Create Account\n");
    printf("\n2. Login\n");
    printf("\n3. Customer Support\n");
    printf("\nEnter your choice: ");
}

void createAccount()
{
    struct account accounts;
    FILE *file = fopen(FILE_NAME, "a");
    if (!file)
    {
        perror("Error opening file");
    }

    printf("\nEnter your name: \n");
    scanf("%s", accounts.name);

    printf("\nEnter your phone number: \n");
    scanf("%d", &accounts.mobileNumber);

    printf("\nEnter your pin: \n");
    scanf("%d", &accounts.pin);

    printf("\nEnter your initial balance: \n");
    scanf("%f", &accounts.balance);

    srand(time(NULL));
    int accountNumber = 1000 + rand() % 1000;

    fprintf(file, "%d,%s,%d,%d,%.2f\n", accountNumber, accounts.name, accounts.mobileNumber, accounts.pin, accounts.balance);

    fclose(file);

    printf("\nAccount Created Successfully\n");
    printf("\nYour account Number is: %d\n", accountNumber);

    sleep(10);
    system("clear");

    user_section(&accounts);
}

void user_section(struct account *user_account)
{
    printf("\nWelcome %s", user_account->name);
    int choice;
    while (true)

    {
        printf("\n\n\n1. Check balance\n");
        printf("\n2. Deposit\n");
        printf("\n3. Withdraw\n");
        // printf("\n4. Transaction History\n");
        // printf("\n5. Change pin\n");
        // printf("\n6. Account Setting\n");
        printf("\n4. logout\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        if (choice == 2)
        {
            deposit(user_account);
        }
        else if (choice == 4)
        {
            break;
        }
        else if (choice == 1)
        {
            check_balance(user_account);
        }
        else if(choice == 3) {
        withdraw(user_account);
        }
        else {
            printf("\nOption not yet available");
        }
    }
}

void login()
{
    int choice;
    char admin_name[] = "Marie-Lois";
    int admin_pin = 6615;
    struct account accounts;

    printf("\n1. Login as User: \n");
    printf("\n2. Login as an Adim: \n");
    printf("\nEnter choice: \n");
    scanf("%d", &choice);
    int input_accountnumber;
    int input_accountpin;

    switch (choice)
    {
    case 1:
        FILE *file = fopen(FILE_NAME, "r");
        if (!file)
        {
            perror("Error opening file");
        }
        printf("\nEnter account number: \n");
        scanf("%d", &input_accountnumber);
        printf("\nEnter pin: \n");
        scanf("%d", &input_accountpin);
        bool found = false;

        while (fscanf(file, "%d,%49[^,],%d,%d,%f\n", &accounts.accountNumber, accounts.name, &accounts.mobileNumber, &accounts.pin, &accounts.balance) != EOF)
            ;
        {
            printf("\n%d", accounts.accountNumber);
            if (input_accountnumber == accounts.accountNumber && input_accountpin == accounts.pin)
            {
                printf("\nLogin in successful. \nWelcome %s\n", accounts.name);
                found = true;
                sleep(10);
                system("clear");
                user_section(&accounts);
                break;
            }
        }

        if (found == false)
        {
            printf("\nInvalid account number/pin\n");
        }
        break;
    case 2:
        char input_admin_name[15];

        printf("\nEnter admin name: \n");
        scanf("%s", input_admin_name);
        printf("\nEnter admin pin: \n");
        scanf("%d", &admin_pin);
        if (strcmp(input_admin_name, "Marie-Lois") == 0 && admin_pin == 6615)
        {
            adminSection();
        }
        else
        {
            printf("\nYou are not an admin");
        }
        break;
    default:
        printf("\nInvalid choice");
        break;
    }
}
void adminSection()
{
    int choice;
    printf("\nAdmin Section\n");
    printf("\n1. View User Infomormation\n");
    printf("\n2. Delete User account\n");
    printf("\n\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

        break;

    default:
        break;
    }
}

void customerSupport()
{
    printf("\nCustumer support selected\n");
}

void deposit(struct account *user_account)
{
    int amount;
    printf("\nEnter deposit amount: ");
    scanf("%d", &amount);
    user_account->balance = amount + user_account->balance;
    printf("\nDeposit Successful");
    printf("\nNew balance: %.2f", user_account->balance);
}

void check_balance(struct account *user_account)
{
    user_account->balance;
    printf("\n\nNew balance: %.2f", user_account->balance);
}

void withdraw (struct account *user_account)

{   int amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%d", &amount);

    if(amount >= user_account->balance) 
    {
        printf("\nAccount cannot be emptied");
        return;
    }
    else 
    {
        user_account->balance = user_account->balance - amount;
    }
check_balance(user_account);
}