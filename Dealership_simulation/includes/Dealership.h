#ifndef DEALERSHIP_H
#define DEALERSHIP_H

#include "Car.h"

#include <vector>

class Dealership {
public:
    Dealership();
    Dealership(std::initializer_list<Car*>);
    ~Dealership();
    void operator=(Car*);

public:
    std::vector<Car*> get_all_cars() const;
    void                   set_cars(int i);
    
private:
    std::vector<Car*> _cars;
};


#endif // DEALERSHIP_H