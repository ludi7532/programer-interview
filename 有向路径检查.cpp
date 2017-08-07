#include <iostream>
#include <map> //���ڱ���Ƿ���ʹ�
#include <queue> //�����������
#include <vector>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Path {
public:
bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b)
    {
        /**����ͼ��Ҫ���a-b��b-a�������**/
        return check(a,b) || check(b,a);
    }

    bool check(UndirectedGraphNode* a, UndirectedGraphNode* b)
    {
        if(a == nullptr || b == nullptr)
            return false;
        if(a == b)
            return true;
        map<UndirectedGraphNode*, bool> flagmap;
        queue<UndirectedGraphNode*> nodequeue;
        nodequeue.push(a);
        while(!nodequeue.empty())
        {
            UndirectedGraphNode* node = nodequeue.front();
            flagmap[node] = true;
            for(int i=0; i<node->neighbors.size();i++)
            {
                if(node->neighbors[i] == b)
                    return true;
                if(node->neighbors[i] != nullptr && flagmap[node->neighbors[i]] != true)
                {
                    nodequeue.push(node->neighbors[i]);
                }
            }
            nodequeue.pop();
        }
         return false;
    }
};
