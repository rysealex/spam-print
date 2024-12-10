#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ASCII_A 97  // ascii value of 'a'
#define ASCII_Z 122 // ascii value of 'z'

/*
    this program will attempt to match the user input word repeatedly until successful
    displays each attempt to create a fun output
    Alex Ryse 12/9/2024
*/

int main(void)
{
    // declare and initialize variables here
    char *word = NULL, *wordCheck = NULL, *result = NULL;
    size_t len = 0, lenCheck = 0, buffer = 100;
    int ch;

    printf("Enter a word: "); // prompt the user

    word = malloc(buffer * sizeof(char)); // allocate memory for user input word

    if (word == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    } // error checking here

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        word[len++] = (char)ch;
    } // adding elements to word and finding length of word

    word[len] = '\0'; // null terminate the word

    if (len == 0)
    {
        printf("No word entered\n");
        return 1;
    } // error checking here

    printf("You entered: %s\n", word); // display to the user

    printf("Enter the word again: "); // prompt the user again

    wordCheck = malloc(buffer * sizeof(char)); // allocate memory for user input word again

    if (wordCheck == NULL)
    {
        printf("Memory allocation failed\n");
        free(word);
        return 1;
    } // error checking here

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        wordCheck[lenCheck++] = (char)ch;
    } // adding elements to wordCheck and finding length of wordCheck

    wordCheck[lenCheck] = '\0'; // null terminate the wordCheck

    if (len != lenCheck || strcmp(word, wordCheck) != 0)
    {
        printf("Incorrect word input\n");
        free(word);
        free(wordCheck);
        return 1;
    } // error checking here

    result = malloc((len + 1) * sizeof(char)); // allocate memory for result

    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        free(word);
        free(wordCheck);
        return 1;
    } // error checking here

    for (int i = 0; i < len; i++)
    {
        while (1)
        {
            char letter = rand() % (ASCII_Z - ASCII_A + 1) + ASCII_A; // random char in the alphabet
            result[i] = letter;
            printf("%s\n", result);
            if (letter == word[i])
            {
                result[i] = letter;
                break;
            } // if matches
            usleep(10000);
        } // continue until current element of word is found
    } // iterate for each element in word

    result[len] = '\0'; // null terminate the result

    // de-allocate here
    free(word);
    free(result);
    return 0;
}