PATH_BIN	=	./bin
PATH_SRC	=	./src
PATH_INCLUDE	=	./include
PATH_LIBRARY	=	.

NAME		=	$(PATH_BIN)/t3-strace

SRCS		=	\
			$(PATH_SRC)/main.c		\
			$(PATH_SRC)/goto_child.c	\
			$(PATH_SRC)/goto_parent.c	\
			$(PATH_SRC)/print_syscall.c	\
			$(PATH_SRC)/get_flags_value.c	\
			$(PATH_SRC)/usage.c		\
			$(PATH_SRC)/syscalls.c		\
			$(PATH_SRC)/print_char.c	\
			$(PATH_SRC)/print_path.c	\
			$(PATH_SRC)/print_flags.c	\
			$(PATH_SRC)/print_buf.c		\
			$(PATH_SRC)/print_read_write.c	\
			$(PATH_SRC)/print_open.c	\
			$(PATH_SRC)/print_close.c	\
			$(PATH_SRC)/print_munmap.c	\
			$(PATH_SRC)/print_access.c	\
			$(PATH_SRC)/print_mprotect.c	\
			$(PATH_SRC)/print_set_tid_address.c	\
			$(PATH_SRC)/print_set_robust_list.c	\
			$(PATH_SRC)/print_futex.c		\
			$(PATH_SRC)/print_rt_sigaction.c	\
			$(PATH_SRC)/print_getrlimit.c	\
			$(PATH_SRC)/print_uname.c	\
			$(PATH_SRC)/print_statfs64.c	\
			$(PATH_SRC)/print_brk.c		\
			$(PATH_SRC)/print_fstat64.c	\
			$(PATH_SRC)/print_stat64.c	\
			$(PATH_SRC)/print_set_thread_area.c	\
			$(PATH_SRC)/print_execve.c	\
			$(PATH_SRC)/print_ioctl.c	\
			$(PATH_SRC)/print_mmap2.c

OBJS		=	$(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -f
MKDIR		=	mkdir -p
ECHO		=	/usr/bin/env echo
ECHOE		=	$(ECHO) -e
ECHON		=	$(ECHO) -n

SUCCESS		=	$(ECHOE) "[\033[32mSUCCESS\033[0m] "
FAILED		=	$(ECHOE) "[\033[31mFAILED\033[0m] "

INCLUDES	+=	-I$(PATH_INCLUDE)
LIBRARIES	+=	-L$(PATH_LIBRARY)

DEBUG_TRUE	=	-g -DDEBUG
COMPAT		+=	-D__BSD_VISIBLE
WARNINGS	+=	-Wall -W -Wstrict-prototypes

CFLAGS		+=	$(INCLUDES) $(DEBUG_$(DEBUG)) $(COMPAT) $(WARNINGS)
LDFLAGS		+=	$(LIBRARIES)

.SUFFIXES	:	.c.o

$(NAME)		:	$(OBJS)
			-@$(ECHON) "*** Making directory $(PATH_BIN) "
			-@$(MKDIR) $(PATH_BIN) && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Compiling $(OBJS) to $@ "
			-@$(CC) -o $@ $(OBJS) $(LDFLAGS) && $(SUCCESS) || $(FAILED)

all		:	$(NAME)

clean		:
			-@$(ECHON) "*** Removing $(PATH_SRC)/*~ "
			-@$(RM) $(PATH_SRC)/*~ && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Removing $(PATH_SRC)/*.o "
			-@$(RM) $(PATH_SRC)/*.o && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Removing $(PATH_BIN)/*.core "
			-@$(RM) $(PATH_BIN)/*.core && $(SUCCESS) || $(FAILED)

fclean		:	clean
			-@$(ECHON) "*** Removing $(NAME) "
			-@$(RM) $(NAME) && $(SUCCESS) || $(FAILED)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			-@$(ECHON) "*** Compiling $< to $@ "
			-@$(CC) $(CFLAGS) -c $< -o $@ && $(SUCCESS) || $(FAILED)
