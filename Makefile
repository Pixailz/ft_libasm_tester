NAME					:= libasm_tester
ifeq ($(LIBASM_DIR),)
LIBASM_DIR				:= ..
endif

LIBASM_TARGET			:= $(LIBASM_DIR)/libasm.a

LIBTEST_OBJ_DIR			:= obj
LIBTEST_SRC_DIR			:= src
LIBTEST_TARGET			:= libtest.a
LIBTEST_MAIN			:= $(LIBTEST_SRC_DIR)/main.c

LIBTEST_SRC				:=	print.c \
							test.c \
							wrapper/read.c \
							wrapper/strcmp.c \
							wrapper/strcpy.c \
							wrapper/strdup.c \
							wrapper/strlen.c \
							wrapper/write.c

LIBTEST_OBJ				:= $(addprefix $(LIBTEST_OBJ_DIR)/,$(LIBTEST_SRC:%.c=%.o))
LIBTEST_SRC				:= $(addprefix $(LIBTEST_SRC_DIR)/,$(LIBTEST_SRC))

CC						:= gcc
CCFLAGS					:= -Wall -Wextra -I./inc

ifneq ($(DEBUG),1)
CCFLAGS					+= -Werror
else
CCFLAGS					+= -ggdb
endif

MAKECMD					:= make -s

INFO					= @/usr/bin/echo -e [\\x1b[32m+\\x1b[0m] $(1)

# DEFAULT RULES
all:					$(NAME)

$(NAME):				$(LIBASM_TARGET) $(LIBTEST_TARGET)
	$(call INFO,Compiling tester)
	$(CC) $(CCFLAGS) $(LIBTEST_MAIN) $(LIBTEST_TARGET) $(LIBASM_TARGET) -o $(NAME)

print_obj:
	$(call INFO,Creating tester object)

# COMPILING TESTER
$(LIBTEST_TARGET):		$(LIBTEST_OBJ)
	$(call INFO,Creating tester archive)
	ar rcs $(LIBTEST_TARGET) $(LIBTEST_OBJ)

$(LIBTEST_OBJ):			$(LIBTEST_OBJ_DIR)/%.o: $(LIBTEST_SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p $(@D) || true
	$(CC) $(CCFLAGS) -c $< -o $@

# COMPILING LIBASM
$(LIBASM_TARGET):
	$(MAKECMD) -C $(LIBASM_DIR)

clean:
	$(call INFO,Cleaning tester)
	rm -rf $(LIBTEST_OBJ_DIR) $(LIBTEST_TARGET)

fclean:					clean
	$(call INFO,Full cleaning tester)
	rm -rf $(NAME)

re:						fclean all

clean_all:				clean
	$(MAKECMD) -C $(LIBASM_DIR) clean

fclean_all:				fclean
	$(MAKECMD) -C $(LIBASM_DIR) fclean

re_all:					fclean_all all

run:					$(NAME)
	$(call INFO,Running tester)
	./$(NAME)
