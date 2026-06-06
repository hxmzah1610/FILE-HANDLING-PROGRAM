#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[100];

    /* CREATE AND WRITE TO FILE */
    fp = fopen("student.txt", "w");

    if (fp == NULL) {
        printf("File cannot be created.\n");
        return 1;
    }

    printf("Enter data to write into file: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);
    fclose(fp);

    printf("\nData written successfully.\n");

    /* READ FROM FILE */
    fp = fopen("student.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened for reading.\n");
        return 1;
    }

    printf("\nReading file contents:\n");

    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }

    fclose(fp);

    /* APPEND DATA TO FILE */
    fp = fopen("student.txt", "a");

    if (fp == NULL) {
        printf("File cannot be opened for appending.\n");
        return 1;
    }

    printf("\n\nEnter data to append: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);
    fclose(fp);

    printf("\nData appended successfully.\n");

    /* READ UPDATED FILE */
    fp = fopen("student.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("\nUpdated file contents:\n");

    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }

    fclose(fp);

    return 0;
}
