#include "Team.hpp"
#include <limits>
 using namespace ariel;


Team::Team(Character* leader) 
{
    if (leader->inPlay == true)
    {
        throw std::runtime_error("Leader is already in play!");
        
    }
    else{
    this->characters.reserve(10);
    this->leader = leader;
    this->numCowboys = 0;
    this->numNinjas = 0;
    this->add(leader);
   leader->inPlay = true;
   }
}

Team:: Team(){
    this->characters.reserve(10);
    this->leader = nullptr;
    this->numCowboys = 0;
    this->numNinjas = 0;
    this->add(leader);
    leader->inPlay = true;

}


Team::~Team()
{
    for (auto character : characters)
    {
        delete character;
    }
}


void Team::add(Character* character)
{
    if (!character)
    {
        throw std::invalid_argument("Invalid enemy pointer.");
    }

    if (character->inPlay)
    {
        throw std::runtime_error("Leader is already in play!");
    }
    else if (characters.size() >= 10)
    {
        throw std::runtime_error("Leader is already in play!");
    }
    else
    {
        if (dynamic_cast<Ninja*>(character) != nullptr)
        {
            characters.push_back(character);
            numNinjas++;
        }
        else
        {
            auto it = characters.begin() + static_cast<std::vector<Character*>::difference_type>(numCowboys);
            characters.insert(it, character);
            numCowboys++;
        }

        character->inPlay = true;
    }
}

void Team::attack(Team* enemy_team)
{
    if (enemy_team == nullptr)
    {
        throw std::invalid_argument("Enemy team is nullptr");
    }

    if (!this->leader->isAlive()) // Choose the leader
    {
        double closestDistance = std::numeric_limits<double>::max();
        Character* closestCharacter = nullptr;

        for (auto character : this->characters)
        {
            if (character->isAlive() && enemy_team->leader->distance(character) < closestDistance)
            {
                closestDistance = enemy_team->leader->distance(character);
                closestCharacter = character;
            }
        }

        this->leader = closestCharacter;
    }

    Point leader_position = leader->getLocation();

    // Choose victim
    Character* victim = nullptr;
    double closestDistance = std::numeric_limits<double>::max();

    for (auto enemyCharacter : enemy_team->characters)
    {
        if (enemyCharacter->isAlive() && leader->distance(enemyCharacter) < closestDistance)
        {
            closestDistance = leader->distance(enemyCharacter);
            victim = enemyCharacter;
        }
    }
//////////

    if (victim && victim->isAlive() && this->stillAlive() > 0 && enemy_team->stillAlive() > 0)
    {
      
        for (auto character : characters)
        {
             if (victim && victim->isAlive()&& enemy_team->stillAlive() > 0)
    {
        bool leaderChanged = (leader->getLocation().getX() != leader_position.getX()) || (leader->getLocation().getY() != leader_position.getY());

        if (!victim->isAlive() || leaderChanged)
        {
            closestDistance = std::numeric_limits<double>::max();

     for (auto enemyCharacter : enemy_team->characters)
            {
                if (enemyCharacter->isAlive() && leader->distance(enemyCharacter) < closestDistance)
                {
                    closestDistance = leader->distance(enemyCharacter);
                    victim = enemyCharacter;
                }
            }
        }
            
            if (character->isAlive())
            {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(character);
                Ninja* ninja = dynamic_cast<Ninja*>(character);

                if (cowboy)
                {
                    if (cowboy->hasboolets() && victim->isAlive()) // Check if the cowboy has bullets and the victim is alive
                    {
                        cowboy->shoot(victim);
                    }
                    if(!cowboy->hasboolets()){

                        cowboy->reload();
                    }
                }
                else if (ninja)
                {
                    // Move the ninja towards the victim if the distance is greater than 1 and the victim is alive
                    if (ninja->distance(victim) > 1 && victim->isAlive())
                    {
                        ninja->move(victim);
                    }
                    if (victim->isAlive()) // Perform the attack if the victim is still alive after moving
                    {
                        ninja->slash(victim);
                    }
                }
            }
        }
    }
}
}


int Team::stillAlive() 
{
    int charactersAlive = 0;
    if (!characters.empty())
    { 
        for(std::size_t i = 0; i < characters.size();i++)
     {

        if(characters[i]->isAlive() ) charactersAlive ++;
     }
    }
    
    
     return charactersAlive;
}


void Team::print()
{
    for (const auto& character : characters)
    {
        std::cout << "Name: " << character->getName() << std::endl;
        std::cout << "Hit Points: " << character->hit_points << std::endl;
        std::cout << "Location: " << character->location.print() << std::endl;

        if (!character->isAlive())
        {
            std::cout << "Status: Dead" << std::endl;
        }
        else
        {
            if (dynamic_cast<Cowboy*>(character))
            {
                std::cout << "Type: Cowboy" << std::endl;
                Cowboy* cowboy = dynamic_cast<Cowboy*>(character);
                std::cout << "Number of Bullets: " << cowboy->numOfBullets << std::endl;
                std::cout << "Damage Point: " << cowboy->hit_points << std::endl;
            }
            else if (dynamic_cast<Ninja*>(character))
            {
                std::cout << "Type: Ninja" << std::endl;
                Ninja* ninja = dynamic_cast<Ninja*>(character);
                std::cout << "Attack point: " << ninja->hit_points << std::endl;
            }
        }

        std::cout << "---------------------------" << std::endl;
    }
}

// for (auto character : characters)
// {
//     Cowboy* cowboy = dynamic_cast<Cowboy*>(character);
//     if (cowboy && cowboy->hasboolets() && cowboy->isAlive())
//     {
//         if (cowboy)
//                 {
//                     if (cowboy->hasboolets() && cowboy->isAlive())
//                     {
//                         if (victim->isAlive()) // Ignore dead enemies
//                         {
//                             cowboy->shoot(victim);
//                         }
//                     }
//                     else
//                     {
//                         cowboy->reload();
//                     }
//                 }
//     }
// }

// for (auto character : characters)
// {
//     Ninja* ninja = dynamic_cast<Ninja*>(character);
//     if (ninja && ninja->isAlive())
//     {
//        if (ninja)
//                 {
//                     if (ninja->distance(victim) <= 1)
//                     {
//                         if (victim->isAlive()) // Ignore dead enemies
//                         {
//                             ninja->slash(victim);
//                         }
//                     }
//                     else
//                     {
//                         ninja->move(victim);
//                     }
//                 }
//     }
// }