# Linux基础
## 文件系统
- 1根目录"/"
```
ls -l
tree
```
## 系统路径
```
.或者./    当前路径
..或者../  上一目录
```
## 常用命令行
### cd
```python
cd [目录名] #cd命令是change dir的简写，它可以把终端当前所在的路径切换至目标路径
“~”：波浪号，表示为当前用户的 home 目录
“.”：一个英文句号，表示当前目录
“..” ：两个英文句号，表示当前目录的上一层目录
“/” ：斜杠符号，表示为根目录
“-” ：减号，不是目录，但作为cd命令的参数时可以返回上一次cd切换前的目录。
```

### mkdir
```python
mkdir [-p] 目录名 #mkdir命令是make directory的简写，它可以在文件系统中创建一个新的目录.命令格式中的“目录名”就是要创建的目录路径，“-p”选项可以不输入，若使用了“-p”选项， 当创建的目录名包
```

### touch
```python
touch 文件名 #touch命令可以创建不存在的文件，或者touch通过参数修改目录或文件的日期时间， 就是摸一下，更新它的时间
```

### ls
```python
ls [选项] [目录] #ls命令是list的简写，功能为显示指定目录下的内容（文件及子目录) ，还可以查看文件大小，修改日期等等信息
-a： 显示所有文件及目录 (ls内定将文件名或目录名称开头为“.”的视为隐藏档，不会列出)
-l ：注意这是字母L的小写，除文件名称外，将文件型态、权限、拥有者、文件大小等信息详细列出
-t ：将文件依建立时间之先后次序列出
-A： 同 -a ，但不列出 “.”(当前目录) 及 “..”(父目录)
-R ：若目录下有文件，则该目录下的文件也会列出，即递归显示
```

### cat
```python
cat 文件名 #cat命令是concatenate的简写，译为串联，即它可以把两个内容串联起来，我们通 常使用它在终端下输出文件的内容进行查看
```

### echo
```python
#echo命令的功能是在终端上打印一段文字，也可以把终端 的变量内容打印出来。
echo "字符串"
echo 字符串
echo $变量名

echo "test"    # 打印字符串test
echo test      # 打印字符串test
echo $PATH     # 打印环境变量PATH
echo "$PATH"   # 打印环境变量PATH
```

###  输出重定向到文件
在上面看到命令执行后都是输入到终端显示，有时我 们希望把命令执行的结果保存到文件进行分析，这时我们可以使用 输出重定向到文件的控制符“>”或“>>”，其中“>”会直接用输出 覆盖原文件，而“>>”则把输出追加到原文件的末尾。
```python
命令 > 文件名
命令 >> 文件名
echo test > file.txt    # 把echo test的输出重定向至file.txt文件
cat file.txt            # 查看file.txt文件的内容
echo abc > file.txt     # 把echo abc 的输出重定向至file.txt文件
cat file.txt            # 查看file.txt文件的内容
echo 123456 >> file.txt # 把echo 123456的输出重定向追加至file.txt文件
cat file.txt            # 查看file.txt文件的内容
ls > file.txt           # 把ls命令的输出重定向至file.txt文件
cat file.txt            # 查看file.txt文件的内容
```

### rmdir
```python
rmdir [-p] 目录名 #mdir命令是remove directory的简写，它的功能是删除空的目录。
```

### rm
```python
rm [选项] 一个或多个文件/文件夹名 #rm命令是remove的简写，它的功能是删除一个或多个文件或目录。文件是会被直接永久删除的，它并不会放到回收站中再确认
-i：删除文件或文件夹前，终端会逐一询问确认
-r：将目录及其包含的子目录或文件全部删除
-f：忽略不存在的文件，无需逐一确认
```

### sudo
```python
sudo 命令 #sudo命令是switch user do的简写，意思是切换用户去做某件事情。
```

### clear
清屏

### reboot/poweroff命令
终端上，reboot/poweroff命令来控制系统的重启与关机。

