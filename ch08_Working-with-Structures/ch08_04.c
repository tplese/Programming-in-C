/* If you take the value of N as computed in exercise 2, subtract 621,049 from it, and then take that result modulo 7,
 * you get a number from 0 to 6 that represents the day of the week (Sunday through Saturday, respectively)
 * on which the particular day falls. For example, the value of N computed for August 8, 2004, is 732,239
 * as derived previously. 732,239 − 621,049 gives 111,190, and 111,190 % 7 gives 2, indicating that this date falls on a Tuesday.
 *
 * Use the functions developed in the previous exercise to develop a program that displays the day of the week
 * on which a particular date falls. Make certain that the program displays the day of the week in English (such as “Monday”).
 */

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int day;
    int month;
    int year;
};

int main (void)
{
    struct date askForDate (void);
    long int calculateN (struct date d);
    void printOutDayName (long int n, struct date d);

    struct date dateToCheck = askForDate ();
    long int N = calculateN (dateToCheck);

    printOutDayName(N, dateToCheck);

    return 0;
}


// Function asks user for a date (dd mm yyyy)
struct date askForDate (void)
{
    bool checkIfDateValid (struct date dateToCheck);

    struct date userDate = {.day = 0, .month = 0, .year = 0};

    do
    {
        printf ("Please provide a valid date (01.01.1901. to 31.12.9999.: ");
        scanf ("%i%i%i", &userDate.day, &userDate.month, &userDate.year);
        while (getchar() != '\n');
    }
    while (!checkIfDateValid(userDate));

    return userDate;
}


// Fuction to check if user's date is a valid date
bool checkIfDateValid (struct date dateToCheck)
{
    bool leapYearCheck (int year);
    int monthLength (int month, bool leap);

    bool leapYear;

    if (dateToCheck.year < 1901 || dateToCheck.year > 9999)
    {
        return false;
    };

    if (dateToCheck.month < 1 || dateToCheck.month > 12)
    {
        return false;
    };

    if (dateToCheck.month == 2)
    {
        leapYear = leapYearCheck (dateToCheck.year);
    }
    else
    {
        leapYear = false;
    };

    if (dateToCheck.day < 1 || dateToCheck.day > monthLength (dateToCheck.month, leapYear))
    {
        return false;
    };

    return true;
}


// Function to check for leap years
bool leapYearCheck (int year)
{
    bool leapYearFlag;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        leapYearFlag = true;   // It's a leap year
    }
    else
    {
        leapYearFlag = false;  // Not a leap year
    };

    return leapYearFlag;
}


// Function to check how long is a month
int monthLength (int month, bool leap)
{
    const int daysInMonths [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int daysPerMonth;

    if (leap)
    {
        daysPerMonth = daysInMonths [month - 1] + 1;
    }
    else
    {
        daysPerMonth = daysInMonths [month - 1];
    };

    return daysPerMonth;
};


// Function to calculate N for user-provided dates
long int calculateN (struct date d)
{
    int f (int year, int month);
    int g (int month);

    long int n;

    n = 1461 * f (d.year, d.month) / 4 + 153 * g (d.month) / 5  + d.day;

    return n;
}


int f (int year, int month)
{
    if (month <= 2)
    {
        return year - 1;
    }
    else
    {
        return year;
    };
}

int g (int month)
{
    if (month <= 2)
    {
        return month + 13;
    }
    else
    {
        return month + 1;
    };
}



void printOutDayName (long int n, struct date d)
{

    int day = (n - 621049) % 7;

    switch (day)
    {
        case 0:
            printf ("%i.%i.%i. is Sunday.\n", d.day, d.month, d.year);
            break;
        case 1:
            printf ("%i.%i.%i. is Monday.\n", d.day, d.month, d.year);
            break;
        case 2:
            printf ("%i.%i.%i. is Tuesday.\n", d.day, d.month, d.year);
            break;
        case 3:
            printf ("%i.%i.%i. is Wednesday.\n", d.day, d.month, d.year);
            break;
        case 4:
            printf ("%i.%i.%i. is Thursday.\n", d.day, d.month, d.year);
            break;
        case 5:
            printf ("%i.%i.%i. is Friday.\n", d.day, d.month, d.year);
            break;
        case 6:
            printf ("%i.%i.%i. is Saturday.\n", d.day, d.month, d.year);
            break;
        default:
            printf ("Error.\n");
    };
}