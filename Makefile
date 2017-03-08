CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g 
OBJECTS = main.o textdisplay.o graphicsdisplay.o piece.o knight.o bishop.o king.o pawn.o queen.o rook.o player.o human.o playerAI1.o playerAI2.o playerAI3.o game.o window.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = chess

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
