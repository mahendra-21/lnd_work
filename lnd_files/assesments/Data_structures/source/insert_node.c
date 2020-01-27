#include "header.h"

DEL *insert_node(void)
{
    DEL *root = NULL;

    static int flag  = 1;
    static int flag1 = 1;
    static int flag2 = 1;

    int pass = 0;


    do {
        DEL *node = create_node();
        
        if (NULL == node)   return FLAG;
        
        node -> prev = NULL;
        node -> next = NULL;
        printf("Enter data : ");
        node -> data = get_number();
        
        if (OKAY == flag++) {
            root = node;
        } else {
            static DEL *temp = NULL;
            
            if (root -> data > node -> data) {

                if (OKAY == flag1++) {
                    temp = node;
                    root -> prev = node;
                } else {

                    if (temp -> data > node -> data) {
                        temp -> prev = node;
                        temp = node;
                    } else {
                        temp -> next = node;
                        temp = node;
                    }

                }

            } else {
                
                if (OKAY == flag2++) {
                    temp = node;
                    root -> next = node;
                } else {

                    if (temp -> data > node -> data) {
                        temp -> prev = node;
                        temp = node;
                    } else {
                        temp -> next = node;
                        temp = node;
                    }

                }
                    
            }

        }
     
        printf("Do you want to add new node --> then press (1->yes / 0->no) : ");
        pass = get_number();
    } while (pass);

    return root;
}
