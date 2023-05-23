#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <random>
#include <chrono>
#include <iostream>

using namespace ariel;
using namespace std;

double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}

auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"Bob", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"Bob", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"Bob", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
    return new Cowboy{"Bob", Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
    int flag = static_cast<int>(random_float()) % 4;

    if (flag == 0) return create_cowboy(x, y);

    if (flag == 1) return create_yninja(x, y);

    if (flag == 2) return create_tninja(x, y);

    return create_oninja(x, y);
}

auto simulate_battle = [](Team &team, Team &team2) {
    int i = 0;
    while (team.stillAlive() && team2.stillAlive()) {
        if (i % 2 == 0) {
            team.attack(&team2);
        } else {
            team2.attack(&team);
        }
        i++;
    }
};

int main() {
    auto create_yninja = [](double x = random_float(-100, 100), double y = random_float(-100, 100)) {
        std::cout << "Creating YNinja with x = " << x << ", y = " << y << std::endl;
    };

    auto create_tninja = [](double x = random_float(-100, 100), double y = random_float(-100, 100)) {
        std::cout << "Creating TNinja with x = " << x << ", y = " << y << std::endl;
    };

    auto create_oninja = [](double x = random_float(-100, 100), double y = random_float(-100, 100)) {
        std::cout << "Creating ONinja with x = " << x << ", y = " << y << std::endl;
    };

    auto create_cowboy = [](double x = random_float(-100, 100), double y = random_float(-100, 100)) {
        std::cout << "Creating Cowboy with x = " << x << ", y = " << y << std::endl;
    };

    create_yninja();
    create_tninja();
    create_oninja();
    create_cowboy();

    // Create the teams and characters
    Team team{create_cowboy(-1, -1)};
    team.add(create_yninja(0, 0));
    team.add(create_oninja(-0.5, -0.5));
    team.add(create_tninja(0.5, 0.5));
    team.add(create_cowboy());

    auto young_ninja = create_yninja(0, 0);
    auto trained_ninja = create_tninja(1, 1);
    auto old_ninja = create_oninja(2, 2);
    auto young_ninja2 = create_yninja(3, 3);
    auto cowboy = create_cowboy(-6, -6);
    auto cowboy2 = create_cowboy(-7, -7);
    auto cowboy3 = create_cowboy(-8, -8);
    Team team2{young_ninja};
    team2.add(trained_ninja);
    team2.add(old_ninja);
    team2.add(young_ninja2);
    team2.add(cowboy);
    team2.add(cowboy2);
    team2.add(cowboy3);

    // Perform the multi-attack
    multi_attack(2, team, team2);

    // Attack the enemy team with the first team
    team.attack(&team2);

    // Perform another multi-attack
    multi_attack(2, team, team2);

    // Perform the final multi-attack
    multi_attack(4, team, team2);

    // Perform the checks
    multi_attack(2, team, team2);
    team.attack(&team2);

    // Print the results
    std::cout << "Final character states:" << std::endl;
    std::cout << "Young Ninja 1: Alive - " << young_ninja->isAlive() << std::endl;
    std::cout << "Trained Ninja: Alive - " << trained_ninja->isAlive() << std::endl;
    std::cout << "Old Ninja: Alive - " << old_ninja->isAlive() << std::endl;
    std::cout << "Young Ninja 2: Alive - " << young_ninja2->isAlive() << std::endl;

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
