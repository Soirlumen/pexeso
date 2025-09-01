#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{

private:
    std::string name;
    unsigned int score;
    void setScore(unsigned int _s);

public:
    Player(std::string _n);
    std::string getName() const;
    unsigned int getScore() const;
    void addScore();
    ~Player();
};

#endif