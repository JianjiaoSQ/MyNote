<center><h1><strong>C++ Primer</strong></h1></center>

- [第九章-顺序容器](#第九章-顺序容器)
  - [顺序容器概述](#顺序容器概述)
  - [顺序容器操作](#顺序容器操作)
    - [添加元素](#添加元素)
    - [访问元素](#访问元素)
    - [删除元素](#删除元素)
    - [改变容器大小](#改变容器大小)
    - [迭代器失效问题](#迭代器失效问题)
  - [vector对象是如何增长的](#vector对象是如何增长的)
    - [管理容量的成员函数](#管理容量的成员函数)
  - [额外的string操作](#额外的string操作)
    - [构造string的其他方法](#构造string的其他方法)
    - [改变string的其他方法](#改变string的其他方法)
    - [string搜索操作](#string搜索操作)
    - [compare函数](#compare函数)
    - [数值转换](#数值转换)
  - [容器适配器](#容器适配器)
- [第十章-泛型算法](#第十章-泛型算法)
  - [概述](#概述)
  - [初识泛型算法](#初识泛型算法)
- [第十一章-关联容器](#第十一章-关联容器)
  - [使用关联容器](#使用关联容器)
  - [关联容器概述](#关联容器概述)
    - [定义关联容器](#定义关联容器)
    - [关键字类型的要求](#关键字类型的要求)
    - [pair类型](#pair类型)
  - [关联容器操作](#关联容器操作)
    - [关联容器迭代器](#关联容器迭代器)
    - [添加元素](#添加元素-1)
    - [删除元素](#删除元素-1)
    - [map的下标操作](#map的下标操作)
    - [访问元素](#访问元素-1)
    - [一个单词转换的map](#一个单词转换的map)
  - [无序容器](#无序容器)
- [第十二章-动态内存](#第十二章-动态内存)
  - [动态内存与智能指针](#动态内存与智能指针)
    - [shared_ptr类](#shared_ptr类)
    - [直接管理内存](#直接管理内存)
    - [shared_ptr和new结合使用](#shared_ptr和new结合使用)
    - [智能指针与异常](#智能指针与异常)
      - [智能指针和哑类](#智能指针和哑类)
      - [使用我们自己的释放操作](#使用我们自己的释放操作)
    - [unique_ptr](#unique_ptr)
    - [weak_ptr](#weak_ptr)
  - [动态数组](#动态数组)
    - [new和数组](#new和数组)

# 第九章-顺序容器

顺序容器为程序员提供了控制元素存储和访问顺序的能力；

## 顺序容器概述

vector，可变大小数组，支持快速访问，在尾部之外的位置插入或者删除元素可能很慢（涉及空间大小的扩容）；

deque，双端队列。支持快速随机访问，在头尾位置插入、删除速度快；

list，双向链表。只支持双向顺序访问，在 list 的任何位置进行插入和删除速度都很快；

forward_list，单向链表。只支持单向顺序访问，在链表任何位置进行插入和删除操作都很快；

array，固定大小数组。支持快速随机访问，不能添加或者删除元素；

string，与 vector 相似的容器，但专门用于保存字符，随机访问快，在尾部插入、删除速度快；

* forward_list 和 array 是 C++11 新增的类型；与内置数组相比，array 是一种更安全、更容易使用的数组类型；
* 通常，使用 vector 是最好的选择，除非有更好的理由选择其他容器；
* 除了array，所有容器都提供了高效的动态内存管理；

## 顺序容器操作

### 添加元素

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtdsevksmbj30yi0rq4d1.jpg" width="700"></div>

### 访问元素

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte1g77haqj31420im7es.jpg" width="700"></div>

### 删除元素

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte1g8a5yrj31440pq7jm.jpg" width="700"></div>

### 改变容器大小

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte1g9aa8rj313w0ein6m.jpg" width="700"></div>

### 迭代器失效问题

向容器添加元素后：
* 如果容器是 vector 或 string，且存储空间被重新分配，则指向容器的迭代器、指针和引用都会失效；如果存储空间未重新分配。指向插入位置之前的元素的迭代器、指针和引用仍有效，但是插入位置之后元素的迭代器、指针和引用都会失效；
* 对于 deque，插入到除首尾位置之外的任何位置都会导致迭代器、指针和引用失效；如果在首尾位置添加元素，迭代器会失效，但是指向存在的元素的引用和指针不会失效；
* 对于 list 和 forward_list，指向容器的迭代器（包括尾后迭代器和首前迭代器）、指针和引用仍有效；

删除容器中的元素：删除元素本身的迭代器、指针和引用会失效；
* 对于 list 和 forward_list，指向容器其他位置的迭代器（包括尾后迭代器和首前迭代器）、指针和引用仍有效；
* 对于 deque，如果在首尾之外的任何位置删除元素，那么指向被删除元素外其他元素的迭代器、引用或指针也会失效；如果删除 deque 的尾元素，则尾后迭代器也会失效，但是其他迭代器、引用和指针不受影响；如果删除首元素，这些也不会受影响；
* 对于 vector 和 string，指向被删除元素之前元素的迭代器、引用和指针仍有效；
  > 注意：当我们删除元素时，尾后迭代器总会失效；

管理迭代器：

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte1gb4n0dj31460awqd0.jpg" width="700"></div>

> Tip：如果在一个循环中插入、删除 deque/string/vector 中的元素，不要缓存 end 返回的迭代器；

## vector对象是如何增长的

### 管理容量的成员函数

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte1gc48e2j313w0e6aiu.jpg" width="700"></div>

只有当需要的内存空间超过当前容量时，reserver 调用才会改变 vector 的容量；调用 reserve 永远也不会减少容器占用的内存空间，resize 成员函数只改变容器中元素的数目，而不是容器的容量；

在 C++11 中，调用 shrink to fit 来要求 deque/vector/string 退回不需要的内存空间；在实际调用时，并不能保证一定退回内存空间；

## 额外的string操作

### 构造string的其他方法

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte1gcuddfj313s0e310b.jpg" width="700"></div>

子字符串：
```cpp
s.substr(pos, n);
```

### 改变string的其他方法

string类型支持顺序容器的赋值运算符以及 assign/insert/erase 操作，除此之外，它还定义了额外的 insert/erase 版本（接受下标的版本）；

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte1gdydqmj30ye0qgk2k.jpg" width="700"></div>

### string搜索操作

每个搜索操作都返回一个string::size_type值，表示匹配发生位置的下标；如果搜索失败，则返回一个名为string：：npos的static成员；

> 标准库将npos定义为一个const string::size_type类型，并初始化为值-1，npos是一个unsigned类型；

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9vjmbkgj313z0d0ahf.jpg" width="700"></div>

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9vk5gt7j313v0atjvc.jpg" width="700"></div>

### compare函数

s.compare 返回0、正数或负数；

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9vkrhs1j31400g945t.jpg" width="700"></div>

### 数值转换

如果string不能转换为一个数值，这些函数抛出一个invalid_argument异常，如果转换得到的数值无法用任何类型来表示，则抛出一个out_of_range异常；

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9vlmjq3j314l0j7akg.jpg" width="700"></div>


## 容器适配器

适配器：是一种机制，使得某种事物的行为看起来像另外一种事物一样；容器、迭代器和函数都有适配器；

三种顺序容器适配器：stack/queue/priority_queue

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9vmp30nj31420jo46x.jpg" width="700"></div>

栈适配器：头文件 `#incldue <stack>`

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9vnflbsj313r0a4q85.jpg" width="700"></div>

队列适配器：头文件 `#include <queue>`

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9voawlzj313o0bb0yq.jpg" width="700"></div>

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gte9vorccgj313n06dq5l.jpg" width="700"></div>

# 第十章-泛型算法

标准库并未给每个容器定义成员函数来实现一些有用的操作（查找特定元素、替换或删除一个特定值），而是定义了一组泛型算法（generic algorithm）
* 称它们为“算法”，是因为它们实现了一些经典算法的公共接口，如排序和搜索；
* 称它们是“泛型的”，是因为它们可以用于不同类型的元素和多种容器类型；

## 概述

大多数算法定义在头文件 `#include <algorithm>`；

关键概念：算法永远不会执行容器的操作；
> 泛型算法本身不会执行容器的操作，它们只会运行于迭代器之上，指向迭代器的操作；<br>
> 编程假定：算法永远不会改变底层容器的大小。算法可以改变容器中保存的元素的值，也可能在容器中移动元素，但是永远不会直接添加或删除元素；

## 初识泛型算法

# 第十一章-关联容器

关联容器支持高效的关键字查询和访问；

```cpp
#include <map> // map/multimap
#include <unordered_map> // unordered_map
#include <set> // set/multiset
#include <unordered_set> // unordered_set
```

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbs58dej313v0h8jy5.jpg" width="700"></div>

## 使用关联容器

map是关键字-值对的集合，下标不必是整数；

set是关键字的简单集合，当只想知道一个值是否存在时，set是最有用的；

## 关联容器概述

关联容器的迭代器都是双向的；

### 定义关联容器

定义map，必须指明关键词类型和值类型；定义一个set，指明关键词类型；

### 关键字类型的要求

对于有序容器，关键字类型必须定义元素比较的方法；默认情况下，标准库使用关键字类型的 `<` 运算符类比较两个关键字； 

> 当用decltype来获得一个函数指针类型时，必须加上一个*来指出我们要使用一个给定函数类型的指针；

### pair类型

pair，标准库类型，头文件`#include <utility>`；一个pair保存两个数据成员；

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbsg07ej313u0oqtjp.jpg" width="700"></div>

## 关联容器操作

对于set，key_type 和 value_type 是一样的；set中保存的值就是关键字（意味着只读）；map中元素是关键字-值对；
 
<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbsmlnyj313s08iaee.jpg" width="700"></div>

### 关联容器迭代器

> 一个map的value_type是一个pair，可以改变pair的值，但不能改变关键字成员的值；

set的迭代器是const的；

遍历关联容器：
```cpp
auto iter = s.begin();
while(iter != s.end()) {
  // 逻辑
  ++ter;
}
```

关联容器和算法
* 关联容器中通常不使用泛型算法，原因是关键字是const这一特性意味着不能将关联容器传递给修改或者重排容器的算法，这类算法需要向元素写入值；
* 关联容器可用于只读取元素的算法；使用关联容器定义的专用find成员比调用泛型find更快；
* 如果一定要使用，那就（一）将它作为一个源序列；（二）当作一个目的位置；

### 添加元素

insert 有两个版本，分别接受一对迭代器，或是一个初始化器列表；

向map添加元素：
* 元素类型是pair；
```cpp
s.insert({word, 1});  // C++11新标准
s.insert(make_pair(word, 1));
s.insert(pair<string, size_t>(word, 1));
s.insert(map<string, size_t>::value_type(word, 1));
```

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbsz0myj313o0klk3w.jpg" width="700"></div>

检测insert的返回值
* insert/emplace 返回的值依赖于容器类型和参数；
* 添加单一元素的insert/emplace版本返回一个pair，pair的first成员是一个迭代器，指向具有给定关键字的元素；second成员是一个bool值，指出元素是插入成功还是已经存在于容器中；
* 如果关键字已存在于容器中，则insert忽略，且返回值中的bool值为false；

### 删除元素

关联容器定义了erase三个版本，传递给erase
* 一个迭代器
* 迭代器对删除一个元素或者一个元素范围
* 接受一个key_type参数，返回删除给定关键字元素的数量

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbtkz6sj313r0bdq99.jpg" width="700"></div>

### map的下标操作

map和unordered_map容器提供了下标运算符和一个对应的at函数；set类型不支持下标；

multimap和unordered_multimap也不能进行下标操作，因为这些容器可能存在多个值与一个关键字相关联；

:star:对一个map使用下标操作其行为与数组或vector上的下标操作很不相同：如果关键字并不在map中，会创建一个元素并插入到map中，关联值将进行值初始化；

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbtwkn8j313q08htdd.jpg" width="700"></div>

使用下标操作的返回值：
* 通常情况下，解引用一个迭代器所返回的类型与下标运算符返回的类型是一样的；
* 对于map则不同：当对一个map进行下标操作时，会获得一个mapped_type对象；但当解引用一个map迭代器时，会得到一个value_type对象；
* 与其他下标运算符相同的是，map的下标运算符返回一个左值；

### 访问元素

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbu1sw4j313r05f0w1.jpg" width="700"></div>

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbuc0eoj313r0cbdlg.jpg" width="700"></div>

对map使用find代替下标操作
* 看是否符合我们的预期；

在multimap或multiset中查找元素 :question:
* 当遍历一个multimap或multiset时，保证可以得到序列中所有具有给定关键字的元素；

回答：一种不同的，面向迭代器的解决办法
* lower_bound/upper_bound返回的迭代器可能是容器的尾后迭代器；
  - 如果查找的元素具有容器中最大的关键字，则此关键字的upper_bound返回尾后迭代器；
  - 如果关键字不存在，且大于容器中任何关键字，则lower_bound返回的也是尾后迭代器；

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbuhvvtj313l057jvu.jpg" width="700"></div>

回答：equal_range函数
* 该函数接受一个关键字，返回一个迭代器pair；
* 若关键字存在，则第一迭代器指向第一个与关键字匹配的元素，第二个迭代器指向最后一个匹配元素之后的位置；
* 若未找到匹配元素，则两个迭代器都指向关键字可以插入的位置；

### 一个单词转换的map

## 无序容器

C++11 定义了4个无序关联容器，使用一个哈希函数（hash function）和关键字类型的==运算符；

使用无序容器
* 除了哈希管理操作之外，无序容器还提供了与有序容器相同的操作（find, insert）；这就意味着用于map和set的操作也能用于unordered_map和unordered_set；

管理桶

<div align=center><img src="https://wx1.sinaimg.cn/mw2000/006UYdYPly1gtggbup4kuj30y30ntn6b.jpg" width="700"></div>

# 第十二章-动态内存

* 全局对象在程序启动时分配，在程序结束时销毁；
* 对于局部变量，当进入其定义所在的程序块时被创建，在离开时销毁；
* 局部static对象在第一次使用前分配，在程序结束时销毁；
* 对于动态分配对象，生存期与它们在哪里创建是无关的，只有当显式被释放时，这些对象才会释放；

## 动态内存与智能指针

动态内存的使用很容易出问题
* 当忘记释放内存时，就会发生内存泄漏；
* 有时尚存在指针引用内存的情况下我们就释放了它，这种情况下就会产生引用非法内存的指针；

为了更容易更安全的使用动态内存，使用智能指针（智能指针并不是能完全杜绝内存泄漏问题，只是尽可能减少；例如：当两个对象相互使用一个shared_ptr成员变量指向对方，会造成循环引用，使引用计数失效，从而导致内存泄漏。）

智能指针与普通指针的区别就在于能够自动释放所指向的对象；
* shared_ptr：允许多个指针指向同一个对象；
* unique_ptr：独占所指向的对象；
* weak_ptr：弱引用，指向shared_ptr所管理的对象；
* 都定义在 memory 头文件中；

### shared_ptr类

智能指针也是模板，创建智能指针必须提供指针可以指向的类型；默认初始化的智能指针中保存着一个空指针；

<div align=center><img src="" width="700"></div>

<div align=center><img src="" width="700"></div>

make_shared函数
* 最安全的分配和使用动态内存的方法就是调用make_shared的标准库函数；
* 类似顺序容器中的emplace成员，make_shared用其参数来构造给定类型的对象；

shared_ptr的拷贝和赋值
* 当进行拷贝或赋值操作时，每个shared_ptr都会记录有多少个shared_ptr指向相同的对象；
* 引用计数（reference count）递增：
  - 当用一个shared_ptr初始化另一个shared_ptr；
  - 或将它作为参数传递给一个函数；
  - 或作为函数的返回值；

<div align=center><img src="" width="700"></div>

shared_ptr自动销毁所管理的对象
* shared_ptr的析构函数会递减它所指向的对象的引用计数，如果引用计数变为0，shared_ptr的析构函数就会销毁对象，并释放它占用的内存；

[手写shared_ptr](../src/smartPointer.cpp)
> 参考：https://cloud.tencent.com/developer/article/1688444#:~:text=shared_p,%EF%BC%8C%E5%AF%B9%E8%B1%A1%E7%9A%84%E5%BC%95%E7%94%A8%E8%AE%A1%E6%95%B0

[（陈硕）为什么多线程读写 shared_ptr 要加锁？](http://www.cppblog.com/Solstice/archive/2013/01/28/197597.html)

### 直接管理内存

直接管理内存的类不能依赖类对象拷贝、赋值和销毁操作的任何默认定义；因此，使用智能指针的程序更容易编写和调试；

使用new动态分配和初始化对象
* 可以使用传统的构造方式（使用圆括号），也可以使用列表初始化（使用花括号）；

动态分配的const对象
* 类似其他const对象，一个动态分配的const对象必须进行初始化；
* 对于一个定义了默认构造函数的类类型，其const动态对象可以隐式初始化，而其他类型的对象必须显式初始化；

内存耗尽
* 默认情况下，抛出一个bad_alloc异常；
* 使用定位new阻止抛出异常；
```cpp
int* p1 = new int; // 如果分配失败，new抛出std::bad_alloc；
int* p2 = new (nothrow) int; // 如果分配失败，new返回一个空指针；
```

使用new和delete管理动态内存存在的三个常见问题：
* 忘记 delete 内存；导致“内存泄漏”问题，泄漏的内存永远不可能被归还给自由空间；排查内存泄漏错误时非常困难的；
* 使用已经释放掉的对象；
* 同一块内存重复释放；

delete之后重置指针值
* 空悬指针，指向一块曾经保存数据对象但现在已经无效的内存的指针；
* 未初始化指针的所有缺点空悬指针都有；
* 避免空悬指针：
  - 在指针即将离开其作用域之前释放掉它所关联的内存；
  - 如果需要保留指针，delete之后将nullptr赋予指针；

### shared_ptr和new结合使用

接受指针参数的智能指针构造函数是explicit的，因此不能将一个内置指针隐式转换为一个智能指针，必须使用直接初始化形式。
```cpp
shared_ptr<int> p1 = new int(1024); // 错误
shared_ptr<int> p2(new int(1024)); // 正确
```
返回shared_ptr的函数不能在其返回语句中隐式转换一个普通指针；
```cpp
shared_ptr<int> clone(int p) {
  return new int(p);   // 错误
  return shared_ptr<int>(new int(p));  // 正确
}
```

<div align=center><img src="" width="700"></div>

<div align=center><img src="" width="700"></div>

！不要混合使用普通指针和智能指针
* 使用一个内置指针来访问一个智能指针所负责的对象是很危险的，因为我们无法知道对象何时会被销毁；

！不要使用get初始化另一个智能指针或为智能指针赋值
* get用来将指针的访问权限传递给代码，只有在确认代码不会delete指针的情况下，才能使用get；特别是永远不要用get初始化另一个指针或者为另一个智能指针赋值；

其他shared_ptr操作
* 用reset来将一个新的指针赋予一个shared_ptr；与赋值类似，reset可以更新引用计数；
* reset和unique一起使用，来控制多个shared_ptr共享的对象
  ```cpp
  if(!p.unique()) {
    p.reset(new string(*p)); // 不是唯一用户，分配新的拷贝
  }
  *p += newVal; // 现在是唯一用户，可以改变对象的指
  ```

### 智能指针与异常

确保异常发生之后资源能够被正确的释放，简单办法就是使用智能指针；

#### 智能指针和哑类

通常为C和C++两种语言设计的类，都要求用户显式地释放所使用的任何资源；

如果在资源分配和释放之间发生了异常，程序就会发生资源泄漏；

使用shared_ptr来保证这些类（哑类）被正确关闭，已被证明是一种有效的办法；

#### 使用我们自己的释放操作

构造一个删除器（delete）函数完成对shared_ptr中保存的指针进行释放的操作；

```cpp
void disconnect(connection); // 关闭给定的连接 
void end_connection(connection* p) { disconnect(*p); } 

void f(destination &d) {
  connection c = connect(&d);
  shared_ptr<connection> p(&c, end_connection);
}
```
> 智能指针使用基本规范：
> * 不使用相同的内置指针初始化（或reset）多个指针；
> * 不delete get()返回的指针；
> * 不使用get()初始化或reset另一个智能指针；
> * 如果你使用get()返回的指针，记住最后一个对应的智能指针销毁后，你的指针就变为无效了；
> * 如果使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器；

### unique_ptr

一个unique_ptr拥有它所指向的对象；与shared_ptr不同，某个时刻只能有一个unique_ptr指向一个给定的对象；当unqiue_ptr被销毁时，它所指向的对象也被销毁；

与shared_ptr一样，初始化unique_ptr必须采用直接初始化形式；

```cpp
unique_ptr<double> p1;
unique_ptr<int> p2(new int(42)); // p2指向一个值为42的int
```

unique_ptr不支持普通的拷贝或者赋值操作

```cpp
unique_ptr<string> p1(new string("Stegosaurus"));
unique_ptr<string> p2(p1); // 错误
unique_ptr<string> p3;
p3 = p2; // 错误
```

<div align=center><img src="" width="700"></div>

我们可以通过release或reset将指针的所有权从一个（非const）unique_ptr转移给另一个unique；

```cpp
// 将所有权从p1（指向string Stegosaurus）转移给p2
unique_ptr<string> p2(p1.release()); // release将p1置为空

unique_ptr<string> p3(new string("Trex"));
// 将所有权从p3转移给p2
p2.reset(p3.release()); // reset释放了p2原来指向的内存
```
> release成员返回unique_ptr当前保存的指针并将其置为空；<br>
> reset成员接受一个可选的指针参数，令unique_ptr重新指向给定的指针；如果unique_ptr不为空，它原来指向的对象被释放；

传递unique_ptr参数和返回unique_ptr
* 不能拷贝unique_ptr的规则之外，特例就是：可以拷贝或赋值一个将要被销毁的unique_ptr；最常见的例子就是从函数返回一个unique_ptr:
  ```cpp
  unique_ptr<int> clone(int p) {
    return unique_ptr<int>(new int(p));
  }
  ```
* 返回一个局部变量的拷贝：
  ```cpp
  unique_ptr<int> clone(int p) {
    unique_ptr<int> ret(new int(p));
    /* ... */
    return ret;
  }
  ```

> 向后兼容：auto_ptr <br>
> 标准库的较早版本包含了一个名为auto_ptr的类，它具有unique_ptr的部分特性，但不是全部；:star: 不能在容器中保存auto_ptr，也不能从函数中返回auto_ptr；
> 在编写程序时应该使用unique_ptr；

向unique_ptr传递删除器
* unique_ptr默认情况下用delete释放它所指的对象；与shared_ptr一样，可以重载一个unique_ptr中默认的删除器；
* 重载一个unique_ptr中的删除器会影响到unique_ptr类型以及如何构造（或reset）该类型的对象；
  - 在尖括号中unique_ptr指向类型之后提供删除器类型；在创建或reset一个unique_ptr类型对象的时候，必须提供一个指定类型的可调用对象（删除器）；
  ```cpp
  // p指向一个类型为objT的对象，并使用一个类型为delT的对象释放objT对象，它会调用一个名为fcn的delT类型对象；
  unique_ptr<objT, delT> p(new objT, fcn);
  ```

### weak_ptr

是一种不控制对象生存期的智能指针，它指向由一个shared_ptr管理的对象；
* 将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数；
* 一旦最后一个指向对象的shared_ptr被销毁，对象就会被释放；即使有weak_ptr指向对象，对象也还是会被释放；

创建一个weak_ptr时，要用一个shared_ptr来初始化它
```cpp
auto p = make_shared<int>(42);
weak_ptr<int> wp(p);  // wp弱共享p，p的引用计数未改变；
```

由于对象可能不存在，调用lock函数检查weak_ptr指向的对象是否存在；如果存在，返回一个指向共享对象的shared_ptr；

（shared_ptr存在，指向的底层对象一定存在，weak_ptr存在，指向的对象不一定存在）

```cpp
if(shared_ptr<int> np = wp.lock()) {  // 如果np不为空则条件成立
  // 在if中，np与p共享对象
}
```
* 在if中，使用np访问共享对象是安全的；

## 动态数组

new和delete运算符一次分配、释放一个对象；vector和string都是在连续内存中保存它们的元素，当容器需要重新分配内存时，必须一次性为很多元素分配内存；

C++定义了另一种new的表达式语法，可以分配并初始化一个对象数组；标准库中包含一个名为allocator的类，允许我们将分配和初始化分离，allocator通常会提供更好的性能和更灵活的内存管理能力；

> 大多数应用应该使用标准库容器而不是动态分配的数组；使用容器更为简单、更不容易出现内存管理错误并且可能有更好的性能；

### new和数组


```cpp
// 调用get_size确认分配多少个
int *pia = new int[get_size()];  // pia指向第一个int

// 用一个数组类型的类型别名来分配一个数组
typedef int arrT[42];
int *p = new arrT;  // 分配一个42个int的数组；p指向第一个int
```

分配一个数组会得到一个元素类型的指针
* new T[]分配的内存称为“动态数组”，某种程度上有些误导；
* new 分配一个数组时，并未得到一个数组类型的对象，而是得到一个数组元素类型的指针；
  - 因此，不能对动态数组调用begin或end；
  - 也不能使用范围for语句；

> :exclamation: 我们所说的动态数组并不是数组类型

初始化动态分配对象的数组
* 对数组中的元素进行值初始化，方法就是在大小之后跟一对空括号；
  ```cpp
  int *pia = new int[10];     // 10个未初始化的int
  int *pia2 = new int[10]();   // 10个初始化为0的int
  string *psa = new string[10];  // 10个空字符串
  string *psa2 = new string[10]();  // 10个空字符串
  ```
* C++11中，提供一个元素初始化器的花括号列表
  ```cpp
  int *pia3 = new int[6] {0, 1, 2, 3, 4, 5};

  // 前4个用给定的初始化器初始化，剩余的进行值初始化
  string *psa3 = new string[10] {"a", "da", "fdg", string(3, 'x')};
  ```
  > 如果初始化器数目大于元素数目，则new表达式失败，不会分配任何内存；本例中，new会抛出一个类型为bad_array_new_length的异常；类似bad_alloc，此类型定义在头文件new中。

动态分配一个空数组是合法的
```cpp
char arr[0]; // 错误，不能定义长度为0的数组
char* cp = new char[0];  // 正确，但是cp不能解引用
```
* 数组大小为0时，new返回的是一个合法的非空指针；（保证与new返回的其他任何指针都不相同）

释放动态数组
```cpp
delete p;   // p必须指向一个动态分配的对象或为空
delete[] p;  // p必须指向一个动态分配的数组或为空
```
* 数组中的元素非销毁并释放响应的内存，顺序按逆序进行销毁；

<div align=center><img src="" width="700"></div>

智能指针和动态数组
* 标准库提供了一个可以管理new分配的数组的unique_ptr版本，必须在对象类型后面跟一对空方括号；
  ```cpp
  unique_ptr<int[]> up(new int[10]);
  up.release();  // 自动用delete[]销毁其指针
  ```
当一个unique_ptr指向一个数组而不是单个对象时，不能使用点和箭头成员运算符；可以通过下标运算符来访问数组中的元素；

<div align=center><img src="" width="700"></div>

shared_ptr不直接支持管理动态管理；如果希望使用shared_ptr管理一个动态数组，必须提供自己定义的删除器:
```cpp
shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
sp.reset();  // 使用我们提供的lambda释放数组，它使用delete[]
```
shared_ptr不直接支持动态数组管理这一特性影响数组数据访问，未定义下标运算符，而且智能指针类型不支持指针算术运算；

用get获取一个内置指针来访问数组元素；