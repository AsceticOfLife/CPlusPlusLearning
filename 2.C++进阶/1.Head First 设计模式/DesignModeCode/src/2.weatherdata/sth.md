# 遇到的问题

1.Observer和Subject类互相指向：Observer里存在指向Subject的指针，是为了调用Subject的方法进行登记和注销。

创建对象需要知道对象的类定义，所以不能在不知道Subject类之前是不能创建Subject类对象，只能创建指针；

想要使用指针对象的方法需要同样需要知道类定义，因此需要在调用方法之前知道方法定义，所以需要在cpp文件中包含另一个类Subject的头文件以便知道类方法定义；

综上，Observer和Subject文件的关系为：

在Observer.h文件中，声明Observer类，注意需要前向声明Subject类，因为观察者类中有一个指向Subject类的指针；

在Observer.cpp文件中，包含Observer.h文件和Subject.h文件，前者是显然的，后者是为了获知Subject类方法定义；

在Subject.h文件中，包含Observer.h文件，以便知道Observer类定义，以及方法。

当主文件包含Subject文件时，就会将Observer文件也包含进去，即使再尝试包含Observer文件也会因为ifndef不会出现冲突；

2.在Subject类中保存Observer对象列表：不能使用对象，因为使用多态，只能使用指针或者引用。引用不能使用容器，所以只能使用指针容器，同时因为没有动态申请观察者对象的空间，使用的是自动变量，所以不会有内存泄漏问题。