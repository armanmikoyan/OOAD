#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

enum Engine {
    Gas,
    Electric,
    Hybrid
};

class Car {
public:
    Car(std::string, Engine, double, int);
    virtual ~Car(){}

public:
    virtual void about_car() const = 0;

public:
    std::string              get_name() const;
    Engine            get_engine_type() const;
    double                  get_price() const;
    int                      get_make() const;

private:
    std::string         _name;
    Engine       _engine_type;
    double             _price;
    int                 _make;
};




class Bmw : public Car {
public:
    Bmw(std::string, Engine, double, int);

public:
    void about_car() const override;
};



class Mercedes : public Car {
public:
    Mercedes(std::string, Engine, double, int);

public:
    void about_car() const override;
};



class Audi : public Car {
public:
    Audi(std::string, Engine, double, int);

public:
    void about_car() const override;
};
#endif // CAR_H