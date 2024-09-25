CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = main.o

all: mutantstack_test

mutantstack_test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o mutantstack_test $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) mutantstack_test

fclean: clean
	rm -f $(NAME)

re: fclean all
