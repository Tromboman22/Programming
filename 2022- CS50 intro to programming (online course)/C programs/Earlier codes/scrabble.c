#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int n;

int total;

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int compute_score(string word)
{
    // Fix toupper func
    total = 0;
    char letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // Template for data trasformation function
    for (int i = 0; i < strlen(word); i++)
    {
        n = 0;
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 32;
        }
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            while (letter[n] != word[i])
            {
                n++;
            }
        }
        else
        {
            total -= 1;
        }
        total += POINTS[n];
    }
    return total;
}