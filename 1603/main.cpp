#include <iostream>

class ParkingSystem {
public:
    int b;
    int m;
    int s;
    ParkingSystem(int big, int medium, int small) : b(big), m(medium), s(small) {}

    bool addCar(int carType) {
        switch (carType) {
            case 1:
                b--;
                return b >= 0;
            case 2:
                m--;
                return m >= 0;
            case 3:
                s--;
                return s >= 0;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main() {

    return 0;
}
