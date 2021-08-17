#include <stdio.h>
int IsLeapYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
int date_verification(int dd, int mm, int yy)
{
    // if (yy > 2003 || yy < 1900)
    //     return 0;
    if (mm < 1 || mm > 12)
        return 0;
    if (dd < 1 || dd > 31)
        return 0;

    if (mm == 2)
    {
        if (IsLeapYear(yy))
            return (dd <= 29);
        else
            return (dd <= 28);
    }
    //handle months which has only 30 days
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        return (dd <= 30);
    return 1;
}
int main()
{
    int dd, mm, yy;
    scanf("%d %d %d", &dd, &mm, &yy);
    printf("%d", date_verification(dd, mm, yy));
}