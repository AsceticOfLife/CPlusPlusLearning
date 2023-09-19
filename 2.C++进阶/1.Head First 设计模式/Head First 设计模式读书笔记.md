# 规划

书本一共14章，一周两章，预计两个月左右看完。今天是5.5，也就是7.5左右看完，同时有思考、笔记、代码。

每一章大概40页左右，那么一周两章就是读80页，一章花费两天看完，一天就是20页；一周中抽出4天看两章。



2023.5.5~2023.7.7：两个月左右

总结：对于各种常见的设计模式进行了学习，并且都编写实际的例子。
但是想要应用到实践中，按照书中的要求，只在需要的时候使用设计模式，否则会大大增加设计复杂度和效率。
后续还需练习和实践。



# 第一章 策略模式

BDF 正确答案：ABCD

要实现部分子类所需要功能，我的想法就是创造一个新类，在这个类中提供方法，谁有这个能力就继承这个新类。

不好的地方：如果每个鸭子的fly有细微差别，那么新类是没有办法复用的，即使是接口也需要不同的实现。

其实上述思路是可以的，即将**需要变化的部分分离出来。**（即鸭子的基本属性是不变的，飞行方式是变化的）

将变化的行为设计成一个接口，也就是抽象类，使用多态的方式实现不同的行为特征。

**接着针对接口（抽象类）进行编程，而不是针对实现编程。**

什么是针对实现：1.继承而来的方法；2.或者继承某个接口**自行实现**。

针对接口编程就是直接使用接口而不考虑其实现。

这样就可以让不变化的部分与变化的部分组合，**并且变化的部分不会影响到不变化的部分。**

这里还有一个缺点就是：即使使用引用或者指针指向接口，需要new一个具体的接口的行为。

总结：

###### 原则1：将需要变化的部分分离出来；

###### 原则2：针对接口编程而不是针对实现编程

-------------

提问：如何设计一个行为可以在运行时改变的鸭子？

目前是使用一个引用或者指针指向动态的行为类，所以可以设计这样一个函数：申请一个新的行为对象，删除旧的行为对象；让这个行为引用或者指针指向新的行为对象。

作者的思路和我一样，只不过作者把一个行为类对象作为参数传入，直接让函数设置这个新的行为对象。

------

将一组行为描述为一族算法，表示鸭子类能够做的事情。

一组算法与鸭子之间是has-a关系（使用composition方式）、鸭子与各种鸭子是is-a关系（public继承方式）、抽象基类与派生类是implement关系（使用public继承方式）

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\1-3.png" alt="image-20230707082748640" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\1-4.png" alt="image-20230707082848875" style="zoom:67%;" />

###### 设计原则3：多用组合实现复用，少用继承

###### 第一个设计模式：策略模式

**将系统中变化的部分拿出来封装**

<img src=".\image\1.png" alt="image-20230506172243134" style="zoom: 80%;" />

<img src=".\image\1-2.png" alt="image-20230506172954113" style="zoom:67%;" />

-----

<img src=".\image\1-1.png" alt="image-20230506172929811" style="zoom:80%;" />

----------

设计模型可以充当行话，使得讨论和思考层面不深入到数据或者操作，而是保留在设计层次。

设计模式指的是如何组织类和对象以解决某种问题。

知道了封装、抽象、继承、多态并不会让你马上变成优秀的面向对象设计者，**构造面向对象系统的经验**被收集和整理成为设计模式。

设计是一门艺术，要考虑**弹性的设计**、**可以维护**、可以应付变化。

- 抽象：把关注的特点提取出来

- 封装：将特点包装在一个类中
- 多态：不同的对象的行为不同，不同的函数的行为不同
- 继承：继承原有属性，进行扩展。

# 第二章 观察者模式

ABCDE 正确答案：ABCE

以报纸（主题）和订阅报纸的人（观察者）说明观察者模式。

###### 观察者模式

**一对多关系，将一个对象的改变通知给所有观察者**

<img src=".\image\2-1.png" alt="image-20230508114437383" style="zoom: 80%;" />

