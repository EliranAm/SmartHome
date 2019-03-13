FLAGS = -g -Werror -Wall -ansi -pedantic


ParserApp: ParserUnitTest.cpp libParser.a
	g++ $(FLAGS) -o ParserApp ParserUnitTest.cpp libParser.a


libParser.a: XmlParser.o ParserFactory.o
	ar rcs libParser.a XmlParser.o ParserFactory.o


ParserFactory.o: ParserFactory.cpp ParserFactory.h
	g++ -c $(FLAGS) ParserFactory.cpp

XmlParser.o: XmlParser.cpp XmlParser.h
	g++ -c $(FLAGS) XmlParser.cpp


clean:
	rm -f ParserApp libParser.a ParserFactory.o XmlParser.o *~
