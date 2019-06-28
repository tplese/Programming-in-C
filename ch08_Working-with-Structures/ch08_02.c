/* In certain applications, particularly in the financial area, it is often necessary to calculate the number
 * of elapsed days between two dates. For example, the number of days between July 2, 2015, and July 16, 2015,
 * is obviously 14. But how many days are there between August 8, 2014, and February 22, 2015?
 * This calculation requires a bit more thought. Luckily, a formula can be used to calculate the
 * number of days between two dates.
 * This is affected by computing the value of N for each of the two dates and then taking the difference,
 * where N is calculated as follows:
 *
 * N = 1461 x f(year, month) / 4 + 153 x g(month) / 5  + day
 *
 * where:
 * f(year, month)   =   year - 1        / if  month <= 2
 *                      year            / otherwise
 *
 * g(month)     =   month + 13      / if month <= 2
 *                  month + 1       / otherwise
 *
 * As an example of applying the formula, to calculate the number of days
 * between August 8, 2004, and February 22, 2005, you can calculate the values of N1 and N2
 * by substituting the appropriate values into the preceding formula as shown:
 *
 * N1   = 1461 x f(2004, 8) / 4  +  153 x g(8) / 5  +  3
 *      = (1461 x 2004) / 4  +  (153 x 9) / 5  +  3
 *      = 2,927,844 / 4  +  1,377 / 5  +  3
 *      = 731,961 + 275 + 3
 *      = 732,239
 *
 * N2   = 1461 x f(2005, 2) / 4  +  153 x g(2) / 5  +  21
 *      = (1461 x 2004) / 4  +  (153 x 15) / 5  +  21
 *      = 2,927,844 / 4  +  2295 / 5  +  21
 *      = 731,961 + 459 + 21
 *      = 732,441
 *
 * Number of elapsed days
 *      = N2 - N1
 *      = 732,441 - 732,239
 *      = 202
 *
 * So the number of days between the two dates is shown to be 202. The preceding formula is applicable for any dates
 * after March 1, 1900 (1 must be added to N for dates from March 1, 1800, to February 28, 1900,
 * and 2 must be added for dates between March 1, 1700, and February 28, 1800).
 *
 * Write a program that permits the user to type in two dates and then calculates the number of elapsed days
 * between the two dates.
 * Try to structure the program logically into separate functions.
 * For example, you should have a function that accepts as an argument a date structure and
 * returns the value of N computed as shown previously. This function can then be called twice, once for each date,
 * and the difference taken to determine the number of elapsed days.
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
    struct date askForDate (int dateNumber);
    long int calculateN (struct date d);

    struct date date1, date2;
    long int n1, n2, differenceInDays;

    date1 = askForDate (1);
    n1 = calculateN (date1);

    date2 = askForDate (2);
    n2 = calculateN (date2);

    if (n1 > n2)
    {
        differenceInDays = n1 - n2;
    }
    else if (n1 < n2)
    {
        differenceInDays = n2 - n1;
    }
    else
    {
        differenceInDays = 0;
    };

    printf ("%li days between dates %i.%i.%i. and %i.%i.%i.\n", differenceInDays, date1.day, date1.month, date1.year,
                                                                                    date2.day, date2.month, date2.year);
    return 0;
}


// Function asks user for a date (dd mm yyyy)
struct date askForDate (int dateNumber)
{
    bool checkIfDateValid (struct date dateToCheck);

    struct date userDate = {.day = 0, .month = 0, .year = 0};

    do
    {
        printf ("Please provide valid date %i (01.01.1901. to 31.12.9999.: ", dateNumber);
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