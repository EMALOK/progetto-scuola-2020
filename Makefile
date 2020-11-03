LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SFMLARGS=-I C:\SFML\include -L C:\SFML\lib
ODIR = build
OBJECTS=$(ODIR)/main.o $(ODIR)/GameClass.o $(ODIR)/SolidObject.o
TOERASE=$(ODIR)\main.o $(ODIR)\GameClass.o $(ODIR)\Game.o $(ODIR)\SolidObject.o
CXX := g++

.PHONY: clean

all: Game

$(ODIR)/%.o: %.cpp
	$(CXX) $(SFMLARGS) -c $< -o $@

$(ODIR)/%.o: %.hpp
	$(CXX) $(SFMLARGS) -c $< -o $@

Game: $(OBJECTS)
	@echo "** Building..."
	$(CXX) $(SFMLARGS) -o $(ODIR)/Game $(OBJECTS) $(LIBS)

clean:
	-erase /S $(TOERASE)