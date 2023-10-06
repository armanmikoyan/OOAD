#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Car.h"
#include "Dealership.h"

#include <vector>

class Customer {
public:
    Customer(std::string, std::string, double);
   ~Customer(){}

public:
    void purchase_car(Dealership&, const std::string&);

public:
    std::string                  get_name() const;
    std::string          get_contact_info() const;
    double                      get_money() const;
    std::vector<Car*>   get_personal_cars() const;
    void                         set_money(double);

private:
    std::string               _name;
    std::string       _contact_info;
    double                   _money;
    std::vector<Car*> _personal_cars;
};


#endif // CUSTOMER_H