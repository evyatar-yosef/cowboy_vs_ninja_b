#include "SmartTeam.hpp"

namespace ariel {

    // Constructor
    SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

    SmartTeam::SmartTeam() : Team() {}

    SmartTeam::~SmartTeam() {}


    

    // void SmartTeam::add(Character* character) {}




void SmartTeam::attack(Team* enemy_team)
{
    if (enemy_team == nullptr)
    {
        throw std::invalid_argument("Enemy team is nullptr");
    }

    if (enemy_team->stillAlive() <= 0)
    {
        throw std::runtime_error("Enemy team is dead");
    }

    if (!this->leader->isAlive()) // Choose the leader
    {
        double closestDistance = std::numeric_limits<double>::max();
        Character* closestCharacter = nullptr;

        for (auto character : this->characters)
        {
            if (character->isAlive() && this->leader->distance(character) < closestDistance)
            {
                closestDistance = this->leader->distance(character);
                closestCharacter = character;
            }
        }

        this->leader = closestCharacter;
    }

    if (!enemy_team->leader->isAlive()) // Choose the leader
    {
        double closestDistance = std::numeric_limits<double>::max();
        Character* closestCharacter = nullptr;

        for (auto character : enemy_team->characters)
        {
            if (character->isAlive() && enemy_team->leader->distance(character) < closestDistance)
            {
                closestDistance = enemy_team->leader->distance(character);
                closestCharacter = character;
            }
        }

        enemy_team->leader = closestCharacter;
    }

    Point leader_position = leader->getLocation();

    while (enemy_team->stillAlive() > 0)
    {
        Character* victim = nullptr;
        double lowestHP = std::numeric_limits<double>::max();

        for (auto enemyCharacter : enemy_team->characters)
        {
            if (enemyCharacter->isAlive() && enemyCharacter->hit_points < lowestHP)
            {
                lowestHP = enemyCharacter->hit_points;
                victim = enemyCharacter;
            }
        }

        if (victim && victim->isAlive())
        {
            bool leaderChanged = (leader->getLocation().getX() != leader_position.getX()) || (leader->getLocation().getY() != leader_position.getY());

            for (auto character : characters)
            {
                if (character->isAlive())
                {
                    Cowboy* cowboy = dynamic_cast<Cowboy*>(character);
                    Ninja* ninja = dynamic_cast<Ninja*>(character);

                    if (cowboy)
                    {
                        if (cowboy->hasboolets())
                        {
                            cowboy->shoot(victim);
                        }
                        else
                        {
                            cowboy->reload();
                        }
                    }
                    else if (ninja)
                    {
                        if (ninja->distance(victim) >= 1)
                        {
                            ninja->move(victim);
                        }
                        else
                        {
                            ninja->slash(victim);
                        }
                    }
                }
            }

            if (!victim->isAlive() || leaderChanged)
            {
                lowestHP = std::numeric_limits<double>::max();

                for (auto enemyCharacter : enemy_team->characters)
                {
                    if (enemyCharacter->isAlive() && enemyCharacter->hit_points < lowestHP)
                    {
                        lowestHP = enemyCharacter->hit_points;
                        victim = enemyCharacter;
                    }
                }
            }
        }
    }
}

    // int SmartTeam::stillAlive() {
        
    //     return 0;
    // }

    // void SmartTeam::print() {}

} // namespace ariel
