/* Write a function called clockKeeper() that takes as its argument a dateAndTime structure as defined in this chapter.
 * The function should call the timeUpdate() function, and if the time reaches midnight, the function should call the
 * dateUpdate function to switch over to the next day. Have the function return the updated dateAndTime structure.
 */

#include <stdio.h>
#include <stdbool.h>

bool leapYearFlag;

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct date
{
    int days;
    int months;
    int years;
};

struct dateAndTime
{
    struct date sdate;
    struct time stime;
};


int main (void)
{
    struct time askForTime (void);
    struct date askForDate (void);
    struct dateAndTime clockKeeper (struct dateAndTime dT);

    char continuation;
    struct dateAndTime workingDateTime;


    do
    {
        continuation = 'y';
        if (continuation == 'y')
        {
            workingDateTime.stime = askForTime ();
            workingDateTime.sdate = askForDate ();
        };

        workingDateTime = clockKeeper (workingDateTime);

        printf ("Updated time is: %i:%i:%i on %i.%i.%i.\n\n",
                                    workingDateTime.stime.hours, workingDateTime.stime.minutes, workingDateTime.stime.seconds,
                                    workingDateTime.sdate.days, workingDateTime.sdate.months, workingDateTime.sdate.years);


        printf ("n =EXIT | Any other letter/Enter =CONTINUE:  ");
        scanf ("%c", &continuation);
    }
    while (continuation != 'n');

    return 0;
}


// Function asks user for a DATE (dd mm yyyy)
struct date askForDate (void)
{
    bool checkIfDateValid (struct date dateToCheck);

    struct date userDate = {.days = 0, .months = 0, .years = 0};

    do
    {
        printf ("Please provide a valid date (1 1 1901  to  31 12 9999: ");
        scanf ("%i%i%i", &userDate.days, &userDate.months, &userDate.years);
        while (getchar() != '\n');
    }
    while (!checkIfDateValid(userDate));

    return userDate;
}


// Fuction to check if user's date is a valid date
bool checkIfDateValid (struct date dateToCheck)
{
    bool leapYearCheck (int year);
    int monthLength (int month);

    if (dateToCheck.years < 1901 || dateToCheck.years > 9999)
    {
        return false;
    };

    if (dateToCheck.months < 1 || dateToCheck.months > 12)
    {
        return false;
    };

    if (dateToCheck.months == 2)
    {
        leapYearFlag = leapYearCheck (dateToCheck.years);
    }
    else
    {
        leapYearFlag = false;
    };

    if (dateToCheck.days < 1 || dateToCheck.days > monthLength (dateToCheck.months))
    {
        return false;
    };

    return true;
}


// Function to check for leap years
bool leapYearCheck (int year)
{
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
int monthLength (int month)
{
    const int daysInMonths [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int daysPerMonth;

    if (leapYearFlag)
    {
        daysPerMonth = daysInMonths [month - 1] + 1;
    }
    else
    {
        daysPerMonth = daysInMonths [month - 1];
    };

    return daysPerMonth;
};


// Function that asks time input from user
struct time askForTime (void)
{
    bool checkTimeValidity (struct time validTime);

    struct time usersTime;

    do
    {
        printf ("Please provide valid time (00 00 00  to  23 59 59): ");
        scanf ("%i %i %i", &usersTime.hours, &usersTime.minutes, &usersTime.seconds);
        while (getchar () != '\n');
    }
    while (!checkTimeValidity (usersTime));
    // KAD STAVIM OVU LINIJU UNUTAR "while" PROVJERE, ODBIJA VRIJEDNOST 23 50 50...DOK NPR. PRIHVAĆA 23 59 59 - IAKO SE VRIJEME UPIŠE U "usersTime" struct variable
    //"|| isdigit (usersTime.hours) || isdigit (usersTime.minutes) || isdigit (usersTime.seconds)"

    return usersTime;
}


// Function checks if user input is in valid time format
bool checkTimeValidity (struct time validTime)
{
    if (validTime.hours < 0 || validTime.hours > 23)
    {
        printf ("false hours \n");
        return false;
    };

    if (validTime.minutes < 0 || validTime.minutes > 59)
    {
        printf ("false minutes \n");
        return false;
    };

    if (validTime.seconds < 0 || validTime.seconds > 59)
    {
        printf ("false seconds \n");
        return false;
    };

    return true;
}



// Function that checks if updated time switched to next day
struct dateAndTime clockKeeper (struct dateAndTime dT)
{
    struct time timeUpdate (struct time now);
    struct date dateUpdate (struct date now);

    dT.stime = timeUpdate (dT.stime);

    if (dT.stime.hours == 0 && dT.stime.minutes == 0 && dT.stime.seconds == 0)
    {
        dT.sdate = dateUpdate (dT.sdate);
    };

    return dT;
}


// Function to update time by 1 second
struct time timeUpdate (struct time now)
{
    ++now.seconds;

    if (now.seconds == 60)      // next minute
    {
        now.seconds = 0;
        ++now.minutes;

        if (now.minutes == 60)    // next hour
        {
            now.minutes = 0;
            ++now.hours;

            if (now.hours == 24)     // midnight
            {
               now.hours = 0;
            };
        };
    };

    return now;
}


// Function that goes to next day if time crosses the Midnight
struct date dateUpdate (struct date now)
{
    bool leapYearCheck (int year);
    int monthLength (int month);

    ++now.days;

    if (now.days > monthLength (now.months))     // next month
    {
        now.days = 1;
        ++now.months;

        if (now.months > 12)     // next year
        {
            now.months = 1;
            ++now.years;
        };
    };

    return now;
}