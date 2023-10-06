#include "Dealership.h"


Dealership::Dealership()
{
}

Dealership::Dealership(std::initializer_list<Car*> cars)
{
    for (auto car : cars)
    {
        _cars.push_back(car);
    }
}
Dealership::~Dealership()
{
    for (int i = 0; i < _cars.size(); ++i)
    {
        delete _cars[i];
    }
}

void Dealership::operator=(Car* car)
{
    _cars.push_back(car);
}

std::vector<Car*> Dealership::get_all_cars() const
{
    return _cars;
}

void Dealership::set_cars(int i)
{
    _cars.erase(_cars.begin() + i);
}