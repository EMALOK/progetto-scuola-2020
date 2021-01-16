LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SFMLARGS=-I C:\SFML\include -L C:\SFML\lib
ODIR = build
OBJECTS=$(ODIR)/main.o $(ODIR)/GameClass.o $(ODIR)/SolidObject.o $(ODIR)/Player.o $(ODIR)/Coin.o $(ODIR)/MovingPlatform.o $(ODIR)/GameUtils.o
TOERASE=$(ODIR)\main.o $(ODIR)\GameClass.o $(ODIR)\Game.o $(ODIR)\SolidObject.o $(ODIR)\Player.o $(ODIR)\Coin.o $(ODIR)\MovingPlatform.o $(ODIR)\GameUtils.o
CXX := g++

.PHONY: clean

all: Game clean

$(ODIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(SFMLARGS)

$(ODIR)/%.o: %.hpp
	$(CXX) -c $< -o $@ $(SFMLARGS)

Game: $(OBJECTS)
	@echo "** Building..."
	$(CXX) -o $(ODIR)/Game $(OBJECTS) $(LIBS) $(SFMLARGS)

clean:
	-erase /S $(TOERASE)