#include "../../Player/Player.h"
#include <iostream>
#include "../../Dice/Dice.h"
#include "../../Graph/Graph.h"
#include "../../MapLoader/MapLoader.h"
#include "../../Deck/TileDeck.h"

int main()
{
  std::cout << "This is a test of the player class." << std::endl;

  Player* player = new Player(); //creating a new player
  Player* player2 = new Player(); //creating a new player
  std::cout << player -> toString() << std::endl; //showing details
  std::cout << player2 -> toString() << std::endl; //showing details
  player -> rollDice(); //rolling the dice for player 1
  std::cout << "\n";
  std::cout << "\n";

  MapLoader::setFilePath("map.map"); //load the map since we will need it in order to resolve the dice effects
  MapLoader::loadMap(); // load the map
  std::cout << MapLoader::getMap() -> toString() << std::endl;

  //quick test of the tile deck
  //TileDeck tilesDeck;
  //tilesDeck.Print();



  player -> setZone(8); //set the player zone to 8 so that he is outside manhattan while the other is inside
                        //this is so we can test the effect of an attack roll
  player -> resolveDice(); //resolve the dice
  std::cout << player -> toString() << std::endl;
  std::cout << player2 -> toString() << std::endl;

  //now let player 2 roll the dice and resolve them
  player2 -> rollDice();
  player2 -> resolveDice();
  std::cout << player -> toString() << std::endl;
  std::cout << player2 -> toString() << std::endl;

  //now let's test the buy cards method
  CardDeck deck;
  deck.Shuffle();

  player2 -> buyCards(deck);

  delete player;
  player = NULL;
  delete player2;
  player2 = NULL;
}