#########################################
#				PROGRAMS				#
#########################################
NAME = brain

#########################################
#				COMMANDS				#
#########################################
CC = c++
MKDIR =	mkdir -p
RM = rm -rf

#########################################
#			DIRECTORIES					#
#########################################
OBJ_DIR = objs/

#########################################
#			FLAGS COMPILATION			#
#########################################
CFLAGS = -Wall -Werror -Wextra -std=c++98
#CFLAGS += -fsanitize=address

#########################################
#			SOURCES	FILES				#
#########################################
SRCS = main.cpp

#########################################
#            OBJECT FILES    	        #
#########################################
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

#########################################
#				COLORS					#
#########################################
RED		:="\033[1;31m"
GREEN	:="\033[1;32m"
PURPLE	:="\033[1;35m"
CYAN	:="\033[1;36m"
EOC		:="\033[0;0m"

#########################################
#				RULES					#
#########################################
all:	${NAME}

${OBJ_DIR}%.o : %.cpp
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		@${RM} ${OBJ_DIR} 

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re