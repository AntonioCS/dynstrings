
#include <stdio.h>
#include "../src/dynstrings.h"

int main() {
    
    pdynstr s = dynstr_init(NULL);
    
    dynstr_add_str(s, "Hello");
    
    printf("Text in string: %s\n", dynstr_text(s));
    printf("Size of string: %d\n", s->size);
    printf("Length of string: %d\n", s->length);   
    
    exit(0);
}
