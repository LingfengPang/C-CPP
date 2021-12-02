# Linux

## 基础命令操作
### 日期
```
onetree@ubuntu:~$ date +%Y/%m/%d
2021/10/08

onetree@ubuntu:~$ date +%H:%M
11:20

onetree@ubuntu:~$ date
2021年 10月 08日 星期五 11:17:11 CST

onetree@ubuntu:~$ cal
      十月 2021         
日 一 二 三 四 五 六  
                1  2  
 3  4  5  6  7  8  9  
10 11 12 13 14 15 16  
17 18 19 20 21 22 23  
24 25 26 27 28 29 30  
31                    
onetree@ubuntu:~$ cal 10 2022
      十月 2022         
日 一 二 三 四 五 六  
                   1  
 2  3  4  5  6  7  8  
 9 10 11 12 13 14 15  
16 17 18 19 20 21 22  
23 24 25 26 27 28 29  
30 31                 
onetree@ubuntu:~$ 
```

### 求助
```
date -help
man date
info date
```

### sync
将内存中未保存的存入硬盘中。

## 文件
### 文件属性与权限
r:可读
w:可写
x:可执行(包括但不限于 切换至该目录下)
```
#修改文件组所属用户组（root）
用法：chgrp [选项]... 用户组 文件...
　或：chgrp [选项]... --reference=参考文件 文件...
将每个指定<文件>的属组变更至指定<用户组>。
使用 --reference 选项时，把指定<文件>的属组设置为与<参考文件>相同。

  -c, --changes          类似 verbose 选项，但仅在做出修改时进行报告
  -f, --silent, --quiet  不显示大多数错误消息
  -v, --verbose          输出各个处理的文件的诊断信息
      --dereference      影响每个符号链接的原始引用文件（这是默认行为），而非
                         符号链接本身
  -h, --no-dereference   只影响符号链接，而非被引用的任何文件
                         (仅当系统支持更改符号链接的所有者时，
                         该选项才有用）
      --no-preserve-root  不特殊对待“/”（默认行为）
      --preserve-root    不允许在“/”上递归操作
      --reference=参考文件  使用<参考文件>的属组信息而非指定一个
                            <用户组>的值
  -R, --recursive        递归操作文件和目录

示例：
  chgrp staff /u            将 /u 的属组更改为"staff"。
  chgrp -hR staff /u    将 /u 及其子目录下所有文件的属组更改为"staff"。



法：chown [选项]... [所有者][:[组]] 文件...
　或：chown [选项]... --reference=参考文件 文件...
修改每个<文件>的所有者和/或所属组为给定的<所有者>和/或<组>。
如同时使用 --reference，将每个给定<文件>的所有者和属组修改为<参考文件>
所具有的对应值。

  -c, --changes          类似 verbose 选项，但仅在做出修改时进行报告
  -f, --silent, --quiet  不显示大多数错误消息
  -v, --verbose          输出各个处理的文件的诊断信息
      --dereference      影响每个符号链接的原始引用文件（这是默认行为），而非
                         符号链接本身
  -h, --no-dereference   只影响符号链接，而非被引用的任何文件
                         (仅当系统支持更改符号链接的所有者时，
                         该选项才有用）
      --from=当前所有者:当前所属组
                         	只当每个文件的所有者和组符合选项所指定时才更改所
				有者和组。其中一个可以省略，这时已省略的属性就不
				需要符合原有的属性。
      --no-preserve-root  不特殊对待“/”（默认行为）
      --preserve-root    不允许在“/”上递归操作
      --reference=<参考文件>  使用指定<参考文件>的所有者和所属组信息，而非
                         手工指定 所有者:组 的值
  -R, --recursive        递归操作文件和目录

以下选项是在指定了 -R 选项时被用于设置如何遍历目录结构体系。
如果您指定了多于一个选项，那么只有最后一个会生效。

  -H                     如果命令行参数是一个指向目录的符号链接，则对其
                         进行遍历
  -L                     遍历每一个遇到的指向目录的符号链接
  -P                     不遍历任何符号链接（默认）

      --help		显示此帮助信息并退出
      --version		显示版本信息并退出

如果没有指定所有者，则不会更改所有者信息。若所属组若没有指定也不会对其更改，
但当加上 ':' 时 GROUP 会更改为指定所有者的主要组。所有者和所属组可以是
数字或名称。

示例：
  chown root /u		将 /u 的属主更改为"root"。
  chown root:staff /u	和上面类似，但同时也将其属组更改为"staff"。
  chown -hR root /u	将 /u 及其子目录下所有文件的属主更改为"root"。



用法：chmod [选项]... 模式[,模式]... 文件...
　或：chmod [选项]... 八进制模式 文件...
　或：chmod [选项]... --reference=参考文件 文件...
将每个文件的权限模式变更至指定模式。
使用 --reference 选项时，把指定文件的模式设置为与参考文件相同。

  -c, --changes          类似 verbose 选项，但仅在做出修改时进行报告
  -f, --silent, --quiet  不显示大多数错误消息
  -v, --verbose          输出各个处理的文件的诊断信息
      --no-preserve-root  不特殊对待“/”（默认行为）
      --preserve-root    不允许在“/”上递归操作
      --reference=参考文件  使用参考文件的模式而非给定模式的值
  -R, --recursive        递归修改文件和目录
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出


r:4
w:2
x:1
chmod 777 .ra #.ra文件权限未rwx rwx rwx  4+2+1 = 7;

u：用户
g:组
o:其他
a:全部

chmod u=rwx,go=rx .r  #.r权限为-rwxr-xr-x
chmod a+w .r #r所用都加上w权限
chmod a-w .r #r所有移除w权限
```

