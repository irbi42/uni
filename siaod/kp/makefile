# cd /cygdrive/c/Users/user/Desktop/code/uni/siaod
CC = gcc
CFLAGS = -Wall 
LDFLAGS = 

# Имена файлов
TARGET = main
SOURCES = $(wildcard *.c) main.c
HEADERS = $(wildcard *.h)


ifeq ($(shell uname -o), Cygwin)
    # Cygwin specific settings
    TARGET := $(TARGET).exe
    RM = rm -f
else ifeq ($(OS),Windows_NT)
    RM = cmd //C del
    TARGET := $(TARGET).exe
else
    RM = rm -f
endif


# Основная цель
$(TARGET): $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS)

