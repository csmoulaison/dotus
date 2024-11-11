#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NOTE_PATH "/home/csmoulaison/Documents/dotus/notes"
#define NOTE_MAX_LENGTH 8196

int main(int argc, char** argv) {
	// > 
	if(argc == 1) {
		printf("You need to provide an argument. Use 'dotus help' for usage.\n");
		return 1;
	}

	// > help
	if(strcmp(argv[1], "help") == 0) {
		printf(
			"Usage: dotus <arguments>...\n"
			"\n"
			"Arguments (\"|\" means or):\n"
			"    help: lists commands\n"
			"\n"
			"    \"<body>\": Write a new note.\n"
			"    <id>: Show the note with the matching id.\n"
			"\n"
			"    list | l: List all notes.\n"
			"    search | s: <word>* : Search for matching keywords.\n"
			"    clear_all: Irreversibly delete all notes.\n"
		);
		return 0;
	}

	// > search 
	if(strcmp(argv[1], "s") == 0 || strcmp(argv[1], "search") == 0) {
		FILE* file;
		file = fopen(NOTE_PATH, "r");
		char line[NOTE_MAX_LENGTH];
		int line_index = 0;
		while(fgets(line, sizeof(line), file) != NULL) {
			int matches = 0;
			for(int arg_index = 1; arg_index < argc; arg_index++) {
				int arg_str_index = 0;
				int line_str_index = 0;
				while(line[line_str_index] != '\0') {
					if(line[line_str_index] == argv[arg_index][arg_str_index]) {
						arg_str_index++;
					} else {
						arg_str_index = 0;
					}
					if(argv[arg_index][arg_str_index] == '\0') {
						matches++;
						arg_str_index = 0;
						break;
					}
					line_str_index++;
				}
			}
			if(matches > 0) {
				printf("%i ", matches);
				if(matches == 1) {
					printf("match");
				} else {
					printf("matches");
				}
				printf(" | %06i | %s", line_index, line);
			}
			line_index++;
		}
		return 0;
	}

	// > list
	if(strcmp(argv[1], "l") == 0 || strcmp(argv[1], "list") == 0) {
		FILE* file;
		file = fopen(NOTE_PATH, "r");
		char line[NOTE_MAX_LENGTH];
		int line_count = 0;
		while(fgets(line, sizeof(line), file) != NULL) {
			printf("%06i | %s", line_count, line);
			line_count++;
		}
		return 0;
	}

	// > <id>
	int argv_id = atoi(argv[1]);
	if(argv_id != 0) {
		FILE* file;
		file = fopen(NOTE_PATH, "r");
		char line[NOTE_MAX_LENGTH];
		int line_count = 0;
		while(fgets(line, sizeof(line), file)) {
			if(line_count == argv_id) {
				printf("%06i | %s", argv_id, line);
				break;
			}
			line_count++;
		}
		return 0;
	}

	// > clear_all
	if(strcmp(argv[1], "clear_all") == 0) {
		FILE* file;
		file = fopen(NOTE_PATH, "w");
		fclose(file);
		printf("All notes cleared!\n");
		return 0;
	}

	// > <note_string>
	FILE* file;
	file = fopen(NOTE_PATH, "a");
	fprintf(file, argv[1]);
	fprintf(file, "\n");
	fclose(file);
	printf("Note created.\n");
	return 0;
}

