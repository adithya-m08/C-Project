#include "projectheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

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

    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        return (dd <= 30);
    return 1;
}

void final_entry(candidate c)
{
	char name;
	FILE *fp;
	fp = fopen("database.txt", "a+");
	if (fp != NULL)
	{
		fwrite(&c, sizeof(c), 1, fp);
		fprintf(fp, "\n");
		fflush(stdin);
		printf("Success!\n\n");
		fclose(fp);
	}

	FILE *fp1;
	time_t seed = 0;
	fp1 = fopen("secretcode.txt", "a+");
	if (fp1 != NULL)
	{
		seed = time(NULL);
		srand(seed);
		printf("Your secret code is: %d\n", rand());
		fprintf(fp1, "%d\n", rand());
		fclose(fp1);
		printf("Enter any key to exit\n");
		getch();
		system("cls");
	}
}
