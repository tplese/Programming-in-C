/* Write a function elapsed_time that takes as its arguments two time structures and returns a time structure
 * that represents the elapsed time (in hours, minutes, and seconds) between the two times. So the call
 *
 * elapsed_time (time1, time2)
 *
 * where time1 represents 3:45:15 and time2 represents 9:44:03, should return a time structure that represents
 * 5 hours, 58 minutes, and 48 seconds. Be careful with times that cross midnight.
 */

#include <stdio.h>
#include <stdbool.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};


int main (void)
{
    struct time askForTime (int _1or2);
    struct time elapsedTime (struct time t1, struct time t2);

    struct time time1, time2, timeDifference;

    time1 = askForTime (1);
    time2 = askForTime (2);

    timeDifference = elapsedTime (time1, time2);

    printf ("Difference between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i is %i hours, %i minutes and %i seconds.\n",
                        time1.hours, time1.minutes, time1.seconds, time2.hours, time2.minutes, time2.seconds,
                        timeDifference.hours, timeDifference.minutes, timeDifference.seconds);

    return 0;
}


// Function that asks time input from user
struct time askForTime (int _1or2)
{
    bool checkTimeValidity (struct time validTime);

    struct time usersTime;

    do
    {
        printf ("Please provide valid time no. %i (00 00 00 to 23 59 59): ", _1or2);
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


// Function to calculate time elapsed between 2 time points
struct time elapsedTime (struct time t1, struct time t2)
{
    long int secondsBackToMidnight (struct time t);
    long int secondsForwardToMidnight (struct time t);
    struct time convertSecondsToTime (long int totalSeconds);

    long int t1_Sec, t2_Sec;
    long int diffInSec = 0;

    t1_Sec = secondsBackToMidnight (t1);
    t2_Sec = secondsBackToMidnight (t2);

    if (t1_Sec > t2_Sec)
    {
        diffInSec = secondsForwardToMidnight (t1) + t2_Sec;
    }
    else if (t2_Sec > t1_Sec)
    {
        diffInSec = t2_Sec - t1_Sec;
    }
    else
    {
        printf ("Something went wrong\n");
    };

    return convertSecondsToTime (diffInSec);
}


// Function to calculate seconds from given time backward to Midnight
long int secondsBackToMidnight (struct time t)
{
    return (t.hours * 60 * 60) + (t.minutes * 60) + t.seconds;
}


// Function to calculate seconds from given time forward to Midnight
long int secondsForwardToMidnight (struct time t)
{
    return ((23 - t.hours) * 60 * 60) + ((59 - t.minutes) * 60) + (59 - t.seconds) + 1; // 23:59:59 + 1s = 24:0:0
}


// Function to get hours:minutes:seconds from total seconds
struct time convertSecondsToTime (long int totalSeconds)
{
    struct time timeHolder;

    timeHolder.hours = (totalSeconds / 3600) % 24;
    totalSeconds %= 3600;
    timeHolder.minutes = totalSeconds / 60;
    totalSeconds %= 60;
    timeHolder.seconds = totalSeconds;

    return timeHolder;
}