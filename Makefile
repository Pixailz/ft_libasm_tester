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
							wrapper/read.c \
							wrapper/strcmp.c \
							wrapper/strcpy.c \
							wrapper/strdup.c \
							wrapper/strlen.c \
							wrapper/write.c

LIBTEST_OBJ				:= $(addprefix $(LIBTEST_OBJ_DIR)/,$(LIBTEST_SRC:%.c=%.o))
LIBTEST_SRC				:= $(addprefix $(LIBTEST_SRC_DIR)/,$(LIBTEST_SRC))

CC						:= gcc
CCFLAGS					:= -Wall -Wextra -Werror -I./inc

PRINT					= @echo -e

# DEFAULT RULES
all:					test

# COMPILING LIBASM
$(LIBASM_TARGET):
	$(PRINT) \\x1b[31mCompiling\\x1b[0m libasm
	make -C $(LIBASM_DIR)
	$(PRINT) \\x1b[32mCompiled\\x1b[0m libasm

clean:
	rm -rf $(LIBTEST_OBJ_DIR) $(LIBTEST_TARGET)

fclean:					clean
	rm -rf $(NAME)

re:						fclean all

clean_all:				clean
	$(PRINT) \\x1b[31mCleaning\\x1b[0m libasm
	make -C $(LIBASM_DIR) clean
	$(PRINT) \\x1b[32mCleaned\\x1b[0m libasm

fclean_all:				fclean
	$(PRINT) \\x1b[31mFull cleaning\\x1b[0m libasm
	make -C $(LIBASM_DIR) fclean
	$(PRINT) \\x1b[32mFull cleaned\\x1b[0m libasm

re_all:					fclean_all all

# COMPILING TESTER
$(LIBTEST_OBJ):			$(LIBTEST_OBJ_DIR)/%.o: $(LIBTEST_SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p $(@D) || true
	$(CC) $(CCFLAGS) -c $< -o $@

$(LIBTEST_TARGET):		$(LIBTEST_OBJ)
	ar rcs $(LIBTEST_TARGET) $(LIBTEST_OBJ)

test:					$(LIBASM_TARGET) $(LIBTEST_TARGET)
	$(CC) $(CCFLAGS) $(LIBTEST_MAIN) $(LIBTEST_TARGET) $(LIBASM_TARGET) -o $(NAME)
