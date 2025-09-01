#include "Pexeso.h"

void Pexeso::setRound(unsigned int _nr)
{
    round = _nr;
}

Pexeso::Pexeso(std::vector<Player> _p, Gameboard _g) : players(_p), Gme(_g), round(1)
{
    if (_p.size() > MAX_PLAYERS)
    {
        throw std::runtime_error("nemuzes mit vic hracu nez " + MAX_PLAYERS);
    }
    if (_p.size() < 2)
    {
        throw std::runtime_error("alespon 2 hraci musi hrat lol");
    }
}

void Pexeso::oneTurn(Player &_player, const int first_card, const int second_card)
{
    if (!getGme().getDeck()[first_card].isVisible() && !getGme().getDeck()[second_card].isVisible())
    {
        getGme().getDeck()[first_card].flipCard();
        getGme().getDeck()[second_card].flipCard();
        if (getGme().getDeck()[first_card].getId() == getGme().getDeck()[second_card].getId())
        {
            _player.addScore();
            std::cout<<"mas bod!\n";
        }
        else
        {
            getGme().getDeck()[first_card].flipCard();
            getGme().getDeck()[second_card].flipCard();
        }
        return;
    }
    std::cout << "policko je uz odkryte,zkus to znovu:3";
}

void Pexeso::oneRound()
{
    std::cout << "kolo: " << round;
    for (auto &pl : getPlayers())
    {
        std::cout << "na rade je hrac " << pl.getName() << "\n";
        int a = getACardIndex();
        int b = getACardIndex();
        oneTurn(pl, a, b);
        if (isAllGone())
        {
            return;
        }
    }
    addRound();
}

bool Pexeso::isAllGone() const
{
    for (auto a : getGme().getDeck())
    {
        if (!a.isVisible())
        {
            return false;
        }
    }
    return true;
}

Pexeso::~Pexeso()
{
}

std::vector<Player> Pexeso::getPlayers() const
{
    return players;
}

unsigned int Pexeso::getRound() const
{
    return round;
}

int Pexeso::getACardIndex() const
{
    while (true)
    {
        int pom;
        std::cout << "zadej cislo: ";
        if (std::cin >> pom)
        {

            return pom;
        }
        else
        {
            if(pom==-1){
                exit;
            }
            // vymaze error flag
            std::cin.clear();
            // Vyprázdnit špatný zbytek vstupu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "To neni cislo zkus znovu...\n";
        }
    }
}

void Pexeso::showResults() const
{
    for (auto pl : getPlayers())
    {
        std::cout << "hrac " << pl.getName() << " ma " << pl.getScore() << " bodu,\n";
    }
}

void Pexeso::play()
{
    while (!isAllGone())
    {
        oneRound();
    }
    showResults();
}
