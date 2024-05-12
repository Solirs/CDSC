#include "trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

TRIE* cdsc_trie_init() {
    TRIE* root = (TRIE*) malloc(sizeof(TRIE));
    if (root == NULL) {
        printf("Failed to allocate memory!");
        return NULL;
    }

    root->value = '\0';
    root->final_chr = 0;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        root->nodes[i] = NULL;
    } 

    return root;
}



// Avoided using recursion for the insert as it makes unecessary stack
// calls.
void cdsc_trie_insert(TRIE* root, char word[]) {
    struct trie_node* current = root;
    size_t word_size = strlen(word); 
    size_t j = 0;
    size_t i = 0;
    
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (j == word_size) {
            current->final_chr = true;
            break;
        }

        if (current->nodes[i] == NULL) {
            current->nodes[i] = (struct trie_node*) malloc(sizeof(struct trie_node));
            current->nodes[i]->value = word[j];
            current = current->nodes[i];
            // printf("Allocated '%c' to '%p'\n", word[j], current);
            i = 0;
            j++;
            continue;
        }

        if (current->nodes[i]->value == word[j]) {    
            current = current->nodes[i];
            i = 0;
            j++;
        }

    }
}

// This needs a rethink, two issues i can think of is
// if the node is last chr but also has child nodes,
// can't just free it straight away.
// alot more logical programming needs to be done here
// for more cases.
void cdsc_trie_delete_word(TRIE* root, char word[]) {
    struct trie_node* current = root;
    size_t word_size = strlen(word); 
    size_t j = 0;
    size_t i = 0;

    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (j == word_size) {
            if (current->final_chr) {
                current->final_chr = false;
            }

            break;
        }
        
        if (current->nodes[i] == NULL) {
            break;
        }

        if (current->nodes[i]->value == word[j]) {
            current = current->nodes[i];
            i = 0;
            j++;
        }
        
    }
}


bool cdsc_trie_contains(TRIE* head, char word[]) {
    struct trie_node* current = head;
    size_t word_size = strlen(word); 
    size_t j = 0;
    size_t i = 0;
    
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (j == word_size) {
            return current->final_chr;
        }

        if (current->nodes[i] == NULL) {
            return false;
        }

        // printf("Scanning %c\n", current->nodes[i]->value);

        if (current->nodes[i]->value == word[j]) {    
            current = current->nodes[i];
            i = 0;
            j++;
        }

    }

    return false;
}

// TODO: this function needs testing
// void cdsc_trie_free(TRIE* head) {
//     struct trie_node* current = head;

//     for (int i = 0; i < ALPHABET_SIZE; i++) {
//         if (current->nodes[i] != NULL) {
//             cdsdc_trie_free(current->nodes[i]);
//         }

//         free(current->nodes[i]);
//     }
// }


// if (head->nodes[i]->key == word[0]) {
//             struct trie_node* current = head->nodes[i]->next;

//             for (size_t j = 1; j < strlen(word); j++) {
//                 if (current->key == word[j]) {
//                     continue;
//                 }

//                 current->next = malloc(sizeof(struct trie_node));

//             }

//             while (current != NULL) {
//                 if (current->key )
//                 current = current->next;
//             }

//             current = (struct trie_node*) malloc(sizeof(struct trie_node));

//             break;
//         }
