#include "Zombie.hpp"

int main() {
    const int N = 5;
    Zombie *horde = zombieHorde(N, "zombi");

    for (size_t i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete [] horde;
    return 0;
}
