#include <iostream>
#include <string>

using namespace std;

struct Course {
    string course_code;
    string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    string registration_number;
    string name;
    int age;
    Course course;
    Grade grades[5];
    int num_of_subjects;
};

class StudentSystem {
    private:
        Student students[40];
        int num_of_students;

    public:
        StudentSystem() : num_of_students(0) {}

        void addStudent(const Student& student) {
            if (num_of_students < 40) {
                students[num_of_students++] = student;
            } else {
                cout << "Cannot add more than 40 students." << endl;
            }
        }

        void editStudentDetails(int index, const string& name, int age) {
            students[index].name = name;
            students[index].age = age;
        }

        void addMarks(int index, int subject_index, int mark) {
            if (mark >= 0 && mark <= 100) {
                students[index].grades[subject_index].mark = mark;
                calculateGrade(students[index].grades[subject_index]);
            } else {
                cout << "Invalid mark. It should be between 0 and 100." << endl;
            }
        }

        void calculateGrade(Grade& grade) {
            if (grade.mark > 69) {
                grade.the_grade = 'A';
            } else if (grade.mark > 59) {
                grade.the_grade = 'B';
            } else if (grade.mark > 49) {
                grade.the_grade = 'C';
            } else if (grade.mark > 39) {
                grade.the_grade = 'D';
            } else {
                grade.the_grade = 'E';
            }
        }

        void displayStudentDetails(int index) {
            cout << "Registration Number: " << students[index].registration_number << endl;
            cout << "Name: " << students[index].name << endl;
            cout << "Age: " << students[index].age << endl;
            cout << "Course Code: " << students[index].course.course_code << endl;
            cout << "Course Name: " << students[index].course.course_name << endl;
            cout << "Grades: ";
            for (int i = 0; i < students[index].num_of_subjects; i++) {
                cout << students[index].grades[i].mark << " (" << students[index].grades[i].the_grade << "), ";
            }
            cout << endl;
        }
};

int main() {
    StudentSystem system;

    // Add students
    Student student1 = {"1234567890", "John Doe", 20, {"CS101", "Computer Science"}, {}};
    system.addStudent(student1);

    // Edit student details
    system.editStudentDetails(0, "John Doe Updated", 21);

    // Add marks and calculate grades
    system.addMarks(0, 0, 75);
    system.addMarks(0, 1, 65);

    // Display student detailss
    system.displayStudentDetails(0);

    return 0;
}