## 目录与路径
### 绝对目录与路径
绝对路径：由根目录写起
相对路径：相对于目前路径写起

### 目录操作
```
cd #切换目录
pwd #显示当前目录
mkdir #建立一个空目录
rmdir #删除一个空目录


cd #回到根目录
cd..  上层目录
cd- 回到刚刚的目录
cd /bin/spool #绝对路径
cd ../pst #相对路径  ..表示上一级目录

mkdir test 当前目录下创建
mkdir -p test/test1/test2  创建test,test/test1...需要加-p
mkdir -m 711 test 带权限的创建

rmdir和mkdir前面两个用法差不多
```

查看环境变量
添加在环境变量的东西可以在任何地方操作
```
onetree@ubuntu:~/makefile_test$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

添加环境变量
PATH = "{PATH}:/root"
```

PATH一定要大写

### 常用操作ls,cp,mkdir,rm,mv
```
用法：ls [选项]... [文件]...
列出给定文件（默认为当前目录）的信息。
如果不指定 -cftuvSUX 中任意一个或--sort 选项，则根据字母大小排序。

必选参数对长短选项同时适用。
  -a, --all                  不隐藏任何以 . 开始的项目
  -A, --almost-all           列出除 . 及 .. 以外的任何项目
      --author               与 -l 同时使用时，列出每个文件的作者
  -b, --escape               以 C 风格的转义序列表示不可打印的字符
      --block-size=大小      与 -l 同时使用时，将文件大小以此处给定的大小为
                               单位进行缩放；例如：“--block-size=M”；
                               请参考下文的大小格式说明
  -B, --ignore-backups       不列出任何以 ~ 字符结束的项目
  -c                         与 -lt 共同使用时：根据 ctime 排序并显示
                             ctime（文件状态最后更改的时间）；
                             与 -l 共同使用时：显示 ctime 并按照名称排序；
                             其它情况：按照 ctime 排序，最新的最前
  -C                         每栏由上至下列出项目
      --color[=WHEN]         控制是否使用带颜色的输出；WHEN 可以是
                               “always”（默认缺省值）、“auto”或
                               “never”；更多信息请见下文
  -d, --directory            当遇到目录时列出目录本身而非目录内的文件
  -D, --dired                产生适合 Emacs 的 dired 模式使用的结果
  -f                         不进行排序，-aU 选项生效，禁用 -ls --color
  -F, --classify             加上文件类型的指示符号（*/=@| 其中一个）
      --file-type            类似，但不后缀‘*’字符
      --format=关键字        交错 -x，逗号分隔 -m，水平 -x，长 -l，
                               单栏 -1，详细 -l，垂直 -C
      --full-time            类似 -l --time-style=full-iso
  -g                         类似 -l，但不列出所有者
      --group-directories-first
                             在文件前分组目录；
                               此选项可与--sort 一起使用，但是一旦使用
                               --sort=none (-U) 将禁用分组
  -G, --no-group             以一个长列表的形式，不输出组名
  -h, --human-readable       与 -l 和 -s 一起，以易于阅读的格式输出文件
                             大小（例如 1K 234M 2G等）
      --si                   同上面类似，但是使用 1000 为基底而非 1024
  -H, --dereference-command-line
                             跟随命令行列出的符号链接
      --dereference-command-line-symlink-to-dir
                             跟随命令行列出的指向目录的符号链接
      --hide=PATTERN         隐藏符合 shell PATTERN 模式的项目
                               （-a 或 -A 将覆盖此选项）
      --hyperlink[=WHEN]     文件名使用超链接；WHEN 可以是“always”
                               （缺省时的默认选项）、“auto”或
                               “never”
      --indicator-style=方式  指定在每个项目名称后加上指示符号方式：
                               none（默认）、slash（-p）、
                               file-type（--file-type）以及 classify（-F）
  -i, --inode                显示每个文件的索引编号（inode 号）
  -I, --ignore=模式          不显示任何匹配指定 shell <模式>的项目
  -k, --kibibytes            默认使用 1024 字节的块显示磁盘使用量；
                               只用于 -s 和每个目录的总计
  -l				使用较长格式列出信息
  -L, --dereference		当显示符号链接的文件信息时，显示符号链接所指示
				的对象而并非符号链接本身的信息
  -m				所有项目以逗号分隔，并填满整行行宽
  -n, --numeric-uid-gid      类似 -l，但列出用户和组的 ID 号
  -N, --literal              输出未经引号括起的项目名称
  -o                         类似 -l，但不列出有关组的信息
  -p, --indicator-style=slash
                             对目录附加“/”作为指示符号
  -q, --hide-control-chars   以“?”字符代替无法打印的字符
      --show-control-chars   原样显示无法打印的字符（这是默认行为，除非被调用
                               本程序的名称是“ls”而且是在终端中进行输出）
  -Q, --quote-name           将条目名称括上双引号
      --quoting-style=方式   使用指定引用的方式显示条目的名称：
                               literal, locale, shell, shell-always,
                               shell-escape, shell-escape-always, c, escape
                               （该选项优先于 QUOTING_STYLE 环境变量的配置）
  -r, --reverse			逆序排列
  -R, --recursive		递归显示子目录
  -s, --size			以块数形式显示每个文件分配的尺寸
  -S                         sort by file size, largest first
      --sort=WORD            sort by WORD instead of name: none (-U), size (-S),
                               time (-t), version (-v), extension (-X)
      --time=WORD            with -l, show time as WORD instead of default
                               modification time: atime or access or use (-u);
                               ctime or status (-c); also use specified time
                               as sort key if --sort=time (newest first)
      --time-style=TIME_STYLE  使用 -l 时显示的时间/日期格式；请见下面
                                 TIME_STYLE 的相关内容
  -t                         sort by modification time, newest first
  -T, --tabsize=COLS         assume tab stops at each COLS instead of 8
  -u                         同 -lt 一起使用：按照访问时间排序并显示；
                               同 -l 一起使用：显示访问时间并按文件名排序
                               其它：按照访问时间排序，最新的最靠前
  -U                         不进行排序；按照目录顺序列出项目
  -v                         在文本中进行数字（版本）的自然排序
  -w, --width=COLS           设置输出宽度为 COLS 对应的值。0 代表无限制
  -x                         逐行列出项目而不是逐栏列出
  -X                         根据扩展名按字母顺序排序
  -Z, --context              输出每个文件的所有安全上下文信息
  -1                         每行只列出一个文件。与 -q 或 -b 共用时避免 '\n'
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出

```


