#include <iostream>
using namespace std;

class Car {
   private:
       string brand;
       string model;
       int year;
   public:
       static int createdCarsCount;

       Car(string brand, string model, int year) {
           this->brand = brand;
           this->model = model;
           this->year = year;

           createdCarsCount++;
       }

       void drive() {
           cout << "Driving car with Brand: " << brand << " Model: " << model << " Year: " << year   << endl;
       }

       static int getCreatedCarsCount() {
           createdCarsCount++;
       }

       ~Car() {
           cout << "Destructing object";
       }
};

int main() {
   Car::createdCarsCount = 0;
   Car myCar = *new Car("Toyota", "Corolla", 2017);
   myCar.drive(); // Driving car with Brand: Toyota Model: Corolla Year: 2017

   cout << "Created cars count: " << Car::getCreatedCarsCount() << endl; // 1
}
