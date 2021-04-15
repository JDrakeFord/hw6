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
    void readFile(string file);
    void generateStats(string fileName) const;
    bool validAmount(float amount) const;
    bool validCrop(string crop) const;
    float calculateAverage() const;
    void countCrops(int &potatoCount, int &beetCount, int &pumpkinCount, int &wheatCount) const;
    static void addToFile(string crop, float amount, string fileName);
    void correctCropType(string crop, int index);

private:
    static const int MAX_CROPS = 15; // the maximum number of crops
    float amounts[MAX_CROPS];
    string crops[MAX_CROPS];
    int numCrops; // keeps track of how many crops you have added to your arrays

};
