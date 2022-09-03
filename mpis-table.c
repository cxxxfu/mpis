#include <string.h>
#include <stdlib.h>
#include "mpis-table.h"

static mpis_table *table;
static int retval;

void new_table() {
    retval = 0;
    table = NULL;
}

void end_table() {

}

mpis_table *get_table() {
    return table;
}

void add_entry(uint8_t selector_type, uint32_t selector, uint8_t selector_mask, uint8_t target_type, uint32_t target, uint8_t target_mask, uint32_t target_data) {
    mpis_table *current_entry = malloc(sizeof(mpis_table)), *last_entry = table;
    memset(current_entry, 0, sizeof(mpis_table));

    current_entry->selector_type = selector_type;
    current_entry->selector = selector;
    current_entry->selector_mask = selector_mask;
    current_entry->target_type = target_type;
    current_entry->target = target;
    current_entry->target_mask = target_mask;
    current_entry->target_data = target_data;

    if (table == NULL) {
        table = current_entry;
        return;
    } 

    while (last_entry->next != NULL) {
        last_entry = last_entry->next;
    }

    last_entry->next = current_entry;
}

void store_retval(int val) {
    retval = val;
}

int get_retval() {
    return retval;
}