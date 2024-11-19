// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Create variable to keep track of number of words
int count = 0;
int num = 0;

// Hash table
node *table[N][N + 1][N + 1][N + 1];
int hsh = 0;
int hsh2 = 0;
int hsh3 = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    num = hash(word);
    // For loop to find the word int he dictionary
    for (node *tmp = table[num][hsh][hsh2][hsh3]; tmp != NULL; tmp = tmp->next)
    {
        // Use strcasecmp
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // hsh
    if (strlen(word) > 1)
    {
        if (0 <= toupper(word[1]) - 'A' && toupper(word[1]) - 'A' <= 25)
        {
            hsh = toupper(word[1]) - 'A';
        }
        else
        {
            hsh = 26;
        }
    }
    else
    {
        hsh = 26;
    }

    // hsh2
    if (strlen(word) > 2)
    {
        if (0 <= toupper(word[2]) - 'A' && toupper(word[2]) - 'A' <= 25)
        {
            hsh2 = toupper(word[2]) - 'A';
        }
        else
        {
            hsh2 = 26;
        }
    }
    else
    {
        hsh2 = 26;
    }

    // hsh3
    if (strlen(word) > 3)
    {
        if (0 <= toupper(word[3]) - 'A' && toupper(word[3]) - 'A' <= 25)
        {
            hsh3 = toupper(word[3]) - 'A';
        }
        else
        {
            hsh3 = 26;
        }
    }
    else
    {
        hsh3 = 26;
    }


    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open file for dictionary
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return false;
    }

    // Create tmp variable
    node *tmp = malloc(sizeof(node));

    if (tmp == NULL)
    {
        return false;
    }

    // Make tmp->next NULL
    tmp->next = NULL;

    // Copy the contents of the dictionary to the hash table, make a linked list
    while (fscanf(input, "%s", tmp->word) != EOF)
    {
        // Create new node
        node *list = malloc(sizeof(node));
        if (list == NULL)
        {
            return false;
        }
        list->next = NULL;

        // Hash word
        num = hash(tmp->word);

        // Copy tmp into 'list'
        strcpy(list->word, tmp->word);

        // Make linked list
        // New_list points to old_list
        list->next = table[num][hsh][hsh2][hsh3];
        // Table now points to new_list
        table[num][hsh][hsh2][hsh3] = list;


        // Increase total word count
        count++;
    }

    // Free tmp and close file
    free(tmp);
    fclose(input);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return global variable 'count'
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *buff;
    node *tmp;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (N + 1); j++)
        {
            for (int n = 0; n < (N + 1); n++)
            {
                for (int m = 0; m < (N + 1); m++)
                {
                    for (tmp = table[i][j][n][m]; tmp != NULL; tmp = buff)
                    {
                        // Move the buffer variable
                        buff = tmp->next;
                        // Free the buffer
                        free(tmp);
                    }
                }
            }
        }
    }
    return true;
}
