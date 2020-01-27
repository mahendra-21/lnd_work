/* funtion for toggle the even bits of a number */
unsigned int even_b_toggle(unsigned int num) {

    int pos = (sizeof(unsigned int) * 8) - 1;

    for (; pos >= 0; --pos) {

        if (pos % 2 == 0) {

            num ^= 1 << pos;

        }

    }

    return num;

}
