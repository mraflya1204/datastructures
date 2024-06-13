// ========[AVL Tree]======== //
/*
    Dibuat dan ditulis oleh ABDUR ROCHMAN
    28-03-2020
    Struktur Data 2020
    For C
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int maxHeight = -1;
int maxRow = -1;
int minRow = 0;
int tempRow = 0;
char Alphabet = 'A';
int countPrint = 1;
char region[100];

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
    int row;
    int power;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(int value, int power) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->power = power;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value, int power) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value, power);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value, power);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value, power);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data) // 
		return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node,int value){
    if(node==NULL)
        return node;
    if(value > node->data)
    	node->right=_remove_AVL(node->right,value);
    else if(value < node->data)
    	node->left=_remove_AVL(node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->data=temp->data;
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

	if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value, int power){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value, power);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

void preorder(AVLNode *root, int height) {
    if (root) {
        if (height == root->row) {
            if(height == 0){
                printf("Final Boss %s_%d: %d\n", region, root->data, root->power);
            }
            else{
                printf("Monster %c%d_%d_%d: %d\n", Alphabet, root->data, maxRow - root->row + 1, countPrint, root->power);
                Alphabet++; countPrint++;
            }
        }
        preorder(root->left, height);
        preorder(root->right, height);
    }
}


void find_max_height(AVLNode *root) {
    if (root) {
        find_max_height(root->left);
        if(root->height > maxHeight){
            maxHeight = root->height;
        }
        find_max_height(root->right);
    }
}

void rowMarker(AVLNode* root, int inputRow) {
    if (root) {
        root->row = inputRow;

        if (inputRow >= maxRow) {
            maxRow = inputRow;
        }
        if (inputRow <= minRow) {
            minRow = inputRow;
        }

        rowMarker(root->left, inputRow + 1);
        rowMarker(root->right, inputRow + 1);
    }
}

void rowFinder(AVLNode* root, int targetRow) {
    if (root) {
        if (root->row == targetRow) {
            tempRow += root->power;
        }
        rowFinder(root->left, targetRow);
        rowFinder(root->right, targetRow);
    }
}


int main(){
    char name[100]; scanf("%s ", name);
    int N; scanf("%d ", &N);
    char element[100]; scanf("%s ", element);
    int trailblazerPower; scanf("%d ", &trailblazerPower);
    scanf("%s ", region);

    printf("*****************************************************************************");
    printf("\n");
    printf("Honkai Star Rail Region %s\n\n", region);
    printf("Trailblazer : %s\n", name);
    printf("Element : %s - %d\n", element, trailblazerPower);
    printf("----------------------------------------------------------------------------");
    printf("\n");
    
    AVL myAVL; avl_init(&myAVL);
    
    for(int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        int z; scanf("%d", &z);
        avl_insert(&myAVL, x, z);
    }
    
    find_max_height(myAVL._root);
    rowMarker(myAVL._root, 0);
    
    
    int stageCount = 1;
    for (int i = maxRow; i >= 0; i--){
        Alphabet = 'A';
        countPrint = 1;
        if(i == 0){
            printf("Final Stage:\n");
        }
        else{
            printf("Stage %d:\n", stageCount);
        }

        preorder(myAVL._root, i);
        printf("\n");
        stageCount++;
    }
    
    stageCount = 1;
    int flag = 1;
    for(int i = maxRow; i >= 0; i--){
        rowFinder(myAVL._root, i);

        if(trailblazerPower % 2 == 0){
            trailblazerPower = trailblazerPower * 1.08;
        }
        else{
            trailblazerPower = trailblazerPower * 1.15;
        }
        
        if(trailblazerPower >= tempRow){
            trailblazerPower = trailblazerPower - tempRow;
            flag = 1;
        }
        else{
            if(i == 0){
                flag = 0;
                printf("Result:\n%s kalah dan mati di Region %s pada Final Stage\n", name, region);
                break;
            }
            else{
                flag = 0;
                printf("Result:\n%s kalah dan mati di Region %s pada Stage %d\n", name, region, stageCount);
                break;
            }
            
        }
        stageCount++;
        tempRow = 0;
    }
    
    if(flag == 1){
        printf("Result:\n%s menang melawan Final Boss dan memenangkan game di Honkai Star Rail Region %s\n", name, region);
    }
    printf("*****************************************************************************");
    
    return 0;
}