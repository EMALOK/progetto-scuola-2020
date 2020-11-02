LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SFMLARGS=-I C:\SFML\include -L C:\SFML\lib
CXX := g++

all: Game

%.o: %.cpp
	$(CXX) $(SFMLARGS) -c $< -o $@

%.o: %.hpp
	$(CXX) $(SFMLARGS) -c $< -o $@

Game: main.o
	@echo "** Building..."
	$(CXX) $(SFMLARGS) -o Game main.o $(LIBS)