###### 设计原则3：为了交互对象之间的松耦合而努力。

------

如何世界天气数据和展示板之间的关系：

注意这里不仅有观察者模式，关注展示板接口的实现还采用了之前的策略模式。

<img src=".\image\2-2.png" alt="image-20230508145537535" style="zoom:67%;" />

 <img src=".\image\2-3.png" alt="image-20230508145629945" style="zoom:67%;" />

-------

这里需要思考的问题是，是否直接将天气的三个数据传递给展示板观察者呢？明显通过调用观察者的update，将三个数据作为参数传递是有问题的，因为如果以后增加了数据，需要重新编写所有的update函数。

-----------

目前实现的观察者模式，总是主题将数据push给观察者，有些时候有些数据观察者并不需要。能否让观察者主动去get想要的数据呢？

----------

观察者模式与设计原则：

1.关于变化的部分与不变的部分分离：一个具体的主题看作是不变的，变化的是谁来订阅这个主题

2.关于针对接口编程而非实现：在主题中，使用的是观察者的接口；在具体的观察者中，使用的是主题的接口。

3.关于多用组合，少用继承：在主题接口中，观察者作为成员数据的一部分；在具体的观察者中，主题作为成员的一部分。

# 第三章 装饰者模式

以饮品和调料为例，我觉得应该设计一个调料的接口，组合进入饮品。

组合的动态扩展。

###### 设计原则4：类应该对扩展开放，对修改关闭

即使用组合的话，由于是通过指针或者引用动态确定，方便了扩展；

并且对于组合类的修改，不会影响现有的类。

总体来说就是在不修改现有代码的情况下**搭配**新的行为。

对于要进行扩展的部分要小心地选择，并不是所有的部分都要扩展。

**装饰者与被装饰对象：**

<img src=".\image\3-1.png" alt="image-20230511110348122" style="zoom:67%;" />

<img src=".\image\3-2.png" alt="image-20230511110428168" style="zoom:80%;" />

与我的构思不同的是，将调味作为一个包含了饮品的类，这样就不会改变音频的代码。

###### 装饰者模式

**装饰者与原接口是同类型，只是扩展了行为或者增加了责任。**

<img src=".\image\3-3.png" alt="image-20230511110644767" style="zoom:80%;" />

<img src=".\image\3-4.png" alt="image-20230511110852093" style="zoom:67%;" />

<img src=".\image\3-5.png" alt="image-20230511111100016" style="zoom:80%;" />

-----

如何实现饮品和调料的cost：对于饮品来说，就是返回饮品的价格；对于调料来说，首先通过访问自己引用的饮品的cost得到饮品的价格，再加上饮料的价格。

如何实现调料的getDescription：需要通过饮品得到饮品的描述，再加上调料的描述。

-----

这里的继承只是为了使得饮品和调料“同类型”；行为是来自装饰者和基础组件。

新的装饰者可以增加新的行为，不用修改组件。

# 第四章 工厂模式

-----

如何把实例化具体类的代码从应用中隔离？
使用一个函数完成这个实例化操作，返回对象的指针。

作者的思路：讲创建对象的工作交给工厂对象完成。

利用静态方法创建对象的工厂与上面的对象有什么区别：不需要使用创建对象的方式实例化对象。

###### 简单工厂

<img src=".\image\4-1.png" alt="image-20230512112117560" style="zoom:67%;" />

如果有多个不同的工厂需求，那就创建三个工厂类。

如果希望各自工厂做稍微的改变，即需要各自工厂（即子类）自己定义creat对象函数，那么可以采用抽象基类的方法。

即工厂现在是一个函数方法而不是之前的类。

<img src=".\image\4-2.png" alt="image-20230512113033446" style="zoom:67%;" />

<img src=".\image\4-3.png" alt="image-20230512113108610" style="zoom: 67%;" />

**解耦的实现：**

<img src=".\image\4-4.png" alt="image-20230512113339229" style="zoom:67%;" />

上面的过程实际上把一个创建对象的工作从交给一个对象转移到交给一个方法（子类中的方法）来实现。

