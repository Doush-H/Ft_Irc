NAME := ircserv
CPP := c++
# CPPFLAGS := -std=c++98 -Wall -Wextra -Werror
CPPFLAGS := -std=c++98


SRC := Message.cpp Server.cpp User.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

DEPS := Message.hpp Server.hpp User.hpp

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@printf "\033[32;1mCompilation Completed\033[0m\n"
	@printf "\033[32;3mProgram name: $(NAME)\033[0m\n"
	@printf "\033[32;3mRun: ./$(NAME) <port> <password>\033[0m\n"

%.o: %.cpp $(DEPS)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@clear
	@printf "\033[31mObject files cleaned\033[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "\033[31mExecutable cleaned\033[0m\n"

re: fclean all
