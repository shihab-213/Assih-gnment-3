#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 3

// Function to calculate average marks of a student
float calculateAverage(int marks[]) {
    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        total += marks[i];
    }
    return total / 3.0;
}

// Function to return grade based on average marks
const char* getGrade(float average) {
    if (average >= 80) return "Grade A";
    else if (average >= 60) return "Grade B";
    else if (average >= 40) return "Grade C";
    else return "Fail";
}

// Function to find index of the student with the highest total marks
int findTopper(int marks[][NUM_SUBJECTS]) {
    int highestTotal = 0;
    int topperIndex = 0;

    for (int student = 0; student < NUM_STUDENTS; student++) {
        int total = 0;
        for (int subject = 0; subject < NUM_SUBJECTS; subject++) {
            total += marks[student][subject];
        }
        if (total > highestTotal) {
            highestTotal = total;
            topperIndex = student;
        }
    }
    return topperIndex;
}

int main() {
    // Sample data: student names and their marks in 3 subjects
    int marks[NUM_STUDENTS][NUM_SUBJECTS] = {
        {50, 60, 70},
        {80, 90, 100},
        {30, 40, 50}
    };
    char studentNames[NUM_STUDENTS][10] = {"Ali", "Bob", "Cat"};

    printf("---- Student Results ----\n\n");

    // Display the result of each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        float average = calculateAverage(marks[i]);
        printf("Student: %s | Average: %.2f | %s\n", studentNames[i], average, getGrade(average));
    }

    // Find the topper and calculate his/her total marks
    int topperIndex = findTopper(marks);
    int topperTotal = 0;
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        topperTotal += marks[topperIndex][j];
    }

    printf("\n--------------------------\n");
    printf("Topper: %s with Total Marks = %d\n", studentNames[topperIndex], topperTotal);
    printf("--------------------------\n");

    return 0;
}
