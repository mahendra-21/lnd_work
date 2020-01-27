/* funtion for returning the count of the cleared bits at leading edge */
unsigned int cnt_leading_cleared_bits (unsigned int num) {
        
    unsigned int count = 0;

    unsigned int bits = sizeof (unsigned int) * 8 -1;

    for (; 0 <= bits; --bits) {

        if ((num & (1 << bits)) == 0) {
            
            count++;
            
        } else {
            
            break;

        }

    }

    return count;

}
