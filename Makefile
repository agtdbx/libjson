#=================================MAKE FLAGES==================================#
MAKEFLAGS		:=	--no-print-directory
.DEFAULT_GOAL	:=	all

.DELETE_ON_ERROR:
.SECONDEXPANSION:

#=================================COMPILATION==================================#
CC					:=	g++
CFLAGS				:=	-MP -MMD
SDL_FLAGS			:=	-LSDL2 -lSDL2main -lSDL2 -lSDL2_image \
						-lSDL2_mixer -lSDL2_ttf
SDL_FLAGS_WINDOWS	:=	-LSDL2/lib -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer \
						-lSDL2_ttf
INCLUDE				:=	-I SDL2/include -I include/

ifdef DEBUG
CFLAGS	+=	-g
endif

#==================================EXECUTABLE==================================#
NAME		:=	json_parser
SOURCE_DIR	:=	srcs
BUILD_DIR	:=	.build
BIN_DIR		:=	bin

#=================================SOURCE FILES=================================#
SRCS	:=	$(SOURCE_DIR)/main.cpp \
			$(SOURCE_DIR)/JsonContent.cpp \
			$(SOURCE_DIR)/Json.cpp

SRCS_BUILD	:=	$(SOURCE_DIR)/JsonContent.cpp \
				$(SOURCE_DIR)/Json.cpp

#====================================OBJECTS===================================#
OBJS	:=	${SRCS:$(SOURCE_DIR)/%.cpp=$(BUILD_DIR)/%.o}
DEPS	:=	${SRCS:$(SOURCE_DIR)/%.cpp=$(BUILD_DIR)/%.d}
DIRS	:=	$(sort $(shell dirname $(OBJS)))

#=================================COUNTER UTILS================================#
# COUNTER, PERCENTAGE, PROGRESS_BAR
DISPLAY 			:= PERCENTAGE
PROGRESS_BAR_SIZE	:= 40
PERCENT				:=	0
NB_COMPILE			:=	1

ifndef RECURSION
TO_COMPILE			:=	$(shell make RECURSION=42 -n | grep Compiling | wc -l)
else
TO_COMPILE			:=	1
endif

