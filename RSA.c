#include <stdio.h>
#include <string.h>

// Function to calculate modular exponentiation (base^exponent % modulus)
unsigned long long mod_pow(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

// Function to perform RSA encryption
void rsa_encrypt(char *message, unsigned long long e, unsigned long long n) {
    printf("Encrypted Message: ");
    for (int i = 0; i < strlen(message); ++i) {
        unsigned long long encrypted_char = mod_pow(message[i], e, n);
        printf("%llu ", encrypted_char);
    }
    printf("\n");
}

// Function to perform RSA decryption
void rsa_decrypt(unsigned long long *encrypted_message, unsigned long long d, unsigned long long n, int len) {
    printf("Decrypted Message: ");
    for (int i = 0; i < len; ++i) {
        unsigned long long decrypted_char = mod_pow(encrypted_message[i], d, n);
        printf("%c", (char) decrypted_char);
    }
    printf("\n");
}

int main() {
    unsigned long long p = 61; // prime number
    unsigned long long q = 53; // prime number
    unsigned long long n = p * q; // modulus
    unsigned long long phi = (p - 1) * (q - 1); // Euler's totient function
    unsigned long long e = 17; // public exponent
    unsigned long long d = 413; // private exponent (calculated using Extended Euclidean Algorithm)

    int choice;
    printf("Choose an option:\n");
    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char message[100]; // original message
        getchar(); // Clear the newline character from the previous input

        // Input message from user
        printf("Enter the message to be encrypted: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove the newline character

        // Encryption
        printf("Original Message: %s\n", message);
        rsa_encrypt(message, e, n);
    } else if (choice == 2) {
        unsigned long long encrypted_message[100]; // encrypted message
        int len = 0;

        // Input encrypted message from user
        printf("Enter the number of encrypted values: ");
        scanf("%d", &len);
        printf("Enter the encrypted values separated by spaces: ");
        for (int i = 0; i < len; ++i) {
            scanf("%llu", &encrypted_message[i]);
        }

        // Decryption
        rsa_decrypt(encrypted_message, d, n, len);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}