<img src=".\image\4-5.png" alt="image-20230512113823969" style="zoom:80%;" />

**工厂模式方法（使用抽象方法实现）：**

<img src=".\image\4-6.png" alt="image-20230512114510094" style="zoom:67%;" />

<img src=".\image\4-7.png" alt="image-20230512114532355" style="zoom:67%;" />

**工厂方法模式另一种观点：**

<img src=".\image\4-8.png" alt="image-20230512114739343" style="zoom:80%;" />

###### 工厂方法模式

**所有工厂都是为了封装对象的创建。**

<img src=".\image\4-9.png" alt="image-20230512114910915" style="zoom:80%;" />

<img src=".\image\4-10.png" alt="image-20230512115035099" style="zoom:67%;" />

分析依赖性：

直接实例化一个对象时，就是在依赖它的具体类：

<img src=".\image\4-12.png" alt="image-20230512115704946" style="zoom:67%;" />

<img src=".\image\4-11.png" alt="image-20230512115640861" style="zoom:67%;" />

###### 设计原则5：依赖抽象而不是依赖具体类

依赖倒置原则

不仅不能让高层组件依赖底层组件的具体类，而是依赖抽象，并且无论高层还是底层组件都应该依赖抽象。

<img src=".\image\4-13.png" alt="image-20230512120135449" style="zoom:67%;" />

倒置思考方式：假如以思考pizza店要生产披萨，从上到下的设计方式是：披萨店要生产哪些pizza，这种思考方式就会使得商店依赖于多种披萨类；

从下向上思考：为所有的披萨类设计一个抽象的pizza接口，即所有的披萨都依赖于这个pizza接口；那么商店只需要使用这个接口，依赖于这个接口。靠一个工厂生产出pizza给商店。

###### **指导方针**

**违反时要有充足的理由**

<img src=".\image\4-14.png" alt="image-20230512144306245" style="zoom:80%;" />



###### 抽象工厂模式

<img src=".\image\4-15.png" alt="image-20230513154652514" style="zoom:80%;" />

抽象工厂的每个方法实际上都是工厂方法。

工厂方法使用的是继承，需要扩展一个类，并覆盖它的工厂方法。

抽象工厂使用的是组合，当需要一个抽象工厂时，需要是实例化一个工厂，并把它传递给客户，让客户的成员中存在这个工厂，使用这个工厂创建产品家族。

抽象工厂方便将产品家族和相关产品集合在一起，工厂方法便于将客户代码与创建对象解耦，使用方式很简单，将其设置为一个抽象方法，必须子类实现它。

# 第五章 单件模式

单件实例类：

1.构造函数是私有的；2.使用一个静态方法创建一个对象；3.使用一个静态成员变量保存实例化对象。

###### 单件模式

**确保程序中一个类最多只有一个实例。**

<img src=".\image\5-1.png" alt="image-20230515111246339" style="zoom: 80%;" />

<img src=".\image\5-2.png" alt="image-20230515111531479" style="zoom: 80%;" />

**单间模式存在的问题是：**

在多线程中或许由于同步问题而创建出多个实例对象。

因此要解决同步问题。

<img src=".\image\5-3.png" alt="image-20230515112354072" style="zoom:80%;" />

书中给了针对java语法关键字解决方案，以及一种牺牲延迟实例化，直接在最开始就借助静态变量实例化这个对象：

<img src=".\image\5-4.png" alt="image-20230515112515137" style="zoom:80%;" />

# 第六章 命令模式

**遥控器对象**使用**命令对象**操控**电灯对象**。

###### 命令模式

**将发出命令对象与接收命令者解耦。**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\6-1.png" alt="image-20230519145358685" style="zoom: 80%;" />

命令对象将一组动作和接收者包含进对象中，并对外提供execute方法，当此方法被调用，命令对象对一个接收者执行这一组动作。

对于调用者来说，使用一个命令对象的execute方式完成一组动作，却并不知道执行了哪些动作。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\6-2.png" alt="image-20230519154312022" style="zoom: 80%;" />

