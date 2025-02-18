#include <iostream>

#include "Elevator.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    Elevator elevator(1, 10); // Создаем лифт с диапазоном от 1 до 10 этажей

    elevator.turnOn(); // Включаем лифт

    elevator.callElevator(5); // Вызываем лифт на 5 этаж
    elevator.callElevator(11); // Попытка вызвать лифт на недопустимый этаж

    cout << "Текущий этаж: " << elevator.getCurrentFloor() << endl; // Получаем текущий этаж

    elevator.turnOff(); // Выключаем лифт

    return 0;
}