### man
```python
man [要查询的内容] #除了–help选项外，Linux还提供了一个man命令， 可用于查看Linux系统自带的参考手册，该手册包含非常丰富的内容， 甚至在我们进行编程开发时还可以使用它来查看函数的接口
man ls
```

## Shell编程
### 1.简单的脚本
命令行
```
sudo vi hello.sh
```
hello.sh里面
```
#!/bin/bash

echo "hello"

```

命令行
```
sudo chmod 777 hello.sh  #赋予权限
./hello.sh 
```

### 赋值
```
var=1234
var1='1234 56'
var2="1234 56"
var3="${var2}aaa" #会解引用
var4='${var2}aaa' #不会解引用
var5=`pwd`
var6=$(pwd)

echo "$var"
echo "$var1"
echo "$var2"
echo "$var3"
echo "$var4"
echo "$var2bb" #$识别全部
echo "${var2}bb" #$识别{}里面的
echo "$var5"
echo "$var6"
```
输出
```
1234
1234 56
1234 56
1234 56aaa
${var2}aaa

1234 56bb
/home/onetree
/home/onetree

```

### 特殊变量
![shell](images/shell.png)

### gcc
```python
#直接编译成可执行文件
gcc hello.c -o hello

#以上命令等价于执行以下全部操作
#预处理，可理解为把头文件的代码汇总成C代码，把*.c转换得到*.i文件
gcc –E hello.c –o hello.i

#编译，可理解为把C代码转换为汇编代码，把*.i转换得到*.s文件
gcc –S hello.i –o hello.s

#汇编，可理解为把汇编代码转换为机器码，把*.s转换得到*.o，即目标文件
gcc –c hello.s –o hello.o

#链接，把不同文件之间的调用关系链接起来，把一个或多个*.o转换成最终的可执行文件
gcc hello.o –o hello
```

## 进程
- 概念
  - 程序只是一系列指令序列与数据的集合，它本身没有任何运行的含义， 它只是一个静态的实体。而进程则不同，它是程序在某个数据集上的执行过程， 它是一个动态运行的实体，有自己的生命周期，它因启动而产生，因调度而运行， 因等待资源或事件而被处于等待状态，因完成任务而被销毁。

  - 进程和程序并不是一一对应的，一个程序执行在不同的数据集上运行就会成为不同的进程， 可以用进程控制块来唯一地标识系统中的每个进程。而这一点正是程序无法做到的， 由于程序没有和数据产生直接的联系，既使是执行不同的数据的程序， 他们的指令的集合依然是一样的，所以无法唯一地标识出这些运行于不同数据集上的程序。 一般来说，一个进程肯定有一个与之对应的程序，而且有且只有一个。 而一个程序有可能没有与之对应的进程（因为这个程序没有被运行）， 也有可能有多个进程与之对应（这个程序可能运行在多个不同的数据集上）。

  - 进程具有并发性而程序没有。

  - 进程是竞争计算机资源的基本单位，而程序不是。


查看进程
```python
#在PC或开发板上执行以下命令
ps –aux
```

- 程序状态
R:运行态
S：可中断睡眠状态，挂起状态
D：不可中断的睡眠状态。通常等待I/O输入输出
T：停止状态
Z:退出状态
X：退出状态，即将呗回收
s:进程时绘画其首进程
l:进程时多线程的
+：进程属于前台进程组
<：高优先级任务

