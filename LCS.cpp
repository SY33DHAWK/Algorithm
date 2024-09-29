#include <iostream>

using namespace std;
 
 
void printLCS(char b[100][100], string X, int i, int j) {

    if (i == 0 || j == 0)

        return;

    if (b[i][j] == 'C') {

        printLCS(b, X, i - 1, j - 1);

        cout << X[i - 1];

    } else if (b[i][j] == 'U') {

        printLCS(b, X, i - 1, j);

    } else {

        printLCS(b, X, i, j - 1);

    }

}
 
 
void printTable(int c[100][100], int m, int n) {

    cout << "LCS Table:" << endl;

    for (int i = 0; i <= m; i++) {

        for (int j = 0; j <= n; j++) {

            cout << c[i][j] << " ";

        }

        cout << endl;

    }

}
 
 
void printDirectionTable(char b[100][100], int m, int n) {

    cout << "Direction Table:" << endl;

    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            cout << b[i][j] << " ";

        }

        cout << endl;

    }

}
 
 
void LCS(string X, string Y) {

    int m = X.length();

    int n = Y.length();
 
    int c[100][100];

    char b[100][100];
 
 
    for (int i = 0; i <= m; i++) {

        for (int j = 0; j <= n; j++) {

            if (i == 0 || j == 0) {

                c[i][j] = 0;

            }

        }

    }
 
 
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (X[i - 1] == Y[j - 1]) {

                c[i][j] = c[i - 1][j - 1] + 1;

                b[i][j] = 'C';

            } else if (c[i - 1][j] >= c[i][j - 1]) {

                c[i][j] = c[i - 1][j];

                b[i][j] = 'U';

            } else {

                c[i][j] = c[i][j - 1];

                b[i][j] = 'L';

            }

        }

    }
 
 
    printTable(c, m, n);
 
 
    printDirectionTable(b, m, n);
 
 
    cout << "LCS: ";

    printLCS(b, X, m, n);

    cout << endl;

}
 
 
int main() {

    //string Y ="AGGTAB";

    //string X = "GXTXATB";
 
    string X,Y;
 
cout<<"First String :";
 
    cin>> X;

     cout<<"Second String:";
 
     cin>> Y;
 
 
    LCS(X, Y);
 
    return 0;

}

 