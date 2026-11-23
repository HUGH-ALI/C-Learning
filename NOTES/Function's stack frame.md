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




我的问题:
 
前置说明：我们讨论的是32位C语言栈帧，栈向下增长（地址越来越小），只有1个esp寄存器、1个ebp寄存器；栈是一块公共内存，栈帧是函数临时划分出来的地盘。代码统一参考：
 
c  
int main()
{
    test1();
    int x=0;
    test2();
    return 0;
}
 
 
 
 
1. 问题：main也有自己的esp是吧，那么esp到了test1()时是如何跳转到test1()的ebp的呢？
 
✅ 答案：
main有ebp、esp。不是esp跳向test1的ebp。
进入test1先执行两句汇编：
 push ebp （把main的ebp压栈保存，esp下移）
 mov ebp, esp （把当前esp的值直接赋值给ebp，这个位置就是test1的ebp地基）
ebp被改成test1的地基，ebp固定，后续放局部变量时esp继续往下走。
 
 
 
2. 问题：返回地址指什么？压进栈，这里的栈是指main自己的栈帧吗
 
✅ 答案：
返回地址：一张“纸条”，记录test1跑完之后，main里面要继续执行的代码位置（这里就是 int x=0; ）。
它不在main栈帧内部，压在main栈帧边界外面、test1栈帧的最前面，属于公共栈空间。
纸条存放的位置 ≠ 纸条记录的代码位置。
 
 
 
3. 问题：返回地址都被放到main的外面了，他是怎么回来的呢
 
✅ 答案：
纸条（返回地址）写的内容是main内部代码的编号。
test结束执行 ret ，会读取纸条上记录的代码位置，CPU直接跳到这个代码位置执行；不是跳到放纸条的内存位置。
 
 
 
4. 问题：test执行完是  mov esp,ebp ，他是怎么拿到返回地址的？
 
✅ 答案：
test结束顺序：
 
1.  mov esp, ebp ：esp拉到test的ebp（保存main ebp的位置）
2.  pop ebp ：取出栈上存的main的ebp还给ebp寄存器，esp自动往上挪一格 → esp刚好对准返回地址
3.  ret ：取出esp指向的返回地址，跳转回main
 
 
 
5. 问题：main不也是有自己的esp吗，怎么会一开始就搭建好了栈帧，都没有走完，他怎么知道自己需要多少的？
 
✅ 答案：
main的栈帧是先钉地基（ebp），后面慢慢分配空间：
刚进入main就执行 push ebp; mov ebp, esp ，ebp固定不动（地基锁死）。
esp是动态的，遇到变量才往下挪开辟空间，不需要提前知道总共要多少变量。
ebp是边界，esp是“用到哪算哪”。
 
 
 
6. 问题：从始至终只有一个esp是吧
 
✅ 答案：
是的！esp寄存器全局唯一，ebp寄存器也只有一个。
所有函数共用这一套寄存器；旧的ebp值，会提前存到栈内存里，用完再恢复。
 
 
 
7. 问题：那么test1的ebp是哪里来的
 
✅ 答案：
进入test1：
 
1.  push ebp ：把当前ebp（main的地基）保存到栈上
2.  mov ebp, esp ：把此时此刻esp的位置，赋值给ebp，这个值就是test1的ebp。
ebp寄存器只有一个，只是把它的值改成了当前esp的位置。
 
 
压返回地址是call指令自带的，和后面test里面  push ebp / mov ebp,esp  是两码事。
 
mov ebp,esp  是进入test之后才执行的，不是call的时候。call阶段只压返回地址，esp已经变小。
 
test的参数也是和返回地址放在一个地方



test栈帧销毁流程（和创建一一对应）
 
前提：test里面业务代码（b、c赋值这些）已经全部跑完，准备回收栈帧
栈布局回顾（高→低）
 
plaintext  
实参
返回地址
保存的main的ebp ← test的ebp（起点）
b=10
c=20
esp
 
 
销毁一共3条汇编：
 
asm  
mov esp, ebp
pop ebp
ret
 
 
① mov esp, ebp
 
esp直接拉回到test的ebp位置。
 
- 作用：把b、c这些局部变量的空间直接宣告回收
- ⚠️ 重点：不会擦掉内存里b、c的数据，只是esp标记不再管理这块空间，数据变成残留垃圾
此时栈上：
 
plaintext  
实参
返回地址
保存的main的ebp ← esp现在对准这里
b=10（残留）
c=20（残留）
 
 
② pop ebp
 
把esp指向的值（保存好的main的ebp）拿出来，放回ebp寄存器
 
- ebp变回main的地基！
- pop操作自带：esp自动往上挪一格（地址变大）
挪完之后，esp正好对准【返回地址】
 
plaintext  
实参
返回地址 ← esp现在对准这里
保存的main的ebp（已经被取走）
 
 
③ ret
 
ret = 弹出返回地址，跳转到这个地址执行
 
- 取出esp指向的返回地址（纸条），CPU跳转回main
- ret也会让esp再往上挪一格
 
plaintext  
实参 ← esp现在对准这里
返回地址（已经被取走）
 
 
✅ 到此：test栈帧彻底销毁，ebp、esp全部恢复到调用test之前的状态。
 
 
 
【创建 ↔ 销毁 对照速记】
 
创建（进test）
 
1. push ebp 保存上层ebp
2. mov ebp, esp 定下test地基
3. esp下移，分配局部变量
 
销毁（出test）
 
1. mov esp, ebp 收回局部变量空间
2. pop ebp 恢复上层ebp
3. ret 跳回上层函数
 
额外小知识点：
上面实参还留在栈上！如果是cdecl调用约定，回到main之后，main自己会把参数的空间平衡掉（esp往上抬），清理实参。