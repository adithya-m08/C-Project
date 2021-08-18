#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "server.h"

int main()
{
	int day, month, year, choice, no_of_candidates;
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
	day = local->tm_mday;		  // get day of month (1 to 31)
	month = local->tm_mon + 1;	  // get month of year (0 to 11)
	year = local->tm_year + 1900; // get year since 1900

	printf("1.ENROLLING\n");
	printf("2.ELECTION CANDIDATES\n");
	printf("3.ELECTION\n");
	printf("4.RESULTS\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d", &choice);

	candidate c;
	int mm, yy, dd;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			printf("\nEnter Your Name: ");
			fflush(stdin);
			scanf("%[^\n]s", &c.name);
			printf("\nEnter your date of birth DD/MM/YYYY : ");
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
					printf("Age less than 18, you are not eligible\n");
				}
			}

			else
				printf("Invalid Date\n");
			break;

		case 2:
			printf("Enter the Number of Candidates: ");
			scanf("%d", &no_of_candidates);
			printf("\n");
			entry_election_candidates(no_of_candidates);
			break;

		case 3:
			election();
			break;
		case 4:
			final_results();
			break;
		}

		printf("0.EXIT\n");
		printf("1.ENROLLING\n");
		printf("2.ELECTION CANDIDATES\n");
		printf("3.ELECTION\n");
		printf("4.RESULTS\n\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d", &choice);
	}
	return 0;
}