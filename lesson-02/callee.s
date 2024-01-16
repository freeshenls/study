/*
  本汇编程序利用系统调用sys_write()实现显示函数int mywrite(int fd, cgar * buf, int count).
  函数int myadd(int a, int b, int * res)用于执行a+b = res运算,若函数返回0,则说明溢出.
  注意:如果在现在Linux系统(如RedHat 9)下编译,则请去掉函数名前的下划线'_'
*/
SYSWRITE = 4
.globl mywrite, myadd
.text
mywrite:
      pushl %ebp
      movl %esp, %ebp
      pushl %ebx
      movl 8(%ebp), %ebx
      movl 12(%ebp), %ecx
      movl 16(%ebp), %edx
      movl $SYSWRITE, %eax
      int $0x80
      popl %ebx
      movl %ebp, %esp
      popl %ebp
      ret
myadd:
      pushl   %ebp
      movl    %esp, %ebp
      xorl    %ecx, %ecx
      movl    16(%ebp), %edx
      movl    12(%ebp), %eax
      addl    8(%ebp), %eax
      jo    1f
      movl    %eax, (%edx)
      incl    %ecx
1:    movl    %ecx, %eax
      movl    %ebp, %esp
      popl    %ebp
      ret
      