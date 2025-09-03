#include "Pexeso.h"

void Pexeso::setRound(unsigned int _nr)
{
    round = _nr;
}

Pexeso::Pexeso(std::vector<Plr> _p, Gameboard _g) : players(_p), Gme(_g), round(1)
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

bool Pexeso::oneTurn(Plr &_player, const int first_card, const int second_card)
{
    if (first_card == second_card)
    {
        std::cout << "nemuzes odkryt jedno a to samo policko bruh\n";
        return false;
    }

    if (!(getGme().getDeck()[first_card].isVisible()) && !(getGme().getDeck()[second_card].isVisible()))
    {
        getGme().getDeck()[first_card].flipCard();
        getGme().getDeck()[second_card].flipCard();
        if (getGme().getDeck()[first_card].getId() == getGme().getDeck()[second_card].getId())
        {
            _player.addScore();
            std::cout << "mas bod! Nyni mas "<< _player.getScore()<< "bodu\n";
        }
        else
        {
            getGme().getDeck()[first_card].flipCard();
            getGme().getDeck()[second_card].flipCard();
            std::cout << "nemas bod!\n";
        }
        return true;
    }
    std::cout << "policko je uz odkryte, zkus to znovu:3";
    return false;
}

void Pexeso::oneRound()
{
    std::cout << "kolo: " << round;
    for (auto &pl : getPlayers())
    {
        std::cout << ", na rade je hrac " << pl.getName() << "\n";
        while (true)
        {
            int a = getACardIndex();
            int b = getACardIndex();
            bool k = oneTurn(pl, a, b);
            if (k)
                break;
        }
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

const std::vector<Plr> &Pexeso::getPlayers() const
{
    return players;
}

std::vector<Plr> &Pexeso::getPlayers()
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
        std::cout << "zadej cislo (0.."
                  << static_cast<int>(getGme().getDeck().size()) - 1
                  << ", -2=ukaz neviditelne, -1=quit): ";

        // zkoušíme načíst číslo
        if (!(std::cin >> pom)) {
            // pokud je vstup neplatný, opakujeme
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "To neni cislo, zkus znovu...\n";
            continue;
        }

        // speciální úspěšní případy
        if (pom == -1) {
            std::exit(0);
        }
        if (pom == -2) {
            getGme().showInvisibleCards();
            continue; //opakujeme smyčku
        }

        // ověření vstupu
        int deckSize = static_cast<int>(getGme().getDeck().size());
        if (pom < -2 || pom >= deckSize) {
            std::cout << "Index mimo rozsah. Zadej cislo mezi 0 a " << deckSize - 1 << ".\n";
            continue;
        }
        return pom;
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
