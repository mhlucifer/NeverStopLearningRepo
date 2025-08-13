### **UEFI 启动流程总结：一个餐厅从零到营业的故事**



我们把整个 UEFI 启动比作一家高级餐厅从“一片漆黑”到“正式营业”的全过程。

**第 1 阶段：SEC (安全验证) - 大厨在黑暗中点亮手电筒**

- **情景**: 餐厅一片漆黑，空无一人。大厨（CPU）第一个进来。
- **任务**: 在没有电灯（主内存）的情况下，摸黑完成最基础的准备。他拿出随身的手电筒（临时内存 CAR），并找到了藏着第一批菜谱（PEI 固件卷 BFV）的柜子。这是信任的起点，后续所有步骤都基于此。

**第 2 阶段：PEI (前期初始化) - 帮厨团队进场，打开厨房大灯**

- **情景**: 大厨叫来一队帮厨（PEIM 模块）。厨房里还是很暗，大家挤在一起用手电筒干活。
- **任务**: 帮厨团队的核心目标是**打开厨房的正式照明系统（初始化主内存 DRAM）**。他们分工合作，通过内部的对讲机频道（PPI 接口）沟通。任务完成后，他们写了一份详细的**交接清单（HOB 列表）**，记录了内存有多大、在哪里等关键信息。

**第 3 阶段：DXE (驱动执行环境) - 厨师军团全面备菜**

- **情景**: 厨房大灯已亮，空间宽敞。总厨（DXE Core）带领整个厨师军团（DXE 驱动）进场。
- **任务**: 这是最繁忙的备菜阶段。总厨根据菜谱的依赖关系，有条不紊地指挥各位专家厨师（显卡驱动、硬盘驱动等）准备好各自的食材和厨具。厨师间通过标准化的“服务窗口”（Protocol 协议）进行协作。最终，整个后厨（所有硬件）万事俱备，并提供好两套服务：**启动服务**（备菜时用的所有工具）和**运行时服务**（营业后也保留的少数应急工具）。

**第 4 阶段：BDS (启动设备选择) - 餐厅领班安排客人入座**

- **情景**: 后厨备菜完毕。餐厅领班（BDS 模块）登场。
- **任务**: 领班不关心备菜细节，他只关心“为哪位客人服务”。他拿出**预订本（NVRAM 变量）**，查看 `BootOrder` 预订顺序，找到“操作系统”这位最重要的客人，并把他（OS Loader）加载到内存中执行。

**第 5-6 阶段：TSL & RT (加载与运行) - 客人用餐，服务员退场**

- **情景**: 客人（OS Loader）已入座。
- **TSL 阶段**: 客人正在看菜单（使用 Boot Services），点菜并准备用餐（加载 OS 内核）。
- **RT 阶段**: 客人说“可以上菜了，谢谢你们的服务”（调用 `ExitBootServices()`）。大部分厨师和服务员（Boot Services）下班回家，释放出所有空间（内存）。餐厅里只留下少数夜班经理（Runtime Services）以备不时之需。客人（操作系统）正式开始用餐，完全掌控局面。

**第 7 阶段：AL (灾后恢复) - 餐厅紧急预案**

- **情景**: 客人在用餐时（RT 阶段）突发严重状况。
- **任务**: 餐厅自己的紧急预案启动，由留守的夜班经理（固件）进行处理。具体怎么处理，每家餐厅（设备厂商）的规定都不同。

------



### **UEFI 核心专有名词列表 (速查手册)**





#### **核心阶段 (Core Phases)**



- **SEC (Security Phase)**: 安全验证阶段。信任链的起点，建立临时内存 (CAR)。
- **PEI (Pre-EFI Initialization)**: EFI 前期初始化。核心任务是初始化主内存 (DRAM)。
- **DXE (Driver Execution Environment)**: 驱动执行环境。初始化几乎所有硬件，是功能最强的阶段。
- **BDS (Boot Device Selection)**: 启动设备选择。根据 NVRAM 变量决定启动哪个操作系统。
- **TSL (Transient System Load)**: 临时系统加载。OS 加载器作为 UEFI 应用运行，使用 Boot Services。
- **RT (Run Time)**: 运行期。`ExitBootServices()` 被调用后，OS 正式接管控制权。
- **AL (After Life)**: 灾难恢复期。处理 OS 运行时发生的、无法恢复的错误。



#### **关键组件与模块 (Key Components & Modules)**



- **PEIM (PEI Module)**: PEI 模块。在 PEI 阶段执行的、用于初始化特定硬件的小型驱动。
- **DXE Driver**: DXE 驱动。在 DXE 阶段执行的、功能完备的驱动程序。
- **OS Loader (Operating System Loader)**: 操作系统加载器。如 `bootmgfw.efi` (Windows) 或 `grubx64.efi` (Linux)，负责将 OS 内核加载到内存。



#### **通信与接口 (Communication & Interfaces)**



- **PPI (PEI-to-PEI Interface)**: PEI 阶段模块间的通信接口，像一个“对讲机频道”。
- **Protocol (协议)**: DXE 阶段模块间的通信接口，是功能更完备的“专业服务窗口”。
- **GUID (Globally Unique Identifier)**: 全局唯一标识符。一长串字符，用作 PPI 和 Protocol 的唯一“名字”。



#### **数据结构与存储 (Data Structures & Storage)**



- **HOB (Hand-Off Block)**: 交接块。PEI 阶段的“工作总结报告”，用于向 DXE 阶段传递信息（特别是内存信息）。
- **NVRAM (Non-Volatile RAM)**: 非易失性内存。存储启动设置的芯片，BDS 从这里读取启动顺序。
- **BFV (Boot Firmware Volume)**: 启动固件卷。固件里存放 PEI 阶段所有 PEIM 模块的“文件包”。
- **BootOrder / Boot####**: NVRAM 中的变量，分别定义了启动设备的顺序和每个启动项的详细信息。



#### **核心概念与函数 (Core Concepts & Functions)**



- **Reset Vector**: 重置向量。CPU 上电后执行的第一条指令的固定内存地址。
- **CAR (Cache-as-RAM)**: 将 CPU 高速缓存用作内存。SEC 阶段的临时解决方案。
- **Boot Services (BS)**: 启动服务。UEFI 在 DXE 和 TSL 阶段提供的丰富服务集，用于初始化和加载。
- **Runtime Services (RS)**: 运行时服务。在 OS 运行后依然保留的一小部分服务，用于 OS 与固件通信。
- **`ExitBootServices()`**: 终结启动服务。标志着控制权从 UEFI 正式移交给 OS 的“分水岭”函数。



#### **底层硬件/软件 (Low-Level Hardware/Software)**



- **SPI Flash**: 存储 UEFI/BIOS 固件程序的物理芯片，焊接在主板上。
- **EFI / UEFI**: 可扩展/统一可扩展固件接口。定义固件与 OS 之间交互的现代软件规范，是 BIOS 的继任者。
- **ABI (Application Binary Interface)**: 应用程序二进制接口。底层的调用约定，规定了函数调用时如何传递参数、使用寄存器等。是理解汇编与 C 语言交互的关键。