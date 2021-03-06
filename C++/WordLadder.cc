#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int ladderLength0(string start, string end, unordered_set<string> &dict) {
    deque<string> q;
    unordered_set<string> used;
    q.push_back(start);
    used.insert(start);
    int level = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            string cur = q.front();
            q.pop_front();
            
            //Check adjacent strings
            for (int j = 0; j < cur.size(); ++j)
            {
                for (int c = 'a'; c <= 'z'; ++c)
                {
                    string temp = cur;

                    if (cur[j] != (char)c) {
                        temp[j] = (char)c;
                        if (temp == end)
                            return level+1;
                        if (dict.find(temp) != dict.end() &&
                                used.find(temp) == used.end()) {
                            q.push_back(temp);
                            used.insert(temp);
                        }
                    }
                }
            }
        }
        level++;
    }
    return 0;
}

//Slightly improved solution
int ladderLength(string start, string end, unordered_set<string> &dict) {
   
    deque<string> q{start};
    int len = 1;
    if (end == start)
        return len;
        
    while (!q.empty()) {
        
        int sz = q.size();
        
        for (int j = 0; j < sz; ++j)
        {
            string cur = q.front();
            q.pop_front();
        
            for (int i = 0; i < cur.size(); ++i)
            {
                string cur2 = cur;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    cur2[i] = c;
                    if (cur2 == end)
                        return len+1;
                    
                    if (dict.find(cur2) != dict.end()) {
                        q.push_back(cur2);
                        dict.erase(cur2);
                    }
                }
            }
        }
       
        
        len++;
    }
    
    return 0;
}

int main(int argc, char** argv)
{
    unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    string start = "hit";
    string end = "cog";
    cout << ladderLength(start, end, dict) << endl;
    return 0;
}
