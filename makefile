compile:
	g++ -Wall -c Project3.cpp
	g++ -Wall -c Cipher.cpp
	g++ -Wall -c Queue.cpp
	g++ -Wall -c CipherAdvanced.cpp
	g++ -Wall Project3.o Cipher.o Queue.o CipherAdvanced.cpp -o project3.out
run:
	./project3.out
clean:
	rm *.out