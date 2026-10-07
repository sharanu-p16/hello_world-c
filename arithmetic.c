#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LEN 50

typedef struct {
    int roll_no;
    char name[NAME_LEN];
    float marks;
} Student;

void display_students(const Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

int main(void) {
    Student records[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Database full!\n");
                    break;
                }
                printf("Enter Roll Number: ");
                scanf("%d", &records[count].roll_no);
                getchar(); // clear leftover newline

                printf("Enter Name: ");
                fgets(records[count].name, NAME_LEN, stdin);
                records[count].name[strcspn(records[count].name, "\n")] = '\0'; // trim newline

                printf("Enter Marks: ");
                scanf("%f", &records[count].marks);

                count++;
                printf("Record added successfully!\n");
                break;

            case 2:
                display_students(records, count);
                break;

            case 3:
                printf("Exiting application.\n");
                break;

            default:
                printf("Invalid selection! Please enter 1, 2, or 3.\n");
        }
    } while (choice != 3);

    return 0;
}