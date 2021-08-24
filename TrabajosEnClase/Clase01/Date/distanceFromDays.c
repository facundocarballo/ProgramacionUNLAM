#include <stdio.h>
#include <stdlib.h>
#include "dates.h"
#include "../bool.h"

Date addDay(Date date)
{
    int day = date.day;
    // We can't use date.day in the if statement because in the question we added by one day
    // So inside of the function, the day are affected.
    if (day++ > monthDays(date))
    {
        date.day = 1;
        if (date.month++ > 12)
        {
            date.month = 1;
            date.year++;
        }
        else
        {
            date.month++;
        }
    }
    else
    {
        date.day++;
    }
    return date;
}

int getDifference(const Date greaterDate, Date lessDate)
{
    int difference = 0;
    while ((greaterDate.year != lessDate.year) || (greaterDate.month != lessDate.month) || (greaterDate.day != lessDate.day))
    {
        difference++;
        lessDate = addDay(lessDate);
    }
    return difference;
}

int findDifference(const Date date1, const Date date2)
{
    if (date1.year > date2.year)
        return getDifference(date1, date2);
    else if (date2.year < date1.year)
        return getDifference(date2, date1);
    else
    {
        if (date1.month > date2.month)
            return getDifference(date1, date2);
        else if (date2.month > date1.month)
            return getDifference(date2, date1);
        else
        {
            if (date1.day > date2.day)
                return getDifference(date1, date2);
            else
                return getDifference(date2, date1);
        }
    }
}