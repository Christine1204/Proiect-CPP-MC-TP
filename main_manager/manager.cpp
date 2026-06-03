#include <iostream>
#include <string>
using namespace std;


// classes include
#include "Job.h"
#include "Candidat.h"
#include "Aplicatie.h" //pentru orice eventualitate

/*  comanda test 
 ./main_manager/build/manager arg1 arg2 "this is arg 3"
*/


int main(int argc, char* argv[]) {
    cout << "You have entered " << argc
         << " arguments:" << endl;

    int i = 0;
    while (i < argc) {
        cout << "Argument " << i + 1
             << ": " << argv[i]
             << endl;
        i++;
    }

    



    return 0;
}