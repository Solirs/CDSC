#ifndef HEADER_TRIE_H_
#define HEADER_TRIE_H_

#include <stddef.h> // size_t
#include <stdbool.h>

#define ALPHABET_SIZE 26


typedef struct trie_node {
    struct trie_node* nodes[ALPHABET_SIZE];
    char value;
    bool final_chr;
} TRIE;



TRIE* cdsc_trie_init();
void cdsc_trie_insert(TRIE* head, char word[]);
void cdsc_trie_delete_word(TRIE* head, char word[]);
bool cdsc_trie_contains(TRIE* head, char word[]);
void cdsc_trie_free(TRIE* head);

#endif