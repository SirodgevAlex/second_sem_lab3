#pragma once

#include <iostream>

using namespace std;

template<class T>
class Student {
private:
    string institute;
    int age;
    int growth;
    int number;
public:
    Student() {
        this->institute = "none";
        this->age = 0;
        this->growth = 0;
        this->number = 0;
    }

    Student(string institute, int age, int growth, int number) {
        this->institute = institute;
        this->age = age;
        this->growth = growth;
        this->number = number;
    }

    string GetInstitute() {
        return this->institute;
    }

    int GetAge() {
        return this->age;
    }

    int GetGrowth() {
        return this->growth;
    }

    int GetNumber() {
        return this->number;
    }
};

template <typename T>
bool operator > (Student<T> s1, Student<T> s2) {
    if (s1.institute > s2.institute) {
        return 1;
    } else if (s1.institute < s2.institute) {
        return 0;
    }
    if (s1.age > s2.age) {
        return 1;
    } else if (s1.age < s2.age) {
        return 0;
    }
    if (s1.growth > s2.growth) {
        return 1;
    } else if (s1.growth < s2.growth) {
        return 0;
    }
    return 0;
}

template <typename T>
bool operator < (Student<T> s1, Student<T> s2) {
    if (s1.institute > s2.institute) {
        return 0;
    } else if (s1.institute < s2.institute) {
        return 1;
    }
    if (s1.age > s2.age) {
        return 0;
    } else if (s1.age < s2.age) {
        return 1;
    }
    if (s1.growth > s2.growth) {
        return 0;
    } else if (s1.growth < s2.growth) {
        return 1;
    }
    return 0;
}

template <typename T>
bool operator == (Student<T> s1, Student<T> s2) {
    if (s1.institute > s2.institute) {
        return 0;
    } else if (s1.institute < s2.institute) {
        return 0;
    }
    if (s1.age > s2.age) {
        return 0;
    } else if (s1.age < s2.age) {
        return 0;
    }
    if (s1.growth > s2.growth) {
        return 0;
    } else if (s1.growth < s2.growth) {
        return 0;
    }
    return 0;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, Student<T> &student)
{
    out << "institute " << student->GetInstitute() << '\n';
    out << "age " << student->GetAge() << '\n';
    out << "growth " << student->GetGrowth() << '\n';
    out << "number " << student->GetNumber() << '\n';
    return out;
}

template <typename T>
std::istream& operator>> (std::istream &in, Student<T> &student)
{
    cout << "input institute growth age number\n";
    string institute;
    in >> institute;
    int growth;
    in >> growth;
    int age;
    in >> age;
    int number;
    in >> number;
    return in;
}