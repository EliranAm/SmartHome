FLAGS = -g -Werror -Wall -ansi -pedantic


libPubSub.a: Router.o Topic.o Message.o MessageFactory.o RouterFactory.o Publisher.o
	ar rcs libPubSub.a Router.o Topic.o Message.o MessageFactory.o RouterFactory.o Publisher.o



RouterFactory.o: RouterFactory.cpp RouterFactory.h
	g++ -c $(FLAGS) RouterFactory.cpp


MessageFactory.o: MessageFactory.cpp MessageFactory.h
	g++ -c $(FLAGS) MessageFactory.cpp


Router.o: Router.cpp Router.h IRouter.h ISubscriber.h Publisher.h
	g++ -c $(FLAGS) Router.cpp
	

Topic.o: Topic.cpp Topic.h
	g++ -c $(FLAGS) Topic.cpp


Message.o: Message.cpp Message.h IMessage.h
	g++ -c $(FLAGS) Message.cpp

Publisher.o: Publisher.cpp Publisher.h
	g++ -c $(FLAGS) Publisher.cpp


clean:
	rm -f libPubSub.a Publisher.o Router.o Topic.o Message.o MessageFactory.o RouterFactory.o *~
	
