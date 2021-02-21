#include <chrono>
#include <iostream>
#include <map>
#include <regex>
#include <stack>
#include <string>
#include <thread>

using namespace std;

class FinalSolution {
   public:
    string countOfAtoms(string formula) {
        while (true) {
            string resolve = removeParentheses(formula);
            if (resolve == formula) {
                break;
            }

            auto counts = countOfAtomsUtil(resolve);
            int multiplier = findMultiplier(formula, resolve);

            resolveCounts(counts, multiplier);
            string resolved = generateString(counts);

            resolve = "(" + resolve + ")";
            if (multiplier != 1) {
                resolve += to_string(multiplier);
            }
            
            formula = replaceString(formula, resolve, resolved);
        }

        string res = compactify(formula);
        return res;
    }

    map<string, int> countOfAtomsUtil(string formula) {
        // to avoid duplicate code for last element in the loop.
        formula += "X";
        
        map<string, int> counts;
        string atom = "";
        int count = 0;

        for (const auto &i : formula) {
            if (isupper(i)) {
                if (!atom.empty()) {
                    if (count == 0) {
                        count = 1;
                    };
                    counts[atom] += count;
                }
                atom = i;
                count = 0;
            } else if (islower(i)) {
                atom += i;
            } else if (isdigit(i)) {
                count = count * 10 + i - '0';
            }
        }

        return counts;
    }

    string removeParentheses(string formula) {
        string resolve = "";

        for (int i = 0; i < formula.length(); ++i) {
            if (formula[i] == '(') {
                resolve = "";
            } else if (formula[i] == ')') {
                break;
            } else {
                resolve += formula[i];
            }
        }

        return resolve;
    }

    int findMultiplier(string formula, string resolve) {
        int mul = 0;
        int pos = formula.find(resolve);
        
        int i = pos + resolve.length() + 1;
        while (i < formula.length() && isdigit(formula[i])) {
            mul = mul * 10 + formula[i] - '0';
            ++i;
        }

        return (mul == 0) ? 1 : mul;
    }

    void resolveCounts(map<string, int> &counts, int mul) {
        for (auto &i : counts) {
            i.second *= mul;
        }
    }

    string generateString(map<string, int> &counts) {
        string res = "";
        for (const auto &i : counts) {
            res += i.first;
            if (i.second != 1) {
                res += to_string(i.second);
            }
        }
        return res;
    }

    string replaceString(string formula, string resolve, string resolved) {
        int pos = formula.find(resolve);
        formula.replace(pos, resolve.length(), resolved);
        return formula;
    }
    
    string compactify(string formula) {
        auto counts = countOfAtomsUtil(formula);
        return generateString(counts);
    }
};


class Solution {
   public:
    string removeParentheses(string formula) {
        string resolve = "";

        for (int i = 0; i < formula.length(); ++i) {
            if (formula[i] == '(') {
                resolve = "";
            } else if (formula[i] == ')') {
                break;
            } else {
                resolve += formula[i];
            }
        }

        return resolve;
    }

    string replaceString(string formula, string resolve, string resolved) {
        // cout << "resolve: " << resolve << " resolved: " << resolved << endl;

        int pos = formula.find(resolve);
        // cout << "position " << pos << endl;
        formula.replace(pos, resolve.length(), resolved);
        return formula;
    }

    int findMultiplier(string formula, string resolve) {
        int pos = formula.find(resolve);

        int i = pos + resolve.length() + 1;
        int mul = 0;
        while (i < formula.length() && isdigit(formula[i])) {
            mul = mul * 10 + formula[i] - '0';
            // cout << "mul - " << mul << endl;
            ++i;
        }

        return (mul == 0) ? 1 : mul;
    }

    void resolveCounts(map<string, int> &counts, int mul) {
        for (auto &i : counts) {
            i.second *= mul;
        }
    }

    string compactify(string formula) {
        auto counts = countOfAtomsUtil(formula);
        return generateString(counts);
    }

