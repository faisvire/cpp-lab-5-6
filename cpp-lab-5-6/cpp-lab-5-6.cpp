#include <iostream>
#include "header.h"
using namespace std;
void function1(Vehicle* VehicleArray, int ArrLen, double costfunc);
void function2(Vehicle* VehicleArray, int ArrLen);
void function3(Vehicle* VehicleArray, int ArrLen, char* owner);
int main()
{
    //конструктор без параметров и функции для вывода на экран и редактирования каждого поля 
    Vehicle vh1;
    vh1.setCost(15000);
    vh1.setType("Car");
    vh1.setOwner("Ann");
    vh1.setFuelcost(250);
    vh1.setFuelconsumption(55);
    vh1.VehicleOutput();
    cout << "----------------------------------------" << endl;
    //конструктор с параметрами
    Vehicle vh2(188000, "Space Rocket", "Mike", 1900, 100);
    vh2.VehicleOutput();
    cout << "----------------------------------------" << endl;
    //конструктор копирования
    Vehicle vh3(vh1);
    vh3.setOwner("Lana");
    vh3.setType("Motorcycle");
    vh3.setCost(200875);
    vh3.setFuelconsumption(95);
    vh3.VehicleOutput();
    cout << "----------------------------------------" << endl;
    auto VehicleArray = new Vehicle[3];
    Vehicle VehArr1(vh1), VehArr2(vh2), VehArr3(vh3);
    double N;
    VehicleArray[0] = VehArr1;
    VehicleArray[1] = VehArr2;
    VehicleArray[2] = VehArr3;
    cout << "Введите число N" << endl;
    cin >> N;
    function1(VehicleArray, 3, N);
    cout << "----------------------------------------" << endl;
    function2(VehicleArray, 3);
    cout << "----------------------------------------" << endl;
    cout << "Введите имя владельца" << endl;
    char own[20];
    int c;
    //очищение буфера - будет считывать символы из стандартного ввода 
    // до тех пор, пока не будет встречен символ новой строки 
    // или конец файла
    while ((c = getchar()) != '\n' && c != EOF) {}
    // принимает три параметра: указатель на буфер, 
    // в который будут помещены считанные символы, 
    // максимальное количество символов для чтения
    //  и указатель, откуда будет считываться строка
    fgets(own, sizeof(own), stdin);
    //надо найти позицию первого символа ('\n') в строке и заменить этот символ на нулевой символ ('\0')
    // заменяем символ новой строки в own завершающим нулевым символом, чтобы обозначить конец строки
    //без этого не работает strcmp
    own[strcspn(own, "\n")] = '\0';
    function3(VehicleArray, 3, own);
}