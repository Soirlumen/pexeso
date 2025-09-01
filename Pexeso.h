#ifndef PEXESO_H
#define PEXESO_H

#include "Gameboard.h"
#include "Player.h"

class Pexeso
{
private:
std::vector<Player> players;
Gameboard Gme;
unsigned int round;
void setRound(unsigned int _nr);
public:
static constexpr int MAX_PLAYERS = 4;
    Pexeso(std::vector<Player> _p, Gameboard _g);
    void oneTurn(Player _player,const int first_card, const int second_card);
    void oneRound();
    bool isAllGone() const;
    ~Pexeso();
    Gameboard getGme() const;
    std::vector<Player> getPlayers() const;
    unsigned int getRound() const;
    int getACardIndex()const;
    void addRound();
    void showResults()const;
    void play();
};

#endif