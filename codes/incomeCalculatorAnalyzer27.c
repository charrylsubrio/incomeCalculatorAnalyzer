//Description:
//
//Programmers:
//
//SUBRIO, CHARRYL
//LOMARDA, ISMAEL MARLON
//TORAJA, HERRO
//
//Date finished:

#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int getPeriod(char *, char *);
float getIncomes(int, char *);
displayTotAvg(int, float, char *);

main() {
	int period;
	float income, totIncome, avgIncome;
	char option, _D[] = "Day",  _D2[] = "Dai", _W[] = "Week", _M[] = "Month", _Y[] = "Year";

	do {
		do {
			printf("INCOME CALCULATOR\n\n");
			printf("**** MENU ****\n\n");
			printf("[D] - Daily\n");
			printf("[W] - Weekly\n");
			printf("[M] - Monthly\n");
			printf("[Y] - Yearly\n");
			printf("[Q] - Quit\n");

			printf("\nPress option... ");
			option = getch();
			option = toupper(option);
			printf("%c\n", option);

			if(option != 'D' && option != 'W' && option != 'M' && option != 'Y' && option != 'Q') {
				printf("Invalid option. Please check the valid options above.\n");
				printf("Press any key to continue ");
				getch();
				system("cls");
			} else if(option == 'Q') {
				printf("Programmers:\n\n");
				printf("SUBRIO, CHARRYL\n");
				printf("LOMARDA, ISMAEL MARLON\n");
				printf("TORAJA, HERRO\n");
			} else {
				system("cls");
			}

		} while(option != 'D' && option != 'W' && option != 'M' && option != 'Y' && option != 'Q');

		switch(option) {
			case 'D':
				period = getPeriod(_D2, _D);
				totIncome = getIncomes(period, _D);
				displayTotAvg(period, totIncome, _D2);
				break;
			case 'W':
				period = getPeriod(_W, _W);
				break;
			case 'M':
				period = getPeriod(_M, _M);
				break;
			case 'Y':
				period = getPeriod(_Y, _Y);
				break;
		}
	} while (option != 'Q');
}

int getPeriod(char *whatPeriod1, char *whatPeriod2) {
	int period;

	do {
		printf("INCOME CALCULATOR\n\n");
		printf("**** %sly ****\n\n", whatPeriod1);
		printf("Number of %ss: ", whatPeriod2);
		scanf("%d", &period);

		if(period <= 1 || isalpha(period)) {
			printf("Invalid input, please enter whole number greater than 1 only.\n");
			fflush(stdin);
			printf("Press any key to continue ");
			getch();
			system("cls");
		} else if(getchar() != '\n') {
			printf("Invalid input, please enter whole number greater than 1 only.\n");
			period = 1;
//			fflush(stdin);
//			break;
			printf("Press any key to continue ");
			getch();
			system("cls");
		} else {
			printf("\n");
//			break;
		}
		
	} while (period <= 1 || isalpha(period) || getchar() != '\n');

	return period;
}

float getIncomes(int period, char *whatPeriod) {
	float income, totIncome;

	for(int i = 1; i <= period; i++) {
		do {
			printf("Income %s %d: ", whatPeriod, i);
			if (scanf("%f", &income) != 1 || income < 0) {
				fflush(stdin);
				printf("\nInvalid input, please enter valid income amounts only.\n\n");
			} else {
				break;
			}
		} while ((income) != 1 || income < 0);

		totIncome += income;
	}
	return totIncome;
}

displayTotAvg(int period, float totIncome, char *whatPeriod) {
	float avgIncome;
	printf("\nTotal income within %d %s: %.2f\n\n", period, whatPeriod, totIncome);
	printf("Average %sly Income: %.2f\n\n\n", whatPeriod, totIncome / period);
}