```
用法：cp [选项]... [-T] 源文件 目标文件
　或：cp [选项]... 源文件... 目录
　或：cp [选项]... -t 目录 源文件...

cp ~./bashrc /tmp/bashrc 把根目录下的.bashrc复制到tmp目录下并改名为bashrc
cp -i ~./bashrc /tmp/bashrc 把根目录下的.bashrc复制到tmp目录下并改名为bashrc,-i表示可以覆盖
cp /test/tes1 .  将test1复制到当前目录下
cp -a /test/tes1 .  将test1包含特性复制到当前目录下
用法：rm [选项]... [文件]...
删除（unlink）指定<文件>。

  -f, --force          强制删除。忽略不存在的文件，不提示确认
  -i                    每次删除前提示确认
  -I                    在删除超过三个文件或者递归删除前提示一次并要求确认；
                          此选项比 -i 提示内容更少，但同样可以阻止大多数
                          错误发生
      --interactive[=场景]  根据指定的<场景>进行确认提示：never（从不）、
                            once（一次，等效于使用 -I）或者 always（总是，
                            等效于使用 -i）。如果使用此参数没有指定<场景>则
                            总是提示
      --one-file-system		递归删除一个层级时，跳过所有不符合命令行参
				数的文件系统上的文件
      --no-preserve-root  不要对“/”特殊处理
      --preserve-root[=all]  不要删除“/”（默认行为）；
                              如添加了“all”参数，将拒绝处理与父目录位于
                              不同设备上的命令行参数
  -r, -R, --recursive   递归删除目录及其内容
  -d, --dir             删除空目录
  -v, --verbose         详细显示进行的步骤
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出

默认时，rm 不会删除目录。使用--recursive(-r 或-R)选项可删除每个给定
的目录，以及其下所有的内容。

要删除文件名第一个字符为“-”的文件（例如“-foo”），请使用
以下方法之一：
  rm -- -foo

  rm ./-foo


用法：mv [选项]... [-T] 源文件 目标文件
　或：mv [选项]... 源文件... 目录
　或：mv [选项]... -t 目录 源文件...

mv a b 将a移到b目录（a是个文件，b是个目录）
mv a b 文件a改名为b
mv a b c将文件a,b移到c目录  最后一个目标文件肯定是目录
```

### 查看文件内容

```
touch t.text 创建文本文件
用法：touch [选项]... 文件...
将所指定的每个文件的访问时间和修改时间更改为当前时间。

除非提供 -c 或 -h 选项，否则指定不存在的文件将会被创建为空文件。

如果所指定文件名为 - 则特殊处理，程序将更改与标准输出相关联的文件的
访问时间。

必选参数对长短选项同时适用。
  -a			只更改访问时间
  -c, --no-create	不创建任何文件
  -d, --date=字符串	使用指定字符串表示时间而非当前时间
  -f			(忽略)
  -h, --no-dereference		会影响符号链接本身，而非符号链接所指示的目的地
				(当系统支持更改符号链接的所有者时，此选项才有用)
  -m			只更改修改时间
  -r, --reference=文件   使用指定文件的时间属性而非当前时间
  -t 时间戳              使用给定 [[CC]YY]MMDDhhmm[.ss] 的时间戳而非当前时间
      --time=类型        修改指定类型的时间：
                           若所指定类型是 access、atime 或 use：与 -a 等效
                           若所指定类型是 modify 或 mtime：与 -m 等效
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出


onetree@ubuntu:~/linuxLearn$ cat t.text
hello
world

onetree@ubuntu:~/linuxLearn$ tac t.text 

world
hello

onetree@ubuntu:~/linuxLearn$ nl t.text 
     1	hello
     2	world
       
可进行翻页的操作more（只能往后翻） less
onetree@ubuntu:~/linuxLearn$ more t.text 
hello
world

head -n 20 t.text 显示前面20行
head -n +100 t.text 接下去显示100行
tail -n 100 t.text 显示后面20行

用法：od [选项]... [文件]...
　或：od [-abcdfilosx]... [文件] [[+]偏移量[.][b]]
　或：od --traditional [选项]... [文件] [[+]偏移量[.][b] [+][标签][.][b]]

以无歧义的表示方式将指定文件输出至标准输出，默认为八进制字节形式。
如果指定了多于一个文件，将它们以列出的顺序连接起来作为输入。

如果没有指定文件，或者文件为"-"，则从标准输入读取。

如果两个调用格式都适用，系统会在最后一个运算量以"+"或数字开始
(如果有两个运算量)的情况下采用第二种格式。
偏移量是指 -j 偏移量。标签是第一个字节的伪地址，
随着累积过程递增。偏移量和标签如果冠以"0x"或"0X"前缀则
表示十六进制数；后缀"."代表八进制数，后缀"b"表示乘以 512。

必选参数对长短选项同时适用。
  -A, --address-radix=RADIX   output format for file offsets; RADIX is one
                                of [doxn], for Decimal, Octal, Hex or None
      --endian={big|little}   swap input bytes according the specified order
  -j, --skip-bytes=BYTES      skip BYTES input bytes first
  -N, --read-bytes=BYTES      limit dump to BYTES input bytes
  -S BYTES, --strings[=BYTES]  output strings of at least BYTES graphic chars;
                                3 is implied when BYTES is not specified
  -t, --format=TYPE           select output format or formats
  -v, --output-duplicates     do not use * to mark line suppression
  -w[BYTES], --width[=BYTES]  output BYTES bytes per output line;
                                32 is implied when BYTES is not specified
      --traditional           accept arguments in third form above
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出


od -t c text以ascii字符输出

a 默认
c ASCII
d 10进制
f 浮点
o 八进制
x 16进制
```

