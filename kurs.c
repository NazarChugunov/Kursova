#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt();
void decrypt();
void caesaralgorithminfo();
void clearInputBuffer();
void readLine(char **text);

int main() {
    int choice;
    while (1) {
        printf("Choose an option:\n");
        printf("1 - Encryption\n");
        printf("2 - Decryption\n");
        printf("3 - The principle of operation of the Caesar encryption algorithm\n");
        printf("0 - Finish the program\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Error. Please enter a number from 1 to 3 or 0\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                encrypt();
                break;
            case 2:
                decrypt();
                break;
            case 3:
                caesaralgorithminfo();
                break;
            case 0:
                printf("End of the program.\n");
                return 0;
            default:
                printf("Error. Please enter a number from 1 to 3 or 0\n");
                break;
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void readLine(char **text) {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            *text = NULL;
        } else {
            *text = malloc(strlen(buffer) + 1);
            if (*text != NULL) {
                strcpy(*text, buffer);
            }
        }
    }
}
void encrypt() {
    char *text = NULL;
    int key;
    
    printf("Enter the text to encrypt: ");
    readLine(&text);
    
    if (text == NULL || strlen(text) == 0) {
        printf("Error. Please enter the text. Returning to the menu.\n");
        return;
    }

    printf("Enter the encryption key (0-25): ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input. Returning to the menu.\n");
        free(text);
        clearInputBuffer();
        return;
    }

    if (key < 0 || key > 25) {
        printf("Error: Key must be between 0 and 25. Returning to the menu.\n");
        free(text);
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
    }

    printf("Encrypted text: %s\n", text);
    free(text);
}

void decrypt() {
    char *text = NULL;
    int key;

    printf("Enter the text to decrypt: ");
    readLine(&text);

    if (text == NULL || strlen(text) == 0) {
        printf("Error. Please enter the text. Returning to the menu.\n");
        return;
    }

    printf("Enter the decryption key (0-25): ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input. Returning to the menu.\n");
        free(text);
        clearInputBuffer();
        return;
    }

    if (key < 0 || key > 25) {
        printf("Error: Key must be between 0 and 25. Returning to the menu.\n");
        free(text);
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
    printf("Decrypted text: %s\n", text);
    free(text);
}

void caesaralgorithminfo() {
    printf("\nThe Caesar cipher is one of the simplest and most widely known encryption techniques. ");
    printf("It is a type of substitution cipher in which each letter in the plaintext is shifted a certain number of places down or up the alphabet.\n");
    printf("For example, with a shift of 3:\n");
    printf("  Plaintext:  Hello World\n");
    printf("  Ciphertext: Khoor Zruog\n");
    printf("To decrypt, shift in the opposite direction by the same number of places.\n\n");
}
