CC=g++ -Wall
exe=Pokemon

$(exe): Trainer.o Pokemon.o Pokeball.o Field.o Froakie.o Bagon.o Honedge.o Larvitar.o Starly.o Treecko.o game.o play.o
	$(CC) Trainer.o Pokemon.o Pokeball.o Field.o Froakie.o Bagon.o Honedge.o Larvitar.o Starly.o Treecko.o game.o play.o -o $(exe)
Trainer.o: Trainer.cpp
	$(CC) -c Trainer.cpp
Pokemon.o: Pokemon.cpp
	$(CC) -c Pokemon.cpp
Pokeball.o: Pokeball.cpp
	$(CC) -c Pokeball.cpp
Field.o: Field.cpp
	$(CC) -c Field.cpp
Froakie.o: Froakie.cpp
	$(CC) -c Froakie.cpp
Bagon.o: Bagon.cpp
	$(CC) -c Bagon.cpp
Honedge.o: Honedge.cpp
	$(CC) -c Honedge.cpp
Larvitar.o: Larvitar.cpp
	$(CC) -c Larvitar.cpp
Starly.o: Starly.cpp
	$(CC) -c Starly.cpp
Treecko.o: Treecko.cpp
	$(CC) -c Treecko.cpp
game.o: game.cpp
	$(CC) -c game.cpp
play.o: play.cpp
	$(CC) -c play.cpp

clean:
	rm -f $(exe) *.o
