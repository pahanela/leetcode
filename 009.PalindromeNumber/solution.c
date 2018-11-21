bool isPalindrome(int x) {
    int max = pow(2, 31) - 1;
    int xFwd = x;
    int xRev = 0;
    if (x < 0)
        return false;
    while (x != 0){
        if ((xRev <= max / 10) && ((xRev * 10) <= (max - x % 10))){
            xRev *= 10;
            xRev += x % 10;
            x /= 10;
        }
        else
            return false;
    }
    if (xFwd == xRev)
        return true;
    else
        return false;
}
