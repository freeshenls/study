as86 -0 -a -o boot.o boot.s
ld86 -0 -s -o boot boot.o
as --32 -o head.o head.s
ld -m elf_i386 -Ttext 0 -e startup_32 -o head head.o

# 跳过32B
dd bs=32 if=boot of=Image.a.img skip=1
# 跳过4096B
dd bs=512 if=head of=Image.b.img skip=8
# 合并
cat Image.a.img Image.b.img >Image
