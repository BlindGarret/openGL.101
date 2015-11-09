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

Werror ?= 0
ifeq ($(Werror), 1)
    CompilerWarningFlags+= -Werror
endif

Extension=.out
LinkerFlags= -lSDL2 -lopengl32 -lglew32
CXX= g++ $(CPP11Support) $(CompilerFlags) $(CompilerWarningFlags)
Executable=ogl101
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
IncludeDir=include
CPP11Support=-std=c++11

ifeq ($(OS), Windows_NT)
	#Windows Support
    Extension=.exe
    LinkerFlags:= -lmingw32 -lSDL2main $(LinkerFlags)
endif

all: $(Executable)

$(Executable): $(OBJ_FILES)
	$(CXX) $^ -o bin/$(Executable)$(Extension) $(LinkerFlags)

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $<\
     -I$(IncludeDir)

clean:
	rm -rf bin
	rm -rf obj
	mkdir bin
	mkdir obj
