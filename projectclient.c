#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
#include <time.h>
#include "projectheader.h" 

int main()
{
int day, month, year;
time_t now;
time(&now);
struct tm *local = localtime(&now);
day = local->tm_mday;            // get day of month (1 to 31)
month = local->tm_mon + 1;      // get month of year (0 to 11)
year = local->tm_year + 1900;   // get year since 1900
int choice;
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
			candidate c = { 0 };
			//char dob[20] = { 0 };
			int tyy, tdd, tmm,mm,yy,dd,counter = 0,i=0;
			printf("\nEnter Your Name: ");
			fflush(stdin);
			scanf("%[^\n]s", &c.name);
			printf("\nEnter candidate date of birth DD/MM/YYYY : ");
			scanf("%d/%d/%d", &c.dd, &c.mm, &c.yy);
    	    		printf(" Todays date is: %02d/%02d/%d\n", day, month, year);
			i = date_verification(c.dd, c.mm, c.yy);
			//printf("i=%d\n",i);
			if(i)
				{
				if (day >= c.dd && c.mm >=month && (year- c.yy) >= 18 || (year - c.yy) >= 18)
					{
						printf("You are eligible\n");
						counter++;
					}
				
				//else
					//printf("Your date is invalid\n");
				}
			//printf("counter=%d\n",counter);
			if (counter)
					{
						sprintf(c.dob,"%d/%d/%d",c.dd,c.mm,c.yy); //sprintf to convert int to str
						final_entry(c);
					}
			else
					{
						printf("Age less than 18,you are not eligible\n");
						printf("\nEnter a key to exit after noting down th code ");
						getch();
						system("cls");
					}
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