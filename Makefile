# EPITECH PROJECT, 2018
# MAKETEMPLATE
# File description:
# Template Makefile for Epitech projects


LIBMY_DIR    = lib/my
LIBMY        = $(LIBMY_DIR)/libmy.a

CC           = gcc
CC_FLAGS     =
ifneq (,$(findstring tests,$(MAKECMDGOALS)))
	CC_FLAGS += -D__TESTS -fprofile-arcs -ftest-coverage
endif

LD           = gcc
LD_FLAGS     =
LD_TESTFLAGS = -lcriterion -lgcov --coverage -Wl,-rpath /usr/local/lib

MAKE         = make

GCOV         = gcov

OUTPUT       = program
TESTS_OUT    = program_tests
BONUS_OUT    = program_bonus

ASM_DIR		 = asm
VM_DIR       = corewar

SOURCE_DIR   = src
BUILD_DIR    = build
TESTS_DIR    = tests

SOURCE       = $(shell find $(SOURCE_DIR) -name "*.c")
SOURCE_TESTS = $(shell find $(TESTS_DIR)  -name "*.c")
OBJS         = $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.test.o,$(SOURCE))
OBJS_TESTS   = $(patsubst $(TESTS_DIR)/%.c,$(BUILD_DIR)/%.test.o,$(SOURCE_TESTS))


define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef


all: asm vm

re: fclean all

tests: clean $(TESTS_OUT)

tests_run: tests
	$(MAKE) -C $(LIBMY_DIR) tests_run
	./$(TESTS_OUT)
	$(GCOV) $(OBJS)

asm: $(ASM_DIR)/Makefile
	@$(MAKE) -C $(ASM_DIR) all

vm: $(VM_DIR)/Makefile
	@$(MAKE) -C $(VM_DIR) all

$(LIBMY): $(LIBMY_DIR)/Makefile
	@$(MAKE) -C $(LIBMY_DIR) all copy-heads

$(TESTS_OUT): $(LIBMY) $(OBJS) $(OBJS_TESTS)
	@$(call rich_echo,"TESTLD","$@")
	@$(LD) $(LD_FLAGS) $(LD_TESTFLAGS) $(OBJS) $(OBJS_TESTS) -o $@ $(LIBMY)


$(BUILD_DIR)/%.test.o: $(TESTS_DIR)/%.c
	@$(call rich_echo,"TESTCC","$@")
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(call rich_echo,"CC","$@")
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@$(call rich_echo,"RM","$(BUILD_DIR)/*.o")
	@rm -f $(OBJS) $(OBJS_TESTS)
	@$(call rich_echo,"RM","*.gcda *.gcno")
	@find $(BUILD_DIR) -name "*.gcda" -delete -or -name "*.gcno" -delete; true
	@$(MAKE) -C $(LIBMY_DIR) clean
	@$(MAKE) -C $(ASM_DIR) clean
	@$(MAKE) -C $(VM_DIR) clean

fclean: clean
	@$(call rich_echo,"RM","$(OUTPUT) $(TESTS_OUT) $(BONUS_OUT) *.gcov")
	@rm -f $(OUTPUT) $(TESTS_OUT) $(BONUS_OUT) $(wildcard *.gcov)
	@$(MAKE) -C $(LIBMY_DIR) fclean
	@$(MAKE) -C $(ASM_DIR) fclean
	@$(MAKE) -C $(VM_DIR) fclean

.PHONY: clean fclean re all asm vm tests tests_run
.NOTPARALLEL:
