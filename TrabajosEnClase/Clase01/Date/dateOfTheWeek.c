#include <stdio.h>
#include <stdlib.h>
#include "dates.h"
#include "../bool.h"

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
    return centuryCode;
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
            for (i; (yearBase / 1000 != year / 1000) || (yearBase / 100 != year / 100); i++)
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
    // varDouble = year / 100.0     |-> (19.98)
    // varInt = year / 100.0        |-> (19)
    // varDouble -= year            |-> (0.98)
    // varDouble = varDouble * 100  |-> (98.0)
    // (int) varDouble              |-> 98 (int)
    float varDouble = year / 100.0;
    int varInt = year / 100.0;
    varDouble -= varInt;
    varDouble = varDouble * 100.0;
    return (int) varDouble;
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
