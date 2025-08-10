// 日志分析器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编写一个能逐行读取log.txt文件，并将其内容原封不动打印到控制台的C++程序。

//行动要点：

//工具： C++标准库中的#include <fstream> 和 #include <string>。

//核心函数： std::ifstream, std::getline。

//方法论： 在这个过程中，您将首次实践“即时学习（JIT）”。遇到“如何打开文件”、“如何读取一行”的问题时，再去查阅资料（《C++ Primer》或网络），然后立刻将学到的知识应用到您的代码中。

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>

// 包含我们新创建的解析模块的“说明书”
#include "parser.h"
void RunAnalysis(const std::vector<LogEntry>& logs)
{
    // 可以在这里加一个循环，打印解析后的结果来验证
    // for (const auto& entry : logs) {
    //     std::cout << "消息: " << entry.message << std::endl;
    // }
    // === 新增验证代码 ===
    if (!logs.empty()) {
        std::cout << "验证：第一条日志的时间戳是: [" << logs[0].timestamp << "]" << std::endl;
        std::cout << "验证：第一条日志的级别是:   [" << logs[0].logLevel << "]" << std::endl;
        std::cout << "验证：第一条日志的级别是:   [" << logs[0].message << "]" << std::endl;
    }

    std::cout << "\n--- 排序后时间戳预览 ---\n";
    for (const auto& entry : logs) {
        std::cout << entry.timestamp << std::endl;
    }
    PrintLogSummary(logs);


    std::cout << "\n正在筛选所有 [ERROR] 级别的日志...\n";
    std::vector<LogEntry> error_logs = FilterLogsByLevel(logs, "ERROR");

    std::cout << "筛选完成！共找到 " << error_logs.size() << " 条 [ERROR] 日志：\n";
    // 打印所有筛选出来的错误日志
    for (const auto& entry : error_logs) {
        std::cout << "  " << entry.timestamp << " " << entry.message << std::endl;
    }
}
int main() {
    std::vector<LogEntry> logs; // 用来存放所有解析好的日志
    std::ifstream log_file("log.txt");

    if (!log_file.is_open()) {
        std::cerr << "错误：无法打开日志文件 log.txt" << std::endl;
        return 1;
    }

    std::cout << "文件已成功打开！开始解析...\n";

    std::string current_line;
    while (std::getline(log_file, current_line)) {
        // 总司令部（main）调用解析部队（ParseLogLine），不关心其内部细节
        LogEntry entry = ParseLogLine(current_line);
        logs.push_back(entry);
    }

    std::cout << "解析完成！总共处理了 " << logs.size() << " 条日志。\n";


    std::cout << "\n正在按时间戳对日志进行排序...\n";
    std::sort(logs.begin(), logs.end(), [](const LogEntry& a, const LogEntry& b)
        {
            return a.timestamp < b.timestamp;
        });
    std::cout << "排序完成！\n";
    RunAnalysis(logs);
    return 0;
}


