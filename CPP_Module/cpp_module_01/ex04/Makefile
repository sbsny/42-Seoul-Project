NAME	=	test
SRCS	=	main.cpp
OBJS	=	$(SRCS:.cpp=.o)
DEPS	=	$(OBJS:.o=.d)

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98
DEPFLAGS=	-MMD -MP
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
			$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(DEPS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

-include $(DEPS)

.PHONY:		all clean fclean re
