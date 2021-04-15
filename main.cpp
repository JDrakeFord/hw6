#include <iostream>
#include "Ledger.h"
using namespace std;

int main()
{
    cout << "Homework 6 written by Jesse Ford." << endl;
    Ledger test;
    test.addToFile("Potato", 1569.69, "JessiesAccount.txt");
    test.readFile("JessiesAccount.txt");
    test.printContents(); cout << endl;
    test.correctCropType("Potato", 4);
    test.printContents(); cout << endl;
    test.generateStats("Output.txt");




    return 0;
}

