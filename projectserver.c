#include "projectheader.h" 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int date_verification(int dd, int mm, int yy)
{
    int i = 0;
    if(mm<1 || mm>12)
	{
        	printf("Month is Invalid\nSo enterted date is also invalid\n");
	}
    else if (mm>=1 && mm<=12)
	{
		if(mm==1||mm==3|| mm==5|| mm==7|| mm==8|| mm==10 || mm==12)
		{ 
    			if(dd<1 || dd>31)
				{
					printf("Date is Invalid\n");
					printf(" %d \n", dd);
				}		
		}
		else if( mm==6|| mm==4|| mm==9|| mm==11)
		{
			if( dd<1 || dd>30)
			{
				printf("Date is Invalid\n");
			}	

		}
   		else if(mm==2)
		{
    		if((yy % 4==0 && yy % 100!=0)||(yy % 400==0))
			{
				if(dd<1 || dd>29)
        				printf(" Date is invalid\n");
	
 
			}
    	 	else
			{
				if(dd<1 || dd>28)
        				printf("Date is invalid\n");
			}
		}
	}
   else
	return i++;

}

void final_entry(candidate c)
{
	char name;
	FILE* fp;
	fp = fopen("database.txt", "a+");
	if (fp != NULL)

	{
		//printf("\nEnter Your Name: ");
		//scanf("%s", &c.name);
		//gets(c.name);
		//printf("\nEnter Your DOB in the Form Date/Month/year(DD/MM/YY): ");
		//scanf("%d/%d/%d", &c.dd, &c.mm, &c.yy);
		fwrite(&c, sizeof(c), 1, fp);
		fprintf(fp,"\n");
		fflush(stdin);
		printf("Verified\n");
		fclose(fp);
	}
	FILE *fp1;
	time_t seed = 0;
	fp1 = fopen("secretcode.txt", "a+");
	if ( fp1 != NULL )
	{
		seed = time(NULL);
		srand(seed);
		/*time_t seconds;
		time(&seconds); // Stores time seconds*/
		printf("Your secret code is: %d\n", rand());
		fprintf(fp1,"%d\n", rand());
		fclose(fp1);
		printf("Enter a key to exit: \n");
		getch();
		system("cls");
	}

}



