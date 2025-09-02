#include "Gameboard.h"

Str Gameboard::getWhereObraski() const
{
    return where_obraski;
}

unsigned int Gameboard::getNumberOfPairs() const
{
    return number_of_pairs;
}

Gameboard::Gameboard(const Str &_wo, unsigned int _nop) : where_obraski(_wo), number_of_pairs(_nop)
{
    if (!fs::exists(_wo))
    {
        throw std::runtime_error("Slozka neexistuje: " + _wo);
    }
    vector_of_pics_names pom = read_folder(where_obraski);
    if (pom.size() < number_of_pairs)
    {
        throw std::runtime_error("Pocet paru je vyssi nez mozny pocet obrazku.");
    }
    if (number_of_pairs < 1)
    {
        throw std::runtime_error("musis hrat aspoň s nejakyma kartickami...");
    }
    for (unsigned int i = 1; i <= number_of_pairs; i++)
    {
        dEck.emplace_back(i, pom[i]);
        dEck.emplace_back(i, pom[i]); // chceme pár :3
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dEck.begin(), dEck.end(), g);
    std::cout << "everything is just right:)" << std::endl;
}

Gameboard::~Gameboard()
{
}

const vector_of_cards &Gameboard::getDeck() const
{
    return dEck;
}

vector_of_cards &Gameboard::getDeck()
{
    return dEck;
}

void Gameboard::showInvisibleCards() const
{
    const auto &deck = getDeck();

    for (size_t i = 0; i < deck.size(); i++)
    {
        if (!deck[i].isVisible())
        {
            std::cout << "Index: " << i << " karta: " << deck[i].getId() << " je viditelny? " << deck[i].isVisible() << "\n";
        }
    }
    std::cout << "hotovo\n";
}

std::vector<Str> read_folder(const Str &fold)
{
    auto actual_path = std::filesystem::current_path() / fold;
    std::vector<Str> result;
    // std::string path = "/path/to/directory";
    try
    {
        for (const auto &entry : fs::directory_iterator(actual_path))
        {
            // std::cout << entry.path() << std::endl;
            result.push_back(entry.path().string());
        }
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Chyba: " << e.what() << "\n";
    }

    return result;
}
