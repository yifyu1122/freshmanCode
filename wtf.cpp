#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// �ǥ͵��c
struct Student {
    string name;
    int midtermScore;
    int finalScore;
};

// �p���`���Z���禡
double calculateTotalScore(int midterm, int final) {
    return midterm * 0.4 + final * 0.6;
}

// �s�W�ǥ͸�ƪ��禡
void addStudent(Student* students, int& count) {
    if (count < 100) {  // ���]�̦h�u��100��ǥ�
        cout << "�п�J�ǥͩm�W�G ";
        cin >> students[count].name;
        cout << "�п�J�����Ҧ��Z�G ";
        cin >> students[count].midtermScore;
        cout << "�п�J�����Ҧ��Z�G ";
        cin >> students[count].finalScore;
        count++;
        cout << "�ǥ͸�Ʒs�W���\�I" << endl;
    } else {
        cout << "�ǥ͸�Ƥw���A�L�k�s�W��h�ǥ͡C" << endl;
    }
}

// �d�߾ǥ͸�ƪ��禡
void searchStudent(const Student* students, int count) {
    string searchName;
    cout << "�п�J���d�ߪ��ǥͩm�W�G ";
    cin >> searchName;

    for (int i = 0; i < count; ++i) {
        if (students[i].name == searchName) {
            cout << "�ǥͩm�W: " << students[i].name << endl;
            cout << "�����Ҧ��Z: " << students[i].midtermScore << endl;
            cout << "�����Ҧ��Z: " << students[i].finalScore << endl;
            cout << "�`���Z: " << calculateTotalScore(students[i].midtermScore, students[i].finalScore) << endl;
            return;
        }
    }

    cout << "�d�L���H" << endl;
}

// ��ܯZ�Ŧ��Z�檺�禡
void displayClassReport(const Student* students, int count) {
    // �_�w�ƧǡA���`���Z�q���ܧC�Ƨ�
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (calculateTotalScore(students[j].midtermScore, students[j].finalScore) <
                calculateTotalScore(students[j + 1].midtermScore, students[j + 1].finalScore)) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "�Z�Ŧ��Z��G" << endl;
    cout << "�ǥͩm�W\t�����Ҧ��Z\t�����Ҧ��Z\t�`���Z" << endl;
    for (int i = 0; i < count; ++i) {
        cout << students[i].name << '\t' << students[i].midtermScore << '\t' << students[i].finalScore << '\t'
             << calculateTotalScore(students[i].midtermScore, students[i].finalScore) << endl;
    }
}

int main() {
    Student students[100];  // ���]�̦h�u��100��ǥ�
    int count = 0;

    while (true) {
        cout << "======== �\��ﶵ�� ========" << endl;
        cout << "1. �s�W�ǥ͸��" << endl;
        cout << "2. �d�߾ǥ͸��" << endl;
        cout << "3. ��ܯZ�Ŧ��Z��" << endl;
        cout << "4. ���}�t��" << endl;
        cout << "============================" << endl;

        int choice;
        cout << "�п�J�z����ܡG ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                searchStudent(students, count);
                break;
            case 3:
                displayClassReport(students, count);
                break;
            case 4:
                cout << "���¨ϥΡA�q�Ы��СI" << endl;
                return 0;
            default:
                cout << "��J�L�ġA�Э��s��J�C" << endl;
        }
    }

    return 0;
}

