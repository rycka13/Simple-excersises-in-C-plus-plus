#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

struct person //structure
{
    string name;
    int by;
    int bm;
    int bd;

    int dy;
    int dm;
    int dd;
};

void input(int &n, person X[]) { //file scanning function
    ifstream fd("U2.txt");
    fd >> n;
    fd >> ws;
    for (int i = 0; i < n; i++) {
        char a[26];
        fd.get(a, 25);
        X[i].name = a;
        fd >> X[i].by;
        fd >> X[i].bm;
        fd >> X[i].bd;

        fd >> X[i].dy;
        fd >> X[i].dm;
        fd >> X[i].dd;
        fd >> ws;
    }
    fd.close();
}

int rdn(int y, int m, int d) { //calculation function
    int days=0;
    days += 365 * y;
    if (m == 2) days += 31;
    if (m == 3) days += 31 + 28;
    if (m == 4) days += 31+ 28+31;
    if (m == 5) days += 31 + 28 + 31+30;
    if (m == 6) days += 31 + 28 + 31 + 30+31;
    if (m == 7) days += 31+ 28 + 31+ 30 + 31 +30;
    if (m == 8) days += 31 + 28 + 31 + 30 + 31 + 30+31;
    if (m == 9) days += 31 + 28 + 31 + 30 + 31 + 30 + 31 +30;
    if (m == 10) days += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 +30;
    if (m == 11) days += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 +31;
    if (m == 12) days += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 +30;
    days += d;
    return days;
}

void output(person X[], int n) { //output
    ofstream fr("U2rez.txt");
    for (int i = 0; i < n; i++) {
        fr << X[i].name << X[i].by << " " << X[i].bm << " " << X[i].bd << " " << X[i].dy << " " << X[i].dm << " " << X[i].dd << " ";
        fr << rdn(X[i].dy, X[i].dm, X[i].dd)- rdn(X[i].by, X[i].bm, X[i].bd) << endl;
    }
    fr.close();
}

int main()
{
    person X[101];
    int n;
    input(n, X);
    output(X, n);
}
