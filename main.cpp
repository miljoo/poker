#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <algorithm>
#include "Card.h"
#include "funcs.h"

using namespace std;

int main(){
    srand(time(NULL));
    //int handvalue;
    int money = 50;
    bool changeArray[5] = {true,true,true,true,true};
    int changeOk = 0;
    int tmp;

    Card deck[52];
    Card hand[5];

    //start gameloop
    while(money > 0){
        money--;
        cout << "Money left:" << money << endl;
        initDeck(deck);
        resetChanges(changeArray);

        for(int i = 0 ; i < 5 ; i++){
            hand[i] = deal(deck);
        }

        for(int i = 0 ; i < 5 ; i++){
        cout << hand[i].Getvalue() << hand[i].Getsuit() << " ";
        }
        cout << endl;

        cout << "select 6 to end selecting" << endl;
        while(changeOk == 0){
            cin >> tmp;
            if(tmp >= 1 && tmp <= 5){
                changeArray[tmp-1] = !changeArray[tmp-1];
            }else if(tmp == 6){
                changeOk = 1;
            }
        }
        changeOk = 0;


        for(int i = 0 ;  i < 5 ; i++){
            if(changeArray[i] == 1){
                hand[i] = deal(deck);
            }
        }

        for(int i = 0 ; i < 5 ; i++){
        cout << hand[i].Getvalue() << hand[i].Getsuit() << " ";
        }
        cout << endl;

        sort(hand, hand + 5);

        /*
        for(int i = 0 ; i < 5 ; i++){
            cout << hand[i].Getvalue() << hand[i].Getsuit() << " ";
        }
        cout << endl;
        */

        /*
        handvalue = checkHand(hand);

        if(handvalue == 7){money += 30;}
        else if(handvalue == 6){money += 15;}
        else if(handvalue == 5){money += 8;}
        else if(handvalue == 4){money += 4;}
        else if(handvalue == 3){money += 3;}
        else if(handvalue == 2){money += 2;}
        else if(handvalue == 1){money += 2;}
        */
        handresults(hand, money);
    }
    //end gameloop

    return 0;
}
