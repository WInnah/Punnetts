#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	char allele1;
	char allele2;
} Gamete;

typedef struct{
	Gamete first;
	Gamete second;
}Dihybrid;

bool checker(char* a, char* b, bool Di1)
{
	char big;
	char small;
	Gamete pair1, pair2, pair3, pair4;

	if (a[0] >= 97 && a[0] <= 122)
	{
		small = a[0];
		big = small - 32;
	}

	else if (a[0] >= 65 && a[0] <= 90)
	{
		big = a[0];
		small = big + 32;
	}
	else
		return false;

	if (Di1 && (a[2] == big || a[2] == small || b[2] == big || b[2] == small))
	{
		printf("\nYou can't have the same letter representation for both alleles.");
		return false;
	}

	if (!Di1 && (a[2] != '\0' || b[2] != '\0'))
		return false;


	if ((a[1] == big || a[1] == small) && (b[0] == big || b[0] == small) && (b[1] == big || b[1] == small))
		return true;

	return false;
}

void MonohybridCross(char* mother, char* father, char* dominant, char* recessive)
{
	system("cls");
	system("color 3F");
	Gamete pair1, pair2, pair3, pair4;

	int i, j;
	char k, l;

	printf("\t\t\t   %c%c", 179, 179);
	for(i = 0; i < 2; i++)
	{
		printf("  %c   %c%c", mother[i], 179, 179); // printing the first row (the mother's allele)
	}

	for(i = 0; i <= 10; i++)
	{
		if (dominant[i] >= 65 && dominant[i] <= 90)
			dominant[i] = dominant[i] + 32;
	}

	for(i = 0; i <= 10; i++)
	{
		if (recessive[i] >= 65 && recessive[i] <= 90)
			recessive[i] = recessive[i] + 32;
	}

	for(i = 0; i < 2; i++)
	{
		printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 181, 198, 205, 205, 205, 205, 205, 205, 181, 198, 205, 205, 205, 205, 205, 205, 181,179);
		printf("\t\t\t %c %c%c", father[i], 179, 179); //printing the first column (the father's allele)
		for(j = 0; j < 2; j++)
		{
			if (mother[j] <= 90) //if mother's allele is dominant (capital letter)
			{
				printf("  %c%c  %c%c", mother[j], father[i], 179, 179);
				k = mother[j];
				l = father[i];
			}
			else
			{
				printf("  %c%c  %c%c", father[i], mother[j], 179, 179);
				k = father[i];
				l = mother[j];
			}

			if (i == 0 && j == 0)
			{
				pair1.allele1 = k;
				pair1.allele2 = l;
			}
			else if (i == 0 && j == 1)
			{
				pair2.allele1 = k;
				pair2.allele2 = l;
			}
			else if (i == 1 && j == 0)
			{
				pair3.allele1 = k;
				pair3.allele2 = l;
			}
			else if (i == 1 && j == 1)
			{
				pair4.allele1 = k;
				pair4.allele2 = l;
			}
		}
	}
	printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 207, 207, 205, 205, 205, 205, 205, 205, 207, 207, 205, 205, 205, 205, 205, 205, 207, 190);

	char big;
	char small;

	// Phenotype Checking
	if (pair1.allele1 <= 90)
	{
		big = pair1.allele1;
		small = big + 32;
	}
	else
	{
		small = pair1.allele1;
		big = small - 32;
	}

	Gamete pos1 = {big, big};
	Gamete pos2 = {big, small};
	Gamete pos3 = {small, small};


	int possi1 = 0, possi2 = 0, possi3 = 0;
	if (pair1.allele1 == pos1.allele1 && pair1.allele2 == pos1.allele2)
	{
		possi1++;
	}
	else if (pair1.allele1 == pos2.allele1 && pair1.allele2 == pos2.allele2)
	{
		possi2++;
	}
	else if (pair1.allele1 == pos3.allele1 && pair1.allele2 == pos3.allele2)
	{
		possi3++;
	}
	if (pair2.allele1 == pos1.allele1 && pair2.allele2 == pos1.allele2)
	{
		possi1++;
	}
	else if (pair2.allele1 == pos2.allele1 && pair2.allele2 == pos2.allele2)
	{
		possi2++;
	}
	else if (pair2.allele1 == pos3.allele1 && pair2.allele2 == pos3.allele2)
	{
		possi3++;
	}
	if (pair3.allele1 == pos1.allele1 && pair3.allele2 == pos1.allele2)
	{
		possi1++;
	}
	else if (pair3.allele1 == pos2.allele1 && pair3.allele2 == pos2.allele2)
	{
		possi2++;
	}
	else if (pair3.allele1 == pos3.allele1 && pair3.allele2 == pos3.allele2)
	{
		possi3++;
	}
	if (pair4.allele1 == pos1.allele1 && pair4.allele2 == pos1.allele2)
	{
		possi1++;
	}
	else if (pair4.allele1 == pos2.allele1 && pair4.allele2 == pos2.allele2)
	{
		possi2++;
	}
	else if (pair4.allele1 == pos3.allele1 && pair4.allele2 == pos3.allele2)
	{
		possi3++;
	}

	printf("\n\nThe offspring has a %d percent chance of having a homozygous dominant trait.\n", possi1 * 25);
	printf("\nThe offspring has a %d percent chance of having a heterozygous dominant trait.\n", possi2 * 25);
	printf("\nThe offspring has a %d percent chance of having a homozygous recessive trait.\n", possi3 * 25);

	printf("\n\nTherefore, you will have %d percent chance of having a %s offspring and %d percent chance of having a %s one.\n",(possi1+possi2) * 25, dominant, possi3*25, recessive);
}

