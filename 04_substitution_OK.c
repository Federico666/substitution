#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int arr_k[26] = {0};
    int ci = 0;

    // If there are only 2 arguments and argv[1] lenght is equal to 26, continue
    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        // Itirate the 2nd element of the command line array,the array of char argv[1]
        for (int i = 0 ; i < strlen(argv[1]) ; i++)
        {
            // If the first and the last ocurrence of the character in the string are different, it is not unique
            if (strchr(argv[1], argv[1][i]) != strrchr(argv[1], argv[1][i]))
            {
                printf("Invalid Key: unique characters only\n");
                return 1;
            }
            // Check if each element of array if an word from ASCII table
            if ((argv[1][i] < 65 || argv[1][i] > 90) && (argv[1][i] < 97 || argv[1][i] > 122))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            // Else, if the element is a lowercase letter, substract 32 to convert in uppercase
            else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                argv[1][i] -= 32;
            }
            // Copy the command line array into my own array
            arr_k[i] = argv[1][i];
        }

    }
    // Else, show error message
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get the plaintext from user and store it as ptext string
    string ptext = get_string("plaintext: ");

    // Itirate ptext string
    for (int i = 0 ; i < strlen(ptext) ; i++)
    {
        // If ptext[i] is Uppercase (between 65 & 90), use array_uc to compare
        if (ptext[i] >= 'A' && ptext[i] <= 'Z')
        {
            ci = (ptext[i] - 65) % 26;
            ptext[i] = arr_k[ci];
        }
        // Else if plainttext[i] is Lowercase (between 97 & 122), use array_lc to compare
        else if (ptext[i] >= 'a' && ptext[i] <= 'z')
        {
            ci = (ptext[i] - 97) % 26;
            // In case of lowercase plaintext letter
            ptext[i] = (arr_k[ci] + 32);
        }
    }

    printf("ciphertext: %s\n", ptext);

    return 0;
}