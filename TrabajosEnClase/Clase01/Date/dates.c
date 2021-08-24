#include <stdio.h>
#include <stdlib.h>
#include "dates.h"
#include "../const.h"

// Is a valid date?

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

// Add date

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

// Reduce date

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

// Difference between dates...

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

int differenceToDates(const Date date1, const Date date2)
{
    if ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year))
        return 0;
    else
        return findDifference(date1, date2);
}

// Day of the Week...

int changeCenturyCode(int centurys, bool greaterCentury)
{
    int centuryCode = 6;
    for (int i = 0; i < centurys; i++)
    {
        if (greaterCentury)
        {
            switch (centuryCode)
            {
            case 0:
                centuryCode = 6;
                break;
            case 2:
                centuryCode -= 2;
                break;
            case 4:
                centuryCode -= 2;
                break;
            case 6:
                centuryCode -= 2;
                break;
            default:
                printf("ERROR: Switch case different to (0, 2, 4, 6)\n");
                break;
            }
        }
        else
        {
            switch (centuryCode)
            {
            case 0:
                centuryCode += 2;
                break;
            case 2:
                centuryCode += 2;
                break;
            case 4:
                centuryCode += 2;
                break;
            case 6:
                centuryCode = 0;
                break;
            default:
                printf("Error: Switch case different to (0, 2, 4, 6)\n");
                break;
            }
        }
    }
}

bool isChangeCentury(const int year)
{
    if (2099 - year > 100 || 2099 - year < 0)
        return true;
    else
        return false;
}

int getCenturyCode(int year)
{
    int yearBase = 2000;
    int centuryCode = 6;
    bool sumar = false;
    if (isChangeCentury(year))
    {
        if (yearBase > year)
        {
            // Century before to century base
            int i = 0;
            for (i; (yearBase / 1000 == year / 1000) && (yearBase / 100 == year / 100); i++)
            {
                year += 100;
            }
            centuryCode = changeCenturyCode(i, false);
        }
        else
        {
            // Century after to century base
            int i = 0;
            for (i; (yearBase / 1000 == year / 1000) && (yearBase / 100 == year / 100); i++)
            {
                yearBase += 100;
            }
            centuryCode = changeCenturyCode(i, true);
        }
    }

    return centuryCode;
}

int getYearCode(int year)
{
    // Example: We received year = 1998
    // varDouble = year / 100.0 |-> (19.98)
    // varInt = year / 100.0    |-> (19)
    // varDouble -= year |-> (0.98)
    // int ret = varDouble * 100 |-> (98)
    double varDouble = year / 100.0;
    int varInt = year / 100.0;
    varDouble -= varInt;
    int ret = varDouble * 100;
    return ret;
}

int getMonthCode(Date date)
{
    switch (date.month)
    {
    case 1:
        if (isBisiesto(date))
            return 6;
        else
            return 0;
    case 2:
        if (isBisiesto(date))
            return 2;
        else
            return 3;
    case 3:
        return 3;
    case 4:
        return 6;
    case 5:
        return 1;
    case 6:
        return 4;
    case 7:
        return 6;
    case 8:
        return 2;
    case 9:
        return 5;
    case 10:
        return 0;
    case 11:
        return 3;
    case 12:
        return 5;
    default:
        printf("Error, Switch case unknown: %d\n)", date.month);
        return date.month;
    }
}

int dayOfTheWeek(const Date date)
{
    int centuryCode = getCenturyCode(date.year);
    int monthCode = getMonthCode(date);
    int yearCode = getYearCode(date.year);
    int day = (date.day + monthCode + yearCode + (yearCode / 4) + centuryCode);
    return day % 7;
}
