#	Names
NAME		=	robot

#	Compilation
CXX			=	c++
CXXFLAG		=	-std=c++11 -Wall -Wextra -Werror
RM			=	rm -rf
SRC_DIR 	= 	src/
TEST_DIR	=	test/

SRC		 	=	$(notdir $(shell find $(SRC_DIR) -type f -name "*.cpp"))
TEST_SRC	=	$(notdir $(shell find $(TEST_DIR) -type f -name "*.cpp"))
OBJ_DIR		=	obj
OBJ 		= 	$(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
INC_DIR		=	include
INC			=	$(shell find $(INC_DIR) -type f -name "*.hpp")
IFLAGS 		=	-I $(INC_DIR)
vpath			%.cpp $(shell find $(SRC_DIR) -type d)
.SUFFIXES: 		.cpp .o .hpp

#	Color
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		=	\033[2K\c

#	Rules
#		Defaults:
all				:	init $(NAME)
					@ echo "$(_SUCCESS) Compilation done"

#		Init:
init			:
					@ $(shell mkdir -p $(OBJ_DIR))

#		Compile:
$(NAME)			:	$(OBJ) $(INC)
					@ echo "$(_INFO) Initialize $(NAME)"
				 	@ $(CXX) $(CXXFLAG) $(IFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o	:	%.cpp
					@ echo "\t$(_YELLOW)Compiling$(_RESET) $*.cpp"
					@ $(CXX) $(CXXFLAG) $(IFLAGS) -c $< -o $@
					@ echo "$(_CLEAR)"

#		Clean:
clean			:
					@ echo "$(_INFO) Deleted object files and directories"
					@ $(RM) $(OBJ_DIR)
					@ echo "$(_SUCCESS) Working directory clean"

#		FClean:
fclean			:	clean
					@ $(RM) $(NAME)

#		Re:
re				: 	fclean all

#		Run:
run				:	all
				    @ ./$(NAME)
#		Phony:
.PHONY: 		all fclean clean re