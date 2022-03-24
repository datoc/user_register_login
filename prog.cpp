#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;

void draw_select_board();

inline void Registration() {
    cout << setfill('#');
    cout << setw(30) << "Registration\n";

    string name, lastname, email, password;
    cout << "Enter first name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> lastname;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    fstream userfile;
    userfile.open("users.txt", ios::out);
    
    if(name == " " || lastname == " " || email == " " || password == " ") {
        system("cls");
        HANDLE f = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(f, FOREGROUND_RED);
        cout << "Registration failed" << "\n";
        cout << "Enter all fields" << "\n";
        SetConsoleTextAttribute(f, 7);
        Registration();
    }else {
        userfile << name << lastname << email << password;
        userfile.close();

        HANDLE f = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(f, FOREGROUND_GREEN);
        cout << "Registration successfully finished" << "\n";
        SetConsoleTextAttribute(f, 7);
    }

    cout << "Go to back main menu, then press B\n";
    int t = getch();
    
    if(t == 98) {
        system("cls");
        draw_select_board();
    }
}

inline void Login() {
    cout << setfill('-');
    cout << setw(60) << " Log in to system\n";

    string email, password;
    string filedata[4];

    ifstream userdata("users.txt", ios::in);

    userdata >> filedata[0];
    userdata >> filedata[1];
    userdata >> filedata[2];
    userdata >> filedata[3];

    cout << "Enter email: ";
    cin >> email;

    cout << "Enter password: ";
    cin >> password;

    if(email == filedata[2] || password == filedata[3]) {
        for(int i = 0; i < 4; i++) {
            cout << filedata[i] << endl;
        }
    }else {
        cout << "That user don't exists";
    }
}

int main() {
    draw_select_board();

    system("pause>nul");
    return 0;
}

void draw_select_board() {
    char select_board[10][20];

    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            select_board[i][j] = ' ';
            if(j == 0) select_board[i][j] = static_cast<char>(219);
            if(i == 0) select_board[i][j] = static_cast<char>(223);
            if(j == 19) select_board[i][j] = static_cast<char>(219);
            if(i == 9) select_board[i][j] = static_cast<char>(223);

            select_board[1][1] = '1';
            select_board[1][2] = ' ';
            select_board[1][3] = alphabet[17];
            select_board[1][4] = alphabet[4];
            select_board[1][5] = alphabet[6];
            select_board[1][6] = alphabet[8];
            select_board[1][7] = alphabet[18];
            select_board[1][8] = alphabet[19];
            select_board[1][9] = alphabet[4];
            select_board[1][10] = alphabet[17];

            select_board[3][1] = '2';
            select_board[3][2] = ' ';
            select_board[3][3] = alphabet[11];
            select_board[3][4] = alphabet[14];
            select_board[3][5] = alphabet[6];
            select_board[3][6] = alphabet[8];
            select_board[3][7] = alphabet[13];
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            cout << select_board[i][j];
        }
        cout << "\n";
    }

    int cat_id;
    cout << "Choose desiered category: 1 or 2: ";

    cin >> cat_id;

    if(cat_id == 1) Registration();
    if(cat_id == 2) Login();
}