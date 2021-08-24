#include <stdio.h>
#include <stdlib.h>
#include "../bool.h"
#include "dates.h"
#include "isValidDate.c"
#include "distanceFromDays.c"
#include "dateOfTheWeek.c"



bool isValidDate(const Date date)
{
    if ((date.year > 1600) && (date.month >= 1) && (date.month <= 12) && (date.day >= 1) && (date.day <= monthDays(date)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Date addDate(Date date, const int days)
{
    if ((date.day + days) <= monthDays(date))
    {
        date.day += days;
    }
    else
    {
        date.day = monthDays(date) - (date.day + days);
        date.month += 1;
    }
    printf("addDate: %0.2d-%0.2d-%d \n", date.day, date.month, date.year);
    return date;
}

Date reduceDate(Date date, const int days)
{
    if ((date.day - days) >= 1)
    {
        date.day -= days;
    }
    else
    {
        date.month -= 1;
        date.day = monthDays(date) + (date.day - days);
    }
    printf("reduceDate: %0.2d-%0.2d-%d \n", date.day, date.month, date.year);
    return date;
}

int differenceToDates(const Date date1, const Date date2)
{
    if ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year))
        return 0;
    else
        return findDifference(date1, date2);
}

int dayOfTheWeek(const Date date)
{
    int centuryCode = getCenturyCode(date.year);
    printf("Century Code: %d\n",centuryCode);
    int monthCode = getMonthCode(date);
    printf("Month Code: %d\n",monthCode);
    int yearCode = getYearCode(date.year);
    printf("Year Code: %d\n",yearCode);
    int day = (date.day + monthCode + yearCode + (yearCode / 4) + centuryCode);
    return day % 7;
}
