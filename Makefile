CC			= cc
CFLAGS		= -g3 #-Wall -Werror -Wextra

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= includes/
SRC_DIR		= srcs/
OBJ_DIR		= objs/

CFLAGS		+= -I$(INCLUDES)

CLI_SRC		= client.c utils.c
SERV_SRC	= server.c utils.c
CLI_OBJ		= $(patsubst %.c, $(OBJ_DIR)%.o, $(CLI_SRC))
SERV_OBJ	= $(patsubst %.c, $(OBJ_DIR)%.o, $(SERV_SRC))

CLIENT		= client
SERVER		= server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) $(CLI_OBJ)
	$(CC) $(CFLAGS) $(CLI_OBJ) $(LIBFT) -o $(CLIENT)

$(SERVER): $(LIBFT) $(SERV_OBJ)
	$(CC) $(CFLAGS) $(SERV_OBJ) $(LIBFT) -o $(SERVER)

$(LIBFT):
	make -sC $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)

fclean: clean
	rm -rf $(CLIENT)
	rm -rf $(SERVER)
	make fclean -sC libft

re: fclean all

.PHONY: all bonus clean fclean re
