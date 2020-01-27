/* funtion for bits swapping of a number */
void bit_swap(unsigned int *num, unsigned int src_pos, unsigned int dest_pos) {

    unsigned int mask1 = (*num >> src_pos) & 1; //mask for src bit pos

    unsigned int mask2 = (*num >> dest_pos) & 1; //mask for dest bit pos

    unsigned int mask = mask1 ^ mask2; 

    mask = (mask << src_pos) | (mask << dest_pos); //setting mask for swap

    *num = *num ^ mask; // logic for changing the bits
 
}

