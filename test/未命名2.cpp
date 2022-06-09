#include <bits/stdc++.h>

using namespace std;

typedef struct bitnode
{
    struct bitnode *lchild;
    struct bitnode *rchild;
    int data;
} BiTNode,*BiTree;

void cengxubianli(BiTree bt)
{
    queue<BiTNode*> q;
    q.push(bt);
    int cnt=1;
    while(!q.empty())
    {
	if (q.front() == NULL) {
        	printf("%d ", -1);
        	q.pop();
        	continue;
		}
        q.push(q.front()->lchild);
        q.push(q.front()->rchild);
         printf("%d ",q.front()->data);
         q.pop();
    }
}

int main() {
	return 0;
}


