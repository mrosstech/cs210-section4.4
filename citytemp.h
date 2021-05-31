#ifndef CITY_TEMP_H
#define CITY_TEMP_H

#include <string>

using namespace std;

class CityTemp {
    private:
        string cityName;
        int temp;
    public:
        void ConvertFromCtoF();
        void ConvertFromFtoC();
        void SetCityName(string newCityName);
        void SetTemp(double newTemp);
        string GetCityName();
        int GetTemp();
        CityTemp();
        CityTemp(string cityName, int temp);
};

#endif