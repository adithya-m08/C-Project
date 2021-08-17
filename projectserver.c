#include "finalprojectheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

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
		printf("Enter any key to continue\n");
		getch();
		system("cls");
	}
}

void entry_election_candidates(int no_of_candidates)
{
	FILE *fp;
	fp = fopen("candidate.txt", "a+");
	char candidate_name[20];
	int j = 1;
	for (int i = 1; i <= no_of_candidates; i++)
	{
		printf("%d. CANDIDATES NAME: ", i);
		fflush(stdin);
		scanf("%[^\n]s", candidate_name);
		printf("\n");
		fputs(candidate_name, fp);
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void election()
{
	FILE *fp;
	fp = fopen("candidate.txt", "a+");
	char line[100];
	char s_code[20];
	char c_name[20];
	char secret_code[5];
	int j = 1;
	int ctr;
	int crt1 = 0;
	int crt2 = 0;
	int crt3 = 0;
	secret_code;
	int choice;
	while ((fgets(c_name, 100, fp)) != NULL)
	{
		printf("%d.", j);
		printf("%s", c_name);
		printf("\n");
		j++;
	}

	printf("WELCOME\n");
	printf("Enter ypur secret code: ");
	printf("\n");
	scanf("%s", &secret_code);
	//printf("%s",secret_code);
	FILE *fp1;
	fp1 = fopen("secretcode.txt", "a+");
	while ((fgets(s_code, 100, fp1)) != NULL)
	{
		if (strcmp(s_code, secret_code) == 0)
		{
			ctr = 1;
		}
	}

	if (ctr == 1)
	{
		printf("enter your choice: ");
		scanf("%d", &choice);
		system("cls");
		while (choice != 0)
		{
			switch (choice)
			{
			case 1:
			{
				crt1++;
				break;
			}
			case 2:
			{
				crt2++;
				break;
			}
			case 3:
			{
				crt3++;
				break;
			}
			}
		}
	}
	else
		printf("invalid code\n");
}

