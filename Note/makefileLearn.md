### 1.创建makefile文档
### 2.#是注释

### 3.显示规则

```python
#目标文件：显示规则
#[TAB]指令
# hello.i:hello.c
#     gcc -E hello.c -o hello.i
# hello.s:hello.i
#     gcc -S hello.i -o hello.S
# hello.o:hello.S
#     gcc -c hello.S -O hello.o
# hello:hello.c
#     gcc hello.o -o hello

# 第一个目标文件是我的最终目标

hello:hello.c
    gcc hello.o -o hello
hello.o:hello.S
    gcc -c hello.S -O hello.o
hello.s:hello.i
    gcc -S hello.i -o hello.S
hello.i:hello.c
    gcc -E hello.c -o hello.i
#伪目标，不需要依赖文件
.PHONY
clean:
rm -rf hello.o hello.s hello.i hello
```


### 4.变量
```python
# =(替换)
# += 追加
# := 恒等于  有点相当于常量

TAR = test
OBJ = circle.o cube.o main.o
CC := gcc

$(TAR):$(OBJ)
    $(CC) $(OBJ) -o $(TAR)

circle.o:circle.c
    $(CC) -c circle.c -o circle.o
cube.o:cube.c
    $(CC) -c cube.c -o cube.o
main.o:main.c
    $(CC) -c main.c -o main.o
.PHONY
clear:
    rm -rf  $(OBJ) $(TAR)
```

### 5.隐含规则
```python
# %.c任意的.c
# *.c所有的.c
TAR = test
OBJ = circle.o cube.o main.o
CC := gcc

$(TAR):$(OBJ)
    $(CC) $(OBJ) -o $(TAR)

%.o:%.c
    $(CC) -c %.c -o %.o
# circle.o:circle.c
#     $(CC) -c circle.c -o circle.o
# cube.o:cube.c
#     $(CC) -c cube.c -o cube.o
# main.o:main.c
#     $(CC) -c main.c -o main.o
.PHONY
clear:
    rm -rf  $(OBJ) $(TAR)

```

### 通配符
```python
# ^所有目标文件
# $@所有的依赖文件
# $< 所有依赖文件的第一个文件


TAR = test
OBJ = circle.o cube.o main.o
CC := gcc

$(TAR):$(OBJ)
    $(CC) $^ -o $@


%.o:%.c
    $(CC) -c $^ -o $@

.PHONY
clear:
    rm -rf  $(OBJ) $(TAR)

```

### 函数
```python

```