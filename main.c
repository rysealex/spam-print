#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define ASCII_A 97   // ascii value of 'a'
#define ASCII_Z 122  // ascii value of 'z'
#define COLOR_MIN 31 // min color value
#define COLOR_MAX 37 // max color value

/*
    this program will attempt to match the user input word repeatedly until successful
    displays each attempt to create a fun output
    Alex Ryse 12/9/2024
*/

int main(void)
{
    // declare and initialize variables here
    char *word = NULL, *wordCheck = NULL, *result = NULL;
    size_t len = 0, lenCheck = 0, buffer = 100, attempts = 0;
    int ch;
    clock_t start, end;
    double time_taken;

    printf("Enter a word: "); // prompt the user

    word = malloc(buffer * sizeof(char)); // allocate memory for user input word

    if (word == NULL)
    {
        printf("\033[31mMemory allocation failed\033[0m\n"); // red text here
        return 1;
    } // error checking here

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (!isalpha(ch))
        {
            printf("\033[31mEnter only letters\033[0m\n"); // red text here
            return 1;
        } // error checking here
        word[len++] = (char)ch;
    } // adding elements to word and finding length of word

    word[len] = '\0'; // null terminate the word

    if (len == 0)
    {
        printf("\033[31mNo word entered\033[0m\n"); // red text here
        return 1;
    } // error checking here

    printf("You entered: %s\n", word); // display to the user

    printf("Enter the word again: "); // prompt the user again

    wordCheck = malloc(buffer * sizeof(char)); // allocate memory for user input word again

    if (wordCheck == NULL)
    {
        printf("\033[31mMemory allocation failed\033[0m\n"); // red text here
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
        printf("\033[31mIncorrect word input\033[0m\n"); // red text here
        free(word);
        free(wordCheck);
        return 1;
    } // error checking here

    result = malloc((len + 1) * sizeof(char)); // allocate memory for result

    if (result == NULL)
    {
        printf("\033[31mMemory allocation failed\033[0m\n"); // red text here
        free(word);
        free(wordCheck);
        return 1;
    } // error checking here

    start = clock(); // start he clock

    for (int i = 0; i < len; i++)
    {
        while (1)
        {
            attempts++;
            char randLetter = rand() % (ASCII_Z - ASCII_A + 1) + ASCII_A; // random char in the alphabet
            result[i] = randLetter;
            int randColor = rand() % (COLOR_MAX - COLOR_MIN + 1) + COLOR_MIN; // random color value
            printf("\033[%dm%s\033[0m\n", randColor, result);
            if (randLetter == word[i])
            {
                result[i] = randLetter;
                break;
            } // if matches
            usleep(10000);
        } // continue until current element of word is found
    } // iterate for each element in word

    end = clock(); // stop the clock

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // calculate time here

    printf("\033[32mTook %ld attempts in %f seconds\033[0m\n", attempts, time_taken); // display to the user

    result[len] = '\0'; // null terminate the result

    // de-allocate here
    free(word);
    free(result);
    return 0;
}