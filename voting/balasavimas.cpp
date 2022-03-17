#include <fstream>
#include <iostream>

using namespace std;

int bad(int d[][4],int b,int i) { //Function that finds the worst out of one worker
    int one = d[i][0];
    int two = d[i][1];
    int three = d[i][2];
    if (one < two && one < three) {
        return 1;
    }
    else if (two < one && two < three) {
        return 2;
    }
    else if (three < two && three < one) {
        return 3;
    }
    else {
        return b;
    }
}

int select(int worst[],int b) { //Finds the worst game that poeple voted
    int one = worst[0];
    int two = worst[1];
    int three = worst[2];
    if (one > two && one > three) {
        return 1;
    }
    else if (two > one && two > three) {
        return 2;
    }
    else if (three > two && three > one) {
        return 3;
    }
    else {
        return b;
    }
}

int main()
{
    ifstream fd("U1.txt");
    int n;
    int b;
    int d[11][4];
    int worst[4];
    fd >> n; //scanning file
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < 3; j++) {
            fd >> d[i][j];
        }
    }
    fd >> b;
    worst[0]=0;
    worst[1]=0;
    worst[2]=0;
    for (int i = 0; i < n; i++) {
        if (bad(d, b, i) == 1) {
            worst[0]++;
        }
        else if (bad(d, b, i) == 2) {
            worst[1]++;
        }
        else{
            worst[2]++;
        }
    }
    ofstream fr("U1rez.txt");
    fr << worst[0] <<" "<< worst[1] <<" "<< worst[2] << endl; //printing aswers to file
    fr << select(worst, b);
}
//35 min