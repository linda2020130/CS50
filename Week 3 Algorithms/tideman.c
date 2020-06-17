/*
Implement a program that runs a Tideman election.
The Tideman voting method consists of three parts:
1. Tally: Once all of the voters have indicated all of their preferences, determine, for each pair of candidates, 
who the preferred candidate is and by what margin they are preferred.
2. Sort: Sort the pairs of candidates in decreasing order of strength of victory, 
where strength of victory is defined to be the number of voters who prefer the preferred candidate.
3. Lock: Starting with the strongest pair, go through the pairs of candidates in order and 
“lock in” each pair to the candidate graph, so long as locking in that pair does not create a cycle in the graph.
Once the graph is complete, the source of the graph (the one with no edges pointing towards it) is the winner!
*/

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
bool check_cycle(int loser, int winner);

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
    // Check if name is on the candidate list
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
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
    // preference[i][j]++ if voter prefer candidate i over candidate j
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Update pair_count once found one candidate is preferred to the other
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
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
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Change pair index if preferences is higher
    int winner_large;
    int loser_large;
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                winner_large = pairs[j].winner;
                loser_large = pairs[j].loser;
                pairs[j].winner = pairs[i].winner;
                pairs[j].loser = pairs[i].loser;
                pairs[i].winner = winner_large;
                pairs[i].loser = loser_large;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Check pairs from top to bottom
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        // Check if the new edge will create a cycle
        if (!check_cycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int total;
    for (int i = 0; i < candidate_count; i++)
    {
        total = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            total += locked[j][i];
        }
        // Check if no edge points to candidate i
        if (total == 0)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}

// Check if the candidate graph exists a cycle
bool check_cycle(int loser, int winner)
{
    // Check if the loser is a winner in other pair
    if (loser == winner)
    {
        return false;   // Cycle exists
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        // Check for "any" loser to see if any create a cycle
        if (locked[loser][i])
        {
            if (!check_cycle(i, winner))
            {
                return false;   // Cycle exists (at least one cycle)
            }
        }
    }
    // The loser is not a winner in other pair
    return true;   // Cycle does not exist
}
