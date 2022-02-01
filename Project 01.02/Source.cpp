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
        cout << "Number : " << number << "\n";
        cout << s << "\n";
    }

    string& get_num()  {
        return number;
    }

    int get_year() {
        return year;
    }

    double get_price() {
        return price;
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

    void search_number() {
        string number;
        cout << "Enter number : ";
        cin >> number;

        auto res = find_if(cars.begin(), cars.end(), [number](car a) {
            return a.get_num() == number;
        });

        if (res == cars.end()) {
            cout << "\nnot found!\n";
        }
        else {
            cout << "\nvalue found";
            res->print();
            cout << "\n";
        }
    }

    void search_price() {
        double price;
        cout << "Enter price : ";
        cin >> price;

        vector<car> res;

        copy_if(cars.begin(), cars.end(), back_inserter(res), [price](car a) {
            return a.get_price() == price;
        });

        for (int i = 0; i < res.size(); i++) {
            res[i].print();
        }
    }

};
int menu_1() {
    int menu;
    cout << "1 - Add new cars\n";
    cout << "2 - Delete car\n";
    cout << "3 - Sort by num\n";
    cout << "4 - Sort by year\n";
    cout << "5 - Search by number\n";
    cout << "6 - Search by price\n";
    cout << "Enter your choise : ";
    cin >> menu;
    return menu;
}
int main() {
    setlocale(LC_ALL, "UKR");
    
    car_dealership c_d;
    int menu = 0;
    while (true) {
        c_d.print();
        menu = menu_1();
        system("cls");
        switch (menu) {
        case 1:
            c_d.set();
            break;
        case 2:
            c_d.del_car();
            break;
        case 3:
            c_d.sort_num();
            break;
        case 4:
            c_d.sort_year();
            break;
        case 5:
            c_d.search_number();
            break;
        case 6:
            c_d.search_price();
            break;
        }
    }
    

    return 0;
}