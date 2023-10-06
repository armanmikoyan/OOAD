#include "Car.h"

Car::Car(std::string name, Engine engine_type, double price, int make)
    :  _name{name}
    ,  _engine_type{engine_type}
    ,  _price{price}
    ,  _make{make}
{     
}

std::string Car::get_name() const
{
    return  _name;
}

Engine Car::get_engine_type() const
{
    return _engine_type;
}

double Car::get_price() const
{
    return _price;
}

int Car::get_make() const
{
    return _make;
}




Bmw::Bmw(std::string name, Engine engine_type, double price, int make)
    : Car{name, engine_type, price, make}
{
}

void Bmw::about_car() const
{
    std::cout << "About Bmw\n"
    << "name - " << get_name() << "\n"
    << "engine_type - " << get_engine_type() << "\n"
    << "price - " << get_price() << "\n"
    << "make - " << get_make() << "\n"; 
}




Mercedes::Mercedes(std::string name, Engine engine_type, double price, int make)
    : Car{name, engine_type, price, make}
{
}

void Mercedes::about_car() const
{
    std::cout << "About Mercedes\n"
    << "name - " << get_name() << "\n"
    << "engine_type - " << get_engine_type() << "\n"
    << "price - " << get_price() << "\n"
    << "make - " << get_make() << "\n"; 
}




Audi::Audi(std::string name, Engine engine_type, double price, int make)
    : Car{name, engine_type, price, make}
{
}

void Audi::about_car() const
{
    std::cout << "About Audi\n"
    << "name - " << get_name() << "\n"
    << "engine_type - " << get_engine_type() << "\n"
    << "price - " << get_price() << "\n"
    << "make - " << get_make() << "\n"; 
}