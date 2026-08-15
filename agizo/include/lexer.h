#ifndef _LEXER_
#define _LEXER_

#include <stdint.h>

/*
 * @brief pre-processes passed input string, removing all spaces
 * and comments
*/
void agizo_lexer_preprocess(char* str, uint32_t size);

void agizo_lexer_tokenize(char* str, uint32_t size, char** tokens);


#endif