![状态](https://doc.embedfire.com/linux/imx6/linux_base/zh/latest/_images/proces007.png)


- 创建一个新进程
  - system
```cpp
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    pid_t result;

    printf("This is a system demo!\n\n");

    /*调用 system()函数*/
    result = system("ls -l");
    //result = system("ls -l &");//在后台运行
    printf("Done!\n\n");

    return result;
}
```

  - fork
  通过fork()可以创建一个完全分离的子进程
  在父进程中的fork()调用后返回的是新的子进程的PID。 新进程将继续执行，就像原进程一样，不同之处在于，子进程中的fork()函数调用后返回的是0， 父子进程可以通过返回的值来判断究竟谁是父进程，谁是子进程。

  子进程与父进程一致的内容：
  进程的地址空间。

  进程上下文、代码段。

  进程堆空间、栈空间，内存信息。

  进程的环境变量。

  标准 IO 的缓冲区。

  打开的文件描述符。

  信号响应函数。

  当前工作路径。 

  子进程独有的内容：

  进程号 PID。 PID 是身份证号码，是进程的唯一标识符。

  记录锁。父进程对某文件加了把锁，子进程不会继承这把锁。

  挂起的信号。这些信号是已经响应但尚未处理的信号，也就是”悬挂”的信号， 子进程也不会继承这些信号。
```cpp
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 int main(void)
 {
     pid_t result;

     printf("This is a fork demo!\n\n");

     /*调用 fork()函数*/
     result = fork();

     /*通过 result 的值来判断 fork()函数的返回情况，首先进行出错处理*/
     if(result == -1) {
         printf("Fork error\n");
     }

     /*返回值为 0 代表子进程*/
     else if (result == 0) {
         printf("The returned value is %d, In child process!! My PID is %d\n\n", result, getpid());

     }

     /*返回值大于 0 代表父进程*/
     else {
         printf("The returned value is %d, In father process!! My PID is %d\n\n", result, getpid());
     }

     return result;
 }
```
  - exec
  这个系列函数主要是用于替换进程的执行程序， 它可以根据指定的文件名或目录名找到可执行文件，并用它来取代原调用进程的数据段、代码段和堆栈段， 在执行完之后，原调用进程的内容除了进程号外，其他全部被新程序的内容替换。 

```cpp
int main(void)
{
    int err;

    printf("this is a execl function test demo!\n\n");

    err = execl("/bin/ls", "ls", "-la", NULL);

    if (err < 0) {
        printf("execl fail!\n\n");
    }

    printf("Done!\n\n");
}
```
 所以示例程序中的“ Done! ”将不被输出，因为当前进程已经被替换了，一般情况下， exec系列函数函数是不会返回的，除非发生了错误。出现错误时， exec系列函数将返回-1，并且会设置错误变量errno。

### 进程中止
1.正常终止
从main函数返回。
调用exit()函数终止。
调用_exit()函数终止。

2.异常中止
调用abort()函数异常终止。
由系统信号终止。
![exit](https://doc.embedfire.com/linux/imx6/linux_base/zh/latest/_images/proces014.png)

### 等待进程
wait()函数在被调用的时候，系统将暂停父进程的执行，直到有信号来到或子进程结束， 如果在调用wait()函数时子进程已经结束，则会立即返回子进程结束状态值。
WIFEXITED(status) ：如果子进程正常结束，返回一个非零值
WEXITSTATUS(status)： 如果WIFEXITED非零，返回子进程退出码
WIFSIGNALED(status) ：子进程因为捕获信号而终止，返回非零值
WTERMSIG(status) ：如果WIFSIGNALED非零，返回信号代码
WIFSTOPPED(status)： 如果子进程被暂停，返回一个非零值
WSTOPSIG(status)： 如果WIFSTOPPED非零，返回一个信号代码
```cpp
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid, child_pid;
    int status;

    pid = fork();                  //(1)

    if (pid < 0) {
        printf("Error fork\n");
    }
    /*子进程*/
    else if (pid == 0) {                  //(2)

        printf("I am a child process!, my pid is %d!\n\n",getpid());

        /*子进程暂停 3s*/
        sleep(3);

        printf("I am about to quit the process!\n\n");

        /*子进程正常退出*/
        exit(0);                          //(3)
    }
    /*父进程*/
    else {                                //(4)

        /*调用 wait，父进程阻塞*/
        child_pid = wait(&status);        //(5)

        /*若发现子进程退出，打印出相应情况*/
        if (child_pid == pid) {
            printf("Get exit child process id: %d\n",child_pid);
            printf("Get child exit status: %d\n\n",status);
        } else {
            printf("Some error occured.\n\n");
        }

        exit(0);
    }
}
```


