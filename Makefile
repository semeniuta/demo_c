# Nice Makefiles tutorial:
# https://www.youtube.com/watch?v=_r7i5X0rXJk

# https://www.gnu.org/software/make/manual/html_node/Pattern-Examples.html
# https://www.gnu.org/software/make/manual/html_node/Foreach-Function.html
# https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html

sources := $(wildcard *.c)
program_names := $(patsubst %.c, %, ${sources})

all: ${program_names}

# Make executable from every C source file
% : %.c
	gcc $< -o build/$@

clean:
	rm build/*