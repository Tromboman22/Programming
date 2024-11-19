#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    // Find a way to set rank int value to actual rank
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO

    // Ranks[] has already been compiled
    // There is a Preferences[][] array to record preferences
    // Convert ranks array into permanent preference counts
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (j > i)
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i < j)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
                else if (preferences[i][j] < preferences[j][i])
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count++;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int pivot = 0;
    int counter = 1;
    int swap = 1;
    while (swap > 0)
    {
        swap = 0;
        for (int i = 0; i < (pair_count - counter); i++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[i + 1].winner][pairs[i + 1].loser])
            {

                pivot = pairs[i].winner;
                pairs[i].winner = pairs[i + 1].winner;
                pairs[i + 1].winner = pivot;
                pivot = pairs[i].loser;
                pairs[i].loser = pairs[i + 1].loser;
                pairs[i + 1].loser = pivot;
                swap++;
            }
        }
        counter++;
    }
    return;
}
int first;
bool mark[MAX][MAX];
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int k = 0; k < candidate_count; k++)
    {
        for (int l = 0; l < candidate_count; l++)
        {
            mark[l][k] = false;
        }
    }
    first = pairs[0].winner;

    // Locking involves drawing an arrow from the winner of the pair to the loser of the pair
    // Record locks
    for (int i = 0; i < pair_count; i++)
    {
        // Send marks along with the lock
        if (mark[pairs[i].winner][pairs[i].loser] == false)
        {
            mark[pairs[i].loser][pairs[i].winner] = true;

            for (int j = 0; j < candidate_count; j++)
            {
                if (mark[pairs[i].winner][j] == true)
                {
                    mark[pairs[i].loser][j] = true;
                }
            }
            // The winner locks the loser
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    // Attempt to print winner despite ties

}

// Print the winner of the election
void print_winner(void)
{
    // TODO

    // The winner is the candidate who hasn't been locked out by anyone
    bool check[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        check[i] = false;
    }

    for (int m = 0; m < candidate_count; m++)
    {
        for (int n = 0; n < candidate_count; n++)
        {
            if (locked[m][n] == true)
            {
                check[n] = true;
            }
        }
    }
    for (int z = 0; z < candidate_count; z++)
    {
        if (check[z] == false)
        {
            printf("%s\n", candidates[z]);
            return;
        }
    }
}
