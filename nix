Debug ?= 1
ifeq ($(Debug), 1)
    CompilerFlags =-DDEBUG -g3 -ggdb
	CompilerWarningFlags=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual \
							-Wctor-dtor-privacy -Wdisabled-optimization \
							-Wformat=2 -Winit-self -Wlogical-op \
							-Wmissing-declarations -Wmissing-include-dirs \
							-Wnoexcept -Wold-style-cast -Woverloaded-virtual \
							-Wredundant-decls -Wshadow -Wsign-conversion \
							-Wsign-promo -Wstrict-null-sentinel \
							-Wstrict-overflow=5 -Wswitch-default -Wundef
else
    CompilerFlags=-O3
	CompilerWarningFlags=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual \
							-Wctor-dtor-privacy -Wdisabled-optimization \
							-Wformat=2 -Winit-self -Wlogical-op \
							-Wmissing-declarations -Wmissing-include-dirs \
							-Wnoexcept -Wold-style-cast -Woverloaded-virtual \
							-Wredundant-decls -Wshadow -Wsign-conversion \
							-Wsign-promo -Wstrict-null-sentinel \
							-Wstrict-overflow=5 -Wswitch-default -Wundef \
							-Wno-unused
endif

Werror ?= 1
ifeq ($(Werror), 1)
	CompilerWarningFlags+= -Werror
endif

LinkerFlags= -lSDL2
CXX= g++ -std=c++11 $(CompilerFlags) $(CompilerWarningFlags)
Executable=ogl101
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
IncludeDir=include

all: $(Executable)

$(Executable): $(OBJ_FILES)
	$(CXX) $^ -o bin/$(Executable).out $(LinkerFlags)

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $<\
	 -I$(IncludeDir)

clean:
	rm -rf bin
	rm -rf obj
	mkdir bin
	mkdir obj