#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class car {

    string name;
    int year;
    double eng_capacity;
    int price;
    string number;

public:

    car() {
        name = "no set";
        year = 0;
        eng_capacity = 0;
        price = 0;
        number = "no set";
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
        cout << "Enter number : ";
        cin >> number;
    }

    void print() {
        string s(50, '-');
        cout << s;
        cout << "\nCar name : " << name << "\n";
        cout << "Year of manufacture of the car : " << year << "\n";
        cout << "Engine capacity : " << eng_capacity << "\n";
        cout << "Price : " << price << "\n";
        cout << "Numebr : " << number << "\n";
        cout << s;
    }

    string& get_num()  {
        return number;
    }

    int get_year() {
        return year;
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

    void del_car() {
        string number;
        cout << "Enter car number : ";
        cin >> number;

        auto it = remove_if(cars.begin(), cars.end(), [number](car a) {
            return a.get_num() == number;
        });
        cars.erase(it, cars.end());

    }

    void sort_num() {
        sort(cars.begin(), cars.end() , [](car & e, car & e1)
        {
            return e.get_num() > e1.get_num();

        });
    }

    void sort_year() {
        sort(cars.begin(), cars.end(), [](car& e, car& e1)
            {
                return e.get_year() > e1.get_year();

            });
    }


};
int main() {
    setlocale(LC_ALL, "UKR");
    
    car_dealership c_d;

    c_d.set();
    c_d.print();
    c_d.sort_num();
    c_d.print();

    return 0;
}