### 文件与目录权限与隐藏属性
文件默认权限
```
umask: umask [-p] [-S] [模式]
    显示或设定文件模式掩码。
    
    设定用户文件创建掩码为 MODE 模式。如果省略了 MODE，则
    打印当前掩码的值。
    
    如果 MODE 模式以数字开头，则被当作八进制数解析；否则是一个
    chmod(1) 可接收的符号模式串。
    
    选项：
      -p	如果省略 MODE 模式，以可重用为输入的格式输入
      -S	以符号形式输出，否则以八进制数格式输出

umask 002 修改默认权限为 002表示原权限去掉002

```
文件隐藏属性
```
用法：lsattr [-RVadlpv] [文件...]
```
### 文件查找
1.脚本文件查找
```
which [-a] command
-a：将所有PATH目录中可以找到的命令列出
```

2.文件查找
```
 whereis [选项] [-BMS <dir>... -f] <文件目录与名称>

定位某个命令的二进制文件、源码和帮助页文件。

选项：
 -b         只搜索二进制文件
 -B <目录>  定义二进制文件查找路径
 -m         只搜索手册和信息
 -M <目录>  定义 man 和 info 查找路径
 -s         只搜索源代码
 -S <目录>  定义源代码查找路径
 -f         终止 <目录> 参数列表
 -u         搜索不常见记录
 -l         输出有效查找路径

whereis ifconfig 查找ifconfig

Usage: locate [OPTION]... [PATTERN]...
Search for entries in a mlocate database.

  -A, --all              only print entries that match all patterns
  -b, --basename         match only the base name of path names
  -c, --count            only print number of found entries
  -d, --database DBPATH  use DBPATH instead of default database (which is
                         /var/lib/mlocate/mlocate.db)
  -e, --existing         only print entries for currently existing files
  -L, --follow           follow trailing symbolic links when checking file
                         existence (default)
  -h, --help             print this help
  -i, --ignore-case      ignore case distinctions when matching patterns
  -p, --ignore-spaces    ignore punctuation and spaces when matching patterns
  -t, --transliterate    ignore accents using iconv transliteration when
                         matching patterns
  -l, --limit, -n LIMIT  limit output (or counting) to LIMIT entries
  -m, --mmap             ignored, for backward compatibility
  -P, --nofollow, -H     don't follow trailing symbolic links when checking file
                         existence
  -0, --null             separate entries with NUL on output
  -S, --statistics       don't search for entries, print statistics about each
                         used database
  -q, --quiet            report no error messages about reading databases
  -r, --regexp REGEXP    search for basic regexp REGEXP instead of patterns
      --regex            patterns are extended regexps
  -s, --stdio            ignored, for backward compatibility
  -V, --version          print version information
  -w, --wholename        match whole path name (default)

find比较慢，如果前面找不到用find
 find [-H] [-L] [-P] [-Olevel] [-D debugopts] [path...] [expression]

```

### 文件系统的简单操作
```
df：列出文件系统的整体磁盘使用量
du: 查看目录所占磁盘空间
```

### 磁盘分区格式化
```
lsblk [选项] [<设备> ...]

列出块设备的信息。

选项：
 -D, --discard        打印时丢弃能力
 -E, --dedup <column> de-duplicate output by <column>
 -I, --include <列表> 只显示有指定主设备号的设备
 -J, --json           使用 JSON 输出格式
 -O, --output-all     输出所有列
 -P, --pairs          使用 key=“value” 输出格式
 -S, --scsi           输出有关 SCSI 设备的信息
 -T, --tree[=<column>] use tree format output
 -a, --all            打印所有设备
 -b, --bytes          以字节为单位而非易读的格式来打印 SIZE
 -d, --nodeps         不打印从属设备(slave)或占位设备(holder)
 -e, --exclude <列表> 根据主设备号排除设备(默认：内存盘)
 -f, --fs             输出文件系统信息
 -i, --ascii          只使用 ascii 字符
 -l, --list           使用列表格式的输出
 -M, --merge          group parents of sub-trees (usable for RAIDs, Multi-path)
 -m, --perms          输出权限信息
 -n, --noheadings     不打印标题
 -o, --output <列表>  输出列
 -p, --paths          打印完整设备路径
 -r, --raw            使用原生输出格式
 -s, --inverse        反向依赖
 -t, --topology       输出拓扑信息
 -z, --zoned          print zone model
 -x, --sort <列>      按<列>对输出排序
     --sysroot <dir>  use specified directory as system root


磁盘分区
gdisk
fdisk
partedS
```

