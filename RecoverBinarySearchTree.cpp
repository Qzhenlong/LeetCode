#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

������
������������Ԫ��λ�ñ�Ū���ˣ��ڲ��ı���ṹ������»�ԭ�������ռ临�Ӷ�ΪO(n)�Ľⷨ���ѣ��ܷ�ʵ�ֿռ临�Ӷ�ΪO(1)�Ľⷨ

˼·��
��1���������BST���ҳ������ǵ�����㽻���������ֵ, ʹ���˵ݹ飬���Կռ�ΪO(n)
��2��Morris inorder traversal. O(1) space. with only auxiliary two pointers��                                                                                                                                                            ���ĵ�ַ

//��Ϊֻ���������ֵ�����ˣ���ô�ж϶������Ƿ���ȷ��ֻ��Ҫ�۲�ǰ����������ȡֵ�����ˣ���ô�Ͳο�����������˼·

1. �����ǰ�ڵ��������Ϊ�գ���Աȵ�ǰ�����ǰ������ֵ��������ͼ�¼������ Ȼ�������������

2. �����ǰ�ڵ�����Ӳ�Ϊ�գ��������������������������ҷ�������ָ��ָ�������������еĺ�̽�㡣
   
   ��������ɺ󣬼�������ǰ�������Ϊ��ǰ�������㣬������1����ֱ�����ֵ�ǰ���Ϊ������ĳһ�����ҽ�㣬������ȷ���жϣ�ȥ����������
   
   ����ԭ�������ҽ�㶼�ѱ��������ˣ���ô�����ֵ�ǰ������������ĳһ�����ҽ��ʱ��˵���Ǹ������������������һ�����ʹ��Ľ�㣬��ǰ��������̣�
   
   ��Ȼ�Ϳ��Լ����ж�����������Ƿ�����
3. ֱ����ǰ���Ϊ�գ�������������ѭ����

�ο���������Mirror�����㷨��

   */
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode *pre;
    void recoverTree(TreeNode* root) {
        TreeNode *ma = NULL, *mb = NULL, *next = NULL;
		pre = NULL;
		InTra(root, ma, mb, next);
		if(ma != NULL){
			if(mb == NULL) mb = next;
			int tmp = ma->val;
			ma->val = mb->val;
			mb->val = tmp;
		}
    }
	void InTra(TreeNode *b, TreeNode *&ma, TreeNode *&mb, TreeNode *&next){
		if(b != NULL){
			InTra(b->left, ma, mb, next);	
			if(pre != NULL && pre->val > b->val){
				if(ma == NULL){
					ma = pre;
					next = b;
				}
				else mb = b;
			}
			pre = b;
			InTra(b->right, ma, mb, next);
		}
	}
   //Mirror���������Դ�ڣ�https://github.com/leetcoders/LeetCode/blob/master/RecoverBinarySearchTree.h�� �Լ�������һ��
    void _recoverTree(TreeNode *root) {
        TreeNode *cur = root, *prev = NULL;
        TreeNode *first = NULL, *second = NULL, *last = NULL;
        while (cur != NULL)
        {
            if (cur->left == NULL)   //�����ǰ����������Ϊ�գ���ǰ�������һ���������������Ϊǰ���ϵ����ǰ���ֵӦ��С����һ�ڵ�ֵ
            {
                compare(last, cur, first, second); //�Ա���һ����㣬�뵱ǰ����ȡֵ�� first��¼��һ��㣬second��¼��ǰ��㣬��������޴����㣬�򽻻����������ֵ
                last = cur;        //��¼��ǰ���
                cur = cur->right;  //�������������͵�ǰ��㣬��������
            }
            else //��ǰ�����������Ϊ�գ���ô�������������в����������������е�ǰ����㣬����ǰ�ڵ�������������ҽڵ�
            {
                prev = cur->left;  //��¼��ǰ��������
                while (prev->right != NULL && prev->right != cur) //�������������Ϊ�գ���һֱ�ҵ������½�
                    prev = prev->right;

                if (prev->right == NULL) //�ҵ������½�Ԫ��
                {
                    prev->right = cur; //�����������������뷨����û�õ�ָ��ָ�������������еĺ�̽��
                    cur = cur->left; //��ǰ���ָ������
                }
                else //���ǰ�������ҽ�㲻Ϊ�գ�˵����ָ�������̽�㣬�ҵ��ˣ����������ж���
                {
                    compare(last, cur, first, second); //�ж�ǰ����������Ƿ����������������¼����
                    last = cur;                        //������һ���
                    prev->right = NULL;                //�ָ���ԭ�нṹ��ȥ��������
                    cur = cur->right;                 //���Լ���������������
                }
            }
        }
        swap(first->val, second->val);  //�������ֵ
    }

    void compare(TreeNode *last, TreeNode *cur, TreeNode *&first, TreeNode *&second)
    {
        if (last && last->val > cur->val)
        {
            if (!first)
                first = last;
            second = cur;
        }
    }
	void InPrint(TreeNode *b){
		if(b != NULL){
			InPrint(b->left);
			cout << b->val << " ";
			InPrint(b->right);
		}
	}
};

int main(){
	Solution c;
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	/*root->right = new TreeNode(8);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(7);
*/
	c.InPrint(root);
	cout << endl;
	c._recoverTree(root);
	cout << endl;
	c.InPrint(root);
	return 0;
}


