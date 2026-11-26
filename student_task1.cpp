#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;
    static int studentCount;

public:
    // Parameterized constructor
    Student(int roll, string studentName, float studentMarks) {
        rollNo = roll;
        name = studentName;
        marks = studentMarks;
        studentCount++;
    }

    // Overloaded functions
    void display() const {
        cout << "Roll No: " << rollNo << " | Name: " << name
             << " | Marks: " << marks << "/100" << endl;
    }

    void display(bool showResult) const {
        display();
        if (showResult) {
            cout << "Result: " << (marks >= 40 ? "PASS" : "FAIL") << endl;
        }
    }

    static int getStudentCount() {
        return studentCount;
    }

    // Friend function can access private data of Student objects
    friend void compareStudents(const Student& s1, const Student& s2);

    // Overload > to compare students by marks
    bool operator>(const Student& other) const {
        return marks > other.marks;
    }
};

int Student::studentCount = 0;

void compareStudents(const Student& s1, const Student& s2) {
    cout << "\nFriend function comparison:\n";
    if (s1.marks > s2.marks)
        cout << s1.name << " has higher marks than " << s2.name << ".\n";
    else if (s2.marks > s1.marks)
        cout << s2.name << " has higher marks than " << s1.name << ".\n";
    else
        cout << s1.name << " and " << s2.name << " have equal marks.\n";
}

int main() {
    Student s1(101, "Aarav", 85.5f);
    Student s2(102, "Diya", 92.0f);
    Student s3(103, "Rohan", 76.0f);

    cout << "===== STUDENT DETAILS =====\n";
    s1.display(true);
    s2.display();
    s3.display();

    cout << "\nTotal number of students: " << Student::getStudentCount() << endl;

    compareStudents(s1, s2);

    cout << "\nOverloaded > operator comparison:\n";
    if (s2 > s1)
        cout << "Diya has more marks than Aarav.\n";
    else
        cout << "Aarav has more marks than or equal to Diya.\n";

    return 0;
}
