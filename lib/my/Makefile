# EPITECH PROJECT, 2020
# COREWAR
# File description:
# Corewar VM


CC          := gcc
CC_FLAGS    :=
ifneq (,$(findstring tests,$(MAKECMDGOALS)))
	CC_FLAGS += -D__TESTS -fprofile-arcs -ftest-coverage
endif

AR          := ar
AR_FLAGS    := rcs

LD          := gcc
LD_FLAGS    := -lcriterion -lgcov --coverage -Wl,-rpath /usr/local/lib

GCOV		:= gcov

DOXYGEN		:= doxygen
OPEN		:= xdg-open

OUTPUT      := libmy.a
TESTS_OUT   := libmy_tests
HEADS_OUT   := ../include

SOURCE_DIR  := src
HEADS_DIR   := include
BUILD_DIR   := build
TESTS_DIR   := tests

SOURCE       = $(shell find $(SOURCE_DIR) -name '*.c')
SOURCE_HEADS = $(shell find $(HEADS_DIR) -name '*.h')
SOURCE_TESTS = $(shell find $(TESTS_DIR) -name '*.c')
OBJS         = $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE))
OBJS_TESTS   = $(patsubst $(TESTS_DIR)/%.c,$(BUILD_DIR)/tests/%.o,$(SOURCE_TESTS))
DEST_HEADS   = $(patsubst $(HEADS_DIR)/%,$(HEADS_OUT)/%,$(SOURCE_HEADS))


define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef


all: $(OUTPUT)

tests: clean $(TESTS_OUT)

tests_run: tests
	./$(TESTS_OUT)
	$(GCOV) $(OBJS)

re: fclean all

copy-heads: $(DEST_HEADS)

doc: README.md $(SOURCE_HEADS)
	$(DOXYGEN) && $(OPEN) doc/html/index.html

$(HEADS_OUT)/%: $(HEADS_DIR)/%
	@$(call rich_echo,"COPY","$@")
	@mkdir -p $(HEADS_OUT)
	@cp $< $@

$(OUTPUT): $(OBJS)
	@$(call rich_echo,"AR","$@")
	@$(AR) $(AR_FLAGS) $@ $(OBJS)

$(TESTS_OUT): $(OBJS) $(OBJS_TESTS)
	@$(call rich_echo,"TESTLD","$@")
	@$(LD) $(LD_FLAGS) $(OBJS) $(OBJS_TESTS) -o $@

$(BUILD_DIR)/tests/%.o: $(TESTS_DIR)/%.c
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
	@find $(BUILD_DIR) -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean: clean
	@$(call rich_echo,"RM","$(OUTPUT) $(TESTS_OUT) *.gcov $(HEADS_OUT)/*.h")
	@rm -f $(OUTPUT) $(TESTS_OUT) $(wildcard *.gcov) $(DEST_HEADS)

.PHONY: all tests tests_run re copy-heads clean fclean doc
.NOTPARALLEL:
