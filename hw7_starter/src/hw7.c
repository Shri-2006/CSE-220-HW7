#include "hw7.h"
#define SIZE 300

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    if(root==NULL){
        //insertt new node
        bst_sf *node=malloc(sizeof(bst_sf));
        node-> mat =mat;
        node->left_child=NULL;
        node->right_child=NULL;
        return node;
    }
    //if there is no leaf child at the node, create a left leaf. else create right leaf
    else if (mat->name< (root->mat->name)){
        root->left_child=insert_bst_sf(mat,(root->left_child));
    }
    else{
        root ->right_child=insert_bst_sf(mat,(root->right_child));
    }
    return root;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
    //if no root, return null. if name is the node, return node. else if name is less than node, go left. else go right
    if(root==NULL){
        return NULL;
    }
    else if (name==root->mat->name){
        return root->mat;
    }
    else if (name<root->mat->name){
        return (find_bst_sf(name, (root->left_child)));
    }
    else{
        return(find_bst_sf(name, (root->right_child)));
    }
   
}

void free_bst_sf(bst_sf *root) {
    //base case to stop when everything is freed
    if(root==NULL){
        return;
    }
    //free left child, thhen free right child, then free node, thhen free root.
    free_bst_sf(root->left_child);
    free_bst_sf(root->right_child);
    free(root->mat);
    free(root);

}

//Matrix Addition of Matrices of same size
matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    //setting up column pointers, unsigned int used to adjust per system
    unsigned int num_cols=mat1->num_cols;
    unsigned int num_rows=mat1->num_rows;
    
    //allocate memory to res_mat so it can handle the new array - took alot of time figuing out the malloc writing
    matrix_sf *res_mat= malloc(sizeof(matrix_sf)+(num_rows*num_cols*sizeof(int)));
    //name is needed from create matrice sf
    res_mat->name=name;
    res_mat->num_rows=num_rows;
    res_mat->num_cols=num_cols;
    //Loop through all elements in order to fill the res  matrix. Use of unsigned int in loops to prevent compiler complants.
    for (unsigned int i =0;i<num_rows;i++){
        for (unsigned int j=0;j<num_cols;j++){
            unsigned int x=(num_cols*i)+j;
            res_mat->values[x]=(mat1->values[x])+(mat2->values[x]);
        }
    }
    return res_mat;
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
   //setting up column pointers, unsigned int used to adjust per system
    unsigned int num_cols=mat2->num_cols;
    unsigned int num_rows=mat1->num_rows;
    
    //allocate memory to res_mat so it can handle the new array - took alot of time figuing out the malloc writing
    matrix_sf *res_mat= malloc(sizeof(matrix_sf)+(num_rows*num_cols*sizeof(int)));
    //name is needed from create matrice sf
    res_mat->name=name;
    res_mat->num_rows=num_rows;
    res_mat->num_cols=num_cols;
    //Loop through all elements in order to fill the res  matrix. Use of unsigned int in loops to prevent compiler complants.
    for (unsigned int i =0;i<num_rows;i++){
        for (unsigned int j=0;j<num_cols;j++){
            //initialize, then multiply and add for each k
            res_mat->values[i*num_cols+j]=0;
            for(unsigned int k=0;k<(mat1->num_cols);k++){
                int val1= mat1->values[i*mat1->num_cols+k];
                int val2=mat2 ->values[num_cols*k+j];
                res_mat->values[i*num_cols+j]+=(val1)*(val2);
            }
            
        }
    }
    return res_mat;
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {
    //setting up column pointers, unsigned int used to adjust per system
    unsigned int num_cols=mat->num_rows;
    unsigned int num_rows=mat->num_cols;
    
    //allocate memory to res_mat so it can handle the new array - took alot of time figuing out the malloc writing
    matrix_sf *res_mat= malloc(sizeof(matrix_sf)+(num_rows*num_cols*sizeof(int)));
    //name is needed from create matrice sf
    res_mat->name=name;
    res_mat->num_rows=num_rows;
    res_mat->num_cols=num_cols;

    //Loop through all elements in order to fill the res  matrix. Use of unsigned int in loops to prevent compiler complants.
    for (unsigned int i =0;i<num_rows;i++){
        for (unsigned int j=0;j<num_cols;j++){
            unsigned int x=(num_cols*j)+i;
            unsigned int y=(num_rows*i)+j;
            res_mat->values[x]=(mat->values[y]);
        }
    }
    return res_mat;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    unsigned int num_cols;
    unsigned int num_rows;
    sscanf(expr,"%u %u",&num_rows,&num_cols);
    matrix_sf *res_mat= malloc(sizeof(matrix_sf)+(num_rows*num_cols*sizeof(int)));
    res_mat->name=name;
    res_mat->num_rows=num_rows;
    res_mat->num_cols=num_cols;

    //skip the [ to start matrix
    const char *ptr=strchr(expr,'[')+1;
    for(unsigned int i=0;i<num_rows;i++){
        for(unsigned int j=0;j<num_cols;j++){
            //While space or semi skip, else add to matrice (assuming all inputs are valid)
            while((*ptr==' '|| *ptr==';')==1){
                ptr++;
            }
            int pos;
            int new_chars;
            sscanf(ptr,"%d%n",&pos,&new_chars);
            res_mat->values[i*num_cols+j]=pos;
            ptr+=new_chars;
            
        }
    }
    return res_mat;
}

//Helpers for infix2postfix_sf
typedef struct{
    char data[SIZE];
    int up;
}stack;

void push(stack *s,char c){
    s->data[++s->up]=c;
}
char pop(stack *s){
    return (s->data[s->up--]);
}
char peek(stack *s){
    return (s->data[s->up]);
}
int is_empty(stack *s){
    return (s->up==-1);
}

int prec(char c){
    if(c=='+'){
        return 1;
    }
    else if (c=='*'){
        return 2;
    }
    else{
        return 0;
    }
}


char* infix2postfix_sf(char *infix) {
    res=malloc(strlen(infix)+1);


    return res;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    return NULL;
}

matrix_sf *execute_script_sf(char *filename) {
   return NULL;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}