    string countOfAtoms(string formula) {
        while (true) {
            string resolve = removeParentheses(formula);
            // cout << "\nstring to resolve: " << resolve << endl;
            if (resolve == formula) {
                break;
            }

            auto counts = countOfAtomsUtil(resolve);
            int multiplier = findMultiplier(formula, resolve);

            resolveCounts(counts, multiplier);
            string resolved = generateString(counts);

            resolve = "(" + resolve + ")";
            if (multiplier != 1) {
                resolve += to_string(multiplier);
            }
            string newFormula = replaceString(formula, resolve, resolved);
            formula = newFormula;

            // cout << "replaced string: " << formula << endl;

            resolve = "";
            // this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        string res = compactify(formula);
        return res;

        // formula += ")";

        // stack<string> st;
        // map<string, int> res;

        // string tmp = "";
        // int i = 0;
        // while (i < formula.length()) {
        //     if ((formula[i] == '(' && !tmp.empty()) || formula[i] == ')') {
        //         if (tmp == "") {
        //             // cout << "breaking" << endl;
        //             break;
        //         }

        //         auto counts = countOfAtomsUtil(tmp);
        //         tmp = "";

        //         ++i;
        //         // cout << formula[i] << " formula[i]" << endl;
        //         int mul = 0;
        //         while (i < formula.length() && isdigit(formula[i])) {
        //             mul = mul * 10 + formula[i] - '0';
        //             // cout << "mul - " << mul << endl;
        //             ++i;
        //         }

        //         // cout << mul << "<mul" << endl;

        //         if (mul == 0) {
        //             // cout << "mul was 0" << endl;
        //             mul = 1;
        //         }
        //         --i;

        //         for (const auto &j : counts) {
        //             // cout << j.first << ":" << j.second << ":" << mul << endl;
        //             int second = j.second;
        //             if (second == 0) {
        //                 second = 1;
        //             }
        //             counts[j.first] = second * mul;
        //         }

        //         string pushme = generateString(counts);
        //         // cout << pushme << " <--pushme" << endl;
        //         st.push(pushme);
        //     } else {
        //         tmp += formula[i];
        //     }
        //     ++i;
        // }

        // // cout << st.size() << " stsize" << endl;

        // string tmp1 = "";
        // while (!st.empty()) {
        //     // cout << st.top() << " <top" << endl;
        //     tmp1 += st.top();
        //     st.pop();
        // }

        // for (int i = 0; i < tmp1.size(); ++i) {
        //     if (tmp1[i] == '1') {
        //         // cout << "hello" << endl;
        //         tmp1.erase(tmp1.begin() + i);
        //     }
        // }

        // // cout << tmp1 << " <--" << endl;

        // res = countOfAtomsUtil(tmp1);
        // return generateString(res);
    }

    string generateString(map<string, int> &counts) {
        string res = "";
        for (const auto &i : counts) {
            // cout << i.first << ":" <<i.second << endl;
            res += i.first;
            if (i.second != 1) {
                res += to_string(i.second);
            }
        }
        // cout << res << "<--res" << endl;
        return res;
    }

    map<string, int> countOfAtomsUtil(string formula) {
        // cout << "formula is " << formula << endl;
        map<string, int> counts;
        counts.clear();

        string atom = "";
        int count = 0;

        for (const auto &i : formula) {
            if (isupper(i)) {
                if (!atom.empty()) {
                    if (count == 0) {
                        count = 1;
                    };
                    int tmp = 0;
                    if (counts.find(atom) != counts.end()) {
                        tmp = counts[atom];
                        if (tmp == 0) {
                            tmp = 1;
                        }
                    }
                    printf("counts[%s] = %d + %d;\n", atom.c_str(), count, tmp);
                    counts[atom] = count + tmp;
                    tmp = 0;
                }
                atom = i;
                count = 0;
            } else if (islower(i)) {
                atom += i;
            } else if (isdigit(i)) {
                count = count * 10 + i - '0';
            }
        }

        // for the last letter
        if (!atom.empty()) {
            if (count == 0) {
                count = 1;
            };
            int tmp = 0;
            if (counts.find(atom) != counts.end()) {
                tmp = counts[atom];
                if (tmp == 0) {
                    tmp = 1;
                }
            }
            counts[atom] = count + tmp;
        }

        for (auto &i : counts) {
            if (i.second == 0) {
                i.second = 1;
            }
        }

        // for (const auto &i : counts) {
        //     cout << i.first << " -> " << i.second << endl;
        // }
        // cout << "----" << endl;

        return counts;
    }
};

int main() {
    FinalSolution s;
    cout << s.countOfAtoms("(H)") << endl;
}
