#pragma once
#include <iostream>


using namespace std;

class Elevator
{
private:
    int lowerFloor;      
    int upperFloor;      
    int currentFloor;    
    bool isRunning;      

public:
    // Конструктор
    Elevator(int lower, int upper) : lowerFloor(lower), upperFloor(upper), currentFloor(lower), isRunning(false) {}

    // Включение лифта
    void turnOn() {
        isRunning = true;
        cout << "Лифт запущен." <<endl;
    }

    // Выключение лифта
    void turnOff() {
        isRunning = false;
        cout << "Лифт остановлен." << endl;
    }

    // Получение состояния лифта
    bool isElevatorRunning() const {
        return isRunning;
    }

    // Получение текущего положения лифта
    int getCurrentFloor() const {
        return currentFloor;
    }

    // Обработка вызова лифта
    void callElevator(int floor) {
        if (floor < lowerFloor || floor > upperFloor) {
            cout << "Такого этажа нету, воодите корректней." << endl;
            return;
        }
        if (isRunning) {
            currentFloor = floor;
            cout << "Лифт движется на этаж №: " << currentFloor << endl;
        }
        else {
            cout << "Лифт нужно запустить." << endl;
        }
    }
};

