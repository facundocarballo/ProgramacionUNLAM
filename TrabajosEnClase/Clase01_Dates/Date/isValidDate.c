#include <stdio.h>
#include <stdlib.h>
#include "dates.h"
#include "../bool.h"


bool isBisiesto(const Date date)
{
    if ((date.year % 4 == 0) && (date.year % 100 != 0) || (date.year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int monthDays(const Date date)
{
    static const int theMonthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.month == 2 && isBisiesto(date))
    {
        return 29;
    }
    return theMonthDays[date.month - 1];
}