### 文件系统校验
```
Usage: xfs_repair [options] device

Options:
  -f           The device is a file
  -L           Force log zeroing. Do this as a last resort.
  -l logdev    Specifies the device where the external log resides.
  -m maxmem    Maximum amount of memory to be used in megabytes.
  -n           No modify mode, just checks the filesystem for damage.
               (Cannot be used together with -e.)
  -P           Disables prefetching.
  -r rtdev     Specifies the device where the realtime section resides.
  -v           Verbose output.
  -c subopts   Change filesystem parameters - use xfs_admin.
  -o subopts   Override default behaviour, refer to man page.
  -t interval  Reporting interval in seconds.
  -d           Repair dangerously.
  -e           Exit with a non-zero code if any errors were repaired.
               (Cannot be used together with -n.)
  -V           Reports version and exits.



用法：fsck.ext4 [-panyrcdfktvDFV] [-b 超级块] [-B 块大小]
	[-l|-L 坏块文件] [-C fd] [-j 外部日志]
	[-E 扩展选项]  [-z 撤销文件] 设备

重要提示：
 -p                   自动修复（不询问）
 -n                   不对文件系统做任何更改
 -y                   对所有询问都回答“是”
 -c                   检查可能的坏块，并将它们加入坏块列表
 -f                   强制进行检查，即使文件系统被标记为“没有问题”
 -v                   显示更多信息
 -b superblock        使用备选超级块
 -B blocksize         使用指定块大小来查找超级块
 -j external_journal  指定外部日志的位置
 -l bad_blocks_file   添加到指定的坏块列表（文件）
 -L bad_blocks_file   指定坏块列表（文件）
 -z undo_file         创建一个撤销文件


```

### 文件挂载与卸载
```
mount [-lhV]
 mount -a [选项]
 mount [选项] [--source] <源> | [--target] <目录>
 mount [选项] <源> <目录>
 mount <操作> <挂载点> [<目标>]

挂载文件系统。

选项：
 -a, --all               挂载 fstab 中的所有文件系统
 -c, --no-canonicalize   不对路径规范化
 -f, --fake              空运行；跳过 mount(2) 系统调用
 -F, --fork              对每个设备禁用 fork(和 -a 选项一起使用)
 -T, --fstab <路径>      /etc/fstab 的替代文件
 -i, --internal-only     不调用 mount.<type> 辅助程序
 -l, --show-labels       也显示文件系统标签
 -n, --no-mtab           不写 /etc/mtab
     --options-mode <mode>
                         what to do with options loaded from fstab
     --options-source <source>
                         mount options source
     --options-source-force
                         force use of options from fstab/mtab
 -o, --options <列表>    挂载选项列表，以英文逗号分隔
 -O, --test-opts <列表>  限制文件系统集合(和 -a 选项一起使用)
 -r, --read-only         以只读方式挂载文件系统(同 -o ro)
 -t, --types <列表>      限制文件系统类型集合
     --source <源>       指明源(路径、标签、uuid)
     --target <目标>     指明挂载点
 -v, --verbose           打印当前进行的操作
 -w, --rw, --read-write  以读写方式挂载文件系统(默认)
 -N, --namespace <ns>    perform mount in another namespace

 -h, --help              display this help
 -V, --version           display version

源：
 -L, --label <标签>      同 LABEL=<label>
 -U, --uuid <uuid>       同 UUID=<uuid>
 LABEL=<标签>            按文件系统标签指定设备
 UUID=<uuid>             按文件系统 UUID 指定设备
 PARTLABEL=<标签>        按分区标签指定设备
 PARTUUID=<uuid>         按分区 UUID 指定设备
 <设备>                  按路径指定设备
 <目录>                  绑定式挂载的挂载点(参阅 --bind/rbind)
 <文件>                  用于设置回环设备的常规文件

操作：
 -B, --bind              挂载其他位置的子树(同 -o bind)
 -M, --move              将子树移动到其他位置
 -R, --rbind             挂载其他位置的子树及其包含的所有子挂载(submount)
 --make-shared           将子树标记为 共享
 --make-slave            将子树标记为 从属
 --make-private          将子树标记为 私有
 --make-unbindable       将子树标记为 不可绑定
 --make-rshared          递归地将整个子树标记为 共享
 --make-rslave           递归地将整个子树标记为 从属
 --make-rprivate         递归地将整个子树标记为 私有
 --make-runbindable      递归地将整个子树标记为 不可绑定

 umount [-hV]
 umount -a [选项]
 umount [选项] <源> | <目录>

卸载文件系统。

选项：
 -a, --all               卸载所有文件系统
 -A, --all-targets       卸载当前名字空间内指定设备
                         对应的所有挂臷点
 -c, --no-canonicalize   不对路径规范化
 -d, --detach-loop       若挂臷了回环设备，也释放该回环设备
     --fake              空运行；跳过 umount(2) 系统调用
 -f, --force             强制卸载(遇到不响应的 NFS 系统时)
 -i, --internal-only     不调用 umount.<类型> 辅助程序
 -n, --no-mtab           不写 /etc/mtab
 -l, --lazy              立即断开文件系统，清理以后执行
 -O, --test-opts <列表>  限制文件系统集合(和 -a 选项一起使用)
 -R, --recursive         递归卸载目录及其子对象
 -r, --read-only         若卸载失败，尝试以只读方式重新挂臷
 -t, --types <列表>      限制文件系统集合
 -v, --verbose           打印当前进行的操作
 -q, --quiet             suppress 'not mounted' error messages
 -N, --namespace <ns>    perform umount in another namespace

 -h, --help              display this help
 -V, --version           display version

```

