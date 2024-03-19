



#include <stdio.h>
#include <string.h>
int maxauth;
char *inputf = "ref.bib";      //  input bib file
char *outputf = "output.bib";  // output bib file
FILE *inputFile, *outputFile;
char copyLine[565];
char line[512];

int main() {

 printf("\n");
    printf("                          Welcome to BibEditor                                \n");
    printf("\n\n");

    printf("BibEditor is an experimental program to limit the number of authors in the given .bib file.\n");
    printf("Motivation for the program is nothing but I found that when adding bibliography in LaTeX\n");
    printf("simply by using \\bibliography will display all the authors, and I felt it is pain-in-ass \n");
    printf("to manually edit each line of authors in a .bib file.\n\n");

    printf("This program will ask you for the number of authors you want to display and simply remove all other\n");
    printf("authors and put an et.al at the tail. Simple :)\n\n");

    printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
    printf("        HOW TO USE\n");
    printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n\n");

    printf("1) Place your ref.bib file in the same folder.\n\n");

    
    printf("IMPORTANT: [ Rename it to \"ref.bib\" (without quotations) if .bib file has a different name. ]\n\n");

    printf("2) Run the program it will ask you for the number of maximum authors. Give what it asks! \n\n");

    printf("3) Press ENTER, and take a few deep breaths ;)\n\n");

    printf("4) Your modified .bib will be generated as output.bib\n\n");

    printf("5) Verify for errors.\n\n");

    printf("6) If you have any questions or need assistance:\n\n");

    printf("   Contact Information:\n");
    printf("   - Author: SOORAJ NHALOOR\n");
    printf("   - Email: soorajnhaloor123@gmail.com\n");
    printf("   - Website: sooraj-nhaloor.github.io\n\n");

    printf("════════════════════════════════════════════════════════════════════════════════\n");
    printf("\n\n");
    printf("\n\n");
    printf("Enter the number of maximum authors : ");
    scanf( "%d",&maxauth);
     printf("\n\n");
    printf("\n\n");
     printf("==============================================================================\n");
     printf("======================  LOGS  ================================================\n");
     printf("==============================================================================\n\n");
    inputFile = fopen(inputf, "r");    
    outputFile = fopen(outputf, "w");  

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files. Please read Readme.txt or see above ^\n");
        return 1;
    } else {
        char pattern[] = "author = {";  
        while (fgets(line, sizeof(line), inputFile)) {
            if (strstr(line, pattern) != NULL) {
                printf("Pattern found in this line: %s", line);
                int commaCount = 0;
                for (int i = 0; i < strlen(line); i++) {
                    if (line[i] == ',') {
                        commaCount++;
                        if (commaCount >= maxauth) {
                            copyLine[i] = line[i];
                        line[i] = '\0';


                            fprintf(outputFile, "%s %s et.al}\n",line,copyLine);
                            break;
                        } /////////////////
                      
                    }
                }
                if (commaCount < maxauth) {
                    fprintf(outputFile,"%s",line);
                }
            } else {
                fprintf(outputFile, "%s", line);  // Write unmodified line to the output file
            }
        }

        fclose(inputFile);
        fclose(outputFile);
    }

    return 0;
}
