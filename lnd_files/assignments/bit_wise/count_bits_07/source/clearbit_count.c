/* funtion for toggle the odd bits of a number */
unsigned int clearbit_count(unsigned int num) {
    
    unsigned int count = 0;

    int pos = (sizeof(int) * 8) - 1;

    for (; pos >= 0; --pos) {

        if (!((num >> pos) & 1)) {

            count++;

        }

    }

    return count;
}
