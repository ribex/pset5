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

node *rootOfTrie = NULL;

// counter for dictionary words
int counter = 0;

// Returns true if word is in dictionary else false
// case insensitive
// strings with alphabetical characters and apostrophes
bool check(const char *word)
{
    node* checknav = rootOfTrie;

    int len = strlen(word);

    char wordCopy[len + 1];

 	for (int i = 0; i < len; i++)
 	{
 	    wordCopy[i] = tolower(word[i]);
 	}

    // for each letter in input word
    for (int j = 0; j < len; j++)
    {
        // go to corresponding element in children
        if (checknav->children[wordCopy[j] - 'a'] == NULL)
        {
            return false;
        }
    }

    // return true if word is in dictionary, return false otherwise
    if (checknav->is_word)
    {
        return true;
    }

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

    // create an array to hold the longest word
    char str[45];

    // create the root node
    rootOfTrie = malloc(sizeof(node));

    for (int i = 0; i < 27; i++)
    {
        rootOfTrie->children[i] = NULL;
    }
    rootOfTrie->is_word = false;

    // create a navigation pointer to remember the location of root as we iterate through the trie
    node *nav = rootOfTrie;

    // read dictionary file until the end is reached
    while (fgets (str, 45, file) != NULL )
    {
        counter++;

        for (int i = 0, len = strlen(str); i < len; i++)
        {
            if (isalpha(str[i]) != 0)
            {
                int position = str[i] - 'a';
                if (nav->children[position] == NULL)
                {
                    node *child = malloc(sizeof(node));
                    for (int j = 0; j < 27; j++)
                    {
                        child->children[j] = NULL;
                    }
                    child->is_word = false;
                    nav->children[position] = child;
                }
            }
            else // character is apostrophe
            {
                if (nav->children[26] == NULL)
                {
                    node *child = malloc(sizeof(node));
                    for (int j = 0; j < 27; j++)
                    {
                        child->children[j] = NULL;
                    }
                    child->is_word = false;
                    nav->children[26] = child;
                }
            }
        }

        // set boolean to true for end of word
        nav->is_word = true;
    }
    // print counter for testing
    // printf("counter: %i\n", counter);

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
    // for (int i = 0; i < 27; i++)
    // {
    //     unload(root->children[i]);
    // }
    // unload(root);
    return true;
}