### 磁盘/文件系统自定义参数
```
用法：mknod [选项]... 名称 类型 [主设备号 次设备号]
以指定的名称和指定的类型创建特殊文件。

必选参数对长短选项同时适用。
  -m, --mode=模式   	设置权限模式(类似chmod)，而不是rwxrwxrwx 减umask
  -Z                   设置 SELinux 安全上下文为默认类型
      --context[=CTX]  类似 -Z，或者如果指定了 CTX 则设置 SELinux 或
                         SMACK 安全上下文为给定的 CTX 值
      --help		显示此帮助信息并退出
      --version		显示版本信息并退出

当类型为"p"时可不指定主设备号和次设备号，否则它们是必须指定的。
如果主设备号和次设备号以"0x"或"0X"开头，它们会被视作十六进制数来
解析；如果以"0"开头，则被视作八进制数；其余情况下被视作十进制数。
可用的类型包括：

  b      创建(有缓冲的)区块特殊文件
  c, u   创建(没有缓冲的)字符特殊文件
  p      创建先进先出(FIFO)特殊文件


```

### 内存分区
```
 mkswap [选项] 设备 [大小]

设置 Linux 交换区。

Options:
 -c, --check               check bad blocks before creating the swap area
 -f, --force               allow swap size area be larger than device
 -p, --pagesize SIZE       specify page size in bytes
 -L, --label LABEL         specify label
 -v, --swapversion NUM     specify swap-space version number
 -U, --uuid UUID           specify the uuid to use
 -h, --help                display this help
 -V, --version             display version

更多信息请参阅 mkswap(8)。

```

## 压缩
### 压缩指令
```
gzip
bzip2
xz
```

### 打包(多个文件进行压缩)
```
tar
```
### 备份
```
dd  
cpio
用法： cpio [选项...] [目标目录]

```

## vim
自己领会去吧 哈哈

## shell
### 变量
```
显示变量
echo $var
echo ${var}
onetree@ubuntu:~$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
onetree@ubuntu:~$ echo ${PATH}
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

设置变量 
onetree@ubuntu:~$ echo ${myname}

onetree@ubuntu:~$ myname=VB
onetree@ubuntu:~$ echo ${myname}
VB

变量定义
var=value
var='value'
var="value"

var = VB
var1 ="$var its me" #VB its me
var1 = '$var its me' #$var its me


变量的键盘读取read
onetree@ubuntu:~$ read var
hello world
onetree@ubuntu:~$ echo ${var}
hello world

//30s内输入并赋值给var
onetree@ubuntu:~$ read -p "Enter your name:" -t 30 var
Enter your name:hello
onetree@ubuntu:~$ echo ${var}
hello


declare: declare [-aAfFgilnrtux] [-p] [名称[=值] ...]
    设定变量值和属性。
    
    声明变量并且赋予它们属性。如果没有给定名称，
    则显示所有变量的属性和值。
    
    选项：
      -f	限制动作或显示为仅函数名称和定义
      -F	限制仅显示函数名称 (以及调试时显示行号和源文件名)
      -g	当用于 shell 函数内时创建全局变量; 否则忽略
      -p	显示每个 NAME 变量的属性和值
    
    设定属性的选项：
      -a	使 NAME 成为下标数组 (如果支持)
      -A	使 NAME 成为关联数组 (如果支持)
      -i	使 NAME 带有 `integer' (整数)属性
      -l	将 NAME 在赋值时转为小写
      -n	使 NAME 成为指向一个以其值为名称的变量的引用
      -r	将 NAME 变为只读
      -t	使 NAME 带有 `trace' (追踪)属性
      -u	将每个 NAME 在赋值时转为大写
      -x	将 NAME 导出
    用 `+' 代替 `-' 会关闭指定选项。
onetree@ubuntu:~$ declare -i sum=100+300
onetree@ubuntu:~$ echo ${sum}
400


```

## 正则表达式
```
下载练习的文本
onetree@ubuntu:~/linuxLearn$ wget http://linux.vbird.org/linux_basic/0330regularex/regular_express.txt

1.找出带the的行
onetree@ubuntu:~/linuxLearn$ grep -n 'the' regular_express.txt 
8:I can't finish the test.
12:the symbol '*' is represented as start.
15:You are the best is mean you are the no. 1.
16:The world <Happy> is the same with "glad".
18:google is the best tools for search keyword.

2。找出不带the的行
onetree@ubuntu:~/linuxLearn$ grep -vn 'the' regular_express.txt 
1:"Open Source" is a good mechanism to develop programs.
2:apple is my favorite food.
3:Football game is not use feet only.
4:this dress doesn't fit me.
5:However, this dress is about $ 3183 dollars.
6:GNU is free air not free beer.
7:Her hair is very beauty.
9:Oh! The soup taste good.
10:motorcycle is cheap than car.
11:This window is clear.
13:Oh!	My god!
14:The gd software is a library for drafting programs.
17:I like dog.
19:goooooogle yes!
20:go! go! Let's go.
21:# I am VBird

