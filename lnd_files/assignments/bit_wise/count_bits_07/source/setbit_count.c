/* funtion for toggle the even bits of a number */
unsigned int setbit_count(unsigned int num) {

    unsigned int count = 0;

    int pos = (sizeof(unsigned int) * 8) - 1;

    for (; pos >= 0; --pos) {

        if ((num >> pos) & 1) {
            
            count++;

        }

    }

    return count;

}
