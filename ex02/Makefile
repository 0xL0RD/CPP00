NAME = Account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp		tests.cpp
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
