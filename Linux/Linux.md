# Linux 命令

## 目录结构
系统启动必须：
```bash
/boot：存放的启动Linux 时使用的内核文件，包括连接文件以及镜像文件。
/etc：存放所有的系统需要的配置文件和子目录列表，更改目录下的文件可能会导致系统不能启动。
/lib：存放基本代码库（比如c++库），其作用类似于Windows里的DLL文件。几乎所有的应用程序都需要用到这些共享库。
/sys： 这是linux2.6内核的一个很大的变化。该目录下安装了2.6内核中新出现的一个文件系统 sysfs 。sysfs文件系统集成了下面3种文件系统的信息：针对进程信息的proc文件系统、针对设备的devfs文件系统以及针对伪终端的devpts文件系统。该文件系统是内核设备树的一个直观反映。当一个内核对象被创建的时候，对应的文件和目录也在内核对象子系统中
```
指令集合：
```
/bin：存放着最常用的程序和指令
/sbin：只有系统管理员能使用的程序和指令。
```
外部文件管理：
```
/dev ：Device(设备)的缩写, 存放的是Linux的外部设备。注意：在Linux中访问设备和访问文件的方式是相同的。
/media：类windows的其他设备，例如U盘、光驱等等，识别后linux会把设备放到这个目录下。
/mnt：临时挂载别的文件系统的，我们可以将光驱挂载在/mnt/上，然后进入该目录就可以查看光驱里的内容了。
```
临时文件：
```
/run：是一个临时文件系统，存储系统启动以来的信息。当系统重启时，这个目录下的文件应该被删掉或清除。如果你的系统上有 /var/run 目录，应该让它指向 run。
/lost+found：一般情况下为空的，系统非法关机后，这里就存放一些文件。
/tmp：这个目录是用来存放一些临时文件的。
```
账户：
```
/root：系统管理员的用户主目录。
/home：用户的主目录，以用户的账号命名的。
/usr：用户的很多应用程序和文件都放在这个目录下，类似于windows下的program files目录。
/usr/bin：系统用户使用的应用程序与指令。
/usr/sbin：超级用户使用的比较高级的管理程序和系统守护程序。
/usr/src：内核源代码默认的放置目录。
```
运行过程中要用：
```
/var：存放经常修改的数据，比如程序运行的日志文件（/var/log 目录下）。
/proc：管理内存空间！虚拟的目录，是系统内存的映射，我们可以直接访问这个目录来，获取系统信息。这个目录的内容不在硬盘上而是在内存里，我们也可以直接修改里面的某些文件来做修改。
```
扩展用的：
```
/opt：默认是空的，我们安装额外软件可以放在这个里面。
/srv：存放服务启动后需要提取的数据（不用服务器就是空）
```

## 正则表达式
正则表达式(regular expression)描述了一种字符串匹配的模式（pattern），可以用来检查一个串是否含有某种子串、将匹配的子串替换或者从某个串中取出符合某个条件的子串等。

* `^` 为匹配输入字符串的开始位置，`$` 结束标识；
* `[0-9]+` 匹配多个数字，`[0-9]` 匹配单个数字，`+` 匹配一个或者多个；

### 普通字符
|字符|描述|
|--|--|
|[ABC]|匹配 [...] 中的所有字符，例如 [aeiou] 匹配字符串 "google runoob taobao" 中所有的 e o u a 字母。|
|[^ABC]|匹配除了 [...] 中字符的所有字符，例如 [^aeiou] 匹配字符串 "google runoob taobao" 中除了 e o u a 字母的所有字母。|
|[A-Z]|[A-Z] 表示一个区间，匹配所有大写字母，[a-z] 表示所有小写字母。|
|.|匹配除换行符（\n、\r）之外的任何单个字符，相等于 [^\n\r]。|
|[\s\S]|匹配所有。\s 是匹配所有空白符，包括换行，\S 非空白符，不包括换行。|
|\w|匹配字母、数字、下划线。等价于 [A-Za-z0-9_]|

