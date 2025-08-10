#include"parser.h"
#include<iostream>
// 在这里，我们给出 ParseLogLine 函数的具体实现
LogEntry ParseLogLine(const std::string& line) {
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