void DihybridCross(char* mother, char* father, char* dominant1, char* recessive1, char* dominant2, char* recessive2)
{
	int i, j, k;
	int count = 0;
	char big1, small1;
	char big2, small2;
	Dihybrid pair[16];
	float pos[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


	system("cls");
	system("color 3F");
	printf("\t\t\t    %c%c", 179, 179);
	for(i = 0; i <=1; i++)
	{
		for(j = 2; j <= 3; j++)
		{
			printf("  %c%c  %c%c", mother[i], mother[j], 179, 179);
		}
	}

	for(i = 0, j = 0; i < 4; i++)
	{
		printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 181, 198, 205, 205, 205, 205, 205, 205, 181, 198, 205, 205, 205, 205, 205, 205, 181, 198, 205, 205, 205, 205, 205, 205, 181, 198, 205, 205, 205, 205, 205, 205, 181, 179);
		printf("\n\t\t\t %c%c %c%c", father[i/2], father[(i%2)+2], 179, 179);
		for(j = 0; j <= 1; j++)
		{
			for(k = 2; k <= 3; k++, count++)
			{
				if (mother[j] > father[i/2])
				{
					printf(" %c%c", father[i/2], mother[j]);
					pair[count].first.allele1 = father[i/2];
					pair[count].first.allele2 = mother[j];
				}
				else
				{
					printf(" %c%c", mother[j], father[i/2]);
					pair[count].first.allele1 = mother[j];
					pair[count].first.allele2 = father[i/2];
				}
				if (mother[k] > father[(i%2)+2])
				{
					printf("%c%c %c%c", father[(i%2)+2], mother[k], 179, 179);
					pair[count].second.allele1 = father[(i%2)+2];
					pair[count].second.allele2 = mother[k];
				}
				else
				{
					printf("%c%c %c%c", mother[k], father[(i%2)+2], 179, 179);
					pair[count].second.allele1 = mother[k];
					pair[count].second.allele2 = father[(i%2)+2];
				}
			}
		}
	}
	printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 205, 205, 205, 205, 207, 207, 205, 205, 205, 205, 205, 205, 207, 207, 205, 205, 205, 205, 205, 205, 207, 207, 205, 205, 205, 205, 205, 205, 207, 207, 205, 205, 205, 205, 205, 205, 207, 190);
	if (mother[0] <= 90)
	{
		big1 = mother[0];
		small1 = big1 + 32;
	}
	else
	{
		small1 = mother[0];
		big1 = small1 - 32;
	}
	if (mother[3] <= 90)
	{
		big2 = mother[3];
		small2 = mother[3] + 32;
	}
	else
	{
		small2 = mother[3];
		big2 = small2 - 32;
	}

	for(i = 0; i < 16; i++)
	{
		if (pair[i].first.allele1 == big1 && pair[i].first.allele2 == big1 && pair[i].second.allele1 == big2 && pair[i].second.allele2 == big2)
		{
			pos[0]++;
		}
		else if (pair[i].first.allele1 == big1 && pair[i].first.allele2 == big1 && pair[i].second.allele1 == big2 && pair[i].second.allele2 == small2)
		{
			pos[1]++;
		}
		else if (pair[i].first.allele1 == big1 && pair[i].first.allele2 == big1 && pair[i].second.allele1 == small2 && pair[i].second.allele2 == small2)
		{
			pos[2]++;
		}
		else if (pair[i].first.allele1 == big1 && pair[i].first.allele2 == small1 && pair[i].second.allele1 == big2 && pair[i].second.allele2 == big2)
		{
			pos[3]++;
		}
		else if (pair[i].first.allele1 == big1 && pair[i].first.allele2 == small1 && pair[i].second.allele1 == big2 && pair[i].second.allele2 == small2)
		{
			pos[4]++;
		}
		else if (pair[i].first.allele1 == big1 && pair[i].first.allele2 == small1 && pair[i].second.allele1 == small2 && pair[i].second.allele2 == small2)
		{
			pos[5]++;
		}
		else if (pair[i].first.allele1 == small1 && pair[i].first.allele2 == small1 && pair[i].second.allele1 == big2 && pair[i].second.allele2 == big2)
		{
			pos[6]++;
		}
		else if (pair[i].first.allele1 == small1 && pair[i].first.allele2 == small1 && pair[i].second.allele1 == big2 && pair[i].second.allele2 == small2)
		{
			pos[7]++;
		}
		else if (pair[i].first.allele1 == small1 && pair[i].first.allele2 == small1 && pair[i].second.allele1 == small2 && pair[i].second.allele2 == small2)
		{
			pos[8]++;
		}
	}

	printf("\n\n");

	if (pos[0] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a homozygous dominant trait for the first pair and homozygous dominant trait for the second.\n", pos[0] * 6.25);
	}
	if (pos[1] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a homozygous dominant trait for the first pair and heterozygous dominant trait for the second.\n", pos[1] * 6.25);
	}
	if (pos[2] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a homozygous dominant trait for the first pair and homozygous recessive trait for the second.\n", pos[2] * 6.25);
	}
	if (pos[3] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a heterozygous dominant trait for the first pair and homozygous dominant trait for the second.\n", pos[3] * 6.25);
	}
	if (pos[4] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a heterozygous dominant trait for the first pair and heterozygous dominant trait for the second.\n", pos[4] * 6.25);
	}
	if (pos[5] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a heterozygous dominant trait for the first pair and homozygous recessive trait for the second.\n", pos[5] * 6.25);
	}
	if (pos[6] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a homozygous recessive trait for the first pair and homozygous dominant trait for the second.\n", pos[6] * 6.25);
	}
	if (pos[7] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a homozygous recessive trait for the first pair and heterozygous dominant trait for the second.\n", pos[7] * 6.25);
	}
	if (pos[8] > 0)
	{
		printf("\nThe offspring has %.0f percent chance of having a homozygous recessive trait for the first pair and homozygous recessive trait for the second.\n", pos[8] * 6.25);
	}

	printf("\n\nTherefore, you will have a:\n%c %.0f percent chance of having a %s, %s offspring;\n%c %.0f percent chance of having a %s, %s offspring;\n%c %.0f percent chance of having a %s, %s offspring; and,\n%c %.0f percent chance of having a %s, %s offspring.\n\n", 26, (pos[0]+pos[1]+pos[3]+pos[4]) * 6.25, dominant1, dominant2, 26, (pos[2]+pos[5]) * 6.25, dominant1, recessive2, 26, (pos[6]+pos[7]) * 6.25, recessive1, dominant2, 26, pos[8] * 6.25, recessive1, recessive2);
}

