#ifndef __MYMALLOC_H__
#define __MYMALLOC_H__

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#define BLOCK_SIZE 24      //记录块信息一个节点的大小

typedef struct s_block *t_block;

//此结构体记录了每在堆中分配一个块，这个块的一些详细的信息
struct s_block{
	size_t size;	//每一块数据区的大小
	int free;	//是否为空的标志位
	t_block pre;
	t_block next;
	void *magic_ptr;
	int padding;	//字节填充
	char data[1];	//数据字段中的第一个字节，也就是malloc函数返回的地址
};

/*编写一个查找一个合适块的函数，利用首次适应算法*/
t_block find_a_block(t_block *last,size_t size);


/*如果现有的块都不能满足，则要开辟一个新的块*/
t_block add_block(t_block last,size_t size);

/*处理内碎片*/
void split_block(t_block b, size_t size);

/*字节对齐*/
size_t align8(size_t s);
 
void *malloc(size_t size);

/*获得这一块中meta的地址，找到magic_ptr返回*/
t_block get_block_add(void *p);

/*判断指针是否有效*/
int judge_ptr(void *p);

/*合并空闲块*/
t_block merge_block(t_block p);

/*释放内存*/
void free(void *p);

#endif