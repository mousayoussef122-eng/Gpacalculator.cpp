#include <iostream>

#include <string> 

#include <vector>



using namespace std;



// 1. Data entry function with input validation

void addCourses(vector<string> &courses, vector<int> &credits, vector<string> &grades) {

    int courseCount;

    cout << "How many courses you want to add? ";

    cin >> courseCount;



    for (int i = 0; i < courseCount; i++) {

        string course;

        cout << "\nEnter course name: ";

        cin >> course;

        courses.push_back(course);



        int creditsHours;

        cout << "Enter credit hours (e.g., 2, 3): ";

        while (!(cin >> creditsHours)) {

            cout << "Invalid input! Please enter a valid number for credit hours: ";

            cin.clear();

            cin.ignore(10000, '\n');

        }

        credits.push_back(creditsHours);



        string grade;

        cout << "Enter grade (e.g., A, B+, or 90): ";

        cin >> grade;

        grades.push_back(grade);

        cout << "-------------------------\n";

    }

}



// 2. Helper function: Converts letter or number string into point value

double gradeToPoints(string g) {

    if (g == "A+" || g == "a+") return 4.0;

    if (g == "A" || g == "a") return 4.0;

    if (g == "A-" || g == "a-") return 3.7;

    if (g == "B+" || g == "b+") return 3.3;

    if (g == "B" || g == "b") return 3.0;

    if (g == "B-" || g == "b-") return 2.7;

    if (g == "C+" || g == "c+") return 2.3;

    if (g == "C" || g == "c") return 2.0;

    if (g == "C-" || g == "c-") return 1.7;

    if (g == "D+" || g == "d+") return 1.3;

    if (g == "D" || g == "d") return 1.0;

    if (g == "D-" || g == "d-") return 0.7;

    if (g == "F" || g == "f") return 0.0;



    // If it's a numeric grade (like "90" or "3.5")

    double score = stod(g);

    if (score > 4.0) {

        if (score >= 90) return 4.0;

        else if (score >= 85) return 3.7;

        else if (score >= 80) return 3.3;

        else if (score >= 75) return 3.0;

        else if (score >= 70) return 2.7;

        else if (score >= 65) return 2.3;

        else if (score >= 60) return 2.0;

        else if (score >= 50) return 1.0;

        else return 0.0;

    }

    return score;

}



// 3. Transcript summary function

void printTranscript(const vector<string>& courses, const vector<int>& credits, const vector<string>& grades) {

    cout << "\n==============================\n";

    cout << "         COURSE SUMMARY       \n";

    cout << "==============================\n";

    for (size_t i = 0; i < courses.size(); i++) {

        double points = gradeToPoints(grades[i]);

        cout << "Course: " << courses[i] 

             << " | Credits: " << credits[i] 

             << " | Grade: " << grades[i] 

             << " (Points: " << points << ")" << endl;

    }

    cout << "------------------------------\n";

}



// 4. GPA calculation function

double calculateGPA(const vector<string>& grades, const vector<int>& credits) {

    double totalPoints = 0;

    int totalCredits = 0;



    for (size_t i = 0; i < grades.size(); i++) {

        double points = gradeToPoints(grades[i]);

        totalPoints += points * credits[i];

        totalCredits += credits[i];

    }



    if (totalCredits == 0) return 0.0;

    return totalPoints / totalCredits;

}



int main() {

    vector<string> courses;

    vector<int> credits;

    vector<string> grades;



    addCourses(courses, credits, grades);



    // Print the detailed transcript summary

    printTranscript(courses, credits, grades);



    // Calculate and display final GPA

    double finalGPA = calculateGPA(grades, credits);

    cout << "Your Cumulative GPA is: " << finalGPA << endl;



    return 0;

}