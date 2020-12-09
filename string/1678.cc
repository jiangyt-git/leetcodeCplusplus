class Solution {
public:
    /*
    设计 Goal 解析器
    请你设计一个可以解释字符串 command 的 Goal 解析器 。command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。
    Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，
    "(al)" 解释为字符串 "al" 。然后，按原顺序将经解释得到的字符串连接成一个字符串。
    给你字符串 command ，返回 Goal 解析器 对 command 的解释结果。
    输入：command = "(al)G(al)()()G"
    输出："alGalooG"
    */
    string interpret(string command) {
        string ret = "";
        if (command.empty()) {
            return command;
        }
            
        int len = command.size();
        for (size_t i = 0; i <len ; i++) {
            if (command.at(i) == 'G') {
               ret += command.at(i);
            } else if (command.at(i) == '(') {
                size_t index_r = command.find(')', i);
                if ((index_r - i) > 1) {
                    ret += "al";
                } else {
                    ret += "o";
                }
                i = index_r;
            }
        }
        return ret;
    }
};
