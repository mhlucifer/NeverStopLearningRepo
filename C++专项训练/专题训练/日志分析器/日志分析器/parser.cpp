#include"parser.h"
#include<iostream>
#include<map>
#include<iterator>
#include <algorithm> 
// 在这里，我们给出 ParseLogLine 函数的具体实现
LogEntry ParseLogLine(const std::string& line) {

    // === 临时安装的“监视器”，用于调试 ===
    // 打印出函数收到的原始 line
    std::cout << "正在解析: [" << line << "]\n";

    LogEntry entry;

    size_t start_bracket = line.find('[');
    size_t end_bracket = line.find(']');

    if (start_bracket != std::string::npos && end_bracket != std::string::npos)
    {
        // 3. 截取它们之间的子字符串
        // 子串的起始位置是 '[' 之后，即 start_bracket + 1
        // 子串的长度是 ']' 和 '[' 的位置之差减一
        size_t length = end_bracket - (start_bracket + 1);
        entry.timestamp = line.substr(start_bracket + 1, length);
    }

    start_bracket = line.find('[', end_bracket);
    end_bracket = line.find(']', start_bracket);
    // =========================================================
    // === 您的下一个主战场：在这里实现字符串解析逻辑 ===
    if (start_bracket != std::string::npos && end_bracket != std::string::npos)
    {
        size_t length = end_bracket - (start_bracket + 1);
        entry.logLevel = line.substr(start_bracket + 1, length);
    }
   

    // =========================================================
    // === 新增代码：提取消息体 (带空格清理功能) ===
    // =========================================================
    // 1. 从第二个 ']' 之后，找到第一个“不是空格也不是制表符”的字符位置
    size_t message_start_bracket = line.find_first_not_of(" \t", end_bracket + 1);
    if (message_start_bracket != std::string::npos)
    {
        entry.message = line.substr(message_start_bracket);
    }
    
    return entry;
}

void PrintLogSummary(const std::vector<LogEntry>& logs) {

    std::cout << "\n-- - 日志分析报告-- - \n";
    std::cout << "总计日志条数: " << logs.size() << std::endl;

    //// 1. 定义三个计数器(简单实现)
    //int info_count = 0;
    //int warning_count = 0;
    //int error_count = 0;
    //for (const auto& entry : logs)
    //{
    //    if (entry.logLevel == "INFO")
    //    {
    //        info_count++;
    //    }
    //    else if (entry.logLevel == "WARNING")
    //    {
    //        warning_count++;
    //    }
    //    else if (entry.logLevel == "ERROR") {
    //        error_count++;
    //    }
    //}

    //// 3. 打印统计结果
    //std::cout << "[INFO]: " << info_count << std::endl;
    //std::cout << "[WARNING]: " << warning_count << std::endl;
    //std::cout << "[ERROR]: " << error_count << std::endl;
    //std::cout << "--- 报告结束 ---\n";
    
    // 1. 创建一个 map 作为我们的“自动记账本”
    std::map<std::string, int> counts;

    //2.遍历日志
    for (const auto& entry : logs)
    {
        counts[entry.logLevel]++;
    }

    // 4. 使用范围for循环，遍历map并打印报告
    //    pair.first 是键 (如 "INFO"), pair.second 是值 (数量)
    for (const auto& pair : counts)
    {
        std::cout << "[" << pair.first << "]" << pair.second << std::endl;
    }
    std::cout << "--- 报告结束 ---\n";
    
}


std::vector<LogEntry> FilterLogsByLevel(const std::vector<LogEntry>& logs, const std::string& level) {
    std::vector<LogEntry> filtered_logs; // 准备一个空vector，用来存放筛选结果

    // copy_if 需要四个参数：
    // 1. 从哪里开始拷贝 (logs.begin())
    // 2. 到哪里结束拷贝 (logs.end())
    // 3. 拷贝到哪里去 (这里用了一个辅助工具 std::back_inserter)
    // 4. 拷贝的“条件” (我们的Lambda表达式)
    std::copy_if(logs.begin(), logs.end(),
        std::back_inserter(filtered_logs),
        [&level](const LogEntry& entry) {
            // 这就是我们的“筛选指南”：
            // 如果这行日志的级别，等于我们想要的级别，就返回 true
            return entry.logLevel == level;
        });

    return filtered_logs;
}