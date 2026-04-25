//Shriyans Singh 114807762
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
    res_mat->name='?';
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
    res_mat->name='?';
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
    res_mat->name='?';
    res_mat->num_rows=num_rows;
    res_mat->num_cols=num_cols;

    //Loop through all elements in order to fill the res  matrix. Use of unsigned int in loops to prevent compiler complants.
    for (unsigned int i =0;i<num_rows;i++){
        for (unsigned int j=0;j<num_cols;j++){
            unsigned int x=(num_cols*i)+j;
            unsigned int y=(num_rows*j)+i;
            res_mat->values[x]=(mat->values[y]);
        }
    }
    return res_mat;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    unsigned int num_cols;
    unsigned int num_rows;
    //get dimensions through sscanf
    sscanf(expr,"%u %u",&num_rows,&num_cols);
    matrix_sf *res_mat= malloc(sizeof(matrix_sf)+(num_rows*num_cols*sizeof(int)));
    if((res_mat)==NULL){
        return NULL;
    }
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
            //store amount of char used, and moves pointer by that
            sscanf(ptr,"%d%n",&pos,&new_chars);
            res_mat->values[i*num_cols+j]=pos;
            ptr+=new_chars;
            
        }
    }
    return res_mat;
}

//Helpers for infix2postfix_sf
typedef struct{
    //char storage
    char stor[SIZE];
    int up;
}stack;
//push to stack
void push(stack *s,char c){
    s->stor[++s->up]=c;
}
//pop and reutrn top char
char pop(stack *s){
    return (s->stor[s->up--]);
}
//returns top char
char peek(stack *s){
    return (s->stor[s->up]);
}
//boolean to check if true or false (1==empty,0==notempty)
int is_empty(stack *s){
    return (s->up==-1);
}
//precende of operators 
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
    stack s;
    s.up=-1;
    char *res=malloc(strlen(infix)+1);
    int index=0;
    for(int i=0;(infix[i]!='\0');i++){
        char c=infix[i];
        if(c== ' '){
            continue; //Skip if space
        }
        //if it is a matrix name it goes to the ooutput directly
        else if (isupper(c)){
            res[index++]=c;
        }
        //if its a slash it goes straight to output, not sure about the 2 ' after the \ but vscode is companning
        else if(c=='\''){
            res[index++]=c;
        }
        else if(c=='('){
            push(&s,c);
        }
        else if (c==')'){
            //check the top of stack to be (, if it isnt then pop the char to res. Once it is (. just discard it.
            while(peek(&s)!='('){
                res[index++]=pop(&s);
            }
            
            pop(&s);

        }
        // before pushing char pop that which has greater than or = precednce.
        else if(c=='+'){
            while(!is_empty(&s)&&(peek(&s)!='(')&&(prec(peek(&s))>=prec(c))){
                res[index++]=pop(&s);
            }
            push(&s,c);
        }
        else if (c=='*'){
            while(!is_empty(&s)&&(peek(&s)!='(')&&(prec(peek(&s))>=prec(c))){
                res[index++]=pop(&s);
            }
            push(&s,c);
        }
        
    }
    //put all that is left in stack to the output
    while(!is_empty(&s)){
        res[index++]=pop(&s);
    }
    res[index]='\0';

    return res;
}

//evaluate structure
typedef struct{
    matrix_sf *arr[SIZE];
    int up;
}Stack;


//helper for evaluate_expr_sf
//push matrix into stack
void m_pusher(Stack *s, matrix_sf *m){
    s->arr[++s->up]=m;
}
//pop matrix from stack
matrix_sf* m_pop(Stack *s){
    return s->arr[s->up--];
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    //convert to postfix format and initialize empty stack
    char *post_format=infix2postfix_sf(expr);
    Stack s;
    //-1 means empty stack
    s.up=-1;
    //processing char until null terminator
    for(int i=0;post_format[i]!='\0';i++){
        char c=post_format[i];
        //If P is there, push else if its transpose, push pop top element, create new matrix, and push new matrix into stack, else if * or +, pop top 2, create new matrix with sum, push into stack
        if(isupper(c)){
            //using pointer from bst push matrix to stack
            m_pusher(&s,find_bst_sf(c,root));
        }
        else if (c=='\''){
            matrix_sf *first=m_pop(&s);
            matrix_sf *res=transpose_mat_sf(first);
            //remove ? matrix since they are temp
            if(!isupper(first->name)){
                free(first);
            }
            m_pusher(&s,res);
        }
        else if(c=='*'){
            //pop right, then left, multiply, then free the old mats and push new mat to s
            matrix_sf *mat2=m_pop(&s);
            matrix_sf *mat1=m_pop(&s);
            matrix_sf *res=mult_mats_sf(mat1,mat2);
            if(!isupper(mat1->name)){
                free(mat1);
            }
            if(!isupper(mat2->name)){
                free(mat2);
            }
            m_pusher(&s,res);
        }
        //same as * but with add instead of mult
        else if(c=='+'){
            //pop right, then left, multiply, then free the old mats and push new mat to s
            matrix_sf *mat2=m_pop(&s);
            matrix_sf *mat1=m_pop(&s);
            matrix_sf *res=add_mats_sf(mat1,mat2);
            if(!isupper(mat1->name)){
                free(mat1);
            }
            if(!isupper(mat2->name)){
                free(mat2);
            }
            m_pusher(&s,res);
        }
    }
    matrix_sf *res =m_pop(&s);
    res->name=name;
    free(post_format);
    return res;
}






//Takes name of filename, 
matrix_sf *execute_script_sf(char *filename) {
    FILE *file=fopen(filename,"r");
    char *line=NULL;
    
    size_t size=MAX_LINE_LEN;
    bst_sf *bst_exec=NULL;
    matrix_sf *res =NULL;

    //loop through lines to get instructions and names
    while(getline(&line,&size,file)!=-1){
        //first char = matrix name, advance pointer past any spaces or =
        char name=line[0];
        char *p=(strchr(line,'=')+ 1);
        while((*p == ' ')){
            p++;
        }
        matrix_sf *evalu;
        //if digit is first valid char, create matrix based on value
        if (*p<='9'&&*p>='0'){
            evalu=create_matrix_sf(name,p);
        }
        //must use bst, and its a formula to evaluate
        else{
            evalu=evaluate_expr_sf(name,p,bst_exec);
        }
        //insert new matrice into BST and then update res to most uptodate matrix
        bst_exec=insert_bst_sf(evalu,bst_exec);
        res=evalu;
    }
    matrix_sf *val_to_return=copy_matrix(res->num_rows,res->num_cols,res->values);
    val_to_return-> name=res->name;
    //free memory (buffer of getline, BST, matrices inside)
    free(line);
    fclose(file);
    free_bst_sf(bst_exec);
    return val_to_return;
   
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
