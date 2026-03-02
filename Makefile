CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -O0 -gdwarf-4 -Wall -Wextra -Werror -pedantic -fsanitize=address,undefined,implicit-conversion,local-bounds -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize-address-use-after-return=always -Wno-error=unused-parameter $(INCLUDES)

exec: bin/exec
tests: bin/tests

obj/project.o: ./includes/project.hpp ./src/project.cc ./includes/helper.hpp
	$(CXX) $(CXXFLAGS) -c ./src/project.cc -o $@

obj/client.o: ./includes/client.hpp ./src/client.cc ./includes/helper.hpp
	$(CXX) $(CXXFLAGS) -c ./src/client.cc -o $@

bin/exec: ./obj/project.o ./obj/client.o ./src/driver.cc
	$(CXX) $(CXXFLAGS) ./obj/client.o ./obj/project.o ./src/driver.cc -o $@

bin/tests: ./obj/project.o ./obj/client.o ./tests/tests.cc 
	$(CXX) $(CXXFLAGS) ./tests/tests.cc ./obj/client.o ./obj/project.o -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*