/* funtion for bits swapping of a number */
void bit_swap(unsigned int *num1, unsigned int *num2, 
            unsigned int src_pos, unsigned int dest_pos) {

    unsigned int mask1 = (*num1 >> src_pos) & 1; //mask for src bit pos

    unsigned int mask2 = (*num2 >> dest_pos) & 1; //mask for dest bit pos

    unsigned int mask = mask1 ^ mask2; 

    mask1 = mask2 = mask;

    mask1 = (mask1 << src_pos); 

    *num1 ^= mask1; 

    mask2 = (mask2 << dest_pos); 

    *num2 ^= mask2; 

}

