# LAB 12

> 本次LAB目标：
>
> 1. 学习链表的简单使用
> 2. Project答疑

## 获取及提交Lab

**获取**：通过 `https://github.com/fdu-20ss-programming-A/lab12`或者`超星平台`获取。

**提交**：超星平台上已经发布了LAB12作业，同学需要将每题的**代码**、**运行结果**、个人对题目的思考体会（可选）以**图片**或者**文档**（ word 或者 pdf ）的形式在超星LAB12对应的作业区域提交即可。

**提交物**：代码、运行结果，每题可整理为一份 word 或者 pdf 文档，也可以将两者截在一张图片上提交。

**截止时间**：2020年12月29日 23:59:59



## 作业回顾

### Question 1

> 某校评选优秀班级，共有五项得分，打分标准如下：
>
> 1. 班级成绩：期末平均成绩高于90分（>90）得20分，小于等于90大于80得15分，小于等于80得10分；
> 2. 班级卫生：日常班级卫生评议成绩高于80分（>80）的学生得20分，小于等于80大于60得15分，小于等于60得10分；
> 3. 班级风气：每个班级默认得满分20分，班级中每有一名纪律处分学生扣2分；
> 4. 班级荣誉：班级期末平均成绩大于80分，体育比赛中获得前3名的班级，可额外获得5分；
> 5. 额外奖励：日常班级卫生评议高于90分（>90）、班级中不存在纪律处分学生，可额外获得5分；
>
> 例如A班的期末平均成绩是87分，班级卫生评议成绩82分，班里有一名受处分同学，体育比赛获得第5名，那么A班的成绩是53分。
>
> 请设计合适的结构体class并编写程序能够计算哪些班级获得的分数最高。
>
> 注意：请编写函数名为FindMax的函数，输入为结构体数组classes，并有返回，返回值可格式自行规定。函数需要用提供的数据测试。

注意：

> 输入都是正整数

参考答案：



### Question 2

> 使用合适结构体clock表示时钟
>
> 请编写程序实现从键盘任意输入两个时间（例如4时55分和1时25分），可以计算并输出这两个时间之间的间隔。要求不输出时间差的负号。
>
> 函数原型： void CalculateTime(CLOCK *t1, CLOCK *t2);
>
> 注：时间输入格式为HH:MM，范围是0:00 ~ 23:59

示例：

> 请输入时间：4:55 1:55
>
> 时间间隔为：3h0min

参考答案：



## 链表

> 以下的步骤来源于[Leetcode](https://leetcode-cn.com/leetbook/read/linked-list/fx61e/)，有兴趣的同学可以到Leetcode上继续学习。

### 介绍

与数组相似，链表也是一种线性数据结构。这里有一个例子：

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/12/screen-shot-2018-04-12-at-152754.png)

正如你所看到的，链表中的每个元素实际上是一个单独的对象，而所有对象都通过每个元素中的引用字段链接在一起。

链表有两种类型：单链表和双链表。上面给出的例子是一个单链表，这里有一个双链表的例子：

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/17/screen-shot-2018-04-17-at-161130.png)

### 链表的节点结构

单链表中的每个结点不仅包含值，还包含链接到下一个结点的`引用字段`。通过这种方式，单链表将所有结点按顺序组织起来。如下图中，数字代表链表节点储存的值，蓝色箭头代表该节点指向下一节点的指针。链表最后一个节点由于没有下一个节点，它储存的指针为空指针（对应图上的终止节点）。

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/12/screen-shot-2018-04-12-at-152754.png)

在C语言中，我们可以使用下面的结构表示单链表的结构：

```c
struct Node{
    int value;
    struct Node *next;
};
```

在大多数情况下，我们将使用头结点(第一个结点Head)来表示整个列表。

类似的，我们也可以创建两个指针，一个指向前面的节点，一个指向后面的节点，这就是双链表。我们可以使用下面的结构表示双链表：

```c
struct Node{
    int value;
    struct Node *next;
    struct Node *prev;
};
```

