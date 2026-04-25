#include "unit_tests.h"

TestSuite(student_tests, .timeout=TEST_TIMEOUT);

//I don't know why it wasn't taking it from unit_test.c so i just added it here. then it started causing compiler error so i made it private (check readme for info for where i learned to do that)
static bst_sf* build_bst() {
    matrix_sf *A = copy_matrix(3, 5, (int[]){-4, 18, 6, 7, 10, -14, 29, 8, 21, -99, 0, 7, 5, 2, -9});
    A->name = 'A';
    matrix_sf *B = copy_matrix(3, 5, (int[]){10, 9, -2, -33, 22, 44, 10, 12, 72, 52, -88, 17, 16, 14, -9});
    B->name = 'B';
    matrix_sf *C = copy_matrix(1, 4, (int[]){-123, 47, -4, 140});  
    C->name = 'C';
    matrix_sf *D = copy_matrix(1, 4, (int[]){-16, 122, 135, 107});
    D->name = 'D';
    matrix_sf *E = copy_matrix(6, 4, (int[]){83, -22, 56, -1, 97, 94, 135, -10, 84, 40, -83, -4, 79, 28, 52, -101, 138, 146, 99, 0, -23, -73, -39, -47});
    E->name = 'E';
    matrix_sf *F = copy_matrix(4, 7, (int[]){-77, -20, 111, -2, 41, 117, 118, 21, -29, -45, 135, 98, 54, 131, 54, 1, 80, 143, -127, 148, 114, -81, 87, -33, -2, -6, 115, 59});
    F->name = 'F';
    matrix_sf *G = copy_matrix(7, 1, (int[]){-38, 4, 46, -14, -102, -72, -27});
    G->name = 'G';
    matrix_sf *H = copy_matrix(1, 5, (int[]){52, 65, -94, -73, -48});
    H->name = 'H';
    matrix_sf *I = copy_matrix(4, 4, (int[]){-7, 78, -87, -113, -144, -94, 22, -75, -137, -130, -113, -106, 85, -120, 50, 55});
    I->name = 'I';
    matrix_sf *J = copy_matrix(6, 3, (int[]){121, -1, 128, 78, -138, 138, -61, 51, -35, -84, 125, -83, -78, 138, 2, 81, -5, -36});
    J->name = 'J';
    bst_sf* Anode = malloc(sizeof(bst_sf));
    Anode->mat = A;
    Anode->left_child = NULL;
    Anode->right_child = NULL;
    bst_sf* Cnode = malloc(sizeof(bst_sf));
    Cnode->mat = C;
    Cnode->left_child = NULL;
    Cnode->right_child = NULL;
    bst_sf* Hnode = malloc(sizeof(bst_sf));
    Hnode->mat = H;
    Hnode->left_child = NULL;
    Hnode->right_child = NULL;
    bst_sf* Jnode = malloc(sizeof(bst_sf));
    Jnode->mat = J;
    Jnode->left_child = NULL;
    Jnode->right_child = NULL;
    bst_sf* Bnode = malloc(sizeof(bst_sf));
    Bnode->mat = B;
    Bnode->left_child = Anode;
    Bnode->right_child = Cnode;
    bst_sf* Fnode = malloc(sizeof(bst_sf));
    Fnode->mat = F;
    Fnode->left_child = NULL;
    Fnode->right_child = NULL;
    bst_sf* Inode = malloc(sizeof(bst_sf));
    Inode->mat = I;
    Inode->left_child = Hnode;
    Inode->right_child = Jnode;
    bst_sf* Dnode = malloc(sizeof(bst_sf));
    Dnode->mat = D;
    Dnode->left_child = Bnode;
    Dnode->right_child = NULL;
    bst_sf* Gnode = malloc(sizeof(bst_sf));
    Gnode->mat = G;
    Gnode->left_child = Fnode;
    Gnode->right_child = Inode;
    bst_sf* Enode = malloc(sizeof(bst_sf));
    Enode->mat = E;
    Enode->left_child = Dnode;
    Enode->right_child = Gnode;
    return Enode;
}

//add_mat_sf tests 

//normal 2x2 matrice to check if it actually compiles and calculates

