int strLen(char* str)     
{ 
    /*  
     * STUDENT ANSWER
     */
    if (str[0] != '\0') return 1 + strLen(str + 1);
    else return 0;
} 