---------

命令模式的设计如何支持请求调用者和请求接收者之间的解耦？

通过命令对象，请求调用者通过调用一个命令对象的execute方式完成对一个请求接收者的调用。

###### 空对象

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\6-3.png" alt="image-20230519155015821" style="zoom:80%;" />

表示一个什么都不做的命令对象。

**撤销动作：**

无论execute方法做了什么，都需要一个undo方法做相反的动作。

并且让调用者对象保留最后一个指令对象的记录，这样就方便选择调用哪一个命令对象的undo方法。

**使用状态实现撤销：**在接收者对象中存在状态成员以及设置成员的状态的方式。在命令对象的execute方式调用接收者对象动作之前，使用一个成员记录动作之前的接收者对象的状态。这样在undo方法中就可以根据之前的状态执行动作。

**宏命令：**一组命令对象的集合，执行这个宏命令时一组命令都被执行。可以在这个命令的成员中设置一个命令对象数组，执行execute方法时将所有命令对象都执行。

**将命令对象作为一个请求队列：**

假设有一个工作队列，在一端添加命令，线程从另一端不断取出命令并执行。

线程不知道命令具体是怎么做的，只是不断调用命令。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\6-4.png" alt="image-20230519161637051" style="zoom:80%;" />

# 第七章 适配器模式和外观模式

适配器：将一个接口转换成另一个接口

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-1.png" alt="image-20230522105653199" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-2.png" alt="image-20230522105730319" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-3.png" alt="image-20230522105745907" style="zoom:67%;" />

以鸭子和火鸡类示例，一个适配器类表示伪装成鸭子的火鸡，通过实现鸭子的接口，并在内部保留一个火鸡对象的引用，将所有鸭子的行为调用成员火鸡的行为。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-4.png" alt="image-20230522110014187" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-5.png" alt="image-20230522110048941" style="zoom:80%;" />

###### 适配器模式

**需要一个现有的类但是接口不符合目前的要求，需要修改接口。**

![image-20230522110410121](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-6.png)

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-7.png" alt="image-20230522110435616" style="zoom:80%;" />

优秀的原则：使用组合方式将被适配者（例子中的火鸡）组合在适配器（例子中的鸭子接口类）实现中

另外：被适配者的子类也能够与适配器搭配使用

**上面是对象适配器，采用组合方式；**

**下面是类适配器，采用多重继承方式：**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-8.png" alt="image-20230522111046808" style="zoom:80%;" />

**二者的弹性对比：**

使用组合方式，在适配器中面向被适配者的接口编程，被适配者的实现改变不影响使用；

使用继承方式，在适配器中面向被适配者的实现编程，即在适配器中需要实现被适配者的方法或者继承方法，当被适配者代码改变时适配器代码也需要改变。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-9.png" alt="image-20230522111955786" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-10.png" alt="image-20230522112210512" style="zoom:80%;" />

对象适配器的优势：可以适配被适配者的子类；使用组合方式弹性高；

类适配器的优势：不用实现被适配者接口，如果必要的话可以在适配器中重定义行为；由于不需要调用对象的方法，少了一层函数调用，效率高。

**装饰者模式、适配器模式、外观模式：**

1.装饰者模式：不改变接口，只是加入了更多责任；

2.适配器模式：将一个接口转换成另一个接口；

3.外观模式：让复杂的接口更简单

---------

以家庭影院的例子说明外观模式。

打开所有子系统的方式：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-11.png" alt="image-20230523155426524" style="zoom:67%;" />

可以上上述所有方法封装在一个新类里面，令这个新类对外提供简单的接口。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-12.png" alt="image-20230523155720868" style="zoom:67%;" />

**外观模式与适配器模式都可以包装很多个类，但是适配器模式的主要目的是转换接口，而外观模式的主要目的是简化接口。**

上述例子步骤：1.将所有用到的类组合进入外观类中；2.将所有类的子方法组合称为一个外观类的对外接口；3.仅调用外观类的接口就可以实现对于所有子系统的调用。

###### 外观模式