int main()
{
	bool valid;
	char mother[5], father[5];
	char dominant1[100], recessive1[100];
	char dominant2[100], recessive2[100];

	system("color 6f");
	printf("\t\t\t   PUNNET SQUARE GENERATOR\n\n\n\tFor convenience purposes, please run the program in fullscreen mode.\n\n");
	system("pause");
	system("cls");
	printf("\t\t\t   PUNNET SQUARE GENERATOR\n\n");
	do
	{
		printf("Please enter mother allele: ");
		scanf(" %[^\n]s", mother);
		printf("Please enter father allele: ");
		scanf(" %[^\n]s", father);

		if (mother[2] == '\0')
		{
			valid = checker(mother, father, false);
		}

		else
		{
			char mother1[3] = {mother[0], mother[1], mother[2]};
			char mother2[3] = {mother[2], mother[3], mother[4]};
			char father1[3] = {father[0], father[1], father[2]};
			char father2[3] = {father[2], father[3], father[4]};

			bool valid1 = checker(mother1, father1, true);
			bool valid2 = checker(mother2, father2, false);

			valid = valid1 * valid2;
		}

		if (valid)
		{
			printf("\n\nWhat does the dominant trait indicates in the first pair? ");
			scanf(" %[^\n]s", dominant1);
			printf("\nHow about the recessive one? ");
			scanf(" %[^\n]s", recessive1);

			if (mother[2] == '\0')
				MonohybridCross(mother, father, dominant1, recessive1);

			else
			{
				printf("\n\nWhat does the dominant trait indicates in the second pair? ");
				scanf(" %[^\n]s", dominant2);
				printf("\nHow about the recessive one? ");
				scanf(" %[^\n]s", recessive2);
				DihybridCross(mother, father, dominant1, recessive1, dominant2, recessive2);
			}
		}

		else
		{
			printf("\n\nERROR! The input you entered is invalid!\n\n");
			system("pause");
			system("cls");
		}
	}

	while (!valid);

    system("pause");
	return 0;
}
