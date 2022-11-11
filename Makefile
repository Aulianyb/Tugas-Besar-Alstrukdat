
# ########################################################################
# ####################### Makefile Template ##############################
# ########################################################################

# # Compiler settings - Can be customized.
# CC = gcc
# CXXFLAGS = -std=c11 -Wall
# LDFLAGS = 

# # Makefile settings - Can be customized.
# APPNAME = BNMO
# EXT = .c
# SRCDIR = ./src
# OBJDIR = obj

# ############## Do not change anything from here downwards! #############
# SRC = $(wildcard $(SRCDIR)/*$(EXT))
# OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
# DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# # UNIX-based OS variables & settings
# RM = rm
# DELOBJ = $(OBJ)
# # Windows OS variables & settings
# DEL = del
# EXE = .exe
# WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

# ########################################################################
# ####################### Targets beginning here #########################
# ########################################################################

# all: $(APPNAME)

# # Builds the app
# $(APPNAME): $(OBJ)
# 	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# # Creates the dependecy rules
# %.d: $(SRCDIR)/%$(EXT)
# 	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# # Includes all .h files
# -include $(DEP)

# # Building rule for .o files and its .c/.cpp in combination with all .h
# $(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
# 	$(CC) $(CXXFLAGS) -o $@ -c $<

# ################### Cleaning rules for Unix-based OS ###################
# # Cleans complete project
# .PHONY: clean
# clean:
# 	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# # Cleans only all files with the extension .d
# .PHONY: cleandep
# cleandep:
# 	$(RM) $(DEP)

# #################### Cleaning rules for Windows OS #####################
# # Cleans complete project
# .PHONY: cleanw
# cleanw:
# 	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# # Cleans only all files with the extension .d
# .PHONY: cleandepw
# cleandepw:
# 	$(DEL) $(DEP)

compile:
	@gcc src/main.c src/Function/ADT/mesinkata.c src/Function/ADT/mesinkarakter.c src/Function/ADT/array.c src/Function/ADT/queue.c src/Function/Create_Game/Create_Game.c src/Function/List_Game/List_Game.c src/Function/Delete_Game/deletegame.c src/Function/Help/help.c src/Function/Queue_Game/queuegame.c src/Function/Skip_Game/skipgame.c src/Function/Play_Game/playgame.c src/console.c src/Function/RNG/rng.c src/Function/Dinner_dash/Dinner_dash.c src/random_generator.c src/Function/RockPaperScissor/RockPaperScissor.c -o main