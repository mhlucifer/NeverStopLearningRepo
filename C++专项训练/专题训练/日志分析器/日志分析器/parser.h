#pragma once
#include <string>
#include <vector>
// 1. 定义我们的“档案袋”结构体
struct LogEntry {
    std::string timestamp;
    std::string logLevel;
    std::string message;
};

// 2. 声明我们的“解析生产线”函数
//    这里只是一个声明（像个路标），告诉别人有这么一个函数存在。
//    具体的实现（函数体{...}）我们不放在这里。
LogEntry ParseLogLine(const std::string& line);

// 3. 声明我们的“情报分析官”函数
void PrintLogSummary(const std::vector<LogEntry>& logs);

// 4. 声明“情报检索”函数
//    它接收所有日志，和一个要筛选的日志级别字符串
//    它返回一个新的vector，里面只包含符合条件的日志
std::vector<LogEntry> FilterLogsByLevel(const std::vector<LogEntry>& logs, const std::string& level);