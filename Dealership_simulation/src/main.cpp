#include <iostream>

#include "Dealership.h"
#include "Car.h"
#include "Customer.h"


int main() {
    Customer c1{"Arman", "094410841", 100000001110.0};
    Dealership d{new Bmw{"X6", Hybrid, 395.453, 2020}, new Bmw{"troyka", Electric, 100.453, 2000},
    new Audi{"TT", Gas, 565.12, 2019}, new Mercedes{"G99", Electric, 999.453, 2023},
    new Bmw{"X99", Hybrid, 1395.453, 2020}};
  
    for (int i = 0; i < d.get_all_cars().size(); ++i)
    {
        std::cout << i + 1 << "-------------------\n";
        d.get_all_cars()[i]->about_car();
        std::cout << "-------------------\n";
    }
    c1.purchase_car(d, "X6");
    c1.get_personal_cars()[0]->about_car();

}