**接口太复杂不利于利用，需要简化接口使用。**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-13.png" alt="image-20230523160020864" style="zoom:80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-14.png" alt="image-20230523160046421" style="zoom:80%;" />

###### 设计原则6：最少知识原则——之和你的密友交谈

减少对象之间的交互，只留下几个密友。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-16.png" alt="image-20230523161125469" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-15.png" alt="image-20230523161053043" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\7-17.png" alt="image-20230523161318386" style="zoom:67%;" />

# 第八章 模板方法模式

制作咖啡和制作茶的过程：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-1.png" alt="image-20230526110233664" style="zoom:67%;" />

汇集重复代码：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-2.png" alt="image-20230526110409562" style="zoom:67%;" />

注意：两种方式的算法是相同的，都分为四步，上面的类设计只是把相同算法中的两个相同的步骤取出。

下面进行抽象另外两个步骤。即将另外两不作为抽象方法放在抽象基类中，子类继承并实现这两个方法。

与上面不同的是：上面是在两个子类中定义了方法，并覆盖了总的算法。

![image-20230526145218358](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-3.png)

模板方法定义了一个算法的步骤，允许子类为一个或者多个步骤提供实现。

###### 模板方法模式

用于创建一个算法的模板。

当算法的步骤需要在子类中实现。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-4.png" alt="image-20230526145416948" style="zoom: 80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-5.png" alt="image-20230526145458966" style="zoom: 80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-6.png" alt="image-20230526145545112" style="zoom:80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-7.png" alt="image-20230526145641163" style="zoom: 80%;" />

**钩子函数：**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-8.png" alt="image-20230527110312961" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-9.png" alt="image-20230527110806425" style="zoom: 80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-10.png" alt="image-20230527110838671" style="zoom:67%;" />

由子类决定是否重新覆盖这个钩子。

###### 设计原则7：下层别调用上层，上层会调用下层

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-11.png" alt="image-20230527111428438" style="zoom:67%;" />

允许底层组件挂钩到系统上，但是高层组件决定什么时候调用底层组件。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-12.png" alt="image-20230527111517770" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\8-13.png" alt="image-20230527111742511" style="zoom:67%;" />

**由框架指定如何做事情，而由使用框架的人指定框架中算法的细节。**

实际上现实中的模板方法模式并不像教科书上这样采用继承的方式。

比如STL中的算法sort，sort依赖于子类提供的比较compare方法来完成具体的实现细节。

这也类似于策略模式，即将会变化的方法封装成一个类，但是模板方法和策略模式的区别就是模板方法并没有实现一个完整的算法，模板方法中实现的是算法的一部分。

工厂方法模板可以看作是模板方法模式的一个特例。

策略模式定义一个算法家族。这里面的的算法可以相互替换；采用组合的方式；采用组合方式使得算法族更有弹性

模板方法模式定义一个算法框架，部分算法细节由子类实现；采用继承的方式；类拥有更多对于方法的控制权，意味着联系更加紧密



# 第九章 迭代器模式和组合模式

一个例子，现有有两种菜单，菜单项都是固定的类对象，但是两种菜单采用不同的容器承载菜单项对象。

现在如果向打印菜单，需要分贝对两种菜单进行遍历，需要两种循环处理容器。

----------

针对目前打印菜单方法的问题：A针对具体菜单的实现变成而不是针对接口 CDE

-----

尝试对于遍历过程进行封装，使用迭代器封装两种容器，遍历的时候使用迭代器的next方法

迭代器接口：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-1.png" alt="image-20230529111311969" style="zoom:80%;" />

有了接口就可以为不同的对象集合（一群对象）实现迭代器：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-2.png" alt="image-20230529111437508" style="zoom:80%;" />

一个具体实现的例子：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-3.png" alt="image-20230529111747364" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-4.png" alt="image-20230529111806847" style="zoom:67%;" />

有了迭代器之后修改原来的菜单类实现，有一个返回迭代器的接口

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-5.png" alt="image-20230529112209929" style="zoom:67%;" />