Test(student_tests, add_test_normal_mat){
    matrix_sf *A=copy_matrix(2,2,(int[]){1,2,3,4});
    matrix_sf *B=copy_matrix(2,2,(int[]){4,3,2,1});
    matrix_sf *C=add_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,2,2,(int[]){5,5,5,5});
    free(C);
}   

//subracting using add_mat
Test(student_tests,subtraction_of_2by2){
    matrix_sf *A=copy_matrix(2,2,(int[]){1,-2,-3,-4});
    matrix_sf *B=copy_matrix(2,2,(int[]){0,2,3,4});
    matrix_sf *C=add_mats_sf(A,B);
    expect_matrices_equal(C,2,2,(int[]){1,0,0,0});
    free(A);
    free(B);
    free(C);
}

//1 by 1 matrices adding
Test(student_tests,adding_1by1s){
    matrix_sf *A=copy_matrix(1,1,(int[]){1});
    matrix_sf *B=copy_matrix(1,1,(int[]){2});
    matrix_sf *C=add_mats_sf(A,B);
    expect_matrices_equal(C,1,1,(int[]){3});
    free(A);
    free(B);
    free(C);
}

//zero matrice addition to non zero matrice

Test(student_tests,zero_mat_to_non_zero_mat_add){
    matrix_sf *A=copy_matrix(2,2,(int[]){1,-2,-3,-4});
    matrix_sf *B=copy_matrix(2,2,(int[]){0,0,0,0});
    matrix_sf *C=add_mats_sf(A,B);
    expect_matrices_equal(C,2,2,(int[]){1,-2,-3,-4});
    free(A);
    free(B);
    free(C);
}
//rowlong matrix instead of square test
Test(student_tests,long_row_mat_add){
    matrix_sf *A=copy_matrix(1,3,(int[]){1,2,3});
    matrix_sf *B=copy_matrix(1,3,(int[]){2,3,1});
    matrix_sf *C=add_mats_sf(A,B);
    expect_matrices_equal(C,1,3,(int[]){3,5,4});
    free(A);
    free(B);
    free(C);
}
//Column long matrix instead of square

Test(student_tests,long_col_mat_add){
    matrix_sf *A=copy_matrix(3,1,(int[]){2,11,4});
    matrix_sf *B=copy_matrix(3,1,(int[]){2,1,5});
    matrix_sf *C=add_mats_sf(A,B);
    expect_matrices_equal(C,3,1,(int[]){4,12,9});
    free(A);
    free(B);
    free(C);
}


//mult_mat_sf

//check of normal 2by2 multiplication
Test(student_tests, mult_test_normal_mat){
    matrix_sf *A=copy_matrix(2,2,(int[]){1,2,3,4});
    matrix_sf *B=copy_matrix(2,2,(int[]){4,3,2,1});
    matrix_sf *C=mult_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,2,2,(int[]){8,5,20,13});
    free(C);
}   

//dot mult matrice

Test(student_tests, mult_test_dot_mat){
    matrix_sf *A=copy_matrix(1,3,(int[]){1,2,3});
    matrix_sf *B=copy_matrix(3,1,(int[]){4,3,2});
    matrix_sf *C=mult_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,1,1,(int[]){16});
    free(C);
}   

//0 mat multiplication  
Test(student_tests, mult_test_zero_mat){
    matrix_sf *A=copy_matrix(1,3,(int[]){0,0,0});
    matrix_sf *B=copy_matrix(3,1,(int[]){4,3,2});
    matrix_sf *C=mult_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,1,1,(int[]){0});
    free(C);
}   

//nonsquare mat mult check that isnt a dot

Test(student_tests, mult_test_nonsqurare_mat){
    matrix_sf *A=copy_matrix(2,3,(int[]){1,2,3,4,5,6});
    matrix_sf *B=copy_matrix(3,2,(int[]){4,3,2,1,0,9});
    matrix_sf *C=mult_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,2,2,(int[]){8,32,26,71});
    free(C);
}   