### 特殊字符
|字符|	描述|
|:--:|--|
$	|匹配输入字符串的结尾位置。如果设置了 RegExp 对象的 Multiline 属性，则 $ 也匹配 '\n' 或 '\r'。要匹配 $ 字符本身，请使用` \$`。
( )	|标记一个子表达式的开始和结束位置。子表达式可以获取供以后使用。要匹配这些字符，请使用 `\( 和 \)`。
\*	|匹配前面的子表达式零次或多次。要匹配 * 字符，请使用 `\*`。
\+	|匹配前面的子表达式一次或多次。要匹配 + 字符，请使用 `\+`。
.	|匹配除换行符 \n 之外的任何单字符。要匹配 . ，请使用 `\.` 。
[	|标记一个中括号表达式的开始。要匹配 [，请使用 `\[`。
?	|匹配前面的子表达式零次或一次，或指明一个非贪婪限定符。要匹配 ? 字符，请使用 `\?`。
\	|将下一个字符标记为或特殊字符、或原义字符、或向后引用、或八进制转义符。例如， 'n' 匹配字符 'n'。'\n' 匹配换行符。序列 '`\\`' 匹配 "`\`"，而 '`\(`' 则匹配 "("。
^	|匹配输入字符串的开始位置，除非在方括号表达式中使用，当该符号在方括号表达式中使用时，表示不接受该方括号表达式中的字符集合。要匹配 ^ 字符本身，请使用 `\^`。
{	|标记限定符表达式的开始。要匹配 {，请使用 `\{`。
|	|指明两项之间的一个选择。要匹配 |，请使用 `\|`。

### 限定符
字符	|描述
--|--
\*	|匹配前面的子表达式零次或多次。例如，zo* 能匹配 "z" 以及 "zoo"。* 等价于{0,}。
\+	|匹配前面的子表达式一次或多次。例如，'zo+' 能匹配 "zo" 以及 "zoo"，但不能匹配 "z"。+ 等价于 {1,}。
?	|匹配前面的子表达式零次或一次。例如，"do(es)?" 可以匹配 "do" 、 "does" 中的 "does" 、 "doxy" 中的 "do" 。? 等价于 {0,1}。
{n}	|n 是一个非负整数。匹配确定的 n 次。例如，'o{2}' 不能匹配 "Bob" 中的 'o'，但是能匹配 "food" 中的两个 o。
{n,}	|n 是一个非负整数。至少匹配n 次。例如，'o{2,}' 不能匹配 "Bob" 中的 'o'，但能匹配 "foooood" 中的所有 o。'o{1,}' 等价于 'o+'。'o{0,}' 则等价于 'o*'。
{n,m}	|m 和 n 均为非负整数，其中n <= m。最少匹配 n 次且最多匹配 m 次。例如，"o{1,3}" 将匹配 "fooooood" 中的前三个 o。'o{0,1}' 等价于 'o?'。请注意在逗号和两个数之间不能有空格。

### 定位符

字符	|描述
:--:|--
^	|匹配输入字符串开始的位置。如果设置了 RegExp 对象的 Multiline 属性，^ 还会与 \n 或 \r 之后的位置匹配。
$	|匹配输入字符串结尾的位置。如果设置了 RegExp 对象的 Multiline 属性，$ 还会与 \n 或 \r 之前的位置匹配。
\b	|匹配一个单词边界，即字与空格间的位置。
\B	|非单词边界匹配。

<br>

## ss
Socket Statistics的缩写。ss命令用来显示处于活动状态的套接字信息。它可以显示和netstat类似的内容。但ss的优势在于它能够显示更多更详细的有关TCP和连接状态的信息，而且比netstat更快速更高效。

语法格式：ss [参数]

常用参数：

```bash
-n	不解析服务名称，已数字方式显示
-a	显示所有套接字
-l 	显示处于监听状态的套接字
-o 	显示计时器信息
-e	显示详细的套接字信息
-m	显示套接字的内存使用情况
-p	显示使用套接字的进程
-i	显示内部的TCP信息
-s	显示套接字使用概况
-4	仅显示ipv4的套接字
-6	仅显示ipv6的套接字
-0	显示PACKET套接字
-t	只显示TCP套接字
-u	只显示UDP套接字
-d	只显示DCCP套接字
-w	只显示RAW套接字
-x	只显示 Unix套接字
-D  将原始TCP套接字信息转储到文件
```

## netstat 
用于显示各种网络相关信息，如网络连接，路由表，接口状态 (Interface Statistics)，masquerade 连接，多播成员 (Multicast Memberships) 等等。

从整体上看，netstat的输出结果可以分为两个部分：一个是Active Internet connections，称为有源TCP连接，其中”Recv-Q”和”Send-Q”指%0A的是接收队列和发送队列。这些数字一般都应该是0。如果不是则表示软件包正在队列中堆积。这种情况只能在非常少的情况见到；另一个是Active UNIX domain sockets，称为有源Unix域套接口(和网络套接字一样，但是只能用于本机通信，性能可以提高一倍)。

语法格式：netstat [参数]

常用参数：
```bash
-a	显示所有连线中的Socket
-p	显示正在使用Socket的程序识别码和程序名称
-u	显示UDP传输协议的连线状况
-i  显示网络界面信息表单
-n	直接使用IP地址，不通过域名服务器
-r  显示路由信息

```

## ifconfig

英文全称是“network interfaces configuring”，即用于配置和显示Linux内核中网络接口的网络参数。用ifconfig命令配置的网卡信息，在网卡重启后机器重启后，配置就不存在。要想将上述的配置信息永远的存的电脑里，那就要修改网卡的配置文件了。 

语法格式：ifconfig [参数]

常用参数：
```bash
add<地址>   设置网络设备IPv6的IP地址
del<地址> 	删除网络设备IPv6的IP地址
down        关闭指定的网络设备
up	        启动指定的网络设备
IP地址	    指定网络设备的IP地址 
```

## 文本搜索工具 - grep

“global search regular expression and print out the line”的简称，意思是全面搜索正则表达式，并将其打印出来。这个命令可以结合正则表达式使用，它也是linux使用最为广泛的命令。

grep命令的选项用于对搜索过程的补充，而其命令的模式十分灵活，可以是变量、字符串、正则表达式。需要注意的是：一当模式中包含了空格，务必要用双引号将其引起来。

linux系统支持三种形式的grep命令，大儿子就是grep，标准，模仿的代表。二儿子兴趣爱好多-egrep，简称扩展grep命令，其实和grep -E等价，支持基本和扩展的正则表达式。小儿子跑的最快-fgrep，简称快速grep命令，其实和grep -F等价，不支持正则表达式，按照字符串表面意思进行匹配。

语法格式： grep [参数]

常用参数：
```bash
-i	搜索时，忽略大小写
-c	只输出匹配行的数量
-l	只列出符合匹配的文件名，不列出具体的匹配行
-n	列出所有的匹配行，显示行号
-h	查询多文件时不显示文件名
-s	不显示不存在、没有匹配文本的错误信息
-v	显示不包含匹配文本的所有行
-w	匹配整词
-x	匹配整行
-r	递归搜索
-q	禁止输出任何结果，已退出状态表示搜索是否成功
-b	打印匹配行距文件头部的偏移量，以字节为单位
-o	与-b结合使用，打印匹配的词据文件头部的偏移量，以字节为单位
```

## 实时显示进程动态 - top

Linux下常用的性能分析工具，能够实时显示系统中各个进程的资源占用状况，常用于服务端性能分析。

在top命令中按f按可以查看显示的列信息，按对应字母来开启/关闭列，大写字母表示开启，小写字母表示关闭。带*号的是默认列。

语法格式：top [参数]

常用参数：

```bash
-d 	改变显示的更新速度，或是在交谈式指令列(interactive command)按 s
-q 	没有任何延迟的显示速度，如果使用者是有 superuser 的权限，则 top 将会以最高的优先序执行
-c  切换显示模式
-s	安全模式，将交谈式指令取消, 避免潜在的危机
-i	不显示任何闲置 (idle) 或无用 (zombie) 的行程
-n	更新的次数，完成后将会退出 top
-b	批次档模式，搭配 “n” 参数一起使用，可以用来将 top 的结果输出到档案内
```

## 文本、数据处理 - awk
一种编程语言，用于在linux/unix下对文本和数据进行处理。

而且它支持用户自定义函数和动态正则表达式等先进功能，是linux/unix下的一个强大编程工具。

语法格式：awk [参数] [文件]

常用参数：
```bash
-F	指定输入时用到的字段分隔符
-v	自定义变量
-f	从脚本中读取awk命令
-m	对val值设置内在限制 
```

## 显示进程状态 - ps
“process status”的缩写，ps命令用于显示当前系统的进程状态。可以搭配kill指令随时中断、删除不必要的程序。

ps命令是最基本同时也是非常强大的进程查看命令，使用该命令可以确定有哪些进程正在运行和运行的状态、进程是否结束、进程有没有僵死、哪些进程占用了过多的资源等等，总之大部分信息都是可以通过执行该命令得到的。

语法格式：ps [参数]

常用参数：
```bash
-a	        显示所有终端机下执行的程序，除了阶段作业领导者之外
a	        显示现行终端机下的所有程序，包括其他用户的程序
-A	        显示所有程序
-c	        显示CLS和PRI栏位
c	        列出程序时，显示每个程序真正的指令名称，而不包含路径，选项或常驻服务的标示
-C <指令名称>	指定执行指令的名称，并列出该指令的程序的状况
-d	        显示所有程序，但不包括阶段作业领导者的程序
-e	        此选项的效果和指定”A”选项相同
e	        列出程序时，显示每个程序所使用的环境变量
-f	        显示UID,PPIP,C与STIME栏位
f	        用ASCII字符显示树状结构，表达程序间的相互关系
-g <群组名称>	此选项的效果和指定”-G”选项相同，当亦能使用阶段作业领导者的名称来指定
g	        显示现行终端机下的所有程序，包括群组领导者的程序
-G <群组识别码>	列出属于该群组的程序的状况，也可使用群组名称来指定
h	        不显示标题列
-H	        显示树状结构，表示程序间的相互关系
-j或j	    采用工作控制的格式显示程序状况
-l或l	    采用详细的格式来显示程序状况
L	        列出栏位的相关信息
-m或m	    显示所有的执行绪
n	        以数字来表示USER和WCHAN栏位
-N	        显示所有的程序，除了执行ps指令终端机下的程序之外
-p <程序识别码>	指定程序识别码，并列出该程序的状况
p  <程序识别码>	此选项的效果和指定”-p”选项相同，只在列表格式方面稍有差异
r	        只列出现行终端机正在执行中的程序
-s  <阶段作业>	指定阶段作业的程序识别码，并列出隶属该阶段作业的程序的状况
s	        采用程序信号的格式显示程序状况
S	        列出程序时，包括已中断的子程序资料
-t  <终端机编号>	指定终端机编号，并列出属于该终端机的程序的状况
t   <终端机编号>	此选项的效果和指定”-t”选项相同，只在列表格式方面稍有差异
-T	        显示现行终端机下的所有程序
-u  <用户识别码>	此选项的效果和指定”-U”选项相同
u	        以用户为主的格式来显示程序状况
-U  <用户识别码>	列出属于该用户的程序的状况，也可使用用户名称来指定
U   <用户名称>	列出属于该用户的程序的状况
v	        采用虚拟内存的格式显示程序状况
-V或V	    显示版本信息
-w或w	    采用宽阔的格式来显示程序状况
x	        显示所有程序，不以终端机来区分
X	        采用旧式的Linux i386登陆格式显示程序状况
-y	        配合选项”-l”使用时，不显示F(flag)栏位，并以RSS栏位取代ADDR栏位
-- <程序识别码>	        此选项的效果和指定”p”选项相同
--cols <每列字符数>	    设置每列的最大字符数
--columns <每列字符数>	此选项的效果和指定”--cols”选项相同
--cumulative	        此选项的效果和指定”S”选项相同
--deselect	            此选项的效果和指定”-N”选项相同
--forest	            此选项的效果和指定”f”选项相同
--headers	            重复显示标题列
--help	                在线帮助
--info	                显示排错信息
--lines <显示列数>	    设置显示画面的列数
--no-headers	        此选项的效果和指定”h”选项相同，只在列表格式方面稍有差异
--group <群组名称>	    此选项的效果和指定”-G”选项相同
--Group <群组识别码>	    此选项的效果和指定”-G”选项相同
--pid <程序识别码>	    此选项的效果和指定”-p”选项相同
--rows <显示列数>	    此选项的效果和指定”--lines”选项相同
--sid <阶段作业>	        此选项的效果和指定”-s”选项相同
-tty <终端机编号>	        此选项的效果和指定”-t”选项相同
--user <用户名称>	    此选项的效果和指定”-U”选项相同
--User <用户识别码>	    此选项的效果和指定”-U”选项相同
--version	            此选项的效果和指定”-V”选项相同
--widty <每列字符数>	    此选项的效果和指定”-cols”选项相同
```

## 监听网络流量 - tcpdump
一款sniffer工具，是linux上的抓包工具，嗅探器；它可以打印出所有经过网络接口的数据包的头信息。

tcpdump命令工作时先要把网卡的工作模式切换到混杂模式。所以tcpdump命令需要以root身份运行。tcpdump命令是linux下使用最广泛的网络协议分析工具。使用tcpdump命令时，必须精通TCP/IP协议工作原理。

语法格式: tcpdump [参数]

常用参数：
```bash
-a	尝试将网络和广播地址转换成名称
-c<数据包数目>	收到指定的数据包数目后，就停止进行倾倒操作
-d	把编译过的数据包编码转换成可阅读的格式，并倾倒到标准输出
-dd	把编译过的数据包编码转换成C语言的格式，并倾倒到标准输出
-ddd	把编译过的数据包编码转换成十进制数字的格式，并倾倒到标准输出
-e	在每列倾倒资料上显示连接层级的文件头
-f	用数字显示网际网络地址
-F<表达文件>	指定内含表达方式的文件
-i<网络界面>	使用指定的网络截面送出数据包
-l	使用标准输出列的缓冲区
-n	不把主机的网络地址转换成名字
-N	不列出域名
-O	不将数据包编码最佳化
-p	不让网络界面进入混杂模式
-q	快速输出，仅列出少数的传输协议信息
-r<数据包文件>	从指定的文件读取数据包数据
-s<数据包大小>	设置每个数据包的大小
-S	用绝对而非相对数值列出TCP关联数
-t	在每列倾倒资料上不显示时间戳记
-tt	在每列倾倒资料上显示未经格式化的时间戳记
-T<数据包类型>	强制将表达方式所指定的数据包转译成设置的数据包类型
-v	详细显示指令执行过程
-vv	更详细显示指令执行过程
-x	用十六进制字码列出数据包资料
-w<数据包文件>	把数据包数据写入指定的文件
```

## 显示并设置路由 - route
用来显示并设置linux内核中的网络路由表，route命令设置的路由主要是静态路由。要实现两个不同的子网之间的通信，需要一台连接两个网络的路由器，或者同时位于两个网络的网关来实现。

在linux系统中设置路由通常是为了解决以下问题：该linux系统在一个局域网中，局域网中有一个网关，能够让主机访问Internet，那么就需要将这台机器的ip地址设置为linux机器的默认路由。

要注意的是：直接在命令行下执行route命令来添加路由，不会永久保存。当网卡重启或者机器重启之后，该路由就失效了。可以在/etc/rc.local中添加route命令来保证该路由设置永久有效。

语法格式：route [参数]

常用参数：
```bash
-A	设置地址类型（ 默认IPv4）
-C	打印linux核心的路由缓存
-v	详细信息模式
-n	不执行DNS反向查找，直接显示数字形式的ip地址
-e	netstat格式显示路由表
-net	到一个网络的路由表
-host	到一个主机的路由表
Add	增加指定的路由记录
Del	删除指定的路由记录
Target	目的网络或目的主机
gw	设置默认网关
mss	设置TCP的最大区块长度（MSS），单位MB
window	指定通过路由表的TCP连接的TCP窗口大小
dev	路由记录所表示的网络接口
```