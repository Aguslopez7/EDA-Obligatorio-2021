todo: main.o editor.o texto.o linea.o palabra.o diccionario.o 
	g++ -Wall -o obligatorio main.o editor.o texto.o linea.o palabra.o diccionario.o 

main.o: main.cpp
	g++ -Wall -c main.cpp

editor.o: editor.h editor.cpp
	g++ -Wall -c editor.cpp

texto.o: texto.h texto.cpp
	g++ -Wall -c texto.cpp

linea.o: linea.h linea.cpp
	g++ -Wall -c linea.cpp

palabra.o: palabra.h palabra.cpp
	g++ -Wall -c palabra.cpp

diccionario.o: diccionario.h diccionario.cpp
	g++ -Wall -c diccionario.cpp

run: todo
	clear
	./obligatorio

clean:
	rm -f obligatorio
	rm -f *.o
