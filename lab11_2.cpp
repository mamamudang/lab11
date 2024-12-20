#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
    return rand() % 13 + 1; // Random number between 1 and 13
}

int calScore(int x,int y,int z){
    int score = cardScores[x] + cardScores[y] + cardScores[z];
    return score % 10;
}

int findYugiAction(int s){
    if(s == 9) return 2; // Stay
    else if(s < 6) return 1; // Draw
    else{
        int randomChoice = rand() % 100 + 1; // Random number between 1 and 100
        if(randomChoice <= 69) return 1; // 69% chance to draw
        else return 2; // 31% chance to stay
    }
}

void checkWinner(int p, int y){
    cout << "\n---------------------------------\n";
    if(p > y) cout << "|         Player wins!!!        |\n";
    else if(p < y) cout << "|          Yugi wins!!!         |\n";
    else cout << "|             Draw!!!           |\n";
    cout << "---------------------------------\n";
}

int main(){    
    srand(time(0)); // Initialize random seed

    int playerScore, yugiScore, playerAction, yugiAction;
    int playerCards[3] = {drawCard(), drawCard(), 0};
    int yugiCards[3] = {drawCard(), drawCard(), 0};
    
    cout << "---------ORE NO TURN, DRAW!!!------------\n";
    cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
    playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
    cout << "Your score: " << playerScore << "\n";
    do{
        cout << "(1) Destiny draw (2) Stay, SELECT: ";
        cin >> playerAction;
    }while(playerAction != 1 && playerAction != 2); // Loop until input is valid

    if(playerAction == 1){
        playerCards[2] = drawCard();
        playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
        cout << "Player draws the 3rd card!!!\n";
        cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
        cout << "Your new score: " << playerScore << "\n";
    }
    cout << "------------ Turn end -------------------\n\n";

    cout << "---------YUGI'S TURN, DRAW!!!------------\n";
    cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
    yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
    cout << "Yugi's score: " << yugiScore << "\n";
    yugiAction = findYugiAction(yugiScore);

    if(yugiAction == 1){
        yugiCards[2] = drawCard();
        yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
        cout << "Yugi draws the 3rd card!!!\n";
        cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
        cout << "Yugi's new score: " << yugiScore << "\n";
    }
    cout << "------------ Turn end -------------------\n";

    checkWinner(playerScore, yugiScore);

    return 0;
}
