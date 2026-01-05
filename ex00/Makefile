NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:%.cpp=%.o)
GCC = g++
CFLAGS = -Wall -Wextra -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(GCC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
