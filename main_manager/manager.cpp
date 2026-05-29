#include <iostream>
#include <string>
using namespace std;


// classes include
#include "../src_clase/Job.h"
#include "../src_clase/Candidat.h"
#include "../src_clase/Aplicatie.h" //pentru orice eventualitate



int main(int argc, char* argv[]) {
    cout << "You have entered " << argc
         << " arguments:" << endl;

    // Using a while loop to
    // iterate through arguments
    int i = 0;
    while (i < argc) {
        cout << "Argument " << i + 1
             << ": " << argv[i]
             << endl;
        i++;
    }

    return 0;
}