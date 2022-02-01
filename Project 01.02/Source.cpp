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

    void print() {
        string s(50, '-');
        cout << s;
        cout << "\nCar name : " << name << "\n";
        cout << "Year of manufacture of the car : " << year << "\n";
        cout << "Engine capacity : " << eng_capacity << "\n";
        cout << "Price : " << price << "\n";
        cout << s;
    }


};

class car_dealership {
    vector<car> cars;
public:

    void set() {
        int size;
        car c;
        cout << "Enter count of machines : ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            c.set();
            cars.push_back(c);
        }
    }

    void print() {
        for (int i = 0; i < cars.size(); i++) {
            cars[i].print();
        }
    }



};
int main() {
    setlocale(LC_ALL, "UKR");
    
    

    return 0;
}