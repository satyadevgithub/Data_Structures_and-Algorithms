# Makefile
CC = gcc
CFLAGS = -Wall -g
TARGET = Data_Structures_and_Algorithms
SRCS = main.c array.c circular_queue.c circular_sll.c queue.c single_linked_list.c stack.c tree.c double_linked_list.c avl_tree.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

