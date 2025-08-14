------



### **UEFI 编程核心知识总结**





#### **1. 代码的组织方式：EDK II 的“蓝图体系”**



UEFI 固件项目就像是用乐高积木搭建一个复杂的模型，EDK II 为此定义了一套清晰的图纸和规范。

- **Package (包) - “乐高零件库”**
  - 它是一系列相关模块的集合，提供了一套基础功能，如同一个“太空主题”或“城堡主题”的乐高大套装。
  - 每个包都用一个 **`.dec` 文件**作为其“公开的零件清单”，向外界声明它能提供哪些可用的零件（GUID、库等）。
- **Module (模块) - “具体的乐高模型”**
  - 它是最小的可编译单元，旨在实现一个单一的功能，就像是用零件库搭建出的一个“宇宙飞船”或一座“小房子”。
  - 每个模块都用一个 **`.inf` 文件**作为其“拼装说明书”，详细描述了拼装该模型需要哪些源文件、依赖哪些零件库，以及最终成品的名称。
- **Platform (平台) - “最终的场景设计图”**
  - 一个完整的固件就是最终的“场景”，比如“月面基地”。
  - 由一个 **`.dsc` 文件**作为“总设计图”，它指定了要从哪些“零件库 (Package)”里，选用哪些“模型 (Module)”，最终将它们组合成完整的固-件映-像。



#### **2. 应用程序的“生命线”：`UefiMain` 函数**



编写一个能在 UEFI 环境下运行的程序，其核心就是编写一个符合规范的 `UefiMain` 入口函数。

```
EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
```

- **入口与出口**
  - **入口 (`UefiMain`)**: 你的代码从这里开始。
  - **出口 (`return EFI_STATUS`)**: 你的代码从这里结束，并需要向系统汇报“任务成功”（`EFI_SUCCESS`）还是“失败”（各种 `EFI_ERROR_CODE`）。
- **两大“法宝”：传递给你的两个核心参数**
  - **`ImageHandle` (你的“身份证”)**: 这是固件在加载你的程序后，分配给它的唯一句柄。它代表了**你的程序自身**，在进行很多操作时都需要出示这个“身份证”。
  - **`SystemTable` (你的“万能工具箱”)**: 这是**最重要的参数**。它是一个指向系统服务总表的指针。你想在 UEFI 环境下做任何事情，都必须通过这个“工具箱”来找到对应的工具。



#### **3. 万物之始：调用 UEFI 服务**



UEFI 编程的本质，就是通过 `SystemTable` 这个“万能工具箱”来调用各种预设好的服务。我们在示例中看到的打印 “Hello World” 的过程，就是最经典的服务调用模式：

```
SystemTable->ConOut->OutputString(SystemTable->ConOut, L"HelloWorld\n");
```

这个模式可以被分解为三步，放之四海而皆准：

1. **第一步：拿出“万能工具箱”**
   - `SystemTable`
2. **第二步：在工具箱里找到相应的“服务部门”**
   - `->ConOut` (控制台输出部门)
   - 未来还会有 `->BootServices` (启动服务总部门), `->RuntimeServices` (运行时服务部门) 等。
3. **第三步：调用该部门提供的具体“工具”（函数）**
   - `->OutputString()`

这个 **“总工具箱 → 服务部门 → 具体工具”** 的链式调用，是您未来进行 UEFI 编程时最常打交道的模式。

------



### **专有名词列表 (EDK II 编程部分)**



- **EDK II (EFI Development Kit II)**: 开源的 UEFI 开发框架和代码库，是现代 UEFI 固件开发的事实标准。
- **Module (模块)**: EDK II 中最小的可编译单元，由一个 `.inf` 文件描述。
- **Package (包)**: 模块的集合，提供了一套可复用的库和声明，由一个 `.dec` 文件描述。
- **`.inf` (Information File)**: 模块信息文件，模块的“项目文件”或“编译说明书”。
- **`.dec` (Declaration File)**: 包声明文件，包的“公共 API 文档”。
- **`.dsc` (Platform Description File)**: 平台描述文件，固件的“总装蓝图”。
- **`UefiMain`**: 标准 UEFI 应用程序的入口函数。
- **`ImageHandle`**: 应用程序在内存中的唯一标识，是程序的“身份证”。
- **`SystemTable` (EFI_SYSTEM_TABLE)**: 系统服务表，是访问所有 UEFI 服务的总入口，是程序的“万能工具箱”。
- **`BootServices` (BS)**: 启动服务。在 `ExitBootServices()` 调用前可用的强大服务集。
- **`RuntimeServices` (RS)**: 运行时服务。在 OS 运行后依然保留的一小部分服务。
- **`ConOut` (Console Output)**: `SystemTable` 的一个成员，指向标准控制台输出协议，用于在屏幕上显示文本。
- **`Protocol` (协议)**: UEFI 中对一组相关功能（服务）的抽象封装，通过 GUID 识别。
- **`EFI_STATUS`**: UEFI 函数通用的返回类型，用于表示成功或失败。
- **`EFI_SUCCESS`**: `EFI_STATUS` 的一种，表示函数成功执行。
- **`L"..."` (Wide-Character String)**: C 语言中表示宽字符（UTF-16）字符串的语法，是 UEFI 的标准字符串格式。
- **`EFIAPI`**: 函数调用约定宏，确保函数编译后符合 UEFI 的 ABI 规范。