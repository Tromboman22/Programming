#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float get_grade(void);
int letters;
int words;
int spaces;
int dot;
int sentences;
int grade;

int main(void)
{
    string input = get_string("Text: ");
    // Make sure random stuff before the text won't count
    spaces = 1;
    dot = 1;

    for (int i = 0; i < strlen(input); i++)
    {
        // Letter counter and word reset
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            letters++;
            spaces = 0;
            dot = 0;
        }
        // Mark end of a word, count spaces
        if (input[i] == 32)
        {
            if (spaces == 0)
            {
                words++;
                spaces = 1;
            }
        }
        // Count periods and such as sentences
        if (input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
            if (dot == 0)
            {
                sentences++;
                words++;
                spaces++;
                dot++;
            }
        }
    }
    grade = get_grade();

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

float get_grade(void)
{
    // Compile results from main
    float compile;
    compile = ((5.88 * letters - 29.6 * sentences) / words - 15.8);
    return round(compile);
}
