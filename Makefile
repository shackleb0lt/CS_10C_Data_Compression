
all:
	g++ HashNode.cpp HashTable.cpp Main.cpp -o encoder
clean:
	rm encoder Encoding.txt
