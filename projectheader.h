typedef struct
{
	char name[30];
	char dob[10];
	int dd;
	int mm;
	int yy;
} candidate;

int date_verification(int dd, int mm, int yy);
void final_entry(candidate c);
