#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50
#define MAX_DEADLINE_LENGTH 11

// Arrays to store task details
char taskNames[MAX_TASKS][MAX_NAME_LENGTH];
char taskDeadlines[MAX_TASKS][MAX_DEADLINE_LENGTH];
int taskPriorities[MAX_TASKS];
int taskStatus[MAX_TASKS];
int totalTasks = 0;

// Function to display the main menu
void displayMenu() {
    printf("\n--- Task Manager ---\n");
    printf("1. Add a new task\n");
    printf("2. View tasks\n");
    printf("3. Edit a task\n");
    printf("4. Delete a task\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new task
void addTask() {
    if (totalTasks >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }

    printf("\nEnter task name: ");
    scanf(" %[^\n]", taskNames[totalTasks]);

    printf("Enter task deadline (YYYY-MM-DD): ");
    scanf(" %s", taskDeadlines[totalTasks]);

    printf("Enter task priority (1-5): ");
    scanf("%d", &taskPriorities[totalTasks]);

    taskStatus[totalTasks] = 1;
    totalTasks++;
    printf("Task added successfully!\n");
}

// Function to display all tasks
void viewTasks() {
    if (totalTasks == 0) {
        printf("\nNo tasks available.\n");
        return;
    }

    printf("\n--- Task List ---\n");
    for (int i = 0; i < totalTasks; i++) {
        if (taskStatus[i] == 1) {
            printf("Task %d:\n", i + 1);
            printf("  Name: %s\n", taskNames[i]);
            printf("  Deadline: %s\n", taskDeadlines[i]);
            printf("  Priority: %d\n", taskPriorities[i]);
            printf("-----------------------\n");
        }
    }
}

// Function to edit a task
void editTask() {
    if (totalTasks == 0) {
        printf("\nNo tasks to edit.\n");
        return;
    }

    int taskNumber;
    printf("\nEnter the task number to edit: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > totalTasks || taskStatus[taskNumber - 1] == 0) {
        printf("Invalid task number.\n");
        return;
    }

    printf("Editing Task %d:\n", taskNumber);

    printf("Enter new task name: ");
    scanf(" %[^\n]", taskNames[taskNumber - 1]);

    printf("Enter new task deadline (YYYY-MM-DD): ");
    scanf(" %s", taskDeadlines[taskNumber - 1]);

    printf("Enter new task priority (1-5): ");
    scanf("%d", &taskPriorities[taskNumber - 1]);

    printf("Task updated successfully!\n");
}

// Function to delete a task
void deleteTask() {
    if (totalTasks == 0) {
        printf("\nNo tasks to delete.\n");
        return;
    }

    int taskNumber;
    printf("\nEnter the task number to delete: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > totalTasks || taskStatus[taskNumber - 1] == 0) {
        printf("Invalid task number.\n");
        return;
    }

    taskStatus[taskNumber - 1] = 0;
    printf("Task %d deleted successfully!\n", taskNumber);
}

// Main function
int main() {
    int userChoice;

    do {
        displayMenu();
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                editTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (userChoice != 5);

    return 0;
}