3.不匹配大小写的the
onetree@ubuntu:~/linuxLearn$ grep -in 'the' regular_express.txt 
8:I can't finish the test.
9:Oh! The soup taste good.
12:the symbol '*' is represented as start.
14:The gd software is a library for drafting programs.
15:You are the best is mean you are the no. 1.
16:The world <Happy> is the same with "glad".
18:google is the best tools for search keyword.



4.[]中括号，如[ae]表示缺失的字符应该为a或e(只有一个字符)
onetree@ubuntu:~/linuxLearn$ grep -n 't[ae]st' regular_express.txt 
8:I can't finish the test.
9:Oh! The soup taste good.

5.[^g]oo查找带‘？oo’的字符，?不是g
onetree@ubuntu:~/linuxLearn$ grep -n '[^g]oo' regular_express.txt 
2:apple is my favorite food.
3:Football game is not use feet only.
18:google is the best tools for search keyword.
19:goooooogle yes!

6.查找带‘？oo’的字符，?不是小写，‘-’表示范围
onetree@ubuntu:~/linuxLearn$ grep -n '[^a-z]oo' regular_express.txt 
3:Football game is not use feet only.


7.查早the出现在行首的
onetree@ubuntu:~/linuxLearn$ grep -n '^the' regular_express.txt 
12:the symbol '*' is represented as start.


8.查早行尾是‘.’的
onetree@ubuntu:~/linuxLearn$ grep -n '\.$' regular_express.txt
1:"Open Source" is a good mechanism to develop programs.
2:apple is my favorite food.
3:Football game is not use feet only.
4:this dress doesn't fit me.
10:motorcycle is cheap than car.
11:This window is clear.
12:the symbol '*' is represented as start.
15:You are the best is mean you are the no. 1.
16:The world <Happy> is the same with "glad".
17:I like dog.
18:google is the best tools for search keyword.
20:go! go! Let's go.

9.查找空白行
onetree@ubuntu:~/linuxLearn$ grep -n '^$' regular_express.txt
22:

10.查找‘gxxd’ ,..代表一个字符
onetree@ubuntu:~/linuxLearn$ grep -n 'g..d' regular_express.txt
1:"Open Source" is a good mechanism to develop programs.
9:Oh! The soup taste good.
16:The world <Happy> is the same with "glad".


11.查找至少练习两个‘o’  *表示重复前面一个字符，重复0ci以上
onetree@ubuntu:~/linuxLearn$ grep -n 'ooo*' regular_express.txt
1:"Open Source" is a good mechanism to develop programs.
2:apple is my favorite food.
3:Football game is not use feet only.
9:Oh! The soup taste good.
18:google is the best tools for search keyword.
19:goooooogle yes!


12.查找g.....g
onetree@ubuntu:~/linuxLearn$ grep -n 'g.*g' regular_express.txt
1:"Open Source" is a good mechanism to develop programs.
14:The gd software is a library for drafting programs.
18:google is the best tools for search keyword.
19:goooooogle yes!
20:go! go! Let's go.


13.查找连续两个o
onetree@ubuntu:~/linuxLearn$ grep -n 'o\{2\}' regular_express.txt
1:"Open Source" is a good mechanism to develop programs.
2:apple is my favorite food.
3:Football game is not use feet only.
9:Oh! The soup taste good.
18:google is the best tools for search keyword.
19:goooooogle yes!


14查找g后面连续2到5个o
onetree@ubuntu:~/linuxLearn$ grep -n 'go\{2,5\}' regular_express.txt
1:"Open Source" is a good mechanism to develop programs.
9:Oh! The soup taste good.
18:google is the best tools for search keyword.
19:goooooogle yes!

15
onetree@ubuntu:~/linuxLearn$ grep -n 'go\{2,\}g' regular_express.txt
18:google is the best tools for search keyword.
19:goooooogle yes!


```
### seed
```
用法: sed [选项]... {脚本(如果没有其他脚本)} [输入文件]...

  -n, --quiet, --silent
                 取消自动打印模式空间
      --debug
                 annotate program execution
  -e 脚本, --expression=脚本
                 添加“脚本”到程序的运行列表
  -f 脚本文件, --file=脚本文件
                 添加“脚本文件”到程序的运行列表
  --follow-symlinks
                 直接修改文件时跟随软链接
  -i[扩展名], --in-place[=扩展名]
                 直接修改文件（如果指定扩展名则备份文件）
  -l N, --line-length=N
                 指定“l”命令的换行期望长度
  --posix
                 关闭所有 GNU 扩展
  -E, -r, --regexp-extended
                 在脚本中使用扩展正则表达式
                 （为保证可移植性使用 POSIX -E）。
  -s, --separate
                 将输入文件视为各个独立的文件而不是单个
                 长的连续输入流。
      --sandbox
                 在沙盒模式中进行操作（禁用 e/r/w 命令）。
  -u, --unbuffered
                 从输入文件读取最少的数据，更频繁的刷新输出
  -z, --null-data
                 使用 NUL 字符分隔各行
      --help     打印帮助并退出
      --version  输出版本信息并退出