当需要打印这个菜单时，就调用这个菜单的返回迭代器接口获取一个迭代器，然后使用这个迭代器对象遍历菜单。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-6.png" alt="image-20230529112328884" style="zoom:67%;" />

整体设计:

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-7.png" alt="image-20230529112919681" style="zoom:80%;" />

另外需要做的一点改进是将两个菜单作为同一种接口的实现，这样招待员就不用依赖于两种具体的菜单类。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-8.png" alt="image-20230529113201579" style="zoom:80%;" />

###### 迭代器模式

需要一种方法顺序访问一个集合中的每个元素但是不想了解具体数据是什么类型。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-9.png" alt="image-20230529113253477" style="zoom:80%;" />

另外把游走的任务交给迭代器，让迭代器在聚合对象身上遍历。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-10.png" alt="image-20230529113629669" style="zoom:80%;" />

**内部迭代器与外部迭代器：**

上面实现的就是外部迭代器，通过迭代器的next方法获取下一个对象；

内部迭代器是指遍历由迭代器自己控制，比如python典型的range方法，返回一个迭代器序列，for i in range()

**为什么不让对象集合实现遍历方法？**

对象集合的责任首先是管理集合对象，但是如果让其实现遍历方法，又增加了责任。如果集合对象改变，类必须该改变，如果遍历方式改变，类也必须要变化。

###### 设计原则8：一个类应该只有一个引起变化的原因

区分设计中的责任是很不容易的。我们总是很喜欢将一大群行为集中在一起。

内聚指的是一个类或者模块紧密达到单一责任或者目的。高内聚指的就是类被设计成只支持一组相关的功能。



有了迭代器之后，不必关系菜单的数据结构时怎样的，使用迭代器**遍历**菜单。

C++中STL所有容器都实现了自己的迭代器。

----------

如果增加一个新的菜单，那么就需要调用三次三个不同的迭代器。

解决方案：把这三个菜单装进一个容器，然后使用这个容器的迭代器进行遍历。



新的问题：需要一个子菜单，即希望菜单中的某一项可以是一个菜单类。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-11.png" alt="image-20230611105835637" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-12.png" alt="image-20230611110329576" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-13.png" alt="image-20230611110359181" style="zoom:67%;" />

怎么可能在一个容器里装不同类型的对象呢？

答案是不能装不同类型的对象。解决方法是将菜单和菜单项作为同一种基类类型——组合。

###### 组合模式

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-14.png" alt="image-20230611111205043" style="zoom: 80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-15.png" alt="image-20230611111224131" style="zoom:67%;" />

菜单就相当于分支结点，菜单项就相当于叶子节点。

分支节点的孩子既可以是叶子节点也可以是一个分支结点。

这样可以将相同的操作作用域叶子节点和分支结点。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-16.png" alt="image-20230611111530295" style="zoom:67%;" />

![image-20230611111954254](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-17.png)

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-18.png" alt="image-20230611112045712" style="zoom:67%;" />

在打印一个菜单的所有菜单项的实现中，可以利用这个菜单的容器的迭代器来遍历。



**在这个模式中，一个结点基类既可以是分支结点（作为菜单）又可以是叶子节点（作为菜单项），相当于一个类完成了两种责任。**
以单一责任模式换取透明性，即用户不知道这个树中的结点是分支结点还是叶子节点。因此有可能会发生一些安全性问题，比如尝试向一个叶子结点中添加孩子。



**实现组合迭代器**

对于分支节点（也就是菜单）需要返回一个组合迭代器，这个组合迭代器不仅要能够遍历这个分支的所有菜单项，也要能够遍历这个分支的菜单的所有菜单项（以及分支的分支...）。

对叶子结点（也就是菜单项）需要返回一个空结点。

**组合迭代器的实现**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-19.png" alt="image-20230611114046416" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-20.png" alt="image-20230611114244262" style="zoom:67%;" />

打印菜单的迭代器是一个内部迭代器，不给外部使用，只是负责遍历自身拥有的菜单项；

而上面这个迭代器是一个外部迭代器，返回给外部使用。



