#include <iostream>
#include <queue>
using namespace std;

struct binTreeNode
{
  char data;
  binTreeNode *left;
  binTreeNode *right;
  
  binTreeNode(char &c):data(c),left(NULL),right(NULL)
  {}
};


class bintree
{
private:
    binTreeNode *root;
public:
    bintree(char *s)
    {
        int i = 0;
        buyNode(root,s,i);
    }
protected:
    void buyNode(binTreeNode *T, char *s,int & i)
    {
	  if(s[i]=='\0')return;
        if(s[i] == '#')
        {
            T = NULL;
            return;
        }
        T = new binTreeNode(s[i]);
        buyNode(T->left,s,++i);
        buyNode(T->right,s,++i);
        
    }
public:
    void cengciorder()
    {
        queue<binTreeNode*> sbt;
        if(root)
        {
            sbt.push(root);
            binTreeNode* cur;
            while(!sbt.empty())
            {   
                cur = sbt.front();
                cout<<cur->data<<" ";
                sbt.pop();
                if(cur->left !=NULL)
                sbt.push(cur->left);
                if(cur->right != NULL)
                sbt.push(cur->right);
            }
    	}
    }
};

int main()
{
    char s[] = "ab#c##de##f##";
    bintree a(s);
   // a.cengciorder();
}

