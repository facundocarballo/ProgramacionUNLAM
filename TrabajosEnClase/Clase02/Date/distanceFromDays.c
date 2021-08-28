#include <stdio.h>
#include <stdlib.h>
#include "dates.h"
#include "../bool.h"

Date addDay(Date date)
{
    // FIXED Bad practice, because we use nested if.

    if ((date.day + 1) <= monthDays(date)) {
        date.day++;
        return date;
    }

    date.day = 1;

    if ((date.month + 1) <= 12) {
        date.month++;
        return date;
    }else {
        date.month = 1;
        date.year++;
        return date;
    }
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

int findDifference(Date date1, Date date2)
{
    // FIXED Bad practice, because we use nested if.

    double date1Double = date1.year * 1000 + date1.month * 1 + date1.day * 0.01;
    double date2Double = date2.year * 1000 + date2.month * 1 + date2.day * 0.01;

    if (date1Double > date2Double) {
        return getDifference(date1, date2);
    }else {
        return getDifference(date2, date1);
    }
}