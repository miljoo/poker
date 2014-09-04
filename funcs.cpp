#include "funcs.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void initDeck(Card deck[]){
    int i = 0;
    for(i = 0; i < 52 ; i++){
        if(i < 13){
            deck[i].Setvalue(i+1);
            deck[i].Setsuit('H');
        }
        else if (i < 26){
            deck[i].Setvalue(i - 12);
            deck[i].Setsuit('D');
        }
        else if (i < 39){
            deck[i].Setvalue(i - 25);
            deck[i].Setsuit('C');
        }
        else {
            deck[i].Setvalue(i - 38);
            deck[i].Setsuit('S');
        }
    }
}

Card deal(Card deck[]){
    //srand(time(NULL));
    int randomCard;
    Card card;

    while(1){
        randomCard = rand() % 52;
        if(deck[randomCard].Getvalue() != 0){
            card = deck[randomCard];
            deck[randomCard].Setvalue(0);
            return card;
        }
    }
}

int checkHand(Card _hand[]){
    int counter = 0;
    int cvalue;
    char csuit;
    int pairs = 0;
    int trees = 0;
    int fours = 0;
    int straight = 0;
    int flush = 0;
    cvalue = _hand[0].Getvalue();
    csuit = _hand[0].Getsuit();
    //Check for Flush
    for(int i = 1 ; i < 5 ; i ++){
        if(_hand[i].Getsuit() == csuit){
            counter++;
        }
    }
    if(counter == 4){
        flush = 1;
    }
     //Check for Straight
    counter = 0;
    for(int i = 1 ; i < 5 ; i++){
        if(cvalue == 1 && _hand[1].Getvalue() == 10 && _hand[2].Getvalue() == 11 && _hand[3].Getvalue() == 12 && _hand[4].Getvalue() == 13){
            straight = 1;
            i = 5;
            counter = 4;
        }else if(cvalue >= 10){
            i = 5;
        }else{
            if(cvalue == _hand[i].Getvalue() - i){
                counter++;
            }
        }
    }
    if(counter == 4){
        straight = 1;
    }
    counter = 0;

    //Check for 4's 3's 2's of the same
    //the card compared to
    for(int j = 0 ; j < 4 ; j++){
        counter = 0;
        //the card to compare with
        for(int i = (j + 1) ; i  < 5 ; i++){
            if(_hand[j].Getvalue() == _hand[i].Getvalue()){
                counter++;
            }
        }

        if(counter == 3){
            fours++;
            j = 5;
        }else if(counter == 2){
            trees++;
            if(j == 0){
                j = 2;
            }
            else{
                j = 5;
            }
        }else if(counter == 1){
            if(j == 0){
                pairs++;
                j = 1;
            }else if(j == 1){
                pairs++;
                j = 2;
            }else{
                pairs++;
            }
        }
    }
    if(flush == 1 && straight == 1){cout << "Royal Flush!" << endl; return 7;}
    if(fours == 1){cout << "4 of a kind!" << endl; return 6;}
    if(trees == 1 && pairs == 1){cout << "Full House!" << endl; return 5;}
    if(straight == 1){cout << "Straight" << endl; return 4;}
    if(flush == 1){cout << "Flush" << endl; return 3;}
    if(trees == 1){cout << "3 of a kind" << endl; return 2;}
    if(pairs == 2){cout << "two pairs" << endl; return 1;}
    return 0;
    /*
    else if(pairs == 1){
        std::cout << "A pair" << std::endl;
    }else if(fours == 0 && trees == 0 && pairs == 0){
        std::cout <<  _hand[4].Getvalue() << " High" << std::endl;
    }
    */
}

void resetChanges(bool _array[]){
    for(int i = 0 ; i < 5 ; i++){
        _array[i] = true;
    }
}

void handresults(Card *_hand, int &_money){
    int handvalue;
    handvalue = checkHand(_hand);

        if(handvalue == 7){_money += 30;}
        else if(handvalue == 6){_money += 15;}
        else if(handvalue == 5){_money += 8;}
        else if(handvalue == 4){_money += 4;}
        else if(handvalue == 3){_money += 3;}
        else if(handvalue == 2){_money += 2;}
        else if(handvalue == 1){_money += 2;}

}
