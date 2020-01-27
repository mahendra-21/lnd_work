/* funtion for toggle the odd bits of a number */
unsigned int odd_b_toggle(unsigned int num) {
    
    unsigned int result = num;

    int pos = (sizeof(int) * 8) - 1;

    for (; pos >= 0; --pos) {

        if (pos % 2 != 0) {

            result ^= 1 << pos;

        }

    }
    return result;
}
