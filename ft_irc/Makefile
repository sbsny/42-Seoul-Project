NAME        := ircserv

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror
DEPFLAGS    := -MMD -MP

RM          := rm -f

SRCS        := $(sort $(wildcard *.cpp) $(wildcard Commands/*.cpp))
OBJS        := $(SRCS:.cpp=.o)
DEPS        := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "🔧 Linking $(NAME)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@echo "🧱 Compiling $<"
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	@echo "🧹 Cleaning objects/deps"
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	@echo "🗑️  Removing binary"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
