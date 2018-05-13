CC = g++
CXXFLAGS = -g -Wall -O2 -o
PWD = $(shell pwd)
INCLUDE_DIR = -I$(PWD)/table/include 
TABLE = $(PWD)/table
LD_DIR = -L$(PWD)/table
LD = -lLinkList
STATIC = libLinkList.a
TARGET = LinkList_ps
ALL_DIR = $(TABLE) \
		  $(PWD)/table_process_main
DEBUG = -DDEBUG_TO_FILE
PRINTF = -DDEBUG_PRINTF

SRC := $(wildcard $(TABLE)/src/*.cpp)
MAIN:= $(wildcard $(PWD)/table_process_main/src/*.cpp)


OBJ1 := $(patsubst %.cpp, %.o, $(SRC))
OBJ2 := $(patsubst %.cpp, %.o, $(MAIN))


export CC CXXFLAGS PWD INCLUDE_DIR TABLE LD_DIR LD STATIC TARGET ALL_DIR SRC MAIN OBJ1 OBJ2 DEBUG PRINTF






all:
	@make -C $(TABLE)
	@make -C $(PWD)/table_process_main
.PHONY:clean
clean:
	@$(RM) $(TABLE)/$(STATIC)
	@echo ' CLEAN . '
	@echo ' $(TABLE)/$(STATIC)'
	@$(RM) $(PWD)/table_process_main/$(TARGET)
	@echo ' $(PWD)/table_process_main/$(TARGET)'
	@$(RM) $(OBJ1)
	@$(RM) $(OBJ2)