删除2~5行，后面不展示了
onetree@ubuntu:~/linuxLearn$ nl seedtest.txt |sed '2,5d'
     1	"Open Source" is a good mechanism to develop programs.
     6	GNU is free air not free beer.
     7	Her hair is very beauty.
     8	I can't finish the test.
     9	Oh! The soup taste good.
    10	motorcycle is cheap than car.
    11	This window is clear.
    12	the symbol '*' is represented as start.
    13	Oh!	My god!
    14	The gd software is a library for drafting programs.
    15	You are the best is mean you are the no. 1.
    16	The world <Happy> is the same with "glad".
    17	I like dog.
    18	google is the best tools for search keyword.
    19	goooooogle yes!
    20	go! go! Let's go.
    21	# I am VBird

sed '2a d'第二行后面加上d
sed '2a d\
d'  第二行后面加上d，另增加一行d
sed '2,5c No 2-5 number'将2-5行替换成”No 2-5 number“
```

## shell编程
### 输出
```
#!/bin/bash
echo "hello world"
exit 0
```

### read读取
```
#!bin/bash
read -p "Please Enter name: " name
echo "Your name is: ${name}"

```

### 运算
```
#!/bin/bash
echo "Enter 2 nums:"
read -p "first num:" firstnum
read -p "second num:" secnum
res=$((${firstnum}*${secnum}))
echo "\n result is ${res}"

```

### test
```
#!/bin/bash
echo "Please input filename:"
read -p "FIlename:" filename
test -z ${filename} && echo "Your must input filename" && exit 0
#test !-e ${filename} && echo "Not exist" && exit 0
test -f ${filename} && filetype="regulare file"
test -d ${filename} && filetype="directory"
test -r ${filename} && perm="read"
test -w ${filename} && perm="${perm} write"

echo "THe filename:${filename} is ${filetype} and ${perm}"

```

### if
```
#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/user/sbin:usr/local/bin:/usr/local/sbin:~/bin
read -p "Enter(y/n):" yn
if [ "$yn" == "Y" ] || [ "$yn" == "y" ];then

	echo "Yes"
	exit 0

elif [ "$yn" == "N" ]||[ "$yn" == "n" ];then
	echo "No"
	exit 0
else
	echo "none"
fi
echo "other"

```

### case
```

#!/bin/bash

case $变量 in
	"第一个变量内容")
		程序段
		;;
	"第二个变量内容")
		程序段
		;;
	*)
		程序段
    exit 1
		;;
esac


#!/bin/bash

case ${1} in
	"hello")
		echo "Hello"
		;;
	"")
		echo "You must input ,ex>{${0} some word}"
		;;
	*)
		echo "${1}"
		;;
esac





onetree@ubuntu:~/shell_learn$ sh hello.sh hellp
hellp
onetree@ubuntu:~/shell_learn$ sh hello.sh hello
Hello
onetree@ubuntu:~/shell_learn$ sh hello.sh 
You must input ,ex>{hello.sh some word}

```


### function
```
#!/bin/bash

function printff(){
	echo "hello ${1}"
}

printff 1;
printff 2;

```

### loop
```
#!/bin/bash
while [ "${yn}" != "Y" ]
do
	read -p "loop1 Y?" yn
	echo "input loop1 is ${yn}"
done

echo "while test ok"

until [ "${yn}" == "y" ]
do
	read -p "y?" yn
done

echo "until test ok"


for animal in dog cat elephant
do
	echo "${animal}"
done
echo "for test ok"

for (( i=1;i<=10;i=i+1))
do
	echo "$[i]"
done

```

### 随机数
```
#!/bin/bash

num=9
res=$(( ${RANDOM} * ${num}  / 32767 + 1 ))
echo ${res}

```

## 程序和进程
程序：通常为二进制程序，防止再存储媒介中，以物理文件的形式存在
进程：程序被触发后，执行者的权限与属性，程序的代码和所需数据都会被加载到内存中，操作系统给予这个内存中的单元一个标识符（PID），可以说进程是一个正在运行的程序

```
#静态显示进程
ps -l 仅仅查看跟自己bash有关的进程
ps -aux 显示所有进程

#动态显示进程
top -d 2 2s刷新一次

#删除进程
kill

#查看内存使用状况
free -m

#查看内核相关信息
uname -a

#查看系统启动时间与任务负载
uptime

#追踪网络
netstat

#分析内核产生的信息
dmsg

#检测系统资源变化
vmstat

#借由文件找出正在使用该文件的进程
fuser
fuser -uv /proc
```

## 服务
```
systemctl [command] [unit]
start：立刻启动后面接的 unit。
stop：立刻关闭后面接的 unit。
restart：立刻关闭后启动后面接的 unit，亦即执行 stop 再 start 的意思。
reload：不关闭 unit 的情况下，重新载入配置文件，让设置生效。
enable：设置下次开机时，后面接的 unit 会被启动。
disable：设置下次开机时，后面接的 unit 不会被启动。
status：目前后面接的这个 unit 的状态，会列出有没有正在执行、开机时是否启动等信息。
is-active：目前有没有正在运行中。
is-enabled：开机时有没有默认要启用这个 unit。
kill ：不要被 kill 这个名字吓着了，它其实是向运行 unit 的进程发送信号。
show：列出 unit 的配置。
mask：注销 unit，注销后你就无法启动这个 unit 了。
unmask：取消对 unit 的注销。


systemctl status cpu.service
```


## GCC
```
产生hello.o,不会产生二进制执行文件
gcc -c hello.c
优化编译
gcc -O hello.c -c
链接外部函数库，如math.h
gcc sin.c -lm -L/lib -I/usr/include
#输出二进制文件名
gcc -o hello hello.c
#会产生警告
gcc -o hello hello.c -Wall
```