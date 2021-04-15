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

//---------------------------------------------------------------------------
// Name: Ledger
// Parameters: Ledger - Pass by reference - original to make a copy from
// Returns: none
// Purpose: Copy Constructor. Initializes everything to the attributes of the parameter ledger.
//---------------------------------------------------------------------------
Ledger::Ledger(Ledger &original)
{
    //Copy amounts array
    for(int i = 0; i < original.numCrops; i++)
    {
        amounts[i] = original.amounts[i];
    }

    //Copy crops array
    for(int i = 0; i < original.numCrops; i++)
    {
        crops[i] = original.crops[i];
    }

    //Copy num crops
    numCrops = original.numCrops;
}

//---------------------------------------------------------------------------
// Name: ~Ledger
// Parameters: none
// Returns: none
// Purpose: Default destructor for the ledger object. Doesn't deallocate memory, but provides a cout statement
// for proof of deconstruction.
//---------------------------------------------------------------------------
Ledger::~Ledger(){ cout << "Destructed" << endl;}

//---------------------------------------------------------------------------
// Name: readFile
// Parameters: String - Pass by value - Contains file path to open and read.
// Returns: none
// Purpose: Opens and reads the input file, populating amounts and crops with the values in the file.
// Stops when it reaches the end of the file.
//---------------------------------------------------------------------------
void Ledger::readFile(const string path)
{
    ifstream infile;
    infile.open(path);
    float tempFloat;
    string tempString;
    int index = 0;

    while(infile >> tempFloat >> tempString)
    {
        if(validAmount(tempFloat) && validCrop(tempString))
        {
            amounts[index] = tempFloat;
            crops[index] = tempString;
            numCrops++;
            index++;
        }
    }
}

//---------------------------------------------------------------------------
// Name: generateStats
// Parameters: string - Pass by value - name of file to output to.
// Returns: none
// Purpose: Generates basic statistics of the ledger and outputs it to a file specified by the method call.
//---------------------------------------------------------------------------
void Ledger::generateStats(const string fileName) const
{
    ofstream outfile;
    outfile.open(fileName);


    if(!(outfile << "Average profit is: " << calculateAverage() << endl))
    {
        cout << "Something went wrong opening the output file!" << endl;
    }

    int potatoCount = 0; int beetCount = 0; int pumpkinCount = 0; int wheatCount = 0;
    countCrops(potatoCount, beetCount, pumpkinCount, wheatCount);
    outfile << "Number of potato crops harvested is: " << potatoCount<< endl;
    outfile << "Number of beet crops harvested is: " << beetCount<< endl;
    outfile << "Number of pumpkin crops harvested is: " << pumpkinCount<< endl;
    outfile << "Number of wheat crops harvested is: " << wheatCount<< endl;
    outfile << "Available to plant: " << (MAX_CROPS - (potatoCount + beetCount + pumpkinCount + wheatCount));

    outfile.close();
}

//---------------------------------------------------------------------------
// Name: validAmount
// Parameters: float - pass by value - amount to be tested for validity
// Returns: Boolean - Valid or Invalid
// Purpose: Tests amount for validity - It is valid if it is between 1000 and 2500.
//---------------------------------------------------------------------------
bool Ledger::validAmount(const float amount) const
{
    if(amount >= 1000 && amount <= 2500)
        return true;
    else return false;
}

//---------------------------------------------------------------------------
// Name: validAmount
// Parameters: string - pass by value - crop to be tested for validity
// Returns: Boolean - Valid or Invalid
// Purpose: Tests crop for validity - It is valid if it is one of the 4 allowed crops.
//---------------------------------------------------------------------------
bool Ledger::validCrop(const string crop)const
{
    if(crop == "Potato" || crop == "Beet" || crop == "Pumpkin" || crop == "Wheat")
        return true;
    else return false;
}

//---------------------------------------------------------------------------
// Name: printContents
// Parameters: none
// Returns: none
// Purpose: Prints the content's of the amounts and crops arrays to the console
//---------------------------------------------------------------------------
float Ledger::calculateAverage()const
{
    float sum = 0;
    int count = 0;
    for(int i = 0; i < numCrops; i++)
    {
        if(!(amounts[i] == -1))
        {
            sum += amounts[i]; count++;
        }
    }
    return (sum / count);
}

//---------------------------------------------------------------------------
// Name: countCrops
// Parameters: 4 Integers - Count of each crop - pass by value to change
// Returns: none
// Purpose: Counts the number of each of the crops found in the arrays set by the readFile function.
//---------------------------------------------------------------------------
void Ledger::countCrops(int & potatoCount, int & beetCount, int & pumpkinCount, int & wheatCount)const
{
    for(int i = 0; i < numCrops; i++)
    {
        if(crops[i] == "Potato")
            potatoCount++;
        else if(crops[i] == "Beet")
            beetCount++;
        else if(crops[i] == "Pumpkin")
            pumpkinCount++;
        else if(crops[i] == "Wheat")
            wheatCount++;
    }
}

//---------------------------------------------------------------------------
// Name: addToFile
// Parameters: 2 strings and a float - pass by value - filename, crop name, and amount to append.
// Returns: none
// Purpose: Adds a crop and amount to the INPUT file - gives the user a chance to correct the ledger before reading it.
//---------------------------------------------------------------------------
 void Ledger::addToFile(const string crop, const float amount, const string fileName)
{
    ofstream outfile;
    //Set to append mode instead of overwrite mode
    outfile.open(fileName, std::ios_base::app);

    outfile << endl << amount << " " << crop;
    outfile.close();

}

//---------------------------------------------------------------------------
// Name: correctCropType
// Parameters: string and int - pass by value - crop name and index
// Returns: none
// Purpose: This corrects an index of the crops array to change the name of the crop.
//---------------------------------------------------------------------------
void Ledger::correctCropType(const string crop, const int index)
{
    crops[index] = crop;
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
