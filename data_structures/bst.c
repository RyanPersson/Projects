#include <stdlib.h>

#include "bst.h"
#include <stdio.h>

/*bst node*/
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};

/* bst tree, contains pointer to root. */
struct bst {
  struct bst_node* root;
};

void node_free(struct bst_node*);
int node_size(struct bst_node*);
struct bst_node* create_node(int, void*);
void node_insert(struct bst_node*, int, void*);
struct bst_node* node_search(struct bst_node*,int);
struct bst_node* node_remove(struct bst_node*,int);

/*creates an empty bst, root=NULL*/
struct bst* bst_create() {
  struct bst* new_bst = malloc(sizeof(struct bst));
  new_bst->root = NULL;
  return new_bst;
}

/*frees a bst*/
void bst_free(struct bst* bst) {
  if(bst->root) {
    node_free(bst->root);
  }
  free(bst);
  return;
}

/* This function makes it easy to recursively free the bst node by node */
void node_free(struct bst_node* node) {
  if(node->left){
    node_free(node->left);
  }
  if(node->right) {
    node_free(node->right);
  }
  free(node);
 
  return;
}

/*counts the elements in a bst*/
int bst_size(struct bst* bst) {
  return node_size(bst->root);
}

/* Function created so I can access it recursively */
int node_size(struct bst_node* node) {
  int count = 0;
  if(node) {
    count++;
  }
  if(!node) {
    return count;
  }
  if(node->left) {
    count += node_size(node->left);
  }
  if(node->right) {
    count += node_size(node->right);
  }
  return count;
}

/*Inserts a new element into a bst*/
void bst_insert(struct bst* bst, int key, void* value) {
  if(bst->root == NULL) {
    bst->root = create_node(key, value);
  }
  node_insert(bst->root, key, value);
  return;
}

/*Recurseve insert function which takes in and returns bst_nodes*/
void node_insert(struct bst_node* current_node, int key, void* value) {
  if(key < current_node->key) {
    if(current_node->left) {
      node_insert(current_node->left, key, value);
    }
    else {
      current_node->left = create_node(key, value);
    }
  }
  else if(key > current_node->key) {
    if(current_node->right) {
      node_insert(current_node->right, key, value);
    }
    else {
      current_node->right = create_node(key, value);
    }  
  }
  else  { /*key repeated. overwirte value */
    current_node->value = value;
  }
}

/* creates node */
struct bst_node* create_node(int new_key, void* new_value) {
  struct bst_node* new_node = malloc(sizeof(struct bst_node));
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->value = new_value;
  new_node->key = new_key;
  return new_node;
}

/* bst search */ 
struct bst_node* node_search(struct bst_node* current, int key) {
  if(!current) {
    return NULL;
  }
  else if(current->key == key){
    return current;
  }
  else if(key < current->key) {
    return node_search(current->left, key);
  }
  else if(key > current->key) {
    return node_search(current->right, key);
  }
}

/*removes an element from the bst */
void bst_remove(struct bst* bst, int key) {
  if(bst->root) {
    bst->root = node_remove(bst->root, key);
  }
  return;
}

struct bst_node* node_remove(struct bst_node* root, int key)
{
    // base case
    if(root == NULL)
    {
        return NULL;
    }
    
    // search in the left-subtree
    else if(root->key > key)
    {
        root->left = node_remove(root->left, key);
    }
    
    // search in the right-subtree
    else if(root->key < key)
    {
        root->right = node_remove(root->right, key);
    }
    
    // find the right node
    else
    {
        // node has no child nodes
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return NULL;
        }
        
        // node has only left-subtree
        else if(root->left != NULL && root->right == NULL)
        {
            struct bst_node * temp = root->left;
            free(root);
            root = NULL;
            return temp;
        }
        
        // node has only right-subtree
        else if(root->left == NULL && root->right != NULL)
        {
            struct bst_node * temp = root->right;
            free(root);
            root = NULL;
            return temp;
        }
        
        // node has two child nodes
        else
        {
            struct bst_node * temp = root->right;
            while(temp->left) {
              temp = temp->left;
            }
            root->key = temp->key;
            root->value = temp->value;
            root->right = node_remove(root->right, root->key);
        }
    }
    return root;
}

/*returns an element in a bst*/
void* bst_get(struct bst* bst, int key) {
  struct bst_node* node = node_search(bst->root, key);
  if(!node) {
    return NULL;
  }
  return node->value;
}