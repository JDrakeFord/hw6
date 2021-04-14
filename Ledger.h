#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Ledger
{
public:
    Ledger();
    ~Ledger();
    Ledger(Ledger &original);
    void printContents() const;
    void readFile(string const file);

private:
    static const int MAX_CROPS = 15; // the maximum number of crops
    float amounts[MAX_CROPS];
    string crops[MAX_CROPS];
    int numCrops; // keeps track of how many crops you have added to your arrays

};
