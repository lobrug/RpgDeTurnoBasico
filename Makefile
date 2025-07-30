# Verifica o sistema operacional
ifdef OS
	OS := $(strip $(OS))
else
	OS := $(strip $(shell uname))
endif

BINNAME = main
CXX = g++

ifeq ($(OS),Windows_NT)
	INCLUDE = -I./include/ -L./libwin
	EXTRA_FLAGS = -Wall -Wextra -std=c++17 -Wno-missing-braces -lraylib -lopengl32 -lgdi32 -lwinmm
	BIN = $(BINNAME).exe
	RM = del /Q /F
else
	INCLUDE = -I./include/ -L./lib
	EXTRA_FLAGS = -Wall -Wextra -std=c++17 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	BIN = $(BINNAME)
	RM = rm -f
endif

SRC = $(wildcard ./*.cpp) $(wildcard ./include/*.cpp)

all:
	$(CXX) $(SRC) -g $(INCLUDE) $(EXTRA_FLAGS) -o $(BIN)

run: all
	./$(BIN)

clean:
	$(RM) $(BIN)

valgrind: all
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BIN)
