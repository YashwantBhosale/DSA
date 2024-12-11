typedef struct entry {
    int key;
    int value;
    unsigned hash;
} Entry;

typedef struct {
    Entry **table;
    int count;
    int size;
    unsigned total_probes;
} HashTable;

void init_table(HashTable *ht, int size);
void insert(HashTable *ht, int key, int value);
void delete(HashTable *ht, int key);
int search(HashTable *ht, int key);
void print_table(HashTable *ht);
void free_table(HashTable *ht);
unsigned hash(int key, int size);