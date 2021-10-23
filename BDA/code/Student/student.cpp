#include "bits/stdc++.h"
using namespace std;

class Student
{
public:
    string name;
    string er_no;
    int mark1;
    int mark2;

    Student(string name, string er_no, int mark1, int mark2)
    {
        this->name = name;
        this->er_no = er_no;
        this->mark1 = mark1;
        this->mark2 = mark2;
    }
};

class MasterStudent : public Student
{
public:
    int mark3;

    MasterStudent(string name, string er_no, int mark1, int mark2, int mark3) : Student(name, er_no, mark1, mark2)
    {
        this->mark3 = mark3;
    }
};

double search(string key, vector<Student> &students)
{
    for (auto x : students)
    {
        if (x.name == key)
        {
            return (double)(x.mark1 + x.mark2) / 2.0;
        }
        if (x.er_no == key)
        {
            return (double)(x.mark1 + x.mark2) / 2.0;
        }
    }
    return -1;
}

double search(string key, vector<MasterStudent> &ms)
{
    for (auto x : ms)
    {
        if (x.name == key)
        {
            return (double)(x.mark1 + x.mark2 + x.mark3) / 3.0;
        }
        if (x.er_no == key)
        {
            return (double)(x.mark1 + x.mark2 + x.mark3) / 3.0;
        }
    }
    return -1;
}

int32_t main()
{
    vector<Student> students;

    students.push_back(Student("John", "CE044", 98, 95));
    students.push_back(Student("Mary", "CE045", 95, 91));
    students.push_back(Student("Doe", "CE046", 90, 93));
    students.push_back(Student("Harsh", "CE047", 94, 97));
    students.push_back(Student("Raj", "CE048", 91, 92));
    students.push_back(Student("Jugal", "CE049", 92, 93));
    students.push_back(Student("Rutvik", "CE050", 93, 94));
    students.push_back(Student("Parth", "CE051", 94, 95));
    students.push_back(Student("Krunal", "CE052", 95, 96));
    students.push_back(Student("Dishen", "CE053", 98, 97));

    string s;
    cout << "You want to add extra column?" << endl;
    cin >> s;

    vector<MasterStudent> master_students;
    if (s == "Yes" || s == "yes")
    {
        string key;
        int data;

        cout << "Enter the name of the student : " << endl;
        cin >> key;
        cout << "Enter the mark of the student : " << endl;
        cin >> data;

        for (auto x : students)
        {
            if (x.name == key)
            {
                master_students.push_back(MasterStudent(x.name, x.er_no, x.mark1, x.mark2, data));
            }
            else
            {
                master_students.push_back(MasterStudent(x.name, x.er_no, x.mark1, x.mark2, 0));
            }
        }
    }

    string key;
    cout << "Enter key value for search : " << endl;
    cin >> key;

    double ans;

    if (s == "Yes" || s == "yes")
    {
        ans = search(key, master_students);
    }
    else
    {
        ans = search(key, students);
    }

    if (ans == -1)
    {
        cout << "Key not found" << endl;
    }
    else
    {
        cout << "Avg of students is : " << ans << endl;
    }

    return 0;
}