#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ukininkai //farmers structure
{
    string name;
    int kg1;
    int kg2;
};
struct pirkejai //buyers structure
{
    string name;
    int kg;
};
struct galinis //rezults structure
{
    string name;
    int kgtotal = 0;
    int kg1 = 0;
    int kg2 = 0;
};

void pageidauja(int nu, pirkejai Y[],int &a, int &b) { //calculating request
    
    for (int i = 0; i < nu; i++) {
        a += (Y[i].kg - (Y[i].kg % 2)) / 2;
        b += Y[i].kg % 2;
    }

}
void turi(int np, ukininkai X[], int& c, int& d) { //calculating how much they have in total
    
    for (int i = 0; i < np; i++) {
        c += X[i].kg1;
        d += X[i].kg2;
    }
}
string uzteks(int a, int b, int c, int d) { //calculating if they have enough resources
    int ab = 0, cd = 0;
    ab = a * 2 + b; //35

    cd = d * 2 + c; //43

    if (ab <= cd) return "Taip";
    else return "Ne";
}
void skaiciavimas(ukininkai X[],pirkejai Y[],galinis Z[], int np, int nu) { //dividing food
    for (int i = 0; i < nu; i++) {
        Z[i].name = Y[i].name;
        Z[i].kgtotal = Y[i].kg;
        Z[i].kg2 = (Y[i].kg - (Y[i].kg % 2)) / 2;

        Z[i].kg1 = Y[i].kg % 2;
        int u = 0;
        int p = 0;
        int n = 0, m = 0;
        
        while (u < np && Z[i].kg2 != 0 && Y[i].kg >= 2) {

            if (X[u].kg2 == 0) {
                u++;
            }
            else if (X[u].kg2 < Z[i].kg2 && Z[i].kg2 != 0) {
            n += X[u].kg2;

            Z[i].kg2 -= X[u].kg2;
            Y[i].kg -= X[i].kg2 * 2;
            X[u].kg2 = 0;
            u++;

            }
            else if (X[u].kg2 >= Z[i].kg2 && Z[i].kg2 > 0) {
                n += Z[i].kg2;
                int bla = Z[i].kg2;
                Z[i].kg2 = 0;
                Y[i].kg -= bla * 2;
                X[u].kg2 -= bla;
                

            }

        }

        while (p < np && Z[i].kg1 != 0 && Y[i].kg > 0) {

            if (X[p].kg1 == 0) {
                p++;
            }
            else if (Y[i].kg > X[p].kg1) {
                m += X[p].kg1;
                Z[i].kg1 -= X[p].kg1;
                Y[i].kg -= X[i].kg1;
                X[p].kg1 = 0;
                p++;

            }
            else if (Y[i].kg <= X[p].kg1) {

                m += Y[i].kg;
                int bla = m;
                Z[i].kg1 = 0;
                Y[i].kg = 0;
                X[p].kg1 -= bla;

                
            }

        }
        Z[i].kg2 = n;
        Z[i].kg1 = m;


    }
}

int main()
{
    ifstream fd("d.txt");
    ofstream fr("r.txt");
    
    int np, nu; //how much buyers and how much sellers
    int a = 0, b = 0; //how many packages requested
    int c = 0, d = 0; //how many packages is provided

    ukininkai X[101];
    pirkejai Y[101];
    galinis Z[202];

    fd >> nu; //scanning
    fd >> ws;

    for (int i = 0; i < nu; i++) {
        char line[21];
        fd.get(line, 20);
        Y[i].name = line;
        fd >> Y[i].kg;

        fd >> ws;
    }

    fd >> np;

    fd >> ws;

    for (int i = 0; i < np; i++) {
        char line[21];
        fd.get(line, 20);
        X[i].name = line;
        fd >> X[i].kg1;
        fd >> X[i].kg2;

        fd >> ws;
    }

    pageidauja(nu, Y, a, b); //output
    fr << b << " " << a << endl;

    turi(np, X, c, d);
    fr << c << " " << d << endl;

    fr << uzteks(a, b, c, d) << endl;
    skaiciavimas(X, Y, Z, np, nu);
    for (int i = 0; i < nu; i++) {
        fr << Z[i].name << " " << Z[i].kgtotal << " " << Z[i].kg1 << " " << Z[i].kg2 << endl;
    }
    for (int i = 0; i < np; i++) {
        fr << X[i].name << " " << X[i].kg1 << " " << X[i].kg2 << endl;
    }
    fd.close();
    fr.close();
}

// fd>>ws;