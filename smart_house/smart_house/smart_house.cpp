#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum smart_house {
    POWER_SUPPLY = 1,
    OUTLETS = 2,
    HOUSE_LIGHTS = 4,
    GARDEN_LIGHTS = 8,
    INDOOR_HEATING = 16,
    BOILER = 32,
    AIR_CONDITIONING = 64
};

void boiler_control(double outdoor_temp, int& status) {
    if (outdoor_temp < 0 && !(status & BOILER)) {
        status |= BOILER;
        cout << "Boiler is on\n";
    }
    else if (outdoor_temp > 5 && status & BOILER) {
        status &= ~BOILER;
        cout << "Boiler is off\n";
    }
}

void garden_lights_control(int hour, string moving, int& status) {
    if (((hour > 16 || hour < 5) && moving == "yes") && !(status & GARDEN_LIGHTS)) {
        status |= GARDEN_LIGHTS;
        cout << "Garden lights is on\n";
    }
    else if ((hour < 16 && hour > 5 || moving != "yes") && status & GARDEN_LIGHTS) {
        status &= ~GARDEN_LIGHTS;
        cout << "Garden lights is off\n";
    }
}

void indoor_heating_control(double indoor_temp, int& status) {
    if (indoor_temp < 22 && !(status & INDOOR_HEATING)) {
        status |= INDOOR_HEATING;
        cout << "Indoor heating is on\n";
    }
    else if (indoor_temp >= 25 && status & INDOOR_HEATING) {
        status &= ~INDOOR_HEATING;
        cout << "Indoor heating is off\n";
    }
}

void air_conditioning_control(double indoor_temp, int& status) {
    if (indoor_temp >= 30 && !(status & AIR_CONDITIONING)) {
        status |= AIR_CONDITIONING;
        cout << "Air conditioning is on\n";
    }
    else if (indoor_temp <= 25 && status & AIR_CONDITIONING) {
        status &= ~AIR_CONDITIONING;
        cout << "Air conditioning is off\n";
    }
}

void house_lights_temp_control(int hour, string house_lights, int& color_temp, int& status) {
    if (house_lights == "on" && !(status & HOUSE_LIGHTS)) {
        status |= HOUSE_LIGHTS;
    }
    else if (house_lights == "off" && status & HOUSE_LIGHTS) {
        status &= ~HOUSE_LIGHTS;
    }
    if (status & HOUSE_LIGHTS) {
        switch (hour) {
        case 17:
            color_temp = 4425;
            break;
        case 18:
            color_temp = 3850;
            break;
        case 19:
            color_temp = 3275;
            break;
        case 20:
        case 21:
        case 22:
        case 23:
            color_temp = 2700;
            break;
        default:
            color_temp = 5000;
            break;
        }
        cout << "Current color temp is " << color_temp << "K" << endl;
    }
}

int main() {
    stringstream status_input;
    string status_str;
    double indoor_temp;
    double outdoor_temp;
    string moving;
    string house_lights;
    int color_temp = 5000;
    int hour = 0;
    int status = 0;

    for (int i = 0; i < 48; ++i) {
        cout << "Current time is " << hour << ":00" << endl << "Enter the house status:\n";
        getline(cin, status_str);
        status_input << status_str;
        status_input >> outdoor_temp >> indoor_temp >> moving >> house_lights;

        boiler_control(outdoor_temp, status);
        garden_lights_control(hour, moving, status);
        indoor_heating_control(indoor_temp, status);
        air_conditioning_control(indoor_temp, status);
        house_lights_temp_control(hour, house_lights, color_temp, status);

        if (hour == 23) {
            hour = 0;
        }
        else {
            ++hour;
        }
        stringstream().swap(status_input);
    }
}