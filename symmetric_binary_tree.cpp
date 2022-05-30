#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define forn for (int i = 0; i < n; i++)
#define srt(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define kk '\n'
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        stack<TreeNode *> s;
        s.push(root->right);
        s.push(root->left);

        while (!s.empty())
        {
            TreeNode *n1 = s.top();
            s.pop();
            TreeNode *n2 = s.top();
            s.pop();

            if (n1 == NULL and n2 == NULL)
            {
                continue;
            }

            if (n1 == NULL or n2 == NULL or n1->val != n2->val)
            {
                return false;
            }

            s.push(n1->left);
            s.push(n2->right);

            s.push(n1->right);
            s.push(n2->left);
        }

        return true;
    }
};