#include <stdio.h>
#include <stdlib.h>
#include "dates.h"
#include "../bool.h"

Date addDay(Date date)
{
    // Bad practice, because we use nested if. CHECK THE CODE OF Clase02
    
    if ((date.day + 1) > monthDays(date))
    {
        date.day = 1;
        if ((date.month + 1) > 12)
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
    // Bad practice, because we use nested if. CHECK THE CODE OF Clase02

    if (date1.year > date2.year)
        return getDifference(date1, date2);
    else if (date2.year > date1.year)
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