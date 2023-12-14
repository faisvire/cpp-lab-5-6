#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;
size_t LengthString(const char* str);
void copyString(char* strk2, const char* strk, int strk2Size);
class Vehicle {
private:
    long double cost;
    char* type;
    char* owner;
    long double fuelcost;
    long double fuelconsumption;
public:
    Vehicle(long double cost, const char* type, const char* owner, long double fuelcost, long double fuelconsumption) {
        this->cost = cost;
        this->type = new char[LengthString(type)];
        this->owner = new char[LengthString(owner)];
        copyString(this->type, type, LengthString(type));
        copyString(this->owner, owner, LengthString(owner));
        this->fuelcost = fuelcost;
        this->fuelconsumption = fuelconsumption;
    }
    Vehicle(const Vehicle& vh) {
        this->cost = vh.cost;
        if (vh.type != nullptr) {
            delete[] this->type;
            this->type = new char[LengthString(vh.type)]; copyString(this->type, vh.type, LengthString(vh.type));
        }
        else type = nullptr;
        if (vh.owner != nullptr) {
            delete[] this->owner;
            this->owner = new char[LengthString(vh.owner)];
            copyString(this->owner, vh.owner, LengthString(vh.owner));
        }
        else owner = nullptr;
        this->fuelcost = vh.fuelcost;
        this->fuelconsumption = vh.fuelconsumption;
    }
    void const VehicleOutput() {
        cout << "Информация о данном транспортном средстве: " << endl;
        cout << "Стоимость транспортного средства: " << cost << endl;
        if (type != nullptr) cout << "Тип транспортного средства: " << type << endl; else cerr << "Тип данного транспортного средства не указан." << endl;
        if (owner != nullptr) cout << "Владелец транспортного средства: " << owner << endl; else cerr << "Владелец транспортного средства не указан." << endl;
        cout << "Цена топлива для транспортного средства: " << fuelcost << endl;
        cout << "Расход топлива на километр для транспортного средства: " << fuelconsumption << endl;
    }
    Vehicle() {
        cost = 0;
        type = nullptr;
        owner = nullptr;
        fuelcost = 0;
        fuelconsumption = 0;
    }
    ~Vehicle() {
        if (type != nullptr) delete[] type;
        if (owner != nullptr) delete[] owner;
    }
    void setCost(long double cost) {
        this->cost = cost;
    }
    void setType(const char* type) {
        if (this->type != nullptr) delete[] this->type;
        this->type = new char[LengthString(type)];
        copyString(this->type, type, LengthString(type));
    }
    void setOwner(const char* owner) {
        if (this->owner != nullptr) delete[] this->owner;
        this->owner = new char[LengthString(owner)];
        copyString(this->owner, owner, LengthString(owner));
    }
    void setFuelcost(long double fuelcost) {
        this->fuelcost = fuelcost;
    }
    void setFuelconsumption(long double fuelconsumption) {
        this->fuelconsumption = fuelconsumption;
    }
    long double const getCost() {
        return cost;
    }
    const char* const getType() {
        return type;
    }
    const char* const getOwner() {
        return owner;
    }
    long double const getFuelcost() {
        return fuelcost;
    }
    long double const getFuelconsumption() {
        return fuelconsumption;
    }
};

#endif
