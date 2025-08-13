
#include <iostream>
#include <string>
#include <stdexcept> // std::exception 和一些标准异常类在这里
#include<vector>

// 异常类型1: 当记录格式不正确时（比如缺少冒号）
struct InvalidFormatException : public std::exception {
    const char* what() const noexcept override {
        return "Error: Record format is invalid. Expected 'ID:Value'.";
    }
};

// 异常类型2: 当Value部分不是一个有效的数字时
struct InvalidValueError : public std::exception {
    const char* what() const noexcept override {
        return "Error: Value part is not a valid number.";
    }
};

//异常类型

// 解析记录，如果成功，打印ID和Value
void parseRecord(const std::string& record) {
    size_t colon_pos = record.find(':');

    if (colon_pos == std::string::npos) {
        throw InvalidFormatException(); // 发射格式错误信号弹
    }

    std::string id_part = record.substr(0, colon_pos);
    std::string value_part = record.substr(colon_pos + 1);

    try {
        double value = std::stod(value_part); // std::stod 可能会自己抛出异常
        std::cout << "Success! ID: " << id_part << ", Value: " << value << std::endl;
    }
    catch (const std::invalid_argument& e) {
        throw InvalidValueError(); // 捕获标准异常，转换为我们自己的异常类型再抛出
    }
}


int main() {
    std::vector<std::string> records = {
        "U_1024:99.5",      // 正常
        "S_512-78.0",       // 格式错误
        "A_256:hello",      // 值错误
        "B_128:123.45"      // 正常
    };

    for (const auto& rec : records) {
        std::cout << "Processing record: \"" << rec << "\"" << std::endl;
        try {
            // 这里是监控区
            parseRecord(rec);
        }
        catch (const InvalidFormatException& e) {
            // 处理格式错误
            std::cerr << "  -> Caught specific error: " << e.what() << std::endl;
        }
        catch (const InvalidValueError& e) {
            // 处理值错误
            std::cerr << "  -> Caught specific error: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            // 捕获所有其他标准异常（作为兜底）
            std::cerr << "  -> Caught a general exception: " << e.what() << std::endl;
        }
        std::cout << "--------------------" << std::endl;
    }

    return 0;
}