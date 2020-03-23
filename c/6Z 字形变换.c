#include <stdlib.h>

// 模拟法，行列存储在二维数组里，占内存
char * convert(char * s, int numRows){
    // 一行直接返回
    if(numRows < 2) return s;

    int length = strlen(s);
    int dir = -1, curRow=1;
    // 保存每行的字符
    char (*ss)[numRows][length] = malloc(sizeof(char) * (length) * numRows);
    // column保存对应行末尾的索引
    int *column = malloc(sizeof(int) * numRows); 
    memset(column, 0, sizeof(int) * numRows);

    for(int i=0; i<length; ++i){
        // 控制行
        curRow += dir;
        (*ss)[curRow][column[curRow]++] = s[i];
        // 控制行的方向
        if(curRow == 0 || curRow == numRows - 1){
            dir = (dir == 1) ? -1 : 1; 
        }
    }
    // 将每行的字符子串存储
    for(int i=0, ii=0; i<numRows; ++i){
        for(int j=0; j<column[i]; ++j){
            s[ii++] = (*ss)[i][j];
        }
    }    
    return s;
}

// 数学规律
char * convert(char * s, int numRows){
    // 一行直接返回
    if(numRows < 2) return s;

    int length = strlen(s);
    char *ss = malloc(sizeof(char) * (length + 1));
    ss[length] = '\0';

    int index = 0, dif = 2 * numRows - 2;       // dif为两头行对应列的间距
    for(int i=0; i<numRows; ++i){               // 每一行   
        for(int j=i; j<length; j += dif){       // 每一列
            // 竖着的
            ss[index++] = s[j];             // printf("%d ", j);
            // 斜着的,两头不包括
            if(i > 0 && i < numRows-1 && j+dif-2*i < length){
                ss[index++] = s[j+dif-2*i]; // printf("%d ", j+dif-2*i);
            }
        } 
                                            // printf("\n");
    }
    return ss;
}