//neg mult 
Test(student_tests, neg_mult_mat){
    matrix_sf *A=copy_matrix(2,3,(int[]){-1,-2,-3,-4,-5,-6});
    matrix_sf *B=copy_matrix(3,2,(int[]){4,3,2,1,0,9});
    matrix_sf *C=mult_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,2,2,(int[]){-8,-32,-26,-71});
    free(C);
}
//1byb1 mat should just be regular multiplication
Test(student_tests,onebyonemultiplication){
    matrix_sf *A=copy_matrix(1,1,(int[]){12});
    matrix_sf *B=copy_matrix(1,1,(int[]){4});
    matrix_sf *C=mult_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,1,1,(int[]){48});
    free(C);
}


//neg onebyones mat should just be regular multiplication
Test(student_tests,negonebyonemultiplication){
    matrix_sf *A=copy_matrix(1,1,(int[]){-12});
    matrix_sf *B=copy_matrix(1,1,(int[]){4});
    matrix_sf *C=mult_mats_sf(A,B);
    free(A);
    free(B);
    //free(C);
    expect_matrices_equal(C,1,1,(int[]){-48});
    free(C);
}


//transpose mat sf tests
//normal transpose of a 2 by 3 to 3 by 2 
Test(student_tests,normal_transpose){
    matrix_sf *A=copy_matrix(2,3,(int[]){1,2,3,4,5,6});
    matrix_sf *B=transpose_mat_sf(A);
    expect_matrices_equal(B,3,2,(int[]){1,4,2,5,3,6});
    free(A);
    free(B);
}
//long row mat to long col matrix transposition
Test(student_tests,long_transpose){
    matrix_sf *A=copy_matrix(1,3,(int[]){2,1,3});
    matrix_sf *B=transpose_mat_sf(A);
    expect_matrices_equal(B,3,1,(int[]){2,1,3});
    free(A);
    free(B);
}

//long col mat to long row matrix transposition
Test(student_tests,long_other_transpose){
    matrix_sf *A=copy_matrix(3,1,(int[]){2,1,3});
    matrix_sf *B=transpose_mat_sf(A);
    expect_matrices_equal(B,1,3,(int[]){2,1,3});
    free(A);
    free(B);
}

//neg elements should nto be changed in transpose
Test(student_tests,normal_with_neg_transpose){
    matrix_sf *A=copy_matrix(2,3,(int[]){-1,2,-3,4,-5,-6});
    matrix_sf *B=transpose_mat_sf(A);
    expect_matrices_equal(B,3,2,(int[]){-1,4,2,-5,-3,-6});
    free(A);
    free(B);
}

//Double transposing something should return to normal
Test(student_tests,double_transpose){
    matrix_sf *A=copy_matrix(3,1,(int[]){2,1,3});
    matrix_sf *B=transpose_mat_sf(A);
    expect_matrices_equal(B,1,3,(int[]){2,1,3});
    matrix_sf *C=transpose_mat_sf(B);
    expect_matrices_equal(C,3,1,(int[]){2,1,3});
    free(A);
    free(B);
    free(C);
}


//Create Matrix sf tests now

//create 1 by 1 mat

Test(student_tests, onebyonemat_create){
    matrix_sf *mat = create_matrix_sf('V', "1 1 [105 ;]");
    expect_matrices_equal(mat, 1, 1, (int[]){105});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
}

//neg one by one test

Test(student_tests, onebyonemat_create_neg){
    matrix_sf *mat = create_matrix_sf('V', "1 1 [-105 ;]");
    expect_matrices_equal(mat, 1, 1, (int[]){-105});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
}

// square larger than one mat

Test(student_tests, twobytwomat_create){
    matrix_sf *mat = create_matrix_sf('V', "2 2 [105 2 ; 1 2]");
    expect_matrices_equal(mat, 2, 2, (int[]){105,2,1,2});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
}
//square with neg
Test(student_tests, twobytwomat_create_neg){
    matrix_sf *mat = create_matrix_sf('V', "2 2 [-105 2 ; 1 -2]");
    expect_matrices_equal(mat, 2, 2, (int[]){-105,2,1,-2});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
}

//long col mat create
Test(student_tests, long_col_create){
    matrix_sf *mat = create_matrix_sf('V', "3 1 [10 ; 19 ; -140 ; ]");
    expect_matrices_equal(mat, 3, 1, (int[]){10, 19, -140});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
}

