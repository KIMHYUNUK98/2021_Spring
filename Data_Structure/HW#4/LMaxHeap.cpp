void LMaxHeap::insert(Element item) {
    if(root != NULL) // root node가 아닌 경우 insert 함수 실행
        insert(item, root);
    else // root node 생성
    {
        root = new tree_node;
        root->key = item.key;
        root->data = item.data;
        root->left_child = root->right_child = root->parent = NULL;
    }
}

// child node에 insert & parent edge 연결 & compare 함수로 크기 순서대로 배열
void LMaxHeap::insert(Element item, tree_node *tree) {
    if(tree->left_child == NULL && tree->right_child == NULL) {
        tree->left_child = new tree_node;
        tree->left_child->key = item.key;
        tree->left_child->data = item.data;
        tree->left_child->left_child = NULL;
        tree->left_child->right_child = NULL;
        tree->left_child->parent = tree;
        compare(tree->left_child);
    }
    else if(tree->left_child != NULL && tree->right_child == NULL) {
        tree->right_child = new tree_node;
        tree->right_child->key = item.key;
        tree->right_child->data = item.data;
        tree->right_child->left_child = NULL;
        tree->right_child->right_child = NULL;
        tree->right_child->parent = tree;
        compare(tree->right_child);
    }
    else if(tree->left_child->left_child != NULL && tree->left_child->right_child != NULL && tree->right_child->right_child == NULL) 
        insert(item, tree->right_child);
    else
        insert(item, tree->left_child);
}

// root node가 아닐 때까지 child node부터 parent로 이동하면서 swap 기능을 구현
void LMaxHeap::compare(tree_node *node) {
    tree_node* Temp_node = node;
    int temp1;
    string temp2;
    //root node가 아니면서 child의 key가 parent의 key보다 더 크면 swap 해주는 알고리즘
    while(Temp_node->parent != NULL && Temp_node->key > Temp_node->parent->key) {
        temp1 = Temp_node->key;
        Temp_node->key = Temp_node->parent->key;
        Temp_node->parent->key = temp1;

        temp2 = Temp_node->data;
        Temp_node->data = Temp_node->parent->data;
        Temp_node->parent->data = temp2;

        Temp_node = Temp_node->parent;
    }
}

//deletion function call
Element LMaxHeap::deletion() {
    Element node;
    node = deletion(root);
    return node;
}

// root node의 값을 Element타입으로 반환 & last node 할당 해제
Element LMaxHeap::deletion(tree_node *node) {
    tree_node *delNode = NULL;
    Element temp;
    // 마지막 node를 delNode로 할당
    delNode = Search(root);
    
    //root node의 key값을 저장
    temp.key = node->key;
    temp.data = node->data;

    //root node에 마지막 node의 key, data 값을 넣어주기
    node->key = delNode->key;
    node->data = delNode->data;

    //마지막 node주변의 edge제거하기
    if(delNode->parent->right_child == delNode)
        delNode->parent->right_child = NULL;
    else 
        delNode->parent->left_child = NULL;

    //마지막 node 할당 해제
    free(delNode);

    Switch(node);

    return temp;
}

// deletion하고 크기 순서대로 switch 해주는 함수 구현
void LMaxHeap::Switch(tree_node *node) {
    int key;
    string data;
    tree_node* tempPointer = node;
    while(tempPointer->left_child != NULL) {
        if(tempPointer->left_child != NULL && tempPointer->right_child != NULL) {
            if(tempPointer->left_child->key > tempPointer->right_child->key && tempPointer->key < tempPointer->left_child->key) {
                key = tempPointer->key;
                tempPointer->key = tempPointer->left_child->key;
                tempPointer->left_child->key = key;

                data = tempPointer->data;
                tempPointer->data = tempPointer->left_child->data;
                tempPointer->left_child->data = data;

                tempPointer = tempPointer->left_child;
            }
            else if(tempPointer->left_child->key < tempPointer->right_child->key && tempPointer->key < tempPointer->right_child->key) {
                key = tempPointer->key;
                tempPointer->key = tempPointer->right_child->key;
                tempPointer->right_child->key = key;

                data = tempPointer->data;
                tempPointer->data = tempPointer->right_child->data;
                tempPointer->right_child->data = data;

                tempPointer = tempPointer->right_child;
            }
        }
        else if(tempPointer->left_child != NULL && tempPointer->right_child == NULL) {
            if(tempPointer->left_child->key > tempPointer->key) {
                key = tempPointer->key;
                tempPointer->key = tempPointer->left_child->key;
                tempPointer->left_child->key = key;

                data = tempPointer->data;
                tempPointer->data = tempPointer->left_child->data;
                tempPointer->left_child->data = data;

                tempPointer = tempPointer->left_child;
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }
}

//제일 마지막 node 찾아서 return 해주는 함수
tree_node* LMaxHeap::Search(tree_node *node) {
    if(node->left_child == NULL && node->right_child == NULL)
        return node;
    else if(node->left_child != NULL && node->right_child == NULL)
        return node->left_child;
    else if(node->left_child->right_child != NULL && node->right_child->left_child != NULL && node->left_child->left_child->left_child == NULL
        || node->left_child->left_child == NULL && node->left_child->right_child == NULL && node->right_child->left_child == NULL && node->right_child->right_child == NULL)
        return Search(node->right_child);
    else 
        return Search(node->left_child);
}

//preorder print function call
void LMaxHeap::Print() {
    print_preorder(root);
}

// preorder로 print해주는 function
void LMaxHeap::print_preorder(tree_node *node) {
    if(node)
    {
        cout << "[" << node->key << " " << node->data << "]";
        print_preorder(node->left_child);
        print_preorder(node->right_child);
    }
}