#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            a[i][j] = '_';
    }

    for (int h = 0; h < 9; h++) {
        char sign = (h % 2 == 0) ? 'X' : 'O';
        cout << ((h % 2 == 0) ? "pl1 " : "pl2 ");

        int x, y;
        bool validInput = false;
        while (!validInput) {
            cin >> x >> y;
            if (cin.fail() || x < 1 || x > 3 || y < 1 || y > 3 || a[x - 1][y - 1] != '_') {
                cout << "Неверный ввод. Попробуйте ещё раз: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                validInput = true;
            }
        }

        a[x - 1][y - 1] = sign;

        system("cls"); 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
        bool win = false;
        for (int i = 0; i < 3; ++i) {
            if ((a[i][0] == sign && a[i][1] == sign && a[i][2] == sign) ||
                (a[0][i] == sign && a[1][i] == sign && a[2][i] == sign)) {
                win = true;
                break;
            }
        }
        if ((a[0][0] == sign && a[1][1] == sign && a[2][2] == sign) ||
            (a[0][2] == sign && a[1][1] == sign && a[2][0] == sign)) {
            win = true;
        }

        if (win) {
            cout << "win pl" << ((sign == 'X') ? "1" : "2") << endl;
            break;
        }
        else if (h == 8) {
            cout << "draw" << endl;
        }
    }
    return 0;
}   

