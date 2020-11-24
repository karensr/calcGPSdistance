// ConsoleApplication13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using namespace std;

#define M_PI (double)3.14159265359

double toRad(double val)
{
    return val * M_PI / 180;
}

double convertPositionToGrad(double val)
{
    int tval1 = val / 100;
    double tval2 = val - (double)(tval1 * 100);
    double retval = (double)tval1 + (double)(tval2 / 60);
    return retval;
}

//convert from dd.dd to dd,mm.mmmm
double convertGradToPosition(double val)
{
    unsigned int tval1 = val;
    double tval2 = val - (double)(tval1);
    double retval = (double)tval1 * 100 + (double)(tval2 * 60);
    return retval;
}


double calc_distance(double lat1, double lon1, double lat2, double lon2)
{
//    lat1 = convertPositionToGrad(lat1);
//    lat2 = convertPositionToGrad(lat2);
//    lon1 = convertPositionToGrad(lon1);
//    lon2 = convertPositionToGrad(lon2);

    double R = 6371.0; // km
    double dLat = toRad((lat2 - lat1));
    double dLon = toRad((lon2 - lon1));
    double a = sin(dLat / 2) * sin(dLat / 2) +
        cos(toRad(lat1)) * cos(toRad(lat2)) *
        sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = R * c * 1000;

    return d;
}

int main()
{
    cout << calc_distance(40.20052, 44.54832, 40.20028, 44.54823) << "\n";
}
