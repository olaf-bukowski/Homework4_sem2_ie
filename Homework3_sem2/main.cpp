#include <iostream>

using namespace std;

class Vehicle {

public:
    std::string name() { return name_; }
    int number_of_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }

protected:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
      : name_(name), number_of_wheels_(number_of_wheels),
        propulsion_type_(propulsion_type), max_speed_(max_speed) {}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};

class Car : public Vehicle {
public:
    Car(const std::string &name, int number_of_wheels,
        const std::string &propulsion_type, double max_speed, int number_of_doors)
      : Vehicle(name, number_of_wheels, propulsion_type, max_speed), number_of_doors_(number_of_doors) {}

    int number_of_doors() { return number_of_doors_; }

private:
    int number_of_doors_;
};

class Boat : public Vehicle {
public:
    Boat(const std::string &name, int number_of_wheels,
         const std::string &propulsion_type, double max_speed, double max_weight_capacity)
      : Vehicle(name, number_of_wheels, propulsion_type, max_speed), max_weight_capacity_(max_weight_capacity) {}

    double max_weight_capacity() { return max_weight_capacity_; }

private:
    double max_weight_capacity_;
};

class Aircraft : public Vehicle {
public:
    Aircraft(const std::string &name, int number_of_wheels,
             const std::string &propulsion_type, double max_speed, double max_altitude)
      : Vehicle(name, number_of_wheels, propulsion_type, max_speed), max_altitude_(max_altitude) {}

    double max_altitude() { return max_altitude_; }

private:
    double max_altitude_;
};

class Airplane : public Aircraft {
public:
    Airplane(const std::string &name, int number_of_wheels,
             const std::string &propulsion_type, double max_speed, double max_altitude, int number_of_engines)
      : Aircraft(name, number_of_wheels, propulsion_type, max_speed, max_altitude), number_of_engines_(number_of_engines) {}

    int number_of_engines() { return number_of_engines_; }

private:
    int number_of_engines_;
};

int main()
{
    Airplane airplane("Boeing 747", 3, "Jet", 570.0, 43000.0, 4);
    std::cout << "Name: " << airplane.name() << std::endl;
    std::cout << "Number of wheels: " << airplane.number_of_wheels() << std::endl;
    std::cout << "Propulsion type: " << airplane.propulsion_type() << std::endl;
    std::cout << "Max speed: " << airplane.max_speed() << std::endl;
    std::cout << "Max altitude: " << airplane.max_altitude() << std::endl;
    std::cout << "Number of engines: " << airplane.number_of_engines() << std::endl;
    return 0;
}
