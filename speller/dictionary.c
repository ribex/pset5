// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
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
    // strategy: use a trie

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
    // temporary counter for dictionary words
    int counter = 0;

    // create an array to hold the longest word
    char str[45];

    typedef struct node
    {
        bool is_word;
        struct node *children[27];
    }
    node;

    // create the root node
    struct node *root = malloc(sizeof(node));

    // create a navigation pointer to remember the location of root as we iterate through the trie
    // struct node *nav = root;

    // read dictionary file until the end is reached
    while (fgets (str, 45, file) != NULL )
    {
        counter++;

        for (int i = 0, len = strlen(str); i < len; i++)
        {
            if (isalpha(str[i]) != 0)
            {
                if (root->children[str[i] - 'a'] == NULL)
                {
                    struct node *child = malloc(sizeof(node));
                    root->children[str[i] - 'a'] = child;

                }

            }
            else // character is apostrophe
            {
                if (root->children[26] == NULL)
                {
                    struct node *child = malloc(sizeof(node));
                    root->children[26] = child;
                    // child->children[26];
                }
            }
        }

        // set boolean to true for end of word

    }
    // print counter for testing
    printf("counter: %i\n", counter);

    fclose(file);
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
