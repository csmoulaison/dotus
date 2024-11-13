#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROOT_PATH "/home/csmoulaison/Documents/dotus/"
#define NOTE_PATH ROOT_PATH "notes"
#define ARCHIVE_PATH ROOT_PATH "archive"
#define NOTE_TMP_PATH ROOT_PATH "temp"
#define NOTE_MAX_LENGTH 8196

int main(int argc, char** argv) {
	// no arguments
	if(argc == 1) {
		printf("You need to provide an argument. Use 'dotus help' for usage.\n");
		return 1;
	}

	// help
	if(strcmp(argv[1], "help") == 0) {
		printf(
			"Usage\n"
			"  dotus help                   display this usage guide.\n"
			"\n"
			"Writing or Modifying Notes\n"
			"  dotus <string>               add note (e.g. dotus \"Hello world!\")\n"
			"  dotus amend <id> <string>    replace note of a given id (line number) with the given string.\n"
			"  dotus remove <id>            remove note of a given id (line number)\n"
			"  dotus archive <id>           remove note of a given id and add it to the archive.\n"
			"  dotus clear                  irreversibly delete all notes (with no confirmation!)\n"
			"  dotus clear archive          same as \"dotus clear\", but from the archive.\n"
			"\n"
			"Reading Notes\n"
			"  dotus <id>                   display note of a given id (line number)\n"
			"  dotus list                   display all notes (and their id) in chronological order.\n"
			"  dotus list archive           same as \"dotus list\", but from the archive.\n"
			"  dotus find <str1> <str2> ... display notes that contain exact matches for all given strings.\n"
			"\n"
			"File Paths\n"
			"  Main notes file:    %s\n"
			"  Archive notes file: %s\n",
		NOTE_PATH, ARCHIVE_PATH);
		return 0;
	}

	// Used in all commands henceforth
	FILE* file;

	// find 
	if(strcmp(argv[1], "f") == 0 || strcmp(argv[1], "find") == 0) {
		file = fopen(NOTE_PATH, "r");
		char line[NOTE_MAX_LENGTH];
		int line_index = 0;
		int total_matches = 0;
		while(fgets(line, sizeof(line), file) != NULL) {
			int line_matches = 0;
			for(int arg_index = 2; arg_index < argc; arg_index++) {
				int arg_str_index = 0;
				int line_str_index = 0;
				int arg_matches = 0; // count of matches for just this argument
				while(line[line_str_index] != '\0') {
					if(line[line_str_index] == argv[arg_index][arg_str_index]) {
						arg_str_index++;
					} else {
						arg_str_index = 0;
					}
					if(argv[arg_index][arg_str_index] == '\0') {
						line_matches++;
						arg_matches++;
						arg_str_index = 0;
						break;
					}
					line_str_index++;
				}
				if(arg_matches == 0) {
					line_matches = 0;
					break;
				}
			}
			if(line_matches > 0) {
				printf("\033[0;31m%06i\033[0m %s", line_index, line);
				total_matches++;
			}
			line_index++;
		}
		if(total_matches == 0) {
			printf("No matches found!\n");
		}
		fclose(file);
		return 0;
	}

	// list
	if(strcmp(argv[1], "l") == 0 || strcmp(argv[1], "list") == 0) {
		if(argc > 2 && strcmp(argv[2], "archive") == 0) {
			file = fopen(ARCHIVE_PATH, "r");
			if(file == NULL) {
				printf("No archive file exists! It will be created once you archive a note.\n");
				return 1;
			}
		} else {
			file = fopen(NOTE_PATH, "r");
		}
		char line[NOTE_MAX_LENGTH];
		int line_count = 0;
		while(fgets(line, sizeof(line), file) != NULL) {
			printf("\033[0;31m%06i\033[0m %s", line_count, line);
			line_count++;
		}
		fclose(file);
		return 0;
	}

	// amend
	if(strcmp(argv[1], "amend") == 0) {
		file = fopen(NOTE_PATH, "r");
		FILE* out_file;
		out_file = fopen(NOTE_TMP_PATH, "w");
		char line[NOTE_MAX_LENGTH];
		int line_count = 0;
		while(fgets(line, sizeof(line), file)) {
			line_count++;
			if(line_count == atoi(argv[2]) + 1) {
				fprintf(out_file, "%s\n", argv[3]);
				continue;
			}
			fprintf(out_file, line);
		}
		fclose(out_file);
		fclose(file);
		remove(NOTE_PATH);
		rename(NOTE_TMP_PATH, NOTE_PATH);
		printf("Note %s updated!\n", argv[2]);
		return 0;
	}

	// remove
	if(strcmp(argv[1], "remove") == 0) {
		file = fopen(NOTE_PATH, "r");
		FILE* out_file;
		out_file = fopen(NOTE_TMP_PATH, "w");
		char line[NOTE_MAX_LENGTH];
		int line_count = 0;
		while(fgets(line, sizeof(line), file)) {
			line_count++;
			if(line_count == atoi(argv[2]) + 1) {
				continue;
			}
			fprintf(out_file, line);
		}
		fclose(out_file);
		fclose(file);
		remove(NOTE_PATH);
		rename(NOTE_TMP_PATH, NOTE_PATH);
		printf("Note %s archived!\n", argv[2]);
		return 0;
	}

	// archive
	if(strcmp(argv[1], "archive") == 0) {
		file = fopen(NOTE_PATH, "r");
		FILE* out_file;
		out_file = fopen(NOTE_TMP_PATH, "w");
		FILE* archive;
		archive = fopen(ARCHIVE_PATH, "a");
		char line[NOTE_MAX_LENGTH];
		int line_count = 0;
		while(fgets(line, sizeof(line), file)) {
			line_count++;
			if(line_count == atoi(argv[2]) + 1) {
				fprintf(archive, line);
				continue;
			}
			fprintf(out_file, line);
		}
		fclose(archive);
		fclose(out_file);
		fclose(file);
		remove(NOTE_PATH);
		rename(NOTE_TMP_PATH, NOTE_PATH);
		printf("Note %s archived!\n", argv[2]);
		return 0;
	}

	// <id>
	int argv_id = atoi(argv[1]);
	if(argv_id != 0) {
		file = fopen(NOTE_PATH, "r");
		char line[NOTE_MAX_LENGTH];
		int line_count = 0;
		while(fgets(line, sizeof(line), file)) {
			if(line_count == argv_id) {
				printf("\033[0;31m%06i\033[0m %s", argv_id, line);
				break;
			}
			line_count++;
		}
		fclose(file);
		return 0;
	}

	// clear
	if(strcmp(argv[1], "clear") == 0) {
		if(argc > 2 && strcmp(argv[2], "archive")) {
			file = fopen(ARCHIVE_PATH, "w");
		} else {
			file = fopen(NOTE_PATH, "w");
		}
		fclose(file);
		printf("All notes cleared!\n");
		return 0;
	}

	// <note_string>
	file = fopen(NOTE_PATH, "a");
	fprintf(file, "%s\n", argv[1]);
	fclose(file);
	printf("Note created.\n");
	return 0;
}

