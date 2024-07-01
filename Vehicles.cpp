#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Vehicle {
protected:
    string name;
    int numberOfWheels;
    int maxVelocity;
public:
    virtual void printInfo() {
        cout << endl << "Наименование транспорта: " << name << endl
            << "Кол-во Колес: " << numberOfWheels << endl
            << "Максимальная скорость: " << maxVelocity << " км/ч" << endl;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle() {
        name = "Мотоцикл";
        numberOfWheels = 2;
        maxVelocity = 150;
    }
};

class Scooter : public Vehicle {
protected:
    int maxLoad;
public:
    Scooter() {
        name = "Самокат";
        numberOfWheels = 2;
        maxVelocity = 30;
        maxLoad = 100;
    }

    void printInfo() {
        Vehicle::printInfo();
        cout << "Максимальная нагрузка: " << maxLoad << " кг" << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        name = "Автомобиль";
        numberOfWheels = 4;
        maxVelocity = 150;
    }
};

class Bus : public Vehicle {
protected:
    int maxPassenger;
public:
    Bus() {
        name = "Автобус";
        numberOfWheels = 6;
        maxVelocity = 100;
        maxPassenger = 20;
    }

    void printInfo() {
        Vehicle::printInfo();
        cout << "Максимальное количество пассажиров: " << maxPassenger << endl;
    }
};

class UnknownVehicle : public Vehicle {
public:
    void printInfo() {
        cout << endl << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА" << endl;
    }
};

class Factory {
private: 
    Vehicle* vehiclesCreated[5] = {};

public:
    void createVehicles(vector<int> vehiclesForCreate) {
        for (int i : vehiclesForCreate) {
            if (!vehiclesCreated[i]) {
                switch (i) {
                case 0:
                    vehiclesCreated[i] = new Motorcycle();
                    break;
                case 1:
                    vehiclesCreated[i] = new Scooter();
                    break;
                case 2:
                    vehiclesCreated[i] = new Car();
                    break;
                case 3:
                    vehiclesCreated[i] = new Bus();
                    break;
                case 4:
                    vehiclesCreated[i] = new UnknownVehicle();
                    break;
                }
            }
            vehiclesCreated[i]->printInfo();
        }
    }
};

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "rus");
    vector<int> types;
    for (int i = 1; i < argc; i++) {        // проход по аргументам, переданным через консоль
        stringstream convert(argv[i]);      // 
        int tryConvert;                     // ковертация в int
        if (!(convert >> tryConvert))       //
            tryConvert = 4;                 // 4 - неизвестный тип траспорта
        if (tryConvert < 0 || tryConvert > 4)
            tryConvert = 4;
        types.push_back(tryConvert);
    }

    Factory factory;
    factory.createVehicles(types);
}