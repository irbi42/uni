# cd /cygdrive/c/Users/user/Desktop/code/uni/siaod
CC = gcc
CFLAGS = -Wall 
LDFLAGS = 

# Имена файлов
TARGET = main
SOURCES = $(wildcard pr*.c) rjin.c main.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(wildcard *.h) rjin.h


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
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) -lm

# Общее правило для компиляции .c файлов
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	$(RM) $(OBJECTS) $(TARGET)

# Пересборка
rebuild: clean $(TARGET)

.PHONY: clean rebuild