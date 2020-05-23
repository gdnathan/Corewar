# EPITECH PROJECT, 2020
# COREWAR
# File description:
# Corewar assembler


LIBMY_DIR    = ../lib/my
LIBMY        = $(LIBMY_DIR)/libmy.a

CC           = gcc
CC_FLAGS     = -I../lib/include -Iinclude

LD           = gcc
LD_FLAGS     =

GCOV         = gcov

OUTPUT       = corewar

SOURCE_DIR   = ./src
BUILD_DIR    = ../build/corewar

SOURCE       = $(shell find $(SOURCE_DIR) -name "*.c")
OBJS         = $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE))


define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef


all: $(OUTPUT)

re:: fclean
re:: all

bonus: $(BONUS_OUT)

$(OUTPUT): $(LIBMY) $(OBJS)
	@$(call rich_echo,"LD","$@")
	@$(LD) $(LD_FLAGS) $(OBJS) -o $@ $(LIBMY)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(call rich_echo,"CC","$@")
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@$(call rich_echo,"RM","$(BUILD_DIR)/*.o")
	@rm -f $(OBJS) $(OBJS_TESTS) $(OBJS_BONUS)
	@$(call rich_echo,"RM","*.gcda *.gcno")
	@find $(BUILD_DIR) -name "*.gcda" -delete -or -name "*.gcno" -delete 2>/dev/null; true

fclean: clean
	@$(call rich_echo,"RM","$(OUTPUT) $(TESTS_OUT) $(BONUS_OUT) *.gcov")
	@rm -f $(OUTPUT) $(TESTS_OUT) $(BONUS_OUT) $(wildcard *.gcov)

.PHONY: clean fclean re all tests tests_run bonus
