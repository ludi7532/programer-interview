#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CatDogAsulum
{
public:
    vector<int> asylum(vector<vector<int>> ope)
    {
        queue<int> dog;
        queue<int> cat;
        vector<int> res;
        int index = 0;
        int size = ope.size();
        for(int i=0; i<size; i++)
        {
            int flag = ope[i][0];
            if(flag == 1) //�ж������
            {
                if(ope[i][i] > 0) //������
                {
                    dog.push(index++);//���ڱ�ʾʱ���
                    dog.push(ope[i][1]);
                }
                else
                {
                    cat.push(index++);
                    cat.push(ope[i][1]);
                }
            }
            else //��������
            {
                if(ope[i][1] == 0)//��һ��������ʽ
                {
                    int first = 0; //����ȡ�ߵ���è�����ǹ���1������-1����è
                    if(cat.empty()&&!dog.empty())
                    {
                        first = 1;
                    }
                    if(!cat.empty() && dog.empty())
                    {
                        first = -1;
                    }
                    if(!cat.empty() && !dog.empty())
                    {
                        if(dog.front() > cat.front())
                            first = -1;
                        else
                            first = 1;
                    }
                    if(first == 1) //ȡ�߹�
                    {
                        dog.pop();//����ʱ���
                        res.push_back(dog.front());//��ȡ�Ķ���
                        dog.pop();//�����Ѿ�����ȡ�Ķ���
                    }
                    if(first == -1)
                    {
                        cat.pop();
                        res.push_back(cat.front());
                        cat.pop();
                    }
                }
                else //�ڶ���������ʽ
                {
                    if(ope[i][1] == 1 && !dog.empty())
                    {
                        dog.pop();
                        res.push_back(dog.front());
                        dog.pop();
                    }
                    if(ope[i][1] == -1 && !cat.empty())
                    {
                        cat.pop();
                        res.push_back(cat.front());
                        cat.pop();
                    }
                }
            }
        }
        return res;
    }
};
