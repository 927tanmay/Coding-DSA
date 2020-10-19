int it = 0;
void serialize(Node *root, vector<int> &A)
{
    it = 0;
    if (root == NULL)
    {
        A.push_back(-1);
        return;
    }

    A.push_back(root->data);

    serialize(root->left, A);
    serialize(root->right, A);
}

/*this function deserializes
 the serialized vector A*/

Node *deSerialize(vector<int> &A)
{
    if (it >= A.size() || A[it] == -1)
    {
        it++;
        return NULL;
    }

    Node *tmp = new Node(A[it]);
    it++;
    tmp->left = deSerialize(A);
    tmp->right = deSerialize(A);

    return tmp;
}