#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stack Zombie");

    return 0;
}
