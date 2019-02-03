#include <stddef.h>
#ifndef MY_MALLOC
#define MY_MALLOC
#define BLOCK_SIZE sizeof(struct block_meta_data)


 //Best Fit malloc/free
     void *bf_malloc(size_t size);
     void bf_free(void *ptr);

 //First Fit malloc/free
     void *ff_malloc(size_t size);
     void ff_free(void *ptr);


//Functions to calculate fragmentation
unsigned long get_data_segment_size(); //total data segment in bytes
unsigned long get_data_segment_free_space_size(); //free data segment in bytes


struct block_meta_data {

	size_t size; //size of the block
	struct block_meta_data * next; //next meta-data block
    struct block_meta_data * prev; //previous meta-data block
	int free; //this is a flag variable descibing whether the block is free or not denoted by 0 and 1

};

typedef struct block_meta_data * block;

//Other necessary functions to implement malloc and free
block new_space(block last, size_t size);
void split_block(block mblock, size_t size);
void coalesce(block my_block);

//Finding blocks using the best-fit and first-fit memory allocation policies
block find_free_block_FF(block * last, size_t size);
block find_best_fit_block_BF(block * last, size_t size);



#endif
