#ifndef CARD_H
#define CARD_H


class Card
{
    protected:
    private:
        int value;
        char suit;
    public:
        Card();
        Card(int _value, char _suit);
        int Getvalue() { return value; }
        void Setvalue( int val) { value = val; }
        char Getsuit() { return suit; }
        void Setsuit(char val) { suit = val; }
        bool operator<(const Card& other) const
        {
            return value < other.value;
        }
};

#endif // CARD_H
