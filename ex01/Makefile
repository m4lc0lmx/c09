NAME = RPN
SRCS =  RPN.cpp main.cpp
FLAG =  -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : ${SRCS}
	c++  ${SRCS} ${FLAG} -o ${NAME}

clean :
	rm -rf *.o
fclean : clean
	rm -rf ${NAME}
re : fclean all