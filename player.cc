#include "player.h"
#include "game.h"
#include <iostream>
using namespace std;

Player::Player(Game *g, char team):g{g}, team{team} {}

char Player::getTeam(){return team;}