//long col mat create
Test(student_tests, long_row_create){
    matrix_sf *mat = create_matrix_sf('V', "1 3 [10 ; 19 ; -140 ; ]");
    expect_matrices_equal(mat, 1, 3, (int[]){10, 19, -140});
    cr_expect_eq(mat->name, 'V', "The new matrix did not have the expected name. Actual: %c, Expected: V", mat->name);
}

//insert bst and find bst test
//helpers from unit_tests.c
static void inorder_sf(bst_sf *root, char *output) {
    if (!root) return;
    inorder_sf(root->left_child, output);
    char s[2] = {root->mat->name};
    strcat(output, s);
    inorder_sf(root->right_child, output);
}

static int compare_chars_sf(const void* a, const void* b) { return (*(char*)a - *(char*)b); }
static void sort_string_sf(char* str) { qsort(str, strlen(str), sizeof(char), compare_chars_sf); }





//insert one, use checkinorder to check the order
Test(student_tests, inserting_valid_bst_testt) {
    bst_sf *root = NULL;
    char names[] = "A";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    
}


Test(student_tests, inserting_valid_bst_test_multi) {
    bst_sf *root = NULL;
    char names[] = "FDSEA";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    
}



Test(student_tests, inserting_upwards_order) {
    bst_sf *root = NULL;
    char names[] = "ABCDEFGHIJKLMN";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    
}


Test(student_tests, insert_dowwnwards_order) {
    bst_sf *root = NULL;
    char names[] = "ZYXWVUTSROPBA";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    
}


Test(student_tests, insert_in_mixed_orer) {
    bst_sf *root = NULL;
    char names[] = "FAZMOS";
    matrix_sf *mats[strlen(names)];
    for (size_t i = 0; i < strlen(names); i++) {
        mats[i] = malloc(sizeof(matrix_sf));
        mats[i]->name = names[i];
        root = insert_bst_sf(mats[i], root);
    }
    char output[27] = {0};
    inorder_sf(root, output);
    sort_string_sf(names);
    cr_expect_arr_eq(output, names, strlen(names), "BST does not store the nodes in sorted order.");
    for (size_t i = 0; i < strlen(names); i++)
        free(mats[i]);
    
}




//infix2postfix_sf

//adding infixtopostix 
Test(student_tests,adding_fori2p) {
    char *actual = infix2postfix_sf("A+B");
    char *expected = "AB+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}

//mult infixtopostfix
Test(student_tests,mult_for_intopos) {
    char *actual = infix2postfix_sf("A*B");
    char *expected = "AB*";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
//first precendence check
Test(student_tests,paren_prece_order) {
    char *actual = infix2postfix_sf("(A+B)+C");
    char *expected = "AB+C+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
//second precendedce check
Test(student_tests,paren_precendencetwo_order) {
    char *actual = infix2postfix_sf("(A+B)*C");
    char *expected = "AB+C*";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
//infix2postifx transpose
Test(student_tests,inf2postranspose) {
    char *actual = infix2postfix_sf("A'");
    char *expected = "A'";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}

Test(student_tests,inf2postranspose2) {
    char *actual = infix2postfix_sf("A''");
    char *expected = "A''";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
Test(student_tests,inf2postranspose_withadd) {
    char *actual = infix2postfix_sf("A'+B");
    char *expected = "A'B+";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}
Test(student_tests,inf2postranspose_withmult) {
    char *actual = infix2postfix_sf("A'*B");
    char *expected = "A'B*";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}




//big expression infixtopostfix
Test(student_tests,inf2posconfusingexpression) {
    char *actual = infix2postfix_sf(("(A')+B+(C+D)*E"));
    char *expected = "A'B+CD+E*";
    cr_expect_arr_eq(actual, expected, strlen(expected), "The returned postfix expression was %s, but it should have been %s",
        actual, expected);
}


//evalulate expr sf tests

//Single matrix expression test
Test(student_tests, eval_first_test) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "A", root);
    expect_matrices_equal(result, 3, 5, (int[]){-4,18,6,7,10,-14,29,8,21,-99,0,7,5,2,-9});
}

//now adding matrice test
Test(student_tests, eval_adding_test) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "A+B", root);
    expect_matrices_equal(result, 3, 5, (int[]){6,27,4,-26,32,30,39,20,93,-47,-88,24,21,16,-18});
}

//transposition test

Test(student_tests, eval_transpose_test) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "A'", root);
    expect_matrices_equal(result, 5, 3, (int[]){-4,-14,0,18,29,7,6,8,5,7,21,2,10,-99,-9});
}
//reversing transposition
Test(student_tests, eval_reverse_le_transpose_test) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "A''", root);
    expect_matrices_equal(result, 3, 5, (int[]){-4,18,6,7,10,-14,29,8,21 ,-99,0,7,5,2 ,-9});
}

