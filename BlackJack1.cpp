//Giselle Guerra
//BlackJack semester project

#include <iostream>
using namespace std;
#include <ctime>

class BlackJackPlayer {
public: 
	int initialDeal ();
	void printCardType (int card);
	int valueCard(int card);
	int sum (int card1, int card2);
	void blackJackP ();
};

int initialDeal () {
  int random_card = 0;
  random_card = 1 + rand() % 13;
  return random_card;
}

void printCardType (int card) {

  if (card == 1)
  	cout << "Ace";
  else if (card == 11)
  	cout << "Jack";
  else if (card == 12)
  	cout << "Queen";
  else if (card == 13)
  	cout << "king";
  else 
  	cout << card;
}

int valueCard(int card){
	int value;
	if (card >= 11 && card <= 13)
		value = 10;
	else if (card == 1)
		value = 11;
	else
		value = card;
	return value;
}

int sum (int card1, int card2) {
  //Data
  int sumOfCards = 0;

  sumOfCards = card1 + card2;
  return sumOfCards;
}

void blackJackP (){
  //Data
  int card1;
  int card2;
  int trueVal1;
  int trueVal2;
  int sumP;
  int hit;
  int cardType;
  int cardNum;
  bool playerDone = false;
  int pStand;
  int cardDealer1;
  int cardDealer2;
  int trueValDealer1;
  int trueValDealer2;
  int sumD;
  int aceTracker = 0;
  int aceTrackerDealer = 0;

  cout << "The dealer was dealt: ";
  cardDealer1 = initialDeal();
  if (cardDealer1 == 1){
  	aceTrackerDealer += 1;
  }
  printCardType (cardDealer1);
  cout << " and ";
  cardDealer2 = initialDeal(); 
  if (cardDealer2 == 1){
  	aceTrackerDealer += 1;
  }
  cout << "X" << endl;

  trueValDealer1 = valueCard(cardDealer1);
  trueValDealer2 = valueCard(cardDealer2);

  sumD = sum (trueValDealer1, trueValDealer2);

  cout << "You were dealt: ";
  card1 = initialDeal();
  if (card1 == 1){
  	aceTracker += 1;
  }
  printCardType (card1);
  cout << " and ";
  card2 = initialDeal(); 
  if (card2 == 1){
  	aceTracker += 1;
  }
  printCardType (card2);
  cout << endl;
  
  trueVal1 = valueCard(card1);
  trueVal2 = valueCard(card2);

  sumP = sum (trueVal1, trueVal2);
  cout << "Sum is: " << sumP << endl;

  while (playerDone == false)
  {
    cout << "Would you like to Hit or Stand? (1 - hit, 2 - Stand)" << endl;
    cin >> hit;

    if (hit == 1)
    {
        cout << "You were dealt: ";
  		cardType = initialDeal ();
  		if (cardType == 1){
  	      aceTracker += 1;
        }
  		printCardType(cardType);
  		cout << endl;
  		cardNum = valueCard (cardType);
  		sumP = sumP + cardNum;
      cout << "Sum is: " << sumP << endl;

  		if (sumP > 21 && aceTracker >= 1){
  			sumP -= 10;
  			aceTracker -= 1;
  		}
      if (sumP > 21)
      {
          cout << "Player's hand exceeded 21. Player loses" << endl;
          return;
      }       
    }
    else 
    	playerDone = true;
  }//while
 
  if (sumP <= 21)
  {
      cout << "The dealer had: ";
      printCardType (cardDealer1);
      cout << " and ";
      printCardType (cardDealer2);
      cout << endl;
      cout << "Sum is: " << sumD << endl;

      while (sumD < 17) {
      	cardType = initialDeal ();
      	if (cardType == 1){
  	      aceTrackerDealer += 1;
        }
      	cout << "Plus: ";
  		printCardType(cardType);
  		cout << endl;
  		cardNum = valueCard (cardType);
  		sumD = sumD + cardNum;

  		if (sumD > 21 && aceTrackerDealer >= 1){
  			sumD -= 10;
  			aceTrackerDealer -= 1;
  	    }
      }
      if (sumD > 21) {
      	cout << "Dealer bust. Player wins!" << endl;
      }
      if (sumD == sumP){
      	cout << "Push, you both tied.";
      }
      if (sumD > sumP && sumD <= 21){
      	cout << "Dealer wins....." << endl;
      }
      if (sumP > sumD && sumP <= 21) {
      	cout << "Player wins!! " << endl; 
      }
  }
}//void

int main() {
	//Data
	int exitGame = 0;
	srand(time(0));

	cout << "Do you want to play BlackJack? (1 - Yes, 2 - No): " << endl;
	cin >> exitGame;

    while (exitGame == 1){
	   blackJackP ();
	   cout << "Do you want to play again? (1 - Yes, 2 - No): " << endl;
	   cin >> exitGame;
    }
    cout << "Thank you for playing!!" << endl;
}