#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

enum state {ALL_RED, NS_GREEN, NS_AMBER, EW_GREEN, EW_AMBER};

void step_sm (enum state* CS, enum state* PS)
{
	
	switch (*CS)
	{	

		case (ALL_RED):
		printf("ALL_RED\n");
		
			switch (*PS)
			{
			case (NS_AMBER):
				*CS = EW_GREEN;	
				break;
			case (EW_AMBER):
				*CS = NS_GREEN;
				break; 
			}
			break;
		
		case (NS_GREEN):
			printf("NS_GREEN\n");
			*CS = NS_AMBER;
			break;			

		case (NS_AMBER):
			printf("NS_AMBER\n");
			*CS = ALL_RED;
			*PS = NS_AMBER;
			break;

		case (EW_GREEN):
			printf("EW_GREEN\n");
			*CS = EW_AMBER;
			break;

		case (EW_AMBER):
			printf("EW_AMBER\n");
			*CS = ALL_RED;
			*PS = EW_AMBER;
			break;

	}

}



int main (void)
{

	enum state CS = ALL_RED, PS = EW_AMBER;

	for (int i=0; i<30;i++)
	{
		step_sm(&CS, &PS);
	}	

}
