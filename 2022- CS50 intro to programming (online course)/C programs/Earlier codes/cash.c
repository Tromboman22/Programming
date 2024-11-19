#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
    printf("%i quarters, %i dimes, %i nickels and %i pennies\n", quarters, dimes, nickels, pennies);
}

int get_cents(void)
{
    // TODO
    int cents = -1;
    while (cents < 0)
    {
        cents = get_int("How many cents: ");
    }
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int q = 0;
    int i = cents;
    int n = 25;
    while (n <= i)
    {
        q++;
        i -= 25;
    }
    return q;
}

int calculate_dimes(int cents)
{
    // TODO
    int q = 0;
    int i = cents;
    int n = 10;
    while (n <= i)
    {
        q++;
        i -= 10;
    }
    return q;
}

int calculate_nickels(int cents)
{
    // TODO
    int q = 0;
    int i = cents;
    int n = 5;
    while (n <= i)
    {
        q++;
        i -= 5;
    }
    return q;
}

int calculate_pennies(int cents)
{
    // TODO
    int q = 0;
    int i = cents;
    int n = 1;
    while (n <= i)
    {
        q++;
        i -= 1;
    }
    return q;
}
