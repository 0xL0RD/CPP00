NAME = phonebook
SRCS = main.cpp
OBJS = $(SRCS:%.cpp=%.o)
GCC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(GCC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
