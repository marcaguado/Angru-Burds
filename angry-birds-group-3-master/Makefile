
CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb -fPIC -DQT_NO_VERSION_TAGGING
MOC 	  := $(QT_INSTALL_LIBEXECS)/moc

EXECUTABLE  := main
BIN     := bin
SRC     := src
INCLUDE := include
LIB     := libs
MOCSRC  := moc

STEP := $(wildcard $(SRC)/*.cpp)
STEP := $(subst .cpp,.o,$(STEP))
OBJECTS := $(subst $(SRC),$(BIN),$(STEP))

HEADERS := -I $(INCLUDE) \
	-I $(QT_INSTALL_HEADERS) \
	-I $(QT_INSTALL_HEADERS)/QtWidgets \
	-I $(QT_INSTALL_HEADERS)/QtCore \
	-I $(QT_INSTALL_HEADERS)/QtGui \
	\
	-I $(BOX2DDIR)/include/box2d 

LIB_DIRS   	:= -L $(QT_INSTALL_LIBS) -L $(BOX2DDIR)/build/bin
LIB_FILES	:= -l Qt6Widgets -l Qt6Core -l Qt6Gui \
				-l box2d

MOC_HEADERS := $(wildcard $(INCLUDE)/*.hpp)
STEP := $(subst .hpp,.moc.cpp,$(MOC_HEADERS))
MOC_SOURCES := $(subst $(INCLUDE),$(MOCSRC),$(STEP))

STEP := $(subst .hpp,.moc.o,$(MOC_HEADERS))
MOC_OBJECTS := $(subst $(INCLUDE),$(BIN),$(STEP))


#Testing stuff:

TEST_EXECUTABLE := test
TEST_DIR := tests
# Add here all the .cpp files in $TEST_DIR that you need, that dont have a header file.
TESTS_TEST := graphicsTest
# .cpp files in 'tests' that do have a header file. The header file must have the same 
# name, and it must also be in $TEST_DIR.
TESTS_TEST_HPP := GraphicsTester
# .cpp files from the actual project (those in $SRC) that you need for the tests. 
# They are expected to have a similarly named header file in $INCLUDE.
TESTS_SRC := GameCore PhysObject LevelGround Pig MyContactListener

TEST_SOURCES_SRC := $(shell echo $(TESTS_SRC) | sed 's/ /.cpp $(SRC)\//g' | sed 's/^/$(SRC)\//g').cpp
TESTS_SOURCES_T_HPP := $(shell echo $(TESTS_TEST_HPP) | sed 's/ /.cpp $(TEST_DIR)\//g' | sed 's/^/$(TEST_DIR)\//g').cpp
STEP := $(shell echo $(TESTS_TEST) | sed 's/ /.cpp $(TEST_DIR)\//g' | sed 's/^/$(TEST_DIR)\//g').cpp \
	$(TEST_SOURCES_SRC) $(TESTS_SOURCES_T_HPP)
STEP := $(subst src/.cpp,,$(STEP))
TEST_SOURCES := $(subst tests/.cpp,,$(STEP))

STEP1 := $(subst .cpp,.moc.cpp,$(TEST_SOURCES_SRC))
STEP1 := $(subst $(SRC),$(MOCSRC),$(STEP1))
STEP2 := $(subst .cpp,.test_moc.cpp,$(TESTS_SOURCES_T_HPP))
STEP2 := $(subst $(TEST_DIR),$(MOCSRC),$(STEP2))
STEP := $(subst moc/.moc.cpp,,$(STEP2) $(STEP1))
TEST_MOC_SOURCES := $(subst moc/.test_moc.cpp,,$(STEP))



# Select the target you want to build by editing:
# all: <target>
# available targets are:
# default - build the main project
# test - build unit tests, see: "Testing stuff" above for configuring.
# print - print variables for debugging purposes.
all: default


default: $(BIN)/$(EXECUTABLE)

# Swap the commented and uncommented rule to compile only a single executable.

#Single executable:
#$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp $(MOC_SOURCES)
#	$(CXX) $(CXX_FLAGS) $(HEADERS) $^ -o $@ $(LIB_DIRS) $(LIB_FILES)

# Separate object files:
$(BIN)/$(EXECUTABLE): $(OBJECTS) $(MOC_OBJECTS)
	$(CXX) $(CXX_FLAGS) $(HEADERS) $^ -o $@ $(LIB_DIRS) $(LIB_FILES)
#

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) -c $(CXX_FLAGS) $(HEADERS) $< -o $@

$(BIN)/%.moc.o: $(MOCSRC)/%.moc.cpp
	$(CXX) -c $(CXX_FLAGS) $(HEADERS) $< -o $@

$(MOCSRC)/%.moc.cpp: $(INCLUDE)/%.hpp
	$(MOC) $(HEADERS) $< -o $@


print:
	echo $(OBJECTS)
	echo $(MOC_OBJECTS)


test: $(BIN)/$(TEST_EXECUTABLE)

$(BIN)/$(TEST_EXECUTABLE): $(TEST_SOURCES) $(TEST_MOC_SOURCES)
	$(CXX) $(CXX_FLAGS) $(HEADERS) $^ -o $@ $(LIB_DIRS) $(LIB_FILES)

$(MOCSRC)/%.test_moc.cpp: $(TEST_DIR)/%.hpp
	$(MOC) $(HEADERS) $< -o $@
