// Fresh Random Civ Picker

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

bool parse_int(char *string, int *integer);

char *civ_name(int index);
int result(int);
void resetter(int *);

int main()
{
	srand(time(NULL));
	printf("Welcome to the Fresh Random Civ Picker for AoE2DE!\n\n");

	int input = 0;
	int available[45];
	int given_index;
	bool parsed_correct = true;

	
	
	resetter(&available);
	
	int iterator = 0;
	int remaining = 45;


	do
	{
		do
		{

			printf("\nEnter 1 to receive a fresh random civ, 0 to reset, or -1 to quit: ");
			char buffer[BUFFER_SIZE];
			fgets(buffer, BUFFER_SIZE, stdin);
			parsed_correct = parse_int(buffer, &input);
			if (!parsed_correct || input != -1 && input != 0 && input != 1) printf("\nInvalid input. Please try again.\n");
		} while (!parsed_correct || input != -1 && input != 0 && input != 1);



		if (input == -1) return 0;
		

		if (iterator == 45 || input == 0)
		{
			printf("\nProgram has been reset.\n");
			iterator = 0;
			resetter(&available);
			remaining = 45;
		}

		if (input == 1)
		{
			given_index = result(remaining);
			int j = 0;
			for (int i = 0;  i < 45; i++) {
				while (available[j] != 1) j++;
				if (i == given_index) {
					given_index = j;
					break;
				}
				j++;

			}
			printf("\n%s (current set: %d/%d)\n", civ_name(given_index), iterator + 1, 45);			
			available[given_index] = 0;
			iterator++;
			remaining--;
		}

	} while (input != -1);
	return 0;
}

bool parse_int(char *string, int *integer)
{
	int i = 0;
	while (isspace(string[i])) i++;
	int length = strlen(string);
	if (length == i) return false;
	char integer_buffer[BUFFER_SIZE];
	int integer_chars = 0;
	if (string[i] == '-')
	{
		integer_buffer[integer_chars] = '-';
		integer_chars++;
		i++;
		if (!isdigit(string[i])) return false;
	}

	while (i < length && !isspace(string[i]))
	{
		if (!isdigit(string[i])) return false;
		integer_buffer[integer_chars] = string[i];
		integer_chars++;
		i++;
	}
	integer_buffer[integer_chars] = '\0';
	while (isspace(string[i])) i++;
	if (string[i] != '\0') return false;
	*integer = atoi(integer_buffer);
	return true;
}

int result(int max)
{
	int result = -1;
	result = rand() % max;
	return result;
}

char *civ_name(int index)
{
	switch (index)
	{
	case 0:
		return "Armenians";
	case 1:
		return "Aztecs";
	case 2:
		return "Bengalis";
	case 3:
		return "Berbers";
	case 4:
		return "Bohemians";
	case 5:
		return "Britons";
	case 6:
		return "Bulgarians";
	case 7:
		return "Burgundians";
	case 8:
		return "Burmese";
	case 9:
		return "Byzantines";
	case 10:
		return "Celts";
	case 11:
		return "Chinese";
	case 12:
		return "Cumans";
	case 13:
		return "Dravidians";
	case 14:
		return "Ethiopians";
	case 15:
		return "Franks";
	case 16:
		return "Georgians";
	case 17:
		return "Goths";
	case 18:
		return "Gurjaras";
	case 19:
		return "Hindustanis";
	case 20:
		return "Huns";
	case 21:
		return "Incas";
	case 22:
		return "Italians";
	case 23:
		return "Japanese";
	case 24:
		return "Khmer";
	case 25:
		return "Koreans";
	case 26:
		return "Lithuanians";
	case 27:
		return "Magyars";
	case 28:
		return "Malay";
	case 29:
		return "Malians";
	case 30:
		return "Mayans";
	case 31:
		return "Mongols";
	case 32:
		return "Persians";
	case 33:
		return "Poles";
	case 34:
		return "Portuguese";
	case 35:
		return "Romans";
	case 36:
		return "Saracens";
	case 37:
		return "Sicilians";
	case 38:
		return "Slavs";
	case 39:
		return "Spanish";
	case 40:
		return "Tatars";
	case 41:
		return "Teutons";
	case 42:
		return "Turks";
	case 43:
		return "Vietnamese";
	case 44:
		return "Vikings";
	default:
		return "(no civ chosen)";
	}
}

void resetter(int *ptr)
{
	for (int i = 0; i < 45; i++)
	{
		ptr[i] = 1;
	}
}
