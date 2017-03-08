#include "piece.h"
#include "game.h"
#include "player.h"
#include "playerAI3.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

PlayerAI3::PlayerAI3(Game *g, char team):Player(g,team){}

char oppositeTeam(char team){
	char c;
	if (team == 'b')
	{
		c = 'w';
	}
	else
	{
		c = 'b';
	}
	return c;
}
					

void PlayerAI3::makeMove(){
	vector<pair<string, string>> Movelists;
    vector<pair<string, string>> captureCheckLists;
    vector<pair<string, string>> kingMovelists;
    pair<string, string> moves;
	string idstring;
	string finalMove;

	string cmd;
	cin >> cmd;

	if (cin.eof()) return;

	if (cmd == "move")
	{

		int kr, kc;

		if(team == 'w')
		{
            if(g->check('K'))
            {
                for(int i=0; i<8; i++)
                {
                    for(int j=0; j<8; j++)
                    {
                        if(g->getBoard(i, j)->getID() == "K1")
                        {
                            kr = i;
                            kc = j;
                        }
                    }
                }
                for(int k=0; k<8; k++)
                {
                    for(int l=0; l<8; l++)
                    {
                    	int size = g->getMoveBoard(k,l).size();
                        for(int x=0; x<size; x++)
                        {
                             if(g->getMoveBoard(k,l)[x].second == "K1")
                             {
                                moves.first = "  ";
                                moves.first[0] = 'a' + kc;
				                moves.first[1] =  '8' - kr;
				                moves.second = "  ";
				                moves.second[0] = 'a'+l;
				                moves.second[1] = '8' - k;
                                kingMovelists.emplace_back(moves);
                            }
                        }
                    }
                }
            }
        }

        if(team == 'b'){
            if(g->check('k'))
            {
                for(int i=0; i<8; i++)
                {
                    for(int j=0; j<8; j++)
                    {
                        if(g->getBoard(i, j)->getID() == "k1")
                        {
                            kr = i;
                            kc = j;
                        }
                    }
                }
                for(int k=0; k<8; k++)
                {
                    for(int l=0; l<8; l++)
                    {
                    	int size = g->getMoveBoard(k,l).size();
                        for(int x=0; x<size; x++)
                        {
                             if(g->getMoveBoard(k,l)[x].second == "k1")
                             {
                                moves.first = "  ";
                                moves.first[0] = 'a' + kc;
				                moves.first[1] =  '8' - kr;
				                moves.second = "  ";
				                moves.second[0] = 'a' + l;
				                moves.second[1] = '8' - k;
                                kingMovelists.emplace_back(moves);
                            }
                        }
                    }
                }
            }
        }

		for (int i = 0; i<8; ++i)
		{
			for (int j = 0; j<8; ++j)
			{
			 	Piece *temp = g->getBoard(i,j);

			 	if(temp->getColour() == team)
			 	{

			 		idstring = temp->getID();

			 		for (int m = 0; m < 8; ++m)
			 		{
			 			for (int n = 0; n < 8; ++n)
			 			{
			 				int size = g->getMoveBoard(m,n).size();
			 				for (int k = 0; k < size; ++k)
			 				{

			 					if (g->getMoveBoard(m,n)[k].second == idstring)
			 					{
			 						if (!g->checkMoveBoardAt(m,n,"*",oppositeTeam(team)))
			 						{
			 							moves.first = "  ";
			 							moves.first[0] = 'a' + j;
			 							moves.first[1] = '8' - 'i';
			 							moves.second = "  ";
			 							moves.second[0] = 'a' + n;
			 							moves.second[1] = '8' - m;
			 							captureCheckLists.emplace_back(moves);
			 						}

				 					else if (!g->getBoard(m,n))
				 					{
				 						moves.first = "  ";
				 						moves.first[0] = 'a' + j;
				 						moves.first[1] = '8' - i;
				 						moves.second = "  ";
				 						moves.second[0] = 'a' + n;
				 						moves.second[1] = '8' - m;
				 						captureCheckLists.emplace_back(moves);
				 					}

				 					else if(g->isKingInRange(i, j, m, n, team))
				 					{
	                                    moves.first = "  ";
	                                    moves.first[0] = 'a' + j;
					                    moves.first[1] =  '8' - i;
					                    moves.second = "  ";
					                    moves.second[0] = 'a'+n;
					                    moves.second[1] = '8' - m;
	                                    Movelists.emplace_back(moves);
                                	}

				 					else 
				 					{
				 						moves.first = "  ";
				 						moves.first[0] = 'a' + j;
				 						moves.first[1] = '8' - i;
				 						moves.second = "  ";
				 						moves.second[0] = 'a' + n;
				 						moves.second[1] = '8' - m;
				 						Movelists.emplace_back(moves);
				 					}
				 				}
				 			}
				 		}
				 	}
				}
			}
		}
		if(!kingMovelists.empty())
		{    
            srand (time(NULL));
            int index = rand() % kingMovelists.size();
            finalMove = "move " +  kingMovelists[index].first + " " + kingMovelists[index].second;
        }
        else
        {
            srand (time(NULL));
            if(!captureCheckLists.empty())
            {
            	int index = rand() % captureCheckLists.size();
                finalMove = "move " +  captureCheckLists[index].first + " " + captureCheckLists[index].second;
            }
            else
            {
                int index = rand() % Movelists.size();
                finalMove = "move " +  Movelists[index].first + " " + Movelists[index].second;
            }
        }

        g->notify(finalMove);
	} 
	else 
	{
		cout << "Invalid command." << endl;
		makeMove();
	}
}