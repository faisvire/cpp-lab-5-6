#include <iostream>
#include "header.h"
using namespace std;
size_t LengthString(const char* str) {
    size_t len = 0;
    while (*str != '\0') {
        ++len;
        ++str;
    }
    return len + 1;
}
void copyString(char* strk2, const char* strk, int strk2Size) {
    int i = 0;
    while (strk[i] != '\0' && i < strk2Size - 1) {
        strk2[i] = strk[i];
        ++i;
    }
    strk2[i] = '\0';
}
void function1(Vehicle* VehicleArray, int ArrLen, double costfunc) {
    int result = 0;
    for (int i = 0; i < ArrLen; ++i) {
        if (VehicleArray[i].getCost() <= costfunc) ++result;
    }
    cout << "Количество устройств стоимостью до N: " << result << endl;
}
//Функция strcmp относится к стандартной библиотеке языка программирования 
void function2(Vehicle* VehicleArray, int ArrLen) {
    double percentcar = 0, percentmotorcycle = 0, percentelectricbike = 0, percentspacerocket = 0;
    for (int i = 0; i < ArrLen; ++i) {
        if (strcmp(VehicleArray[i].getType(), "Car") == 0) ++percentcar;
        else if (strcmp(VehicleArray[i].getType(), "Motorcycle") == 0) ++percentmotorcycle;
        else if (strcmp(VehicleArray[i].getType(), "Electric Bike") == 0) ++percentelectricbike;
        else if (strcmp(VehicleArray[i].getType(), "Space Rocket") == 0) ++percentspacerocket;
    }
    cout << "Процент транспортных средств типа автомобиль: " << (percentcar / ArrLen) * 100 << "%" << endl;
    cout << "Процент транспортных средств типа мотоцикл: " << (percentmotorcycle / ArrLen) * 100 << "%" << endl;
    cout << "Процент транспортных средств типа электровелосипед: " << (percentelectricbike / ArrLen) * 100 << "%" << endl;
    cout << "Процент транспортных средств типа космическая ракета: " << (percentspacerocket / ArrLen) * 100 << "%" << endl;
}
void function3(Vehicle* VehicleArray, int ArrLen, char* owner) {
    int cnt = 0;
    for (int i = 0; i < ArrLen; ++i) {
        if (strcmp(VehicleArray[i].getOwner(), owner) == 0) {
            if (cnt == 0) {
                cout << "Список транспортных средств владельца " << owner << ": " << endl << VehicleArray[i].getType() << endl; ++cnt;
            }
            else if (cnt > 0) { cout << VehicleArray[i].getType() << endl; ++cnt; }
        }
    }
    if (cnt == 0) cout << "У данного владельца отсутствуют транспортные средства" << endl;
}