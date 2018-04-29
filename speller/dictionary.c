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

node *createNode(void)
{
    node *newNode = NULL;
    newNode = malloc(sizeof(node));

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
node *nav = NULL;

// counter for dictionary words
int counter = 0;

// Returns true if word is in dictionary else false
// case insensitive
// strings with alphabetical characters and apostrophes
bool check(const char *word)
{
    nav = rootOfTrie;
    // for each character in input word
    for (int j = 0, len = strlen(word); j < len; j++)
    {
        int position;

        if (word[j] == '\'')
        {
            position = 26;
        }
        if (isalpha(word[j]))
        {
            position = tolower(word[j]) - 'a';
        }

        if (!nav->children[position])
        {
            return false;
        }
        else
        {
            nav = nav->children[position];
        }
    }

    // return true if word is in dictionary, return false otherwise
    return (nav->is_word);
}

// Loads dictionary into memory using a trie, returning true if successful else false
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

    // create an array to hold the longest word of 45 characters
    char str[46];

    // initialize the root node
    rootOfTrie = malloc(sizeof(node));
    for (int i = 0; i < 27; i++)
    {
        rootOfTrie->children[i] = NULL;
    }
    rootOfTrie->is_word = false;

    // create a navigation pointer to remember the location of root as we iterate through the trie
    nav = rootOfTrie;

    // read dictionary file until the end is reached
    while (fgets (str, 47, file) != NULL )
    {
        nav = rootOfTrie;

        int i = 0;
        while (str[i] != 10)
        {
            int position;
            if (isalpha(str[i]))
            {
                position = str[i] - 'a';
            }
            if (str[i] == '\'')
            {
                position = 26;
            }

            if (!nav->children[position])
            {
                nav->children[position] = createNode();
            }
            nav = nav->children[position];
            i++;
        }
        counter++;

        // set boolean to true for end of word
        nav->is_word = true;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

void freeNode(node* navigator)
{
    for (int i = 0; i < 27; i++)
    {
        if (navigator->children[i])
        {
            freeNode(navigator->children[i]);
        }
    }

    // base case
    free(navigator);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    nav = rootOfTrie;

    if(rootOfTrie != NULL)
    {
        nav = rootOfTrie;
        freeNode(nav);
        return true;
    }
    else
    {
        return false;
    }
}