单链表只能获得下一个节点，双链表就可以获取前一个节点，也可以获取后一个节点。接下来的例子将以**单链表**为例，并且假设输入的链表没有**环**。

### 查询操作

与数组不同，我们无法直接通过下标快速访问单链表中的元素。 如果我们想要获得第 i 个元素，我们必须从头结点逐个遍历。下面展示一个寻找链表中第index个元素的过程：

```c
struct Node *getIndexNode(struct Node *head, int index){
    int i = 0;
    struct Node *node = head;
    while(node != NULL){ // NULL 代表最后链表最后的空节点
        if(i == index){
            return node;
        }
        i++;
        node = node->next;
    }
    // 超出下标，返回空指针
    return NULL;
}
```

### 添加操作

#### 在中间节点添加元素

如果我们想在给定的结点 prev 之后添加新值，我们应该：

+ 使用给定值初始化新结点 cur；

  ![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/08/05/screen-shot-2018-04-25-at-163224.png)

+ 将 cur 的 next 字段链接到 prev 的下一个结点 next ；

  ![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/04/26/screen-shot-2018-04-25-at-163234.png)

+ 将 prev 中的 next 字段链接到 cur 。

  ![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/04/26/screen-shot-2018-04-25-at-163243.png)

与数组不同，我们不需要将所有元素移动到插入元素之后。

#### 在开头插入元素

众所周知，我们使用头结点来代表整个列表。

因此，在列表开头添加新节点时更新头结点 head 至关重要。

初始化一个新结点 cur ；
将新结点链接到我们的原始头结点 head。
将 cur 指定为 head 。
例如，让我们在列表的开头添加一个新结点 9 。

+ 我们初始化一个新结点 9 并将其链接到当前头结点 23 。

  ![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/04/19/screen-shot-2018-04-19-at-125118.png)

+ 指定结点 9 为新的头结点。

  ![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/04/19/screen-shot-2018-04-19-at-125350.png)

#### Question 1

实现一个函数，在给定链表的index的位置插入值为value的节点，（如果下标越界，直接插在链表结尾）：

```c
struct Node *insert(struct Node *head, int value, int index){
    // 请在这里实现
}
```

例如：

```
链表初始化为
23->6->15->NULL
接着在下标为2的位置插入值为9的节点，返回的链表为
23->6->9->15->NULL
再在开头插入值为10的节点，返回的链表为
10->23->6->9->15->NULL
```

### 链表的反转

反转一个单链表是链表操作的经典问题，一个例子如下：

```
链表初始化为
23->6->15->NULL
经过反转操作后，返回的链表为
15->6->23->NULL
```

一种解决方案是`按原始顺序迭代结点`，并将它们`逐个移动到列表的头部`。

让我们看一个例子：

![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/04/14/screen-shot-2018-04-14-at-163143.png)

请记住，黑色结点 23 是原始的头结点。

1. 首先，我们将黑色结点的下一个结点（即结点 6）移动到列表的头部：

![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/04/14/screen-shot-2018-04-14-at-163336.png)

2. 然后，我们将黑色结点的下一个结点（即结点 15）移动到列表的头部：

![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/04/14/screen-shot-2018-04-14-at-163525.png)

3. 黑色结点的下一个结点现在是空。因此，我们停止这一过程并返回新的头结点 15。

#### Question 2

实现一个函数，反转给定链表：

```c
struct Node *reverse(struct Node *head){
    // 请在这里实现
}
```



## Project

距离Project的截至日期已经不到一个星期了，还没完成的同学注意时间，遇到问题可以及时向助教同学求助。**切勿抄袭他人作业**。一旦发现抄袭现象，助教将严厉处罚相关同学。

我们的**面试时间**定于12月31日，请同学们下次LAB课一定要来上课。

再强调一遍：

**Project提交时间**：北京时间12月30号23:59

**Project提交地点**：超星平台Project提交区

**提交物**：将你的源代码与设计文档进行打包，命名为学号_ 姓名（如20302010000_

王明），作为提交物。