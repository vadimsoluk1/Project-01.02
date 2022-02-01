#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class car {

    string name;
    int year;
    double eng_capacity;
    int price;

public:

    car() {
        name = "no set";
        year = 0;
        eng_capacity = 0;
        price = 0;
    }

    void set() {
        cout << "Enter car name : ";
        cin >> name;
        cout << "Enter year of manufacture of the car : ";
        cin >> year;
        cout << "Enter engine capacity : ";
        cin >> eng_capacity;
        cout << "Enter price : ";
        cin >> price;
    }


};

class car_dealership {
    vector<car> cars;
public:

};
int main() {
    setlocale(LC_ALL, "UKR");


    return 0;
}