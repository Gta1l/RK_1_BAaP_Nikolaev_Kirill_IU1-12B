#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
private:
    string mark;
    string model;
public:
    Vehicle(const string& Vmark, const string& Vmodel) : mark(Vmark), model(Vmodel) {}

    string get_mark() const {
        return mark;
    }

    string get_model() const {
        return mark;
    }

    void set_mark(const string& Vmark) {
        mark = Vmark;
    }

    void set_model(const string& Vmodel) {
        model = Vmodel;
    }

    virtual void display()  {
        cout << "Mark: " << mark << ", Model: " << model << endl;
    }
};

class Car : public Vehicle {
private:
    int doorcount;
public:
    Car(const string& Cmark, const string& Cmodel, const int& Cdoorcount) : Vehicle(Cmark, Cmodel), doorcount(Cdoorcount) {}

    int get_doorcount() const {
        return doorcount;
    }

    void set_doorcount(const int& Cdoorcount) {
        doorcount = Cdoorcount;
    }

    void display() override {
        cout << "Mark: " << get_mark() << ", Model: " << get_model() << ", Doorcount: " << doorcount << endl;
    }
    
};

class Motocycle : public Vehicle {
private:
    string type;
public:
    Motocycle(const string& Mmark, const string& Mmodel, const string& Mtype) : Vehicle(Mmark, Mmodel), type(Mtype) {}

    string get_type() const {
        return type;
    }

    string set_type(const string& Mtype) {
        type = Mtype;
    }

    void display() override {
        cout << "Mark: " << get_mark() << ", Model: " << get_model() << ", Type: " << type << endl;
    }
};

void update_vehicle(Vehicle* V, const string& mark, const string& model) {
    V->set_mark(mark);
    V->set_model(model);
}

int main()
{
    vector<Vehicle*> Vehicles;
    
    Vehicles.push_back(new Car("Chevrolet", "Lacetti", 4));
    Vehicles.push_back(new Car("Hendai", "Solaris", 4));
    Vehicles.push_back(new Car("Lamborghini", "Urus", 4));
    Vehicles.push_back(new Motocycle("Kawasaki", "Ninja", "Sport"));
    Vehicles.push_back(new Motocycle("Honda", "CB500", "Road"));

    for (const auto& V : Vehicles)
    {
        V->display();
    }

    update_vehicle(Vehicles[1], "BMW", "X7");
    update_vehicle(Vehicles[3], "BMW", "R1250RS");

    for (const auto& V : Vehicles)
    {
        V->display();
    }
}
