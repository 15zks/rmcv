#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符
    
    // 使用哈希表存储序列，键为id，值为存储整数的向量
    unordered_map<int, vector<int>> sequences;
    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        
        // 解析命令
        size_t pos = line.find(' ');
        string cmd = line.substr(0, pos);
        
        if (cmd == "new") {
            // 新建序列
            int id = stoi(line.substr(pos + 1));
            sequences[id] = vector<int>();
        }
        else if (cmd == "add") {
            // 向序列添加元素
            size_t pos2 = line.find(' ', pos + 1);
            int id = stoi(line.substr(pos + 1, pos2 - pos - 1));
            int num = stoi(line.substr(pos2 + 1));
            sequences[id].push_back(num);
        }
        else if (cmd == "merge") {
            // 合并两个序列
            size_t pos2 = line.find(' ', pos + 1);
            size_t pos3 = line.find(' ', pos2 + 1);
            int id1 = stoi(line.substr(pos + 1, pos2 - pos - 1));
            int id2 = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            
            if (id1 != id2) {
                // 将id2的元素合并到id1
                sequences[id1].insert(sequences[id1].end(), 
                                     sequences[id2].begin(), 
                                     sequences[id2].end());
                // 清空id2
                sequences[id2].clear();
            }
        }
        else if (cmd == "unique") {
            // 去除序列中的重复元素
            int id = stoi(line.substr(pos + 1));
            vector<int>& seq = sequences[id];
            
            // 先排序再去重
            sort(seq.begin(), seq.end());
            auto last = unique(seq.begin(), seq.end());
            seq.erase(last, seq.end());
        }
        else if (cmd == "out") {
            // 输出序列
            int id = stoi(line.substr(pos + 1));
            vector<int>& seq = sequences[id];
            
            // 排序后输出
            sort(seq.begin(), seq.end());
            for (size_t j = 0; j < seq.size(); ++j) {
                if (j > 0) cout << " ";
                cout << seq[j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
    