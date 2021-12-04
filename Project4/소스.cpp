#include <iostream>
#include <string>
using namespace std;


int Totalscore(int a, int b, int c, int d, int e);
double Totalscore(double a, double b, double c, double d, double e);

int main() {
    string a;
    cout << "Are you scores integer? (y or n )";
    cin >> a;
    if (a == "y") {
        int midterm, finalexam, attendance, assignment, lab;
        cout << "Enter your scores for miditerm, final exam, attendance, assignment, and lab:";
        cin >> midterm >> finalexam >> attendance >> assignment >> lab;
        if (midterm <= 100 && finalexam <= 100 && attendance <= 100 && assignment <= 100 && lab <= 100) {
            cout << "your total score is " << Totalscore(midterm, finalexam, attendance, assignment, lab) << endl;
        }
        else {
            cout << "Enter your score again! (your score <= 100) ";
        }
    }
    else if (a == "n") {
        double midterm, finalexam, attendance, assignment, lab;
        cout << "Enter your scores for miditerm, final exam, attendance, assignment, and lab:";
        cin >> midterm >> finalexam >> attendance >> assignment >> lab;
        if (midterm <= 100 && finalexam <= 100 && attendance <= 100 && assignment <= 100 && lab <= 100) {
            cout << "your total score is " << Totalscore(midterm, finalexam, attendance, assignment, lab) << endl;
        }
        else {
            cout << "Enter your score again! (your score <= 100) ";
        }
    }
    else {
        cout << " I can't receive text messages. ";
    }
}

int Totalscore(int a, int b, int c, int d, int e) {
    return (a * 0.3) + (b * 0.3) + (c * 0.1) + (d * 0.2) + (e * 0.1);
}

double Totalscore(double a, double b, double c, double d, double e) {
    return (a * 0.3) + (b * 0.3) + (c * 0.1) + (d * 0.2) + (e * 0.1);
}