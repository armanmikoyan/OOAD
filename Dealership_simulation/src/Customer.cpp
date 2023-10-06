#include <Customer.h>

Customer::Customer(std::string name, std::string contact_info, double money)
    : _name{name}
    , _contact_info{contact_info}
    , _money{money}
{
}

std::string Customer::get_name() const
{
    return _name;
}

std::string Customer::get_contact_info() const
{
    return _contact_info;
}

double Customer::get_money() const
{
    return _money;
}

std::vector<Car*> Customer::get_personal_cars() const
{
    return _personal_cars;
}

void Customer::set_money(double money)
{
    _money -= money;
}

void Customer::purchase_car(Dealership& dealership, const std::string& preferable_car) 
{
    for (int i = 0; i < dealership.get_all_cars().size(); ++i)
    {
        if (dealership.get_all_cars()[i]->get_name() == preferable_car && dealership.get_all_cars()[i]->get_price() <= get_money())
        {
            get_personal_cars().push_back(dealership.get_all_cars()[i]);
            dealership.set_cars(i);
            set_money(dealership.get_all_cars()[i]->get_price());
            return;
        }
    }
    std::cout << "You don't have enough money or this car is not available\n";
}
