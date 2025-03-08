//LG6_Q2
//Fitness
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define LIMIT 5
#define EXIT 8

typedef struct {
	char exType;  // 'C' = Cardio, 'S' = Strength Training, 'Y' = Yoga
	int hrs;   // Hours spent on the exercise
	double calBurnedPerHr;
} workout_t;

typedef struct {
	int memberID;
	char name[SIZE];
	workout_t workout;
} member_t;

int menu();
void readFromFile(FILE *inp, member_t *members, int noOfMem);
void displayMemberInfo(member_t *members, int noOfMem);
int searchMember(member_t *members, int noOfMem, int searchID);
int mostActiveMem(member_t *members, int noOfMem);
void mostPopEx(member_t *members, int noOfMem);
void extraWorkout(member_t *members, int noOfMem);
void highCalBurners(member_t *members, int noOfMem, double calLimit);
double calAvgWorkout(member_t *members, int noOfMem);


int main()
{
	FILE *inp = fopen("fitness.txt", "r");

	if (inp == NULL) {
		printf("Error opening inp.\n");
	}
	else
	{
		int memberCount, choice, indx;
		double avg;
		fscanf(inp, "%d", &memberCount);

		member_t *members = (member_t *)malloc(memberCount * sizeof(member_t));
		if (members == NULL) {
			printf("Memory allocation error.\n");
		}
		else
		{
			readFromFile(inp, members, memberCount);

			fclose(inp);

			do {
				choice = menu();

				if (choice != EXIT)
				{
					switch (choice)
					{
					case 1: // Display members
						displayMemberInfo(members, memberCount);
						break;

					case 2:
						// Search for a specific member by ID
						int searchID;
						printf("\nEnter member_t ID to search: ");
						scanf("%d", &searchID);

						indx = searchMember(members, memberCount, searchID);
						if (indx == -1)
							printf("\nMember ID %d not found.\n", searchID);
						else
							printf("\nMember ID: %d\nType: %c\nHours: %d\nCalories Burned: %.2f\n",
								members[indx].memberID, members[indx].workout.exType,
								members[indx].workout.hrs,
								members[indx].workout.hrs * members[indx].workout.calBurnedPerHr);
						break;

					case 3:
						// Filter high calorie burners
						double calLimit;
						printf("\nEnter calorie burn Limit to filter members: ");
						scanf("%lf", &calLimit);
						highCalBurners(members, memberCount, calLimit);
						break;

					case 4:
						// Find most active member
						indx = mostActiveMem(members, memberCount);
						printf("\nMost Active: %d-%s with %d hours of exercise.\n",
							members[indx].memberID, members[indx].name, members[indx].workout.hrs);
						break;

					case 5:
						// Find most popular exercise
						mostPopEx(members, memberCount);
						break;

					case 6:
						// Calculate average workout per member
						avg = calAvgWorkout(members, memberCount);
						printf("\nAverage Weekly Workout Time: %.2f hours\n", avg);
						break;

					case 7:
						// Recommend additional workout hours
						extraWorkout(members, memberCount);

					}
				}
			} while (choice != EXIT);
		}
		// Free dynamically allocated memory
		free(members);
	}
	return 0;
}

int menu()
{
	int choice;

	printf("\nFITNESS CENTER MENU\n");
	printf("-------------------\n");
	printf("1. Display All Members\n");
	printf("2. Search a Member by ID\n");
	printf("3. Display the high-calorie burners\n");
	printf("4. Find the most active member\n");
	printf("5. Find the most popular exercise type\n");
	printf("6. Display Average Weekly Workout Time\n");
	printf("7. Find Members Who Need Extra Workout Time\n");
	printf("8. EXIT\n");

	do {
		printf("Enter your choice: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice >8);

	return choice;
}

void readFromFile(FILE *inp, member_t *members, int noOfMem)
{
	for (int i = 0; i < noOfMem; i++)
	{
		fscanf(inp, "%d %s %c %d %lf",
			&members[i].memberID,
			members[i].name,
			&members[i].workout.exType,
			&members[i].workout.hrs,
			&members[i].workout.calBurnedPerHr);
	}
}

void displayMemberInfo(member_t *members, int noOfMem)
{
	printf("\nMember Fitness Data:\n");
	printf("ID   Name                Type   Hours  Calories Burned\n");
	printf("------------------------------------------------------\n");
	for (int i = 0; i < noOfMem; i++) {
		
		double totalCalories = members[i].workout.hrs * members[i].workout.calBurnedPerHr;

		printf("%-6d   %-17s %c %6d %10.2f\n",
			members[i].memberID,
			members[i].name,
			members[i].workout.exType,
			members[i].workout.hrs,
			totalCalories);
	}
}

// Function to search for a member by ID
int searchMember(member_t *members, int noOfMem, int searchID)
{
	for (int i = 0; i < noOfMem; i++) {
		if (members[i].memberID == searchID) {
			return i;
		}
	}

	return -1;
}

int mostActiveMem(member_t *members, int noOfMem)
{
	int index = 0;
	for (int i = 0; i < noOfMem; i++)
	{
		if (members[i].workout.hrs > members[index].workout.hrs)
		{
			index = i;
		}
	}

	return index;
}

void mostPopEx(member_t *members, int noOfMem)
{
	int cardioHours = 0,
		strengthHours = 0,
		yogaHours = 0;

	for (int i = 0; i < noOfMem; i++)
	{
		switch (members[i].workout.exType)
		{
		case 'C': cardioHours += members[i].workout.hrs; break;
		case 'S': strengthHours += members[i].workout.hrs; break;
		case 'Y': yogaHours += members[i].workout.hrs; break;
		}
	}

	char mostPopular;
	int maxHours = cardioHours;
	mostPopular = 'C';

	if (strengthHours > maxHours) {
		maxHours = strengthHours;
		mostPopular = 'S';
	}

	if (yogaHours > maxHours) {
		maxHours = yogaHours;
		mostPopular = 'Y';
	}

	printf("\nMost Popular Exercise: %c with %d total hours.\n", mostPopular, maxHours);
}

void extraWorkout(member_t *members, int noOfMem) {
	
	printf("\nMembers needing more workout (less than 5 hours):\n");
	
	for (int i = 0; i < noOfMem; i++) 
	{
		if (members[i].workout.hrs < LIMIT) {
			printf("%d-%s needs %d more hours\n",
				members[i].memberID, members[i].name, LIMIT - members[i].workout.hrs);
		}
	}
}

// Function to filter high calorie burners
void highCalBurners(member_t *members, int noOfMem, double calLimit)
{
	printf("\nMembers burning more than %.2f calories:\n", calLimit);
	for (int i = 0; i < noOfMem; i++) {

		double totalCalories = members[i].workout.hrs * members[i].workout.calBurnedPerHr;

		if (totalCalories > calLimit) {
			printf("%d-%s burned %.2f calories\n", members[i].memberID, members[i].name, totalCalories);
		}
	}
}

// Function to calculate and display average workout time
double calAvgWorkout(member_t *members, int noOfMem)
{
	int totalHours = 0;

	for (int i = 0; i < noOfMem; i++) {
		totalHours += members[i].workout.hrs;
	}

	return (totalHours *1.0 / noOfMem);
}