//multiplication test, used matrix calculator from internet to calculate
Test(student_tests, eval_multi_test) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "G*H", root);
    expect_matrices_equal(result, 7, 5, (int[]){-1976,-2470,3572,2774,1824,208,260,-376,-292,-192,2392,2990,-4324,-3358, -2208,-728,-910, 1316, 1022, 672,-5304, -6630, 9588, 7446,4896,-3744,-4680,6768,5256,3456,-1404,-1755,2538,1971,1296});
}

//reusing same matrix in eval should still work fine

Test(student_tests, eval_adding_same_test) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "A+A", root);
    expect_matrices_equal(result, 3, 5, (int[]){-4*2,18*2,6*2,7*2,10*2,-14*2,29*2,8*2,2*21,-99*2,0,7*2,5*2,2*2,-9*2});
}


//adding and transposing a matrix
Test(student_tests, eval_adding_then_transpose_test) {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "(A+A)'", root);
    expect_matrices_equal(result, 5, 3, (int[]){-8,-28,0,36,58,14,12,16,10,14,42, 4,20,-198,-18});
}



//free_bst_sf same as unit_test, as directed by piazza because we cnanot create files that don't alreaedy exist

Test(student_tests,free_bst1) {
    expect_no_valgrind_errors(run_with_valgrind("free_bst01"));
}

Test(student_tests,free_bst2) {
    expect_no_valgrind_errors(run_with_valgrind("free_bst02"));
}

Test(student_tests,free_bst3) {
    expect_no_valgrind_errors(run_with_valgrind("free_bst03"));
}

//copied some of the eval tests from unit just to test myself
//copied execute_script_sf as according to piazza post @282
/* evaluate_expr_sf tests*/
Test(base_evaluate_expr, expr01_student_test_c, .description="Given root of a tree, evaluation of an expression") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "G * C + F'", root);
    expect_matrices_equal(result, 7, 4, (int[]){4597, -1765, 206, -5401, -512, 159, -15, 647, -5547, 2117, -104, 6407, 1720, -523, 199, -1962, 12587, -4696, 281, -14286, 8973, -3330, 436, -9965, 3439, -1138, 222, -3721});
}

Test(base_evaluate_expr, expr02_student_test_c, .description="Given root of a tree, evaluation of an expression") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "(A + B) * H' * D", root);
    expect_matrices_equal(result, 3, 4, (int[]){-32848, 250466, 277155, 219671, 37088, -282796, -312930, -248026, 84704, -645868, -714690, -566458});
}

Test(base_evaluate_expr, expr03_student_test_c, .description="Given root of a tree, evaluation of an expression") {
    bst_sf* root = build_bst();
    matrix_sf* result = evaluate_expr_sf('R', "(I + D' * C) * E' * J", root);
    expect_matrices_equal(result, 4, 3, (int[]){-11171376, 56535582, 3236371, 69463160, -416294603, -47900609, 76095851, -459940949, -56668593, 60848961, -362841916, -37213021});
}


//as stated in piazza post @282, this can be copied


/* execute_script_sf tests */
// 1. call execute_script_sf() to check for correctness()
// 2. call execute_script_sf() via valgrind to check for memory errors
Test(base_execute, add_mats01) { run_script_without_valgrind("script01"); }
Test(base_execute_valgrind, add_mats01) { expect_no_valgrind_errors(run_script_with_valgrind("script01")); }

