NAME	=	PmergeMe
SRCS	=	main.cpp PmergeMe.cpp
OBJS	=	$(SRCS:.cpp=.o)
CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
			${CXX} ${CXXFLAGS} -c $< -o ${<:.cpp=.o}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:
			make fclean
			make all

.PHONY:		all clean fclean re
