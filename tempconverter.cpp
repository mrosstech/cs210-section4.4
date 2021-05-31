#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "citytemp.h"

// Function declarations
vector<CityTemp> ReadTemps(string filename);
void WriteTemps(string filename, vector<CityTemp> outputTemps);
vector<CityTemp> ConvertTempsFromFtoC(vector<CityTemp> oldTemps);



int main() {
    // Vector of CityTemp objects to hold the inputted F data pairs.
    vector<CityTemp> myFTemps;
    // Vector of CityTemp objects to hold the converted C data pairs.
    vector<CityTemp> myCTemps;

    // Read the input file contents into the myFTemps vector.
    myFTemps = ReadTemps("./FahrenheitTemperature.txt");
    // Hold the converted F to C temperatures in the myCTemps vector
    myCTemps = ConvertTempsFromFtoC(myFTemps);
    // Write the myCTemps values back into the new file.
    WriteTemps("./CelsiusTemperature.txt", myCTemps);

    return 0;
}

// Read the temperature data from the filename.  Return a vector
// with the read data.
vector<CityTemp> ReadTemps(string filename) {
    vector<CityTemp> inputTemps;
    CityTemp addTemp;
    ifstream f;
    string cityName;
    double cityTemp;

    int index = 0;
    f.open(filename);

    if (!f.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return inputTemps;
    }

    // Inital read of city and temperature.
    f >> cityName;
    f >> cityTemp;
    // Initial store of city and temperature into addTemp.
    addTemp.SetCityName(cityName);
    addTemp.SetTemp(cityTemp);
    // Push the addTemp object to the inputTemps vector.
    inputTemps.push_back(addTemp);

    while (!f.fail()) {
        f >> cityName;
        f >> cityTemp;
        addTemp.SetCityName(cityName);
        addTemp.SetTemp(cityTemp);
        inputTemps.push_back(addTemp);
        f.ignore();
        cout << f.fail();
        index++;
    }
    // Close the file for cleanup
    f.close();
    return inputTemps;
}

// Write the temperature to a file from a vector of objects of type CityTemp
void WriteTemps(string filename, vector<CityTemp> outputTemps) {
    ofstream f;
    int i;

    f.open(filename);

    for (i = 0; i < outputTemps.size(); i++) {
        f << outputTemps.at(i).GetCityName() << " " << outputTemps.at(i).GetTemp() << endl;
    }

    f.close();
}

// Convert the vector of CityTemp objects temperature from F to C using the 
// object method.
vector<CityTemp> ConvertTempsFromFtoC(vector<CityTemp> oldTemps) {
    int i;

    for (i = 0; i < oldTemps.size(); i++) {
        oldTemps.at(i).ConvertFromFtoC();
    }

    return oldTemps;
}