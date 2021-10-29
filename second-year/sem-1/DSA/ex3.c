#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct students
{
	char name[40];
	char gender;
	int avg;
}STUDENT;

int N;

void readStudents(STUDENT **s)
{
	char tempN[40];
	char tempG;
	int tempAvg;
	int i;
	
	for(i=0; i<N; i++)
	{
		scanf("%d %c", &tempAvg, &tempG);
		fgets(tempN,41,stdin);
		strcpy((*s)[i].name, tempN);
		(*s)[i].gender=tempG;
		(*s)[i].avg=tempAvg;
	}
	
	
}

void sortRule(STUDENT *s)
{
	int i;
	int j;
	char secondStudent[40];
	int index;
	for(i=N-2; i>=0; i--)
	{
		s[N]=s[i];
		j=i+1;
		while((s[j].avg<s[N].avg && s[j].avg<5) && (s[j].gender<s[N].gender))
		{
			s[j-1]=s[j];
			j++;
		}
		s[j-1]=s[N];
	}
	
	/*for(i=N-2; i>=0; i--)
	{
		s[N]=s[i];
		j=i+1;
		if(s[j].avg==s[N].avg)
		{
			while(s[j].gender<s[N].gender)
			{
				s[j-1]=s[j];
				j++;
			}
			s[j-1]=s[N];
		}
	}
	
	for(i=N-2; i>=0; i--)
	{
		s[N]=s[i];
		j=i+1;
		if(s[j].gender==s[N].gender && s[j].avg==s[N].avg)
		{
			while(strcmp(s[j].name,s[N].name)<0)
			{
				s[j-1]=s[j];
				j++;
			}
			s[j-1]=s[N];
		}
	}*/
	
	for(i=0; i<N; i++)
	{
		if(strcmp(secondStudent,s[i].name)==0) index=i;
		printf("%d %c %s ",s[i].avg,s[i].gender, s[i].name);
	}
	printf("The index of the second student read after sorting is: %d\n",index);
	
}

void sortName(STUDENT *s)
{
	int i;
	int j;
	char firstStudent[40];
	int index;
	strcpy(firstStudent,s[0].name);
	
	for(i=N-2; i>=0; i--)
	{
		s[N]=s[i];
		j=i+1;
		while(strcmp(s[j].name,s[N].name)<0)
		{
			s[j-1]=s[j];
			j++;
		}
		s[j-1]=s[N];
	}
	
	for(i=0; i<N; i++)
	{
		if(strcmp(firstStudent,s[i].name)==0) index=i;
		//printf("%s %d \n",s[i].name,s[i].avg);
	}
	printf("The index of the first student read after sorting is: %d\n",index);
}

int main()
{
	printf("Enter N: ");
	scanf("%d",&N);
	//printf("%d",N);
	STUDENT *s= malloc(N*sizeof(STUDENT));
	readStudents(&s);
	sortName(s);
	sortRule(s);
	
	
	
	return 0;
	
}