**空迭代器的实现：**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-21.png" alt="image-20230611114450622" style="zoom:80%;" />



<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-22.png" alt="image-20230611114508732" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\9-23.png" alt="image-20230611115627586" style="zoom:67%;" />

# 第十章 状态模式

糖果机：不同的状态可以采取不同的操作

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-·.png" alt="image-20230615114020388" style="zoom:67%;" />

四种状态：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-1.png" alt="image-20230615114100890" style="zoom:67%;" />

四个操作：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-2.png" alt="image-20230615114122999" style="zoom:67%;" />

第一个版本在设计时，每个动作函数都需要为四个状态条件给出对应的操作。

------------

现在，想要添加一个“赢家”状态：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-3.png" alt="image-20230615114248517" style="zoom:67%;" />

那么如果修改代码，添加一个状态还好，但是每个动作都需要添加一个新的条件，弹性非常差。

----------

ACDEF

-----

新的设计：

每一个状态是一个类，类内方法对应着状态可以采取的动作。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-4.png" alt="image-20230618111524372" style="zoom: 67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-5.png" alt="image-20230618111605917" style="zoom:67%;" />

具体实现一个状态：

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-6.png" alt="image-20230618111947615" style="zoom:67%;" />



糖果机的状态由整数表示变为状态对象表示。

![image-20230618112020037](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-7.png)

**糖果机委托状态对象去完成动作。**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-8.png" alt="image-20230618112610983" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-9.png" alt="image-20230618112638694" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-10.png" alt="image-20230618112701507" style="zoom:67%;" />

###### 状态模式

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-11.png" alt="image-20230618112758618" style="zoom:80%;" />

将状态封装成类，并将动作交给状态对象完成。

对于糖果机来说，面对客户的需求能够在不同状态在给出不同的动作，好像类的方法在发生改变。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-12.png" alt="image-20230618113104974" style="zoom:67%;" />

状态模式：将行为封装在每一个状态对象中，当前状态发生变化时，起行为也发生变换；

策略模式：指定当前的行为是哪一种行为，也能够在运行时发生改变，凡是通常只有一个最佳的行为。

策略模式是为了随意组合行为，状态模式是为了对象处于不同状态下能够有不同的行为。



<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\10-13.png" alt="image-20230618114107572" style="zoom:67%;" />

# 第十一章 代理模式

代理就是代表了真实的对象。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-1.png" alt="image-20230706103622023" style="zoom:80%;" />

**远程方法调用：**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-2.png" alt="image-20230706104218883" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-3.png" alt="image-20230706104252205" style="zoom:67%;" />

**远程方法调用过程：**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-4.png" alt="image-20230706104454224" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-5.png" alt="image-20230706104521027" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-6.png" alt="image-20230706104550736" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-7.png" alt="image-20230706104618676" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-8.png" alt="image-20230706104640060" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-9.png" alt="image-20230706104704060" style="zoom:67%;" />

**Java RMI概述：**

RMI将客户辅助对象称为stub（桩），将服务辅助对象称为skeleton（骨架）

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-10.png" alt="image-20230706105218191" style="zoom: 80%;" />

**具体实现步骤概述：**

1.制作远程接口：定义出可以让客户远程调用的方法。客户使用这个接口作为服务的类类型，stub和实际的服务都需要实现这个接口；

2.制作远程实现：定义远程方法的真正实现。这就是客户想要真正调用方法的对象。

3.利用rmic产生sub和skeleton类：也就是客户和服务的辅助类。

4.启动RMI registry：里面保存了代理对象的位置。

5.开始远程服务：注册服务，让服务能够被客户调用。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-11.png" alt="image-20230706105831235" style="zoom:67%;" />

**具体工作方式：**

1.客户到RMI registry中寻找需要的代理；

2.RMI registry返回stub对象；

3.客户调用stub的方法，就像使用真正的服务对象方法一样。



###### 代理模式

