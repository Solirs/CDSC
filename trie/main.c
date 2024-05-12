#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    TRIE* root = cdsc_trie_init();
    cdsc_trie_insert(root, "apple");
    cdsc_trie_insert(root, "apples");
    cdsc_trie_insert(root, "tomato");
    cdsc_trie_insert(root, "orange");
    cdsc_trie_insert(root, "ada");

    printf("%d\n", cdsc_trie_contains(root, "apple"));
    printf("%d\n", cdsc_trie_contains(root, "apples"));
    cdsc_trie_delete_word(root, "apples");
    printf("%d\n", cdsc_trie_contains(root, "apple"));
    printf("%d\n", cdsc_trie_contains(root, "apples"));

    printf("Finished!\n");
    return 0;
}
