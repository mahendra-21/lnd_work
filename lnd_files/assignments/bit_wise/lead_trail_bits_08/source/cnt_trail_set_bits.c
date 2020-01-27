/* funtion for returning the count of the set bits at trailing edge */
unsigned int cnt_trailing_set_bits (unsigned int num) {
        
    unsigned int count = 0;

    unsigned int start = 0;

    unsigned int bits = sizeof (unsigned int) * 8 -1;

    for (; 0 <= bits; ++start) {

        if (num & (1 << start)) {
            
                count ++ ;
                
        } else {
            
            break;

        }

    }

    return count;

}
