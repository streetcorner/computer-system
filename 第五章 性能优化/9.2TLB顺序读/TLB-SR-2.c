//

#include <stdlib.h>

#include <stdio.h>

#include <time.h>



#define NPAD 7

#define MinSet 1<<10

#define MaxSet 1<<22

/*

CPU:2.5GHz

*/

#define CYCLE_TIME (1 / 2.5 / 1000 /1000)







struct li {

	struct li *next;

	long long pad[NPAD];

};





int main()

{

	int set, i, len;

	printf("When NPAD= %d, the total time is:\n",NPAD);

	/*size means work set*/

	for (set = MinSet; set <= MaxSet; set = set <<1)

	{

		struct li *first = (struct li *)malloc(sizeof(struct li));



		first->next = first;

		struct li *tmp = first;

		len=set/64;

		for (i = 0; i < len; i++)

		{

			struct li *node = (struct li *)malloc(sizeof(struct li));

			node->next = first;//new node to head

			tmp->next = node;//new node to list

			tmp = node;//current node to tmp

		}



		tmp = first;



		clock_t st, ed;

		st = clock();



		do

		{

			tmp = tmp->next;

		} while (tmp->next != first);



		ed = clock();

		double t =ed - st;

		printf("%.10f\n", t / CLOCKS_PER_SEC / CYCLE_TIME /  (set / 64));

	}



	system("pause");

    return 0;

}

