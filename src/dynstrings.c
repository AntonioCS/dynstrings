#include "dynstrings.h"

static bool dynstr_is_resize_needed(pdynstr, int);

bool dynstr_is_resize_needed(pdynstr s, int len_to_add) {
    return (s->length + len_to_add) >= s->size;
}

pdynstr dynstr_init(char *start_string) {
    pdynstr newstr = malloc(sizeof (dynstr));

    if (newstr != NULL) {
        newstr->str = calloc(DYNSTR_INIT_SIZE, sizeof (char));
        if (newstr->str == NULL) {
            perror("Unable to allocate space for string");
            exit(-1);
        }

        newstr->increase_by = DYNSTR_INIT_SIZE;
        newstr->size = DYNSTR_INIT_SIZE;
        newstr->length = 0;
        
        if (start_string != NULL) {
            dynstr_add_str(newstr, start_string);
        }

        return newstr;
    }

    return NULL;
}

void dynstr_add_char(pdynstr string, int c) {

    if (dynstr_is_resize_needed(string, 1)) {
        dynstr_resize(string);
    }

    string->str[string->length++] = c;
}

void dynstr_add_str(pdynstr s, char *str) {
    int len = strlen(str);
    dynstr_add_str_num(s, str, len);
}

void dynstr_add_str_num(pdynstr s, char *str, int length) {
    while (dynstr_is_resize_needed(s, length)) {
        dynstr_resize(s);
    }

    memcpy(s->str + s->length, str, length);
    s->length += length;
}



void dynstr_resize(pdynstr string) {
    char *tmp_buffer = realloc(string->str, (string->size += string->increase_by));

    if (tmp_buffer) {
        string->str = tmp_buffer;
        memset(string->str + string->length, 0, string->size - string->length);
    } else {
        perror("Unable to reallocate memory");
        exit(-1);
    }
}

void dynstr_destroy(pdynstr s) {
    free(s->str);
    free(s);
}

void dynstr_clear(pdynstr s) {
    s->size = 0;
    s->length = 0;
    s->increase_by = DYNSTR_INIT_SIZE;

    dynstr_resize(s);
}

char *dynstr_text(pdynstr s) {
    return s->str;
}
