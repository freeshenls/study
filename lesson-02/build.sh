as --32 -o callee.o callee.s
gcc -m32 -o caller caller.c callee.o
gcc -m32 -o caller caller.c callee.o
# gcc -m32 -S caller.c -o caller.s
