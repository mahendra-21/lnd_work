/* funtion for returning the count of the set bits at leading edge */
unsigned int cnt_leading_set_bits (unsigned int num) {
        
    unsigned int count = 0;

    unsigned int bits = sizeof (unsigned int) * 8 -1;

    for (; 0 <= bits; --bits) {

        if (num & (1 << bits)) {
            
            count ++;
            
        } else {
            
            break;

        }

    }

    return count;

}
