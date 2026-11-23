代码：
 
c  
int main()
{
    test1();
    int x=0;
    return 0;
}
 
 
 
 
阶段1：程序进入main，搭建main的栈帧
 
1. 刚进main，执行：
 
asm  
push ebp
mov ebp, esp
 
 
- push ebp：把调用main的上层ebp压栈保存
- mov ebp, esp：ebp钉死，变成main的地基（不动了）
✅ 现在：ebp=main地基，esp和ebp挨在一起，main地盘框架搭好
 
esp唯一，ebp现在代表main
 
木板：
 
plaintext  
【高地址】
main ebp ← 地基钉在这里
esp ← 现在和ebp重合
【低地址】
 
 
阶段2：main执行 test1(); 准备调用
 
1. 先压test1的实参（如果有参数），esp往下挪
2.  call test1 ：把返回地址（纸条：干完回main的int x=0;）压栈，esp继续往下走
👉 现在栈上多了：实参、返回地址，在main地基的下面（外面）
 
木板：
 
plaintext  
【高地址】
main ebp
main地盘
————main边界
实参
返回地址 ← 纸条
esp ← 现在esp在这里
【低地址】
 
 
然后CPU跳去test1里面执行代码
 
阶段3：进入test1，搭建test1的栈帧
 
test1开头两句：
 
asm  
push ebp
mov ebp, esp
 
 
1.  push ebp ：ebp现在还是main的地基！把main的ebp压到栈上存起来，esp再往下挪一格
2.  mov ebp, esp ：把esp当前位置赋值给ebp
✅ 现在ebp切换成test1的地基！（test的ebp就位，全程固定）
 
木板更新：
 
plaintext  
【高地址】
main ebp
main地盘
实参
返回地址
保存的main的ebp ← push ebp放进来的
esp ← mov ebp,esp之后，ebp=这个位置（test的地基）
【低地址】
 
 
接下来执行test1里面代码： int b=10; int c=20; 
每定义一个局部变量，esp继续往下挪，开辟空间放b、c
 
plaintext  
保存的main的ebp ← test的ebp（固定不动）
b=10
c=20
esp ← 现在在这里
【低地址】
 
 
阶段4：test1代码跑完，遇到 } ，开始销毁test1栈帧
 
依次执行三条指令：
 
1.  mov esp, ebp 
esp直接拉回到test的ebp位置！b、c的地盘宣告回收（数据还在，只是不归test用了）
 
plaintext  
保存的main的ebp ← test ebp，esp现在挪到这里
b=10（残留）
c=20（残留）
 
 
2.  pop ebp 
把栈上【保存的main的ebp】拿出来，放回ebp寄存器！
👉 ebp变回main的地基！
同时pop动作会让esp往上挪一格 → esp对准【返回地址（纸条）】
 
plaintext  
返回地址 ← esp现在对准这里
保存的main的ebp（已经被拿走给ebp寄存器了）
 
 
3.  ret 
取出esp指向的返回地址，CPU跳转到main里面  int x=0; 
esp再往上挪一格
 
✅ test1栈帧彻底销毁，ebp回到main，esp回到main这边
 
阶段5：回到main，继续跑
 
执行  int x=0; 
esp在main的地盘里面，往下挪一点，划出位置放x
 
plaintext  
main ebp
x=0 ← 刚分配的
————main边界
（下面是空闲的栈空间，等待下一次调用函数）
 
 
之后继续执行后面代码，直到main的return，main栈帧销毁。