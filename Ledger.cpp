#include "Ledger.h"

//---------------------------------------------------------------------------
// Name: Ledger
// Parameters: none
// Returns: none
// Purpose: Constructor. Initializes everything to nothing.
//---------------------------------------------------------------------------
Ledger::Ledger()
{
    for (int i=0; i < MAX_CROPS; i++)
    {
        crops[i] = "NO_CROP";
        amounts[i] = -1;
    }
    numCrops = 0;
}

Ledger::Ledger(Ledger &original)
{
    //Copy amounts array
    for(int i = 0; i < sizeof(amounts); i++)
    {
        amounts[i] = original.amounts[i];
    }

    //Copy crops array
    for(int i = 0; i < sizeof(crops); i++)
    {
        crops[i] = original.crops[i];
    }

    //Copy num crops
    numCrops = original.numCrops;
}
//Empty Destuctor
Ledger::~Ledger(){}

void Ledger::readFile(const string path)
{
    ifstream File;
    File.open(path);

    while(File.good())


}



//---------------------------------------------------------------------------
// Name: printContents
// Parameters: none
// Returns: none
// Purpose: Prints the content's of the amounts and crops arrays to the console
//---------------------------------------------------------------------------
void Ledger::printContents() const
{
    for(int i = 0; i < numCrops; i++)
    {
        cout << amounts[i] << " " << crops[i] << endl;
    }
}
