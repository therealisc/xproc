#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAXCHAR 1000

#define MAX_LINE_LEN 1024
#define MAX_FIELDS   100 
#define DELIMITER    ","   


void trim_newline(char *str) {
  size_t len = strlen(str);
  while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {

       str[len - 1] = '\0';
len--;
    }
}


void read() {
    FILE *fpt;
    char line [MAXCHAR];
    fpt = fopen("sc.csv", "r");
    
    while (fgets(line, sizeof(line), fpt)) {
	            trim_newline(line);


    if (strlen(line) == 0) {
       continue;
    }

    char *fields[MAX_FIELDS];
    int field_count = 0;
    char *token = strtok(line, DELIMITER);
    while (token != NULL && field_count < MAX_FIELDS) {
	    fields[field_count++] = token;
	    token = strtok(NULL, DELIMITER);
    }

    //printf("Row with %d fields:\n", field_count);
    for (int i = 0; i < field_count; i++) {
	    //printf("  Field %d: '%s'\n", i + 1, fields[i]);
	    printf("%d'%s'\n", i + 1, fields[i]);
    }
    }
    fclose(fpt);
}

void write(FILE *fpt, int id, char name[]) {
    fpt = fopen("sc.csv", "a");
    //fprintf(fpt,"move; article\n");
    fprintf(fpt,"%s; %s\n", id, name);
    fclose(fpt);
}
// argc is the number of words: prog -h new (3) 
int main(int argc, char *argv[]) {
    FILE *fpt;
    int opt;
    time_t raw_time;
    struct tm *time_info;
    time_info = localtime(&raw_time);
	while ((opt = getopt(argc,
	    argv, "ab:c:")) != -1) {
		switch (opt) {
		case 'a':
		read(); break;
		break;
		case 'b':
		write(fpt, time_info, argv[2]); read(); break;
		case 'c':
                  break;
		default:
		  fprintf(stderr, "Usage: &s[-a] [-b value] [-c value]\n", argv[0]);
		return 1;
	        }
         }
return 0;
}
