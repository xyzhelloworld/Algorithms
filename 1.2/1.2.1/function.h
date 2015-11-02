
typedef struct btnode
{
    int data;
    struct btnode* left_child;
    struct btnode* right_child;
}binary_tree_node, *pbinary_tree_node;

pbinary_tree_node create_binary_tree();
void inorder_traversal(pbinary_tree_node node);
void tree_to_linklist(pbinary_tree_node current_node);
void print_linklist(pbinary_tree_node head);
