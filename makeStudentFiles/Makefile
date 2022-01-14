main.x: main.o MakeTree.o systemInterface.o Token.o Tokenizer.o Graph.o GraphNode.o
	g++ -std=c++17 main.o MakeTree.o systemInterface.o Token.o Tokenizer.o Graph.o GraphNode.o -o main.x

main.o: main.cpp Graph.hpp Token.hpp Tokenizer.hpp
	g++ -std=c++17 -c main.cpp -o main.o

MakeTree.o: MakeTree.hpp MakeTree.cpp TreeNode.hpp 
	g++ -std=c++17 -c MakeTree.cpp -o MakeTree.o

systemInterface.o: systemInterface.hpp systemInterface.cpp
	g++ -std=c++17 -c systemInterface.cpp -o systemInterface.o

Token.o: Token.hpp Token.cpp
	g++ -std=c++17 -c Token.cpp -o Token.o

Tokenizer.o: Tokenizer.cpp Tokenizer.hpp Token.hpp
	g++ -std=c++17 -c Tokenizer.cpp -o Tokenizer.o

Graph.o: Graph.cpp Graph.hpp MakeTree.hpp Token.hpp Tokenizer.hpp GraphNode.hpp
	g++ -std=c++17 -c Graph.cpp -o Graph.o

GraphNode.o: GraphNode.cpp GraphNode.hpp systemInterface.hpp Token.hpp
	g++ -std=c++17 -c GraphNode.cpp -o GraphNode.o

clean:
	rm -fr main.x *.o
