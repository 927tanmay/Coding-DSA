#include <bits/stdc++.h>

int isPairPresent(struct Node *root, int target)
{
    stack<Node *> s1, s2;
    Node *tmp1 = root;
    Node *tmp2 = root;

    while (1)
    {
        while (tmp1 != NULL)
        {
            s1.push(tmp1);
            tmp1 = tmp1->left;
        }

        while (tmp2 != NULL)
        {
            s2.push(tmp2);
            tmp2 = tmp2->right;
        }

        if (s1.empty() || s2.empty())
        {
            return 0;
            break;
        }
        int val1 = s1.top()->data;
        int val2 = s2.top()->data;

        if (val1 + val2 == target)
        {
            return 1;
            break;
        }

        if (val1 + val2 > target)
        {
            Node *x = s2.top();
            if (x->left)
                tmp2 = x->left;
            s2.pop();
        }
        else
        {
            Node *x = s1.top();
            if (x->right)
                tmp1 = x->right;
            s1.pop();
        }
    }
}