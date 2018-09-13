char* convert(char* s, int numRows) {
    int len = 0;
    int numCols = 0;
    // find the string length
    while (s[len] != '\0')
        len++;
    if (len == 0 || len == 1 || numRows == 1)
        return s;
    // allocate space for the output buffer
    char* sOut = malloc(sizeof(char) * (len + 1));
    sOut[len] = '\0';
    // find number of columns
    numCols = len / (numRows * 2 - 2) * 2 + 2;
    // allocate buffer for calculation matrix and initialize it to special value
    char matrix[numRows][numCols];
    memset(matrix, '~', numRows * numCols * sizeof(char));
    // populate matrix with zigzag
    for (int i = 0, row = 0, col = 0; i < len; i++){
        if ((row < numRows - 1 && (col % 2) == 0) || (row == 0))
            matrix[row++][col] = s[i];
        else if (row == numRows - 1)
            matrix[row--][col++] = s[i];
        else if (row > 1 && (col % 2) == 1)
            matrix[row--][col] = s[i];
        else if (row == 1 && (col % 2) == 1)
            matrix[row--][col++] = s[i];
    }
    // read matrix by rows
    int k = 0;
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols && k < len; j++){
            if (matrix[i][j] != '~'){
                sOut[k] = matrix[i][j];
                k++;
            }
        }
    }
    return sOut;
}

