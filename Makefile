.PHONY: all
all: highFiveHiring

highFiveHiring: highFiveHiring.cpp
	g++ -o highFiveHiring highFiveHiring.cpp highFiveHiring.hpp

.PHONY: clean 
clean:
	rm -f highFiveHiring