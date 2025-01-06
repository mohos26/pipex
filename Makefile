AIDFILES = aid_files/ft_putendl_fd.c aid_files/ft_putstr_fd.c aid_files/ft_split.c aid_files/ft_strncmp.c aid_files/get_next_line.c aid_files/get_next_line_utils.c
SRCS = src/ft_command_path.c src/ft_isfile.c src/pipex.c src/ft_execute.c src/ft_process_command.c src/ft_exit.c src/ft_redirecting.c
SRCSB = bonus/ft_execute.c bonus/ft_process_command.c bonus/ft_isfile.c bonus/ft_exit.c bonus/ft_here_doc.c bonus/ft_redirecting.c bonus/ft_command_path.c bonus/pipex.c
OBJS = ${AIDFILES:.c=.o} ${SRCS:.c=.o}
OBJSB = ${AIDFILES:.c=.o} ${SRCSB:.c=.o}

NAME = pipex

%.o: %.c pipex.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
	cc -Wall -Werror -Wextra $(OBJS) -o $(NAME)

bonus: .bonus

.bonus: $(OBJSB)
	cc -Wall -Werror -Wextra $(OBJSB) -o $(NAME)
	@touch .bonus

clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)

fclean: clean
	rm -f $(NAME)
	@rm -f .bonus

re: fclean all

.PHONY: clean