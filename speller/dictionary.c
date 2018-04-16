// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

// Returns true if word is in dictionary else false
// case insensitive
// strings with alphabetical characters and apostrophes
bool check(const char *word)
{
    // TODO
    printf("*check %s*", word);
    // return true if word is in dictionary, return false otherwise
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // create a reference to the dictionary file
    FILE *file = fopen(dictionary, "r");

    // notify if the dictionary file cannot be opened
    if (file == NULL)
    {
        fprintf(stderr, "The file %s cannot be opened for reading.\n", dictionary);
        return 2;
    }
    // print statement for testing
    // else
    // {
    //     printf("Opened the dictionary.\n");
    // }

    // printf("the dictionary is %s xxx\n", dictionary);
    int counter = 0;

    // create an array to hold the longest word
    char str[45];

    // typedef struct node
    // {
    //     bool is_word;
    //     struct node *children[27];
    // }
    // node;

    // create the root node
    //node *root;


    // read dictionary file until the end is reached
    while (fgets (str, 45, file) != NULL )
    {
        counter++;
        for (int i = 0; i < strlen(str); i++)
        {
            printf("%c", str[i]);
        }


    }
    // print counter for testing
    printf("counter: %i\n", counter);


    // TODO


    char *word = "";
    printf("%s", word);

    // while (fscanf(file, "%s", word) != EOF)
    // {
    //     counter++;
    // }
    // printf("counter: %i\n", counter);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
