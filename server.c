#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
voter v = {0};

int IsLeapYear(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int date_verification(int dd, int mm, int yy)
{
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
		int code = rand();
		printf("Your secret code is: %d\n", code);
		fprintf(fp1, "%d\n", code);
		fclose(fp1);
		printf("Enter any key to continue\n");
		getch();
		system("cls");
	}
	fclose(fp1);
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
	fp = fopen("candidate.txt", "r");
	FILE *fp2;
	fp2 = fopen("secretcode.txt", "r");
	FILE *fp1;
	fp1 = fopen("duplicate.txt", "a+");

	char line[100], s_code[20], c_name[20], secret_code[5], s1_code[100];
	int j = 1, choice, ctr1 = 0, ctr2 = 0;
	while ((fgets(c_name, 100, fp)) != NULL)
	{
		printf("%d.", j);
		printf("%s", c_name);
		printf("\n");
		j++;
	}

	printf("Enter your Secret Code: ");
	printf("\n");
	scanf("%s", &v.secret_code);

	while ((fscanf(fp2, "%s", &s_code)) != EOF)
	{
		if (strcmp(s_code, v.secret_code) == 0)
		{
			while ((fgets(line, 100, fp1)) != NULL)
			{
				char *val = strtok(line, "\t");
				if (strcmp(val, v.secret_code) == 0)
					printf("\n Already Voted!\n");
			}

			printf("Enter your Choice: ");
			scanf("%s", &v.cast);
			fprintf(fp1, "\n");

			switch (atoi(v.cast))
			{
			case 1:
				count1++;
				break;
			case 2:
				count2++;
				break;
			case 3:
				count3++;
				break;
			}
			fprintf(fp1, "%s\t", v.secret_code);
			fprintf(fp1, "%s\n", v.cast);
		}
		else
			printf("Invalid Code!\n");
	}

	printf("\nEnter a key to exit ");
	getch();
	system("cls");
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
}

void final_results()
{
	char line[100];
	int k = 1;
	char c_name[20];
	FILE *fp;
	FILE *fp1;

	fp = fopen("candidate.txt", "r");
	fp1 = fopen("duplicate.txt", "r");
	while (fgets(line, 100, fp) != NULL)
	{

	}
	while ((fgets(line, 100, fp)) != NULL)
	{
		char *val = strtok(line, "\t");
		char *val1 = strtok(NULL, "\t");
		if (strcmp(val1, "1") == 0)
			count1++;
		if (strcmp(val1, "2") == 0)
			count2++;
		if (strcmp(val1, "3") == 0)
			count3++;
		if (strcmp(val1, "4") == 0)
			count4++;
		if (strcmp(val1, "5") == 0)
			count5++;
	}
	printf("\nCandidate 1 - %d ", count1);
	printf("\nCandidate 2 - %d ", count2);
	printf("\nCandidate 3 - %d ", count3);
	printf("\nCandidate 4 - %d ", count4);
	if (count1 > count2 && count1 > count3 && count1 > count4)
		printf("\n\nCandidate 1 Won the Elections\n\n");
	else if (count2 > count3 && count2 > count4 && count2 > count1)
		printf("\n\nCandidate 2 Won the Elections\n\n");
	else if (count3 > count4 && count3 > count2 && count3 > count1)
		printf("\n\nCandidate 3 Won the Elections\n\n");
	else if (count4 > count1 && count4 > count2 && count4 > count3)
		printf("\n\nCandidate 4 Won the Elections\n\n");
	else
		printf("\n\nNo Clear Winner\n\n");
	fclose(fp);
}