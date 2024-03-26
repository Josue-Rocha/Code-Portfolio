/* table.c: Separate Chaining Hash Table */

#include "table.h"
#include "hash.h"
#include "macros.h"

/**
 * Create Table data structure.
 * @param   capacity        Number of buckets in the hash table.
 * @return  Allocated Table structure.
 */
Table *	    table_create(size_t capacity) {
    Table *table = calloc(1, sizeof(Table));
    if (capacity == 0){
        table->capacity = DEFAULT_CAPACITY;
    }else{
        table->capacity = capacity;
    }
    table->buckets = calloc(table->capacity, sizeof(Pair));
    //table->size = 0;
    return table;
}

/**
 * Delete Table data structure.
 * @param   t               Table data structure.
 * @return  NULL.
 */
Table *	    table_delete(Table *t) {
    for(size_t i = 0; i < t->capacity; i++){
        pair_delete(t->buckets[i].next, true);
    }
    free(t->buckets);
    free(t);
    return NULL;
}

/**
 * Insert or update Pair into Table data structure.
 * @param   m               Table data structure.
 * @param   key             Pair's key.
 * @param   value           Pair's value.
 * @param   type            Pair's value's type.
 */
void        table_insert(Table *t, const char *key, const Value value, Type type) {
    uint64_t bucket = hash_from_data(key, strlen(key)) % t->capacity;
    Pair *curr = t->buckets[bucket].next;
    while(curr){
        if(!strcmp(curr->key, key)){ // if the key is alrady there
            pair_update(curr, value, type);
            return;
        }
        curr = curr->next;
    }
    Pair *new = pair_create(key, value, t->buckets[bucket].next, type);
    t->buckets[bucket].next = new;
    t->size++;
}

/**
 * Search Table data structure by key.
 * @param   t               Table data structure.
 * @param   key             Key of the Pair to search for.
 * @return  Pointer to the Value associated with specified key (or NULL if not found).
 */
Value *     table_search(Table *t, const char *key) {
    uint64_t bucket = hash_from_data(key, strlen(key)) % t->capacity;
    Pair *curr = t->buckets[bucket].next;
    while(curr){
        if(!strcmp(curr->key, key)){ // if the key is alrady there
            return &curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}

/**
 * Remove Pair from Table data structure with specified key.
 * @param   t               Table data structure.
 * @param   key             Key of the Pair to remove.
 * return   Whether or not the removal was successful.
 */
bool        table_remove(Table *t, const char *key) {
    uint64_t bucket = hash_from_data(key, strlen(key)) % t->capacity;
    Pair *curr = t->buckets[bucket].next;
    Pair *prev = &t->buckets[bucket];
    while(curr){
        if(!strcmp(curr->key, key)){ // if the key is alrady there
            prev->next = curr->next;
            pair_delete(curr, false);
            t->size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

/**
 * Format all the entries in the Table data structure.
 * @param   m               Table data structure.
 * @param   stream          File stream to write to.
 */
void	    table_format(Table *t, FILE *stream) {
    for(size_t i = 0; i < t->capacity; i++){
        Pair *curr = t->buckets[i].next;
        while(curr){
            pair_format(curr, stream);
            curr = curr->next;
        }
    }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
