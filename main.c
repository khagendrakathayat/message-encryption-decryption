
// library declaration  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i = 0;
    char ch;
    // while loop for message encryption
    while (message[i] != '\0') {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + key) % 26) + 'a';
            message[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + key) % 26) + 'A';
            message[i] = ch;
        }

        i++;
    }
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i = 0;
    char ch;
    // while loop for message decryption
    while (message[i] != '\0') {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - key + 26) % 26) + 'a';
            message[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - key + 26) % 26) + 'A';
            message[i] = ch;
        }

        i++;
    }
}

int main() {
    int choice;
    char message[100];
    int key;

printf("\n ##################### Welcome to message encryption and decryption program  ######################### \n");
    while (1) {

    
        printf("1. Encryption\n2. Decryption\n3. Exit\n");
        printf("Enter your choice: ");
        // scanning the user input choice 
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        if (choice == 3) {
            printf("Exiting the program...\n");
            break;  // Terminate the loop and exit the program
        } else if (choice != 1 && choice != 2) {
            printf("Invalid choice\n");
            continue;  // Restart the loop for a valid choice
        }

        printf("Enter a message: ");

        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove the trailing newline character
        
        // print the  message key  option 
        printf("Enter a key (0-25): ");
        scanf("%d", &key);
        
        // Consume the newline character
        getchar(); 

        if (choice == 1) {
            // passing args in encrypt function 
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            printf("\n");
            printf("your message has been encrypted sucessfully.\n");
            printf("\n");

        } else if (choice == 2) {
            // passing args in decrypt function 
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
                        printf("\n");

            printf("your message has been decrypted sucessfully.\n");
            printf("\n");

        }
    }

    printf("\n ************************ Thank you *************************** \n");

    return 0;
}
