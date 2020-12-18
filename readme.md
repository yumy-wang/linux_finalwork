# linux高级环境编程期末考核

## 要求
- 实现一个部署在服务端的可扩展的远程调用功能。
- 客户端能够指定服务端已有的功能号和符合该功能接口的参数，并将功能号和参数序列化发送给服务端。
- 服务端收到后进行反序列化，根据功能号，调用本地的函数对客户端的参数进行计算，将结果序列化发送给客户端。
- 客户端收到后，反序列化得到结果。
- 要求服务端支持的功能能够在服务端进程正常运行的情况下进行扩展和更新。



## 生成插件库
```shell

g++ -fpic -shared -o libfunc1.so function1.cpp IPrintPlugin.cpp
g++ -fpic -shared -o libfunc2.so function2.cpp IPrintPlugin.cpp

```

> 需要注意：生成so动态链接库之后需要将生成的so文件放入./plugin文件夹下面

## 编译

> 直接make即可~


## 运行
> 两个窗口分别输入运行命令：

```shell
./server

./client
```

从client发送命令【包括 序列化文件和功能参数】会从server得到计算的序列化结果，再进行反序列化即可