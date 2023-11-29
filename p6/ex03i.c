#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char text[1024];
    FILE *logFile = fopen("command.log", "a"); // Open command.log in append mode

    if (logFile == NULL) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        if(strcmp(text, "end") != 0) {
            // Get current time
            time_t rawtime;
            struct tm *timeinfo;
            char timeBuffer[80];

            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", timeinfo);

            // Log command with timestamp
            fprintf(logFile, "[%s] %s\n", timeBuffer, text);

            printf("\n * Command to be executed: %s\n", text);
            printf("---------------------------------\n");
            system(text);
            printf("---------------------------------\n");
        }
    } while(strcmp(text, "end") != 0);

    printf("-----------The End---------------\n");
    fclose(logFile); // Close the log file
    return EXIT_SUCCESS;
}