#====================================COLORS====================================#
NOC			:=	\033[0m
BOLD		:=	\033[1m
UNDERLINE	:=	\033[4m
BLINK		:=	\033[5m
DARK_GRAY	:=	\033[1;30m
RED			:=	\033[1m\e[38;5;196m
GREEN		:=	\033[1m\e[38;5;76m
YELLOW		:=	\033[1m\e[38;5;220m
BLUE		:=	\033[1m\e[38;5;33m
PURPLE		:=	\033[1;35m
CYAN		:=	\033[1;36m
WHITE		:=	\033[0;37m

#=====================================RULES====================================#
all: $(BIN_DIR)/$(NAME)

$(DIRS):
	@mkdir -p $@

ifeq ($(DISPLAY), PERCENTAGE)
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $$(@D)
	@if [ $(NB_COMPILE) -eq 1 ];\
		then echo "$(BLUE)Begin compilation of $(TO_COMPILE) files$(NOC)";\
	fi;
	$(eval PERCENT=$(shell expr $(NB_COMPILE)00 / $(TO_COMPILE)))
	@if [ $(PERCENT) -lt 10 ];\
		then echo -n "  $(PERCENT) %";\
	elif [ $(PERCENT) -lt 100 ];\
		then echo -n " $(PERCENT) %";\
	else\
		echo -n "$(PERCENT) %";\
	fi;
	@echo " - $(PURPLE)Compiling $<$(NOC)"
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
	@if [ $(NB_COMPILE) -eq $(TO_COMPILE) ];\
		then echo "$(BLUE)Compilation done$(NOC)";\
	fi;
	$(eval NB_COMPILE=$(shell expr $(NB_COMPILE) + 1))

else ifeq ($(DISPLAY), PROGRESS_BAR)
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $$(@D)
	@if [ $(NB_COMPILE) -eq 1 ];\
		then make create_script; \
		echo "$(BLUE)Begin compilation of $(TO_COMPILE) files$(NOC)";\
	else printf "\e[1A\e[K";\
	fi;
	$(eval PERCENT=$(shell expr $(NB_COMPILE)00 / $(TO_COMPILE)))
	@./.progress_bar $(PERCENT)
	@echo " - $(PURPLE)Compiling $<$(NOC)"
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
	@if [ $(NB_COMPILE) -eq $(TO_COMPILE) ];\
		then echo "$(BLUE)Compilation done$(NOC)";\
	fi;
	$(eval NB_COMPILE=$(shell expr $(NB_COMPILE) + 1))

else
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $$(@D)
	@if [ $(NB_COMPILE) -eq 1 ];\
		then echo "$(BLUE)Begin compilation of $(TO_COMPILE) files$(NOC)";\
	fi;
	@echo "$(NB_COMPILE)/$(TO_COMPILE) - $(PURPLE)Compiling $<$(NOC)"
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<
	@if [ $(NB_COMPILE) -eq $(TO_COMPILE) ];\
		then echo "$(BLUE)Compilation done$(NOC)";\
	fi;
	$(eval NB_COMPILE=$(shell expr $(NB_COMPILE) + 1))

endif

$(BIN_DIR)/$(NAME): $(OBJS)
	@rm -rf .progress_bar
	@mkdir -p $(BIN_DIR)
	@$(CC) -o $@ $^ $(SDL_FLAGS)
	@echo "$(GREEN)Linking complete$(NOC)"

clean:
	@echo "$(RED)Delete objects$(NOC)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(RED)Delete binary$(NOC)"
	@rm -f $(BIN_DIR)/$(NAME)

re: fclean
	@make

run: $(BIN_DIR)/$(NAME)
	@echo "$(BLUE)Launch game$(NOC)"
	@cd $(BIN_DIR); ./$(NAME)
	@echo "$(GREEN)Have a nice day :)$(NOC)"

runval: $(BIN_DIR)/$(NAME)
	@echo "$(BLUE)Launch game$(NOC)"
	@cd $(BIN_DIR); valgrind ./$(NAME)
	@echo "$(GREEN)Have a nice day :)$(NOC)"

build:
	@echo "$(BLUE)Create a build for libjson$(NOC)"
	@rm -rf build_jsonlib
	@mkdir build_jsonlib
	@mkdir build_jsonlib/bin
	@mkdir build_jsonlib/lib
	@cp -r include build_jsonlib/include
	@cp README.md build_jsonlib/README.md
	@ar rc build_jsonlib/lib/libjson.a $(SRCS_BUILD)
	@g++ -shared -o build_jsonlib/bin/libjson.so $(INCLUDE) -fPIC $(SRCS_BUILD)
	@x86_64-w64-mingw32-g++ -shared -o build_jsonlib/bin/libjson.dll $(INCLUDE) $(SRCS_BUILD)
	@echo "$(GREEN)Done$(NOC)"

create_script:
	@echo '#include <unistd.h>' > .progress_bar.c
	@echo '#include <stdlib.h>' >> .progress_bar.c
	@echo 'int	main(int argc, char **argv)' >> .progress_bar.c
	@echo '{' >> .progress_bar.c
	@echo ' char *chars = "-#";' >> .progress_bar.c
	@echo ' int progress = atoi(argv[1]);' >> .progress_bar.c
	@echo ' float factor = 100.0f / $(PROGRESS_BAR_SIZE);' >> .progress_bar.c
	@echo ' write(1, "[", 1);' >> .progress_bar.c
	@echo ' for (int i = 0; i < $(PROGRESS_BAR_SIZE); i++)' >> .progress_bar.c
	@echo '  write(1, &chars[i * factor < progress], 1);' >> .progress_bar.c
	@echo ' write(1, "]", 1);' >> .progress_bar.c
	@echo ' return (0);' >> .progress_bar.c
	@echo '}' >> .progress_bar.c
	@gcc .progress_bar.c -o .progress_bar
	@rm -rf .progress_bar.c

.PHONY: all clean fclean re run runval build create_script

-include $(DEPS)
