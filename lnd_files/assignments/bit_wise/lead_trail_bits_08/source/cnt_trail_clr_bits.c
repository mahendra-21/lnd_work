/* funtion for returning the count of the cleared bits at trailing edge */
unsigned int cnt_trailing_cleared_bits (unsigned int num) {
        
    unsigned int count = 0;
    
    unsigned int start = 0;

    unsigned int bits = sizeof (unsigned int) * 8 -1;

    for (; 0 <= bits; ++start) {

        if ((num & (1 << start)) == 0) {
                
                count ++;
                
        } else {
            
            break;

        }

    }

    return count;

}
