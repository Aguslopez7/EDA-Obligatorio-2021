todo: main.o editor.o
	g++ -Wall -o main main.o editor.o
main.o: main.cpp
	g++ -Wall -c main.cpp
editor.o: editor.h editor.cpp
	g++ -Wall -c editor.cpp
# se deben agregar aca las reglas de compilacion para los modulos que agreguen
# agregar tambien las dependencias en la regla todo:
clean:
	rm -f main
	rm -f *.o
