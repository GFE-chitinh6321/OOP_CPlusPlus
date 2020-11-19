#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;

class University;

class School
{
protected:
    char codeSchool[30];
    char nameSchool[30];
    char address[30];
public:
    void Input();
    void Output();
};

class Faculty
{
private:
    char codeFaculty[30];
    char nameFaculty[30];
    char managerFaculty[30];
public:
    friend class University;
    friend void ShowListFaculty(Faculty x[], int n);
    friend void ShowUniversityHasITFaculty(University a[], int k);
};

class Room
{
private:
    char codeRoom[30];
    char nameRoom[30];
    char date[30];
public:
    friend class University;
    friend void ShowListRoom(Room y[], int m);
};

class University : public School
{
private:
    Faculty *x;
    int n;
    Room *y;
    int m;
public:
    void Input();
    void Output();
    friend void ShowUniversityHasITFaculty(University a[], int k);
};

void School::Input()
{
    cout << "\t\tEnter code school: ";            fflush(stdin);          gets(codeSchool);
    cout << "\t\tEnter name school: ";            fflush(stdin);          gets(nameSchool);
    cout << "\t\tEnter address school: ";         fflush(stdin);          gets(address);
}

void School::Output()
{
    cout << setw(15) << codeSchool;
    cout << setw(15) << nameSchool;
    cout << setw(15) << address << endl;
}

void University::Input()
{
    School::Input();
    cout << "\tEnter amount of faculty: ";    cin >> n;
    x = new Faculty[n];
    for(int i=0; i<n; i++){
        cout << "\tEnter information of faculty " << i+1 << ": " << endl;
        cout << "\t\tEnter code faculty: ";            fflush(stdin);          gets(x[i].codeFaculty);
        cout << "\t\tEnter name faculty: ";            fflush(stdin);          gets(x[i].nameFaculty);
        cout << "\t\tEnter manager faculty: ";         fflush(stdin);          gets(x[i].managerFaculty);
    }
    cout << "\tEnter amount of room: ";       cin >> m;
    y = new Room[m];
    for(int i=0; i<m; i++){
        cout << "\tEnter information of room " << i+1 << ": " << endl;
        cout << "\t\tEnter code room: ";               fflush(stdin);          gets(y[i].codeRoom);
        cout << "\t\tEnter name room: ";               fflush(stdin);          gets(y[i].nameRoom);
        cout << "\t\tEnter date create room: ";        fflush(stdin);          gets(y[i].date);
    }
}

void InputListUniversity(University a[], int k)
{
    for(int i=0; i<k; i++){
        cout << "\tEnter information of University " << i+1 << ": " << endl;
        a[i].Input();
    }
}

void TitleFaculty()
{
    cout << setw(15) << "Code";
    cout << setw(15) << "Faculty";
    cout << setw(15) << "Manager" << endl;
}

void TitleRoom()
{
    cout << setw(15) << "Code";
    cout << setw(15) << "Room";
    cout << setw(15) << "Date" << endl;
}

void TitleSchool()
{
    cout << setw(15) << "Code";
    cout << setw(15) << "School";
    cout << setw(15) << "Address" << endl;
}

void ShowListFaculty(Faculty x[], int n)
{
    cout << "---------------------------------------------------" << endl;
    cout << "LIST FACULTY" << endl;
    TitleFaculty();
    for(int i=0; i<n; i++){
        cout << setw(15) << x[i].codeFaculty;
        cout << setw(15) << x[i].nameFaculty;
        cout << setw(15) << x[i].managerFaculty << endl;
    }
}

void ShowListRoom(Room y[], int m)
{
    cout << "---------------------------------------------------" << endl;
    cout << "LIST ROOM" << endl;
    TitleRoom();
    for(int i=0; i<m; i++){
        cout << setw(15) << y[i].codeRoom;
        cout << setw(15) << y[i].nameRoom;
        cout << setw(15) << y[i].date << endl;
    }
}

void University::Output()
{
    TitleSchool();
    School::Output();
    ShowListFaculty(x, n);
    ShowListRoom(y, n);
    cout << "---------------------------------------------------" << endl;
}

void ShowListUniversity(University a[], int k)
{
    cout << "---------------------------------------------------" << endl;
    cout << "UNIVERSITY" << endl;
    for(int i=0; i<k; i++){
        a[i].Output();
    }
}


void ShowUniversityHasITFaculty(University a[], int k)
{
    for(int i=0; i<k; i++){
        for(int j=0; j<a[i].n; j++){
            if(strcmp(a[i].x[j].nameFaculty, "IT") == 0)
                cout << a[i].nameSchool << " ";
        }
    }
}

int main()
{
    int k;
    cout << "Enter amount of University: ";     cin >> k;
    University *a;
    a = new University[k];
    InputListUniversity(a, k);
    ShowListUniversity(a, k);
    cout << "University has IT faculty: ";
    ShowUniversityHasITFaculty(a, k);

    return 0;
}