为一个对象提供代理对象，即作为一个对象的代表对外提供服务。
被代理的对象可以是**远程对象**、**创建开销比较大的对象**、**需要安全控制的对象**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-12.png" alt="image-20230706110124624" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-15.png" alt="image-20230706110447703" style="zoom:80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-13.png" alt="image-20230706110319530" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-14.png" alt="image-20230706110403859" style="zoom:67%;" />

**远程代理与虚拟代理比较：**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-16.png" alt="image-20230706110533573" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-17.png" alt="image-20230706110607284" style="zoom:67%;" />



都是将客户对于服务对施加的方法调用拦截，这种间接操作可以做很多事，比如将请求分发到远程对象、给创建开销比较大的对象提供代表、以及提供某种级别的保护（比如只允许客户能够调用哪些方法）。

可以使用工厂实例化并返回一个代理对象，这样客户就不知道使用的是代理还是真正的对象。

装饰者模式的目的是为了给对象增加行为，而代理模式是为了控制对于真正对象的访问。
装饰者模式不会实例化一个对象，而代理模式会实例化真正的对象。
装饰者模式可能会包装多次，而代理模式只会包装真正的对象一次。

**动态代理：**

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-18.png" alt="image-20230706153008155" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-19.png" alt="image-20230706153052684" style="zoom:67%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-20.png" alt="image-20230706153219226" style="zoom:67%;" />

保护代理指的是根据访问权限决定客户是否能够访问对象的代理以及对象的哪些方法。

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\11-21.png" alt="image-20230706153605906" style="zoom:67%;" />



# 第十二章 复合模式

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-1.png" alt="image-20230707082447513" style="zoom:67%;" />



以一个鸭子的例子讲解组合模式，从适配器、装饰者、工厂、组合和迭代器、观察者。



MVC：Model、View、Controller

以一个音乐播放器为例

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-2.png" alt="image-20230707092916863" style="zoom:80%;" />

<img src="D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-3.png" alt="image-20230707092943016" style="zoom:80%;" />

**从模式的角度看待MVC：**

![image-20230707093446342](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-4.png)

![image-20230707093659562](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-5.png)

![image-20230707093736507](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-6.png)

![image-20230707093757480](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-7.png)



模型：

![image-20230707094748052](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-8.png)

视图部分代码实现：

书上内容。包括组件、模型和控制器的引用、点击组件时会调用方法



控制器代码实现：控制器是策略，需要插入视图中，控制器中包含视图所有能够调用的方法。



**通常可以使用适配器模式将现有的MVC适配成需要对MVC**



MVC与WEB：

![image-20230707100040314](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-9.png)

![image-20230707100313153](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\12-10.png)



# 第十三章 与设计模式相处

###### 设计模式定义

![image-20230707105558724](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\13-1.png)

![image-20230707105921175](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\13-2.png)

![image-20230707105953817](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\13-3.png)

![image-20230707110043722](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\13-4.png)



![image-20230707110456896](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\13-5.png)

###### 设计模式分类

![image-20230707111517828](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\13-6.png)

![image-20230707111613740](D:\RegularFile\C++\learning\2.C++进阶\1.Head First 设计模式\image\13-7.png)





###### 使用模式

- 保持简单：尽可能使用最简单的方式解决问题，而不是应用模式。
- 何时使用模式：当设计中可以利用某个模式解决某个问题时，就使用这个模式。当系统变得非常复杂，并不需要预留任何弹性时，就不要使用模式（这种场景说明应当使用一个更简单的解决方案）
- 只在需要的时候使用设计模式：应用模式只有在需要时自然而然地设计和应用。

初学者：使用的模式越多，设计就越好。但事实并非如此，只有需要实践扩展的地方，才值得使用复杂性和模式。

中级人员：开始分辨可是需要模式，何时不需要。

悟道者：并不急切地使用模式，而是找到解决问题的简单方案。



设计模式的缺点就是常常产生一些额外的类和对象，所以会增加设计的复杂度。



###### 共享词汇的方式

1.在设计会议中

2.和其它开发人员交流

3.在架构文档中

4.在代码注释和命名习惯上

5.将志同道合的开发人员集合在一起



后续阅读资源：四人组的《Design Pattern》















