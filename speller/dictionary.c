// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

struct node *createNode(void)
{
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode)
    {
        for (int i = 0; i < 27; i++)
        {
            newNode->children[i] = NULL;
        }
        newNode->is_word = false;
    }
    return newNode;
}

node *rootOfTrie = NULL;

// counter for dictionary words
int counter = 0;

// Returns true if word is in dictionary else false
// case insensitive
// strings with alphabetical characters and apostrophes
bool check(const char *word)
{
    node *checknav = rootOfTrie;
    checknav->is_word = false;
    // for each character in input word
    for (int j = 0, len = strlen(word); j < len; j++)
    {
        int position;

        if (word[j] == '\'')
        {
            printf("CHECK APOSTROPHE");
            position = 26;
        }
        if (isalpha(word[j]))
        {
            position = tolower(word[j]) - 'a';
        }

        if (!checknav->children[position])
        {
            // printf("letter but false: %c\n", word[j]);
            return false;
        }
        else
        {
            // printf("check letter: %c\n", word[j]);
            checknav = checknav->children[position];
        }
    }

    // return true if word is in dictionary, return false otherwise
    // printf("word in dictionary ");
    // return (checknav != NULL && checknav->is_word);
    return true;
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

    // create an array to hold the longest word of 45 characters
    char str[47];

    // initialize the root node
    rootOfTrie = malloc(sizeof(node));
    for (int i = 0; i < 27; i++)
    {
        rootOfTrie->children[i] = NULL;
    }
    rootOfTrie->is_word = false;

    // create a navigation pointer to remember the location of root as we iterate through the trie
    node *nav = malloc(sizeof(node));

    // read dictionary file until the end is reached
    while (fgets (str, 47, file) != NULL )
    {
        nav = rootOfTrie;
        // printf("loading ");
        for (int i = 0, len = strlen(str); i < len; i++)
        {
            int position;
            if (isalpha(str[i]))
            {
                // printf("%c ", str[i]);
                position = str[i] - 'a';
            }
            if (str[i] == '\'')
            {
                printf("apostrophe ");
                position = 26;
            }

            if (!nav->children[position])
            {
                nav->children[position] = createNode();
            }
            nav = nav->children[position];

        }
        counter++;

        // set boolean to true for end of word
        nav->is_word = true;
        // printf("end of word\n");
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // // TODO


    for (int i = 0; i < 27; i++)
    {
        free(rootOfTrie->children[i]);
    }
    free(rootOfTrie);
    return true;
}
