/*
  调用汇编函数mywrite(fd, buf, count)显示信息;调用myadd(a, b, result)执行加运算.
  如果myadd返回0,则表示加函数发生溢出,首先显示开始计算信息,然后显示运算结果
*/
int main()
{
  char buf[1024];
  int a, b, res;
  char * mystr = "Calulating...\n";
  char * emsg = "Error in adding\n";
  // a = 2147483644; b = 5;
  a = 1; b = 5;
  mywrite(1, mystr, strlen(mystr));
  if (myadd(a, b, &res))
  {
    sprintf(buf, "The result is %d\n", res);
    mywrite(1, buf, strlen(buf));
  } else {
    mywrite(1, emsg, strlen(emsg));
  }
  return 0;
}
