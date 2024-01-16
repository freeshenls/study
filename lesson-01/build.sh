as86 -0 -o boot.o bootsect.S
ld86 -0 -o boot boot.o
dd bs=32 if=boot of=Image skip=1
