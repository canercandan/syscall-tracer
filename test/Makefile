all:
	gcc -o hello hello.c
	gcc -o filer filer.c
	gcc -o execme execme.c

clean:
	rm -f *.o *~

fclean: clean
	rm -f hello filer execme

re:	fclean all

.PHONY:
	all clean fclean re
