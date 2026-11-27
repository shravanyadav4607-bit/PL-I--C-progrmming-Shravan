/*
Program (41) -> Write a program to create a file, store the details of a student (Roll No., Name, and Marks),
                and display the stored data.
Solution: File Handling
*/

#include <stdio.h>

int main() {
    FILE *fp;
    int roll_no;
    char name[50];
    float marks;
    int ch;

    // Take student details from the user
    printf("Enter Roll Number: ");
    scanf("%d", &roll_no);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name); // Reads full name including spaces

    printf("Enter Marks: ");
    scanf("%f", &marks);

    // Create and open file in write mode
    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    // Write student details into the file
    fprintf(fp, "Roll Number: %d\n", roll_no);
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Marks: %.2f\n", marks);

    // Close the file after writing
    fclose(fp);
    printf("\nStudent details stored successfully!\n");

    // Open the file in read mode
    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Read and display stored data character by character
    printf("\n----- Student Details -----\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    // Close the file after reading
    fclose(fp);

    return 0;
}
