#include <stdio.h>
#include <stdlib.h>
#include "Date/dates.c"

int main()
{
    Date date = {10, 8, 2000};
    printf("Date: %0.2d-%0.2d-%d\n", date.day, date.month, date.year);
    if (isValidDate(date) == true)
    {
        printf("The date is valid.\n");
        Date newAddDate = addDate(date, 5);             
        Date newReduceDate = reduceDate(newAddDate, 3);
        int differenceBTWdates = differenceToDates(date, newAddDate);
        int dayWeek = dayOfTheWeek(date);
        printf("Difference in days between two dates: %d\n", differenceBTWdates);
        printf("Day of the week: %d\n", dayWeek);
    }
    else
    {
        printf("The date isn't valid :(\n");
    }
    return 0;
}