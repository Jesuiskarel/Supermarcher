# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
LDFLAGS = -lsqlite3
TARGET = supermarche
BUILD_DIR = build
SRC_DIRS = database gestion models utils
SRCS = $(wildcard main.cpp $(foreach dir, $(SRC_DIRS), $(dir)/*.cpp))
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Règle par défaut
all: $(TARGET)

# Création du répertoire de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) $(foreach dir, $(SRC_DIRS), $(BUILD_DIR)/$(dir))

# Compilation de l'exécutable
$(TARGET): $(BUILD_DIR) $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compilation des fichiers objets
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Exécution du programme
run: all
	./$(TARGET)

# Nettoyage
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Nettoyage complet
dist-clean: clean

# Cibles pour tests et autres
.PHONY: all clean dist-clean run

