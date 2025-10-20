#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 3


float calculateAverage(int marks[]) {
    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        total += marks[i];
    }
    return total / 3.0;
}


const char* getGrade(float average) {
    if (average >= 80) return "Grade A";
    else if (average >= 60) return "Grade B";
    else if (average >= 40) return "Grade C";
    else return "Fail";
}


int findTopper(int marks[][NUM_SUBJECTS]) {
    int highestTotal = 0;
    int topperIndex = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            total += marks[i][j];
        }
        if (total > highestTotal) {
            highestTotal = total;
            topperIndex = i;
        }
    }
    return topperIndex;
}

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS] = {
        {50, 60, 70},
        {80, 90, 100},
        {30, 40, 50}
    };

    char studentNames[NUM_STUDENTS][10] = {"Ali", "Bob", "Cat"};

    for (int i = 0; i < NUM_STUDENTS; i++) {
        float average = calculateAverage(marks[i]);
        printf("%s - Average: %.2f | %s\n", studentNames[i], average, getGrade(average));
    }

 
    int topperIndex = findTopper(marks);
    int topperTotal = 0;
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        topperTotal += marks[topperIndex][j];
    }

    printf("\nTopper: %s with total marks = %d\n", studentNames[topperIndex], topperTotal);

    return 0;
}
