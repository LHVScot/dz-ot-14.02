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
    // �����������
    Elevator(int lower, int upper) : lowerFloor(lower), upperFloor(upper), currentFloor(lower), isRunning(false) {}

    // ��������� �����
    void turnOn() {
        isRunning = true;
        cout << "���� �������." <<endl;
    }

    // ���������� �����
    void turnOff() {
        isRunning = false;
        cout << "���� ����������." << endl;
    }

    // ��������� ��������� �����
    bool isElevatorRunning() const {
        return isRunning;
    }

    // ��������� �������� ��������� �����
    int getCurrentFloor() const {
        return currentFloor;
    }

    // ��������� ������ �����
    void callElevator(int floor) {
        if (floor < lowerFloor || floor > upperFloor) {
            cout << "������ ����� ����, ������� ����������." << endl;
            return;
        }
        if (isRunning) {
            currentFloor = floor;
            cout << "���� �������� �� ���� �: " << currentFloor << endl;
        }
        else {
            cout << "���� ����� ���������." << endl;
        }
    }
};

