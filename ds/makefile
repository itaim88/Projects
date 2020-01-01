INC_DIR=./../include
REL_FLAGS=-ansi -pedantic-errors -Wall -Wextra -g -DNDEBUG -O3 -I$(INC_DIR)

debug_%:
	cd $* && make;

release_%:
	cd $* && make FOLDER=release CFLAGS='$(REL_FLAGS)'

run_debug_%:
	./$*/out/debug/$*.out

run_release_%:
	./$*/out/release/$*.out

clean_%:
	cd $* && make clean;

echo_%:
	cd $* && make echo;
