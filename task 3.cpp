#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
    public:
        string course_code;
        string course_name;

        Course(const string& course_code, const string& course_name) : course_code(course_code), course_name(course_name) {}
};

class Grade {
    public:
        int mark;
        char the_grade;

        Grade(int mark) : mark(mark), the_grade('-') {}

        void calculateGrade() {
            if (mark > 69) {
                the_grade = 'A';
            } else if (mark > 59) {
                the_grade = 'B';
            } else if (mark > 49) {
                the_grade = 'C';
            } else if (mark > 39) {
                the_grade = 'D';
            } else {
                the_grade = 'E';
            }
        }
};

class Student {
    public:
        string registration_number;
        string name;
        int age;
        Course course;
        vector<Grade> grades;

        Student(const string& registration_number, const string& name, int age, const Course& course) : registration_number(registration_number), name(name), age(age), course(course) {}

        void addMark(int mark) {
            if (mark >= 0 && mark <= 100) {
                grades.push_back(Grade(mark));
                grades.back().calculateGrade();
            } else {
                cout << "Invalid mark. It should be between 0 and 100." << endl;
            }
        }

        void displayDetails() {
            cout << "Registration Number: " << registration_number << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Course Code: " << course.course_code << endl;
            cout << "Course Name: " << course.course_name << endl;
            cout << "Grades: ";
            for (const Grade& grade : grades) {
                cout << grade.mark << " (" << grade.the_grade << "), ";
            }
            cout << endl;
        }
};

class StudentSystem {
    private:
        vector<Student> students;

    public:
        void addStudent(const Student& student) {
            students.push_back(student);
        }

        void editStudentDetails(int index, const string& name, int age) {
            students[index].name = name;
            students[index].age = age;
        }

        void displayStudentDetails(int index) {
            students[index].displayDetails();
        }
};

int main() {
    StudentSystem system;

    // Add students
    Student student1("1234567890", "John Doe", 20, Course("CS101", "Computer Science"));
    system.addStudent(student1);

    // Edit student details
    system.editStudentDetails(0, "John Doe Updated", 21);

    // Add marks and calculate grades
    system.students[0].addMark(75);
    system.students[0].addMark(65);

    // Display student details
    system.displayStudentDetails(0);

    return 0;
}