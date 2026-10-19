#include <iostream>
#include <queue>
#include <vector>

struct Variables {
    std::vector<int> vars;

    inline Variables() : vars(26, 0) {}

    inline int query(char c) {
        return vars[c - 'a'];
    }

    inline void assign(char c, int value) {
        vars[c - 'a'] = value;
    }
};

struct Opr {
    int type;  // 0: assign; 1: prt; 2:lock; 3:unlock; 4:end
    char c;
    int value;

    Opr() : type(-1), c(0), value(0) {}

    Opr(std::string& s) {
        if (s[2] == '=') {
            type = 0;
            c = s[0];
            value = std::stoi(s.substr(4));
        } else {
            switch (s[0]) {
                case 'p':
                    type = 1;
                    c = s[6];
                    break;
                case 'l':
                    type = 2;
                    break;
                case 'u':
                    type = 3;
                    break;
                case 'e':
                    type = 4;
                    break;
                default:
                    break;
            }
        }
    }
};

struct Program {
    std::vector<Opr> operations;
    std::vector<Opr>::iterator crtInstruction;

    inline Program() {
        operations.reserve(256);
        crtInstruction = operations.begin();
    }

    inline void add(std::string& s) {
        operations.push_back(s);
    }
};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int time[5];
        int prograNum, quantum;
        std::cin >> prograNum >> time[0] >> time[1] >> time[2] >> time[3] >> time[4] >> quantum;
        getchar();

        std::vector<Program> programs(prograNum + 1);
        std::string tmp;
        tmp.reserve(8);
        for (int crtId = 1; crtId <= prograNum; crtId++) {
            while (1) {
                std::getline(std::cin, tmp);
                programs[crtId].add(tmp);
                if (tmp == "end") {
                    break;
                }
            }
        }

        std::deque<int> readyQueue, blockQueue;
        for (int i = 1; i<= prograNum; i++) {
            readyQueue.push_back(i);
        }
        
        Variables varList;
        bool locked = false;
        while (!readyQueue.empty()) {
            int remainTime = quantum;
            int id = readyQueue.front();
            readyQueue.pop_front();
            auto& crtProgra = programs[id];
            while (remainTime > 0) {
                auto& op = crtProgra.crtInstruction;
                remainTime -= time[op->type];
                switch (op->type) {
                    case 0:
                        varList.assign(op->c, op->value);
                        break;
                    case 1:
                        std::cout << id << ':' << ' ' << varList.query(op->c) << '\n';
                        break;
                    case 2:
                        if (locked) {
                            goto prograBlocked;
                        }
                        locked = true;
                        break;
                    case 3:
                        locked = false;
                        if (!blockQueue.empty()) {
                            readyQueue.push_front(blockQueue.front());
                            blockQueue.pop_front();
                        }
                        break;
                    case 4:
                        goto prograEnd;
                        break;
                    default:
                        break;
                }
                ++op;
            }
            readyQueue.push_back(id);
            continue;
        prograBlocked:
            blockQueue.push_back(id);
            continue;
        prograEnd:
            continue;
        }
        if (t!=0) std::cout << '\n';
    }
}
