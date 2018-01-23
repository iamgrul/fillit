NAME=fillit

SRC= main.c ft_lstaddback.c ft_sqrt.c ft_check.c ft_printmap.c ft_vars_amount.c \
	ft_terms_amount.c ft_defmatr.c ft_calcesq.c ft_destr.c
	
OBJ= $(SRC:.c=.o)


%.o: %.c
	gcc -Wall -Wextra -Werror -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./Libft/ all 
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L./Libft -lft 

clean:
	/bin/rm -Rf $(OBJ)
	make -C ./Libft/ clean

fclean: clean
	/bin/rm -Rf $(NAME)
	@$(MAKE) -C ./Libft/ fclean 

re: fclean $(NAME)
	@$(MAKE) -C ./Libft/ re

.PHONY: all $(NAME) clean fclean re