Test(base_execute, add_mats02) { run_script_without_valgrind("script02"); }
Test(base_execute_valgrind, add_mats02) { expect_no_valgrind_errors(run_script_with_valgrind("script02")); }

Test(base_execute, mult_mats01) { run_script_without_valgrind("script03"); }
Test(base_execute_valgrind, mult_mats01) { expect_no_valgrind_errors(run_script_with_valgrind("script03")); }

Test(base_execute, mult_mats02) { run_script_without_valgrind("script04"); }
Test(base_execute_valgrind, mult_mats02) { expect_no_valgrind_errors(run_script_with_valgrind("script04")); }

Test(base_execute, trans_mat01) { run_script_without_valgrind("script05"); }
Test(base_execute_valgrind, trans_mat01) { expect_no_valgrind_errors(run_script_with_valgrind("script05")); }

Test(base_execute, trans_mat02) { run_script_without_valgrind("script06"); }
Test(base_execute_valgrind, trans_mat02) { expect_no_valgrind_errors(run_script_with_valgrind("script06")); }

Test(base_execute, add_mats03) { run_script_without_valgrind("script07"); } // A + B + C
Test(base_execute_valgrind, add_mats03) { expect_no_valgrind_errors(run_script_with_valgrind("script07")); }

Test(base_execute, mult_mats03) { run_script_without_valgrind("script08"); } // A * B * C
Test(base_execute_valgrind, mult_mats03) { expect_no_valgrind_errors(run_script_with_valgrind("script08")); }

Test(base_execute, trans_mat03) { run_script_without_valgrind("script09"); } // A''
Test(base_execute_valgrind, trans_mat03) { expect_no_valgrind_errors(run_script_with_valgrind("script09")); }

Test(base_execute, script10) { run_script_without_valgrind("script10"); } // A * B + C
Test(base_execute_valgrind, script10) { expect_no_valgrind_errors(run_script_with_valgrind("script10")); }

Test(base_execute, script11) { run_script_without_valgrind("script11"); } // A + B * C
Test(base_execute_valgrind, script11) { expect_no_valgrind_errors(run_script_with_valgrind("script11")); }

Test(base_execute, script12) { run_script_without_valgrind("script12"); } // (A + B) * C
Test(base_execute_valgrind, script12) { expect_no_valgrind_errors(run_script_with_valgrind("script12")); }

Test(base_execute, script13) { run_script_without_valgrind("script13"); } // (A + B) * (C + D)
Test(base_execute_valgrind, script13) { expect_no_valgrind_errors(run_script_with_valgrind("script13")); }

Test(base_execute, script14) { run_script_without_valgrind("script14"); } // (A + B * C) * (C + D * E) * (E + F * G)
Test(base_execute_valgrind, script14) { expect_no_valgrind_errors(run_script_with_valgrind("script14")); }

Test(base_execute, script15) { run_script_without_valgrind("script15"); } // (A + B * C) * (C + D * E)
Test(base_execute_valgrind, script15) { expect_no_valgrind_errors(run_script_with_valgrind("script15")); }

Test(base_execute, script16) { run_script_without_valgrind("script16"); } // A' * B + C
Test(base_execute_valgrind, script16) { expect_no_valgrind_errors(run_script_with_valgrind("script16")); }

Test(base_execute, script17) { run_script_without_valgrind("script17"); } // (A' * B + C)'
Test(base_execute_valgrind, script17) { expect_no_valgrind_errors(run_script_with_valgrind("script17")); }

Test(base_execute, script18) { run_script_without_valgrind("script18"); } 
Test(base_execute_valgrind, script18) { expect_no_valgrind_errors(run_script_with_valgrind("script18")); }

Test(base_execute, script19) { run_script_without_valgrind("script19"); } 
Test(base_execute_valgrind, script19) { expect_no_valgrind_errors(run_script_with_valgrind("script19")); }

Test(base_execute, script20) { run_script_without_valgrind("script20"); } 
Test(base_execute_valgrind, script20) { expect_no_valgrind_errors(run_script_with_valgrind("script20")); }

