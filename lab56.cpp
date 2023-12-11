#include <iostream>
using namespace std;
size_t LengthString(const char* str) {
    size_t len = 0;
    while (*str != '\0') {
        ++len;
        ++str;
    }
    return len+1;
}
//strk2Size - проверкa на выход за границы строки strk2
void copyString(char* strk2, const char* strk, int strk2Size) {
    int i = 0;
    while (strk[i] != '\0' && i < strk2Size - 1) {
        strk2[i] = strk[i];
        ++i;
    }
    strk2[i] = '\0';
}
class Vehicle {
public:
    long double cost;
    char* type;
    char* owner;
    long double fuelcost;
    long double fuelconsumption;
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
    void VehicleOutput() {
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
        if(this->type != nullptr) delete[] this->type;
        this->type = new char[LengthString(type)];
        copyString(this->type,type, LengthString(type));
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
};
void function1(Vehicle* VehicleArray, int ArrLen, double costfunc) {
      int result = 0;
      for (int i = 0; i < ArrLen; ++i) {
          if (VehicleArray[i].cost <= costfunc) ++result;
       }
      cout << "Количество устройств стоимостью до N: " << result << endl;
    }
//Функция strcmp относится к стандартной библиотеке языка программирования 
void function2(Vehicle* VehicleArray, int ArrLen) {
    double percentcar = 0, percentmotorcycle = 0, percentelectricbike = 0, percentspacerocket = 0;
    for (int i = 0; i < ArrLen; ++i) {
        if (strcmp(VehicleArray[i].type,"Car")==0) ++percentcar; 
        else if (strcmp(VehicleArray[i].type, "Motorcycle")==0) ++percentmotorcycle;
        else if (strcmp(VehicleArray[i].type, "Electric Bike")==0) ++percentelectricbike;
        else if (strcmp(VehicleArray[i].type, "Space Rocket")==0) ++percentspacerocket;
    }
    cout << "Процент транспортных средств типа автомобиль: " << (percentcar / ArrLen)*100 <<"%" << endl;
    cout << "Процент транспортных средств типа мотоцикл: " << (percentmotorcycle / ArrLen) * 100 << "%" << endl;
    cout << "Процент транспортных средств типа электровелосипед: " << (percentelectricbike / ArrLen) * 100 << "%" << endl;
    cout << "Процент транспортных средств типа космическая ракета: " << (percentspacerocket / ArrLen) * 100 << "%" << endl;
}
void function3(Vehicle* VehicleArray, int ArrLen, char* owner) {
    int cnt = 0;
    for (int i = 0; i < ArrLen; ++i) {
        if (strcmp(VehicleArray[i].owner, owner) == 0) {
            if (cnt == 0) {
                cout << "Список транспортных средств владельца " << owner << ": " << endl << VehicleArray[i].type << endl; ++cnt;
            }
            else if (cnt > 0) { cout << VehicleArray[i].type << endl; ++cnt; }
        }
    }
    if (cnt == 0) cout << "У данного владельца отсутствуют транспортные средства" << endl;
}
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
