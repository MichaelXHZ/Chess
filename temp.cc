else if (cmd == "resign") {
			if (turn) {
				cout << "White wins!" << endl;
				++wwon;
			} else {
				cout << "Black wins!" << endl;
				++bwon;
			}
		} else if (cmd == "move") {
			string prevPos,newPos;
			cin >> prevPos >> newPos;
			Piece *pp = board[stoi(prevPos[1])][prevPos[0]-'a'];
			char color = pp->getColour();
			if ((turn && (color != 'b')) || (!turn && (color != 'w')) {
				cout << "Need to move your own chess piece!" << endl;
				continue;
			}
			Pawn *pt = dynamic_cast<Pawn *>(pp);
			if (pt != nullptr) {
				if (newPos[1] == "8") {
					if ()
					String promo;
					cin >> promo;
					delete pp;
					if ((promo == "Q") || (promo == "q")) {
						if (turn) {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Queen(stoi(newPos[1]),newPos[0]-'a',newPos,"q",'b');
						} else {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Queen(stoi(newPos[1]),newPos[0]-'a',newPos,"Q",'w');
						}
					} else if ((promo == "B") || (promo == "b")) {
						if (turn) {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Bishop(stoi(newPos[1]),newPos[0]-'a',newPos,"b",'b');
						} else {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Bishop(stoi(newPos[1]),newPos[0]-'a',newPos,"B",'w');
						}
					} else if ((promo == "R") || (promo == "r")) {
						if (turn) {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Rook(stoi(newPos[1]),newPos[0]-'a',newPos,"r",'b');
						} else {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Rook(stoi(newPos[1]),newPos[0]-'a',newPos,"R",'w');
						}
					} else if ((promo == "N") || (promo == "n")) {
						if (turn) {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Knight(stoi(newPos[1]),newPos[0]-'a',newPos,"n",'b');
						} else {
							board[stoi(newPos[1])][newPos[0]-'a'] = new Knight(stoi(newPos[1]),newPos[0]-'a',newPos,"N",'w');
						}
					} else {
						cout << "Invalid input" << endl;
						continue;
					}
				}
			} else {
				pp->move(newPos);
			}
			turn = !turn;