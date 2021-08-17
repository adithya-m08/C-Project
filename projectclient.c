#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "projectheader.h"

int main()
{
	int day, month, year, choice;
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
	day = local->tm_mday;		  // get day of month (1 to 31)
	month = local->tm_mon + 1;	  // get month of year (0 to 11)
	year = local->tm_year + 1900; // get year since 1900

	printf("1.ENROLLING\n");
	printf("2.ELECTION\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d", &choice);

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			candidate c = {0};
			int tyy, tdd, tmm, mm, yy, dd;
			printf("\nEnter Your Name: ");
			fflush(stdin);
			scanf("%[^\n]s", &c.name);
			printf("\nEnter candidate date of birth DD/MM/YYYY : ");
			scanf("%d/%d/%d", &c.dd, &c.mm, &c.yy);
			printf("Today's date is: %02d/%02d/%d\n\n", day, month, year);

			if (date_verification(c.dd, c.mm, c.yy))
			{
				if (day >= c.dd && c.mm >= month && (year - c.yy) >= 18 || (year - c.yy) >= 18)
				{
					printf("You are eligible\n");
					sprintf(c.dob, "%d/%d/%d", c.dd, c.mm, c.yy);
					final_entry(c);
				}
				else
				{
					printf("Age less than 18,you are not eligible\n");
				}
			}

			else
				printf("Invalid Date\n");
		}
			/*case 2: 
		{
            		ELECTION();
            		break; 
		}*/
			choice = 0;
		}
		return 0;
	}
}
