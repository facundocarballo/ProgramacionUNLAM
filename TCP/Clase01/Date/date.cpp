#include "date.h"

// prototypes functions
bool isBisiesto(int y);
int monthDays(int month, int year);
int addDay(int d, int m, int y);
int reduceDay(int d, int m, int y);
int addMonth(int d, int m, int y);
int reduceMonth(int d, int m, int y);
int addYear(int d, int m, int y);
int reduceYear(int d, int m, int y);

// internal functions

bool isBisiesto(int y) {
    if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int monthDays(int month, int year) {
    static const int theMonthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isBisiesto(year))
    {
        return 29;
    }
    return theMonthDays[month - 1];
}

int addDay(int d, int m, int y) {
    if ((d + 1) <= monthDays(m,y)) {
        return d+1;
    }
    return 1;
}

int reduceDay(int d, int m, int y) {
    if ((d - 1 == 0) && (m - 1 == 0)) return 31;
    if (d - 1 == 0) return monthDays(m-1,y);
    return d-1;
}

int addMonth(int d, int m, int y) {
    if ((d + 1 > monthDays(m,d)) && (m + 1) > 12) return 1;
    if (d + 1 > monthDays(m,d)) return m+1; 
    return m;
}
int reduceMonth(int d, int m, int y) {
    if ((d - 1 == 0) && (m - 1 == 0)) return 12;
    if (d - m == 0) return m-1;
    return m;
}

int addYear(int d, int m, int y) {
    if ((d + 1 > monthDays(m,d)) && (m + 1 > 12)) return y+1;
    return y;
}
int reduceYear(int d, int m, int y) {
    if ((d - 1 == 0) && (m - 1 == 0)) return y-1;
    return y;
}
int getRelativeDay(int day, int month, int year) {
    int relativeDay = 1;
    int baseDay = 1;
    int auxDay = 1;
    int baseMonth = 1;
    int auxMonth = 1;
    int baseYear = 1600;
    int auxYear = 1600;

    if (year > baseYear) {
        while ((baseDay != day) && (baseMonth != month) && (baseYear != year))
        {
            relativeDay++;
            auxDay = addDay(baseDay, baseMonth, baseYear);
            auxMonth = addMonth(baseDay , baseMonth, baseYear);
            auxYear = addYear(baseDay, baseMonth, baseYear);
            baseDay = auxDay;
            baseMonth = auxMonth;
            baseYear = auxYear;

            
        }
    }else {
        while ((baseDay != day) && (baseMonth != month) && (baseYear != year))
        {
            relativeDay--;
            auxDay = reduceDay(baseDay, baseMonth, baseYear);
            auxMonth = reduceMonth(baseDay, baseMonth, baseYear);
            auxYear = reduceYear(baseDay, baseMonth, baseYear);
            baseDay = auxDay;
            baseMonth = auxMonth;
            baseYear = baseYear;
        }
    }
    
    return relativeDay;
}


Date::Date() {
    this->relativeDay = 1;
}

Date::Date(int day, int month, int year) {
    this->relativeDay = getRelativeDay(day, month, year);
}

Date::Date(int relativeDay) {
    this->relativeDay = relativeDay;
}

// public functions

Date Date::addDays(int days) const {
    return Date(this->relativeDay + days);
}

void Date::addDays(int days) {
    this->relativeDay += days;
}

// I have to do more functions