// generate_sql.cpp: 定义应用程序的入口点。
//

#include "generate_sql.h"



int main()
{
	auto file_path_r = std::filesystem::path("D:\\workfile\\cpp\\generate_sql\\resource\\test.txt");
	auto file_path_w = std::filesystem::path("D:\\workfile\\cpp\\generate_sql\\resource\\write.txt");
	std::ifstream file(file_path_r);
	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << file_path_r << std::endl;
		return 1;
	}
	std::string content{ std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>() };

	//去除空格，默认空格就包含换行和回车不需要单独处理
	std::erase_if(content, [](unsigned char c) { return std::isspace(c); });
	std::cout << content << std::endl;
	std::ofstream file_r{file_path_w};
	if(!file_r.is_open()){
		std::cerr << "Failed to open file: " << file_path_w << std::endl;
		return 1;
	}
	file_r << content;

	std::string text = "Boost version: 1.84.0";
	// 正则表达式：匹配以 A/B/C 开头，后跟 12 个数字的字符串
	boost::regex pattern(R"(([ABC]\d{12}))"); // 使用捕获组确保匹配完整项
	// 遍历所有匹配项
	boost::sregex_iterator it(content.begin(), content.end(), pattern);
	boost::sregex_iterator end{};
	//boost::smatch match;

	std::vector<std::string> matches;
	for (; it != end; ++it) {
		// 提取匹配的完整字符串
		std::string match = (*it)[0].str();
		matches.push_back("'" + match + "'");
	}

	// 组合为逗号分隔的字符串
	std::string result;
	if (!matches.empty()) {
		result = matches[0];
		for (size_t i = 1; i < matches.size(); ++i) {
			result += "," + matches[i];
		}
	}

	// 输出结果
	std::cout << "匹配结果: " << result << std::endl;
	
}
