//~ Student IDs: 1132701350, 1193540154, 1156548216

#include <iostream>
#include <chrono>
#include <math.h>
#include <fstream>

using namespace std;

class Planet {
    public:
    string p_name;
    int x,y,z;  // coordinates
    int weight,profit;
};

void generate (string id, int a[]) { // generates 10 numbers from id
    id += id;

    for (int i=0;i<10;i++) {
        char t1[4] = {id[i], id[i+1], id[i+2], '\0'};
        a[i] = atoi(t1);
    }
}

void genPlanet (string id1, string id2, string id3) {
    if ((id1.compare(id2) ==0) || (id1.compare(id3) == 0)) {
        // reverse id1
        for (int i=0;i<5;i++) {
            int tmp;
            tmp=id1[i];
            id1[i]=id1[9-i];
            id1[9-i]=tmp;
        }
    }

    if (id2.compare(id3) == 0) {
        // reverse id2
        for (int i=0;i<5;i++) {
            int tmp;
            tmp=id2[i];
            id2[i]=id2[9-i];
            id2[9-i]=tmp;
        }
    }

    static const char alphabets[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const int p_count=10;
    int x[p_count],y[p_count],z[p_count];

    generate(id1,x);
    generate(id2,y);
    generate(id3,z);

    Planet p[p_count];

    srand (time(0));

    int totalweight = 0;

    int i = 0;

    // initialise Planet A (home planet)
    p[i].p_name = "Planet_" ;
    p[i].p_name += alphabets[i];
    p[i].x = x[i];
    p[i].y = y[i];
    p[i].z = z[i];
    p[i].weight = 0;
    p[i].profit = 0;

    // initialise other planets
    for (int i=1;i<p_count;i++) {
        p[i].p_name = "Planet_" ;
        p[i].p_name += alphabets[i];
        p[i].x = x[i];
        p[i].y = y[i];
        p[i].z = z[i];
        p[i].weight = (rand() % 16) + 5;
        totalweight += p[i].weight;
        p[i].profit = ((rand() % 16) + 5) * 10;
    }

    ofstream myfile;
    myfile.open ("A2planets.txt");

    cout << "Generating data ..." << endl;

    for (int i=0;i<p_count;i++) {
        cout << i << ":" << p[i].p_name << "," << p[i].x << "," << p[i].y << "," << p[i].z
             << "," << p[i].weight <<  "," << p[i].profit <<endl;
        myfile << p[i].p_name << " " << p[i].x << " " << p[i].y << " " << p[i].z
             << " " << p[i].weight <<  " " << p[i].profit <<endl;
    }

    cout << "Total weight = " << totalweight << endl;

    myfile.close();

    cout << endl << "Data generated." << endl;
}

bool isValid(string studentID) {
    if (studentID.size() != 10) {
        cout << " invalid" << endl;
        return false;
    }

    for (int i=0;i<10;i++) {
        if (!isdigit(studentID[i])) {
            cout << " invalid" << endl;
            return false;
        }
    }

    return true;
}

int main () {
    string student[3];

    for (int i=0;i<3;i++) {
        do {
            cout<<"Enter student ID " << i+1 << ": ";
            cin>>student[i];
        }
        while (!isValid(student[i]));
    }

    genPlanet(student[0],student[1],student[2]);

    return 0;
}
