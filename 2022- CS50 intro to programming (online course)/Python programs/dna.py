import csv
import sys
# Compare databases and dna sequences
# Look for STRs
# Print match if found


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database/file sequence/file")

    # Create variable for database and x
    database = {}
    # TODO: Read database file into a variable
    # Open database file
    with open(sys.argv[1], "r") as f:
        # Copy database in temp var
        tmp = csv.DictReader(f)
        subseq = {}

        # Make loop to write dict
        for row in tmp:
            folder = {}
            # Copy tmp in database var as dict
            # TODO find a way to simply copy the large csv as a dict
            for i in row:
                if i != 'name':
                    folder[i] = int(row[i])
            database[row['name']] = folder

        for row in database:
            for i in database[row]:
                if i != 'name':
                    subseq[i] = 0
            break

    # Initialize dna as an empty string
    dna = ""
    # TODO: Read DNA sequence file into a variable
    # Open sequences file
    with open(sys.argv[2], "r") as g:
        # Print string(g) into dna
        dna += g.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Read list and look for STRs
    # Make loop to check for every STR
    for i in subseq:
        subseq[i] = longest_match(dna, i)

    # TODO: Check database for matching profiles
    # Compare database[i][j] and subseq[j]
    clear = 0
    for i in database:
        for j in database[i]:
            if database[i][j] != subseq[j]:
                clear = 1
        if clear == 0:
            print(i)
            return
        clear = 0
    print("No Match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)
    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
