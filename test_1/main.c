/*
 *  Test 1
 *  ======
 *  
 *
*/

#include "agizo.h"
#include <stdio.h>


FILE* fptr;

int main()
{
    Agizo_Runtime runtime;
    Agizo_Stack stack;

    agizo_runtime_init(&runtime, &stack);
    agizo_runtime_debug(&runtime); 

    fptr = fopen("./t_file.agizo", "r");
    if (fptr == NULL)
    {
        printf("Error: couldn't open file\r\n");
        return 1;
    }
    //char content[MAX_FILE_CHARS];
    //fgets(content, MAX_FILE_CHARS, fptr);
    //printf("Got file contents: %s\r\n", content);
    

    RET_STATE result = agizo_execute_file(&runtime, fptr);

    return result;
}
