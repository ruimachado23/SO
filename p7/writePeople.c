#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p) {
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    Person p;

    /* Validate number of arguments */
    if (argc != 2) {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if (fp == NULL) {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    printf("Quantas pessoas pretende considerar? ");
    int people;
    if (scanf("%d", &people) != 1) { // Ensure that an integer was read
        perror("Error reading number of people");
        fclose(fp);
        return EXIT_FAILURE;
    }
    getchar(); // Clear the input buffer

    /* Write 'people' items to a file */
    for (int i = 1; i <= people; i++) {
        printf("\n---------- Person %d ----------\n", i);

        printf("Name: ");
        fgets(p.name, sizeof(p.name), stdin);
        p.name[strcspn(p.name, "\n")] = 0; // Remove newline character

        printf("Age: ");
        scanf("%d", &p.age);

        printf("Height: ");
        scanf("%lf", &p.height);
        getchar(); // Clear the input buffer

        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
