#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "citytemp.h"

vector<CityTemp> ReadTemps(string filename);
void WriteTemps(string filename, vector<CityTemp> outputTemps);
vector<CityTemp> ConvertTempsFromFtoC(vector<CityTemp> oldTemps);


int main() {

    vector<CityTemp> myFTemps;
    vector<CityTemp> myCTemps;

    myFTemps = ReadTemps("FarenheitTemperature.txt");
    myCTemps = ConvertTempsFromFtoC(myFTemps);
    WriteTemps("CelsiusTemperature.txt", myCTemps);

    return 0;
}

vector<CityTemp> ReadTemps(string filename) {
    vector<CityTemp> inputTemps(100);
    ifstream f;
    string cityName;
    double cityTemp;

    int index = 0;
    f.open(filename);

    if (!f.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return inputTemps;
    }

    f >> cityName;
    f >> cityTemp;

    while (!f.fail()) {

        inputTemps.at(index).SetCityName(cityName);
        inputTemps.at(index).SetTemp(cityTemp);

        f >> cityName;
        f >> cityTemp;

        f.ignore();

        index++;
    }

    f.close();
    return inputTemps;
}

void WriteTemps(string filename, vector<CityTemp> outputTemps) {
    ofstream f;
    int i;

    f.open(filename);

    for (i = 0; i < outputTemps.size(); i++) {
        f << outputTemps.at(i).GetCityName() << outputTemps.at(i).GetTemp() << endl;
    }

    f.close();
}
vector<CityTemp> ConvertTempsFromFtoC(vector<CityTemp> oldTemps) {
    int i;

    for (i = 0; i < oldTemps.size(); i++) {
        oldTemps.at(i).ConvertFromFtoC();
    }

    return oldTemps;
}