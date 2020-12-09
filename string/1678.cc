class Solution {
public:
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
