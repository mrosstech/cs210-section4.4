#include <string>

using namespace std;

#include "citytemp.h"

CityTemp::CityTemp() {
    this->cityName = "NeedsName";
    this->temp = -1000.0;
}

CityTemp::CityTemp(string cityName, double temp) {
    this->cityName = cityName;
    this->temp = temp;
}

void CityTemp::ConvertFromCtoF() {
    double tempTemp;
    tempTemp = (this->temp * (9.0/5.0) + 32);
    this->temp = tempTemp;
}

void CityTemp::ConvertFromFtoC() {
    double tempTemp;
    tempTemp = (this->temp - 32.0) * (5.0/9.0);
    this->temp = tempTemp;
}

void CityTemp::SetCityName(string newCityName) {
    this->cityName = newCityName;
}

void CityTemp::SetTemp(double newTemp) {
    this->temp = temp;
}

string CityTemp::GetCityName() {
    return this->cityName;
}

double CityTemp::GetTemp() {
    return this->temp;
}
