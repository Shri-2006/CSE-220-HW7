#include "unit_tests.h"
//Shriyans Singh 114807762
TestSuite(student_tests, .timeout=TEST_TIMEOUT); 

//Copied from the unit_test.c because it was not letting me test without it, and i dont know why it wasnt calling 
bst_sf* build_bst() {
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