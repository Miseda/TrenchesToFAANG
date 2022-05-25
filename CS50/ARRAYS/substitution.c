#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Check if theres only one line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    int count = 0;
    string key = argv[1];


    for (int i = 0 ; i < strlen(key); i++)
    {
        count = count  + 1; //Count characters

        for (int j = i + 1 ; j < strlen(key) ; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Your text contains similar characters.\n");
                return 1;
            }
        }
    }

    for (int i = 0 ; i < strlen(key) ; i++)
    {
        if (!isalpha(key[i])) //Check if characters are alphabetical
        {
            printf("Your text contain a non-alphabetical character.\n");
            return 1;
        }
    }


    if (count != 26) //Check if the argument has 26 characters
    {
        printf("Key must contains 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0 ; i < strlen(plaintext) ; i++)
    {
        if (isupper(plaintext[i])) //To check if its capital letters
        {
            int before = (int) plaintext[i] - 65;  //To get the index of the character in the plaintext
            char cipher = key [before]; //To substitute the character
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(cipher));
            }

        }
        else if (islower(plaintext[i])) //To check if its not capital letters
        {
            int before1 = (int) plaintext[i] - 97;
            char cipher1 = key [before1];
            if (islower(plaintext[i]))
            {
                printf("%c", tolower(cipher1));
            }
        }
        else if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

}
