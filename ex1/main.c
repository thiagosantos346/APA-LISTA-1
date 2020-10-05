#include <stdio.h>

#define PQ_SIZE 2

typedef struct {
    int q[PQ_SIZE+1];
    int n;
} priority_queue;
/* body of queue */
/* number of queue elements */

void pq_swap(priority_queue *priority_queue, int n, int key );

void swap(int *s, int n, int key );

int pq_parent(int n);

/* implicitly take floor(n/2) */
int pq_young_child(int n);

int pq_insert(priority_queue *q, int x);

void bubble_up(priority_queue *q, int p);

void pq_init(priority_queue *q);

void make_heap(priority_queue *q, int s[], int n);

int extract_min(priority_queue *q);

void bubble_down(priority_queue *q, int p);

void heapsort(int s[], int n);

int simpleFindeMinimum(int * s, int n,  int *operations);

int deleteMinimum(int * s, int start, int end, int minimum );

int SelectionSort(int * s, int * sortedS, int n);

int heap_compare(priority_queue *q, int i, int count, int x);

void main( int agrc, char *argv[]){

    
    int t = 10;
    int vetor[t];
    int nVetor[t];
    int vVetor[t];

    for(int i = 0; i < t; ++i){
        vetor[i] = (t - i); // the hard way.
        nVetor[i] = (t - i); // the hard way.
        vVetor[i] = (t - i); // the hard way.
    }
    
    
    
    heapsort(vetor, t);

    printf(
        "Number of operarions to sort a vector with size equals to %d is %d.", 
        t,
        SelectionSort(vetor, nVetor, t)
    );

}


void myfuncn( int *var1, int var2)
{
	/* The pointer var1 is pointing to the first element of
	 * the array and the var2 is the size of the array. In the
	 * loop we are incrementing pointer so that it points to
	 * the next element of the array on each increment.
	 *
	 */
    for(int x=0; x<var2; x++)
    {
        printf("Value of var_arr[%d] is: %d \n", x, *var1);
        /*increment pointer for next element fetch*/
        var1++;
    }
}

int bmain()
{
    int var_arr[] = {11, 22, 33, 44, 55, 66, 77};
    myfuncn(var_arr, 7);
    return 0;
}

//q, p, min_index
void pq_swap(priority_queue *priority_queue, int i, int min_index ){
    int swapVar;

    swapVar = (int)priority_queue->q[i];
    priority_queue->q[i]    = priority_queue->q[min_index];
    priority_queue->q[min_index]  = swapVar;

}



void swap(int *s, int i, int min_index ){

    int swapVar;

    swapVar = s[i];
    s[i] = s[min_index];
    s[min_index] = swapVar;

}

int pq_parent(int n)
{
    if (n == 1) return(-1);
    else return((int) n/2);
}

/* implicitly take floor(n/2) */
int pq_young_child(int n)
{
    return(2 * n);
}

int pq_insert(priority_queue *q, int x)
{
    if (q->n >= PQ_SIZE)
        printf("Warning: priority queue overflow insert x=%d\n",x);
    else {
        q->n = (q->n) + 1;
        q->q[ q->n ] = x;
        bubble_up(q, q->n);
    }
}

void bubble_up(priority_queue *q, int p)
{
    if (pq_parent(p) == -1) return; /* at root of heap, no parent */

    if (q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q,p,pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}

void pq_init(priority_queue *q)
{
    q->n = 0;
}

void make_heap(priority_queue *q, int s[], int n)
{
    int i;
    /* counter */
    pq_init(q);

    for (i=0; i<n; i++)
        pq_insert(q, s[i]);
}

int extract_min(priority_queue *q)
{
    int min = -1;
    /* minimum value */

    if (q->n <= 0)
        printf("Warning: empty priority queue.\n");
    else {
        min = q->q[1];
        q->q[1] = q->q[ q->n ];
        q->n = q->n - 1;
        bubble_down(q,1);
    }

    return(min);
}

void bubble_down(priority_queue *q, int p)
{
    int c;
    /* child index */

    int i;
    /* counter */

    int min_index;
    /* index of lightest child */

    c = pq_young_child(p);
    min_index = p;
    
    for (i = 0; i <= 1; i++)
        if ((c + i) <= q->n)
        {
            if (q->q[min_index] > q->q[c + i])
                min_index = c + i;
        }
    if (min_index != p)
    {
        pq_swap(q, p, min_index);
        bubble_down(q, min_index);
    }
}

void heapsort(int s[], int n)
{
    int i;
    priority_queue q;
    /* counters */
    /* heap for heapsort */

    make_heap(&q,s,n);
    for (i=0; i<n; i++)
        s[i] = extract_min(&q);
}

int simpleFindeMinimum(int * s, int n, int *operations){
    int i;
    int minimum;

    minimum = s[0];

    for(i = 1; i < n; i++){
        
        if( s[i] < minimum ){
            minimum = s[i];
        }
    }

   *operations += n; 

   return minimum;
}

int deleteMinimum(int * s, int start, int end, int minimum ){
    int i;
    int swapVar;

    for(i = start; i < end; ++i){
    
        if( minimum == s[i] ){

            swap(s, i, start);

        }

    }

    return i;
}

int SelectionSort(int *s, int * sortedS, int n){
   int i;
   int operations = 0;

   for( i = 0; i < n; ++i){
        sortedS[i] = simpleFindeMinimum(s, n, &operations );
        operations+=deleteMinimum(s, i, n, *sortedS);
        operations++;
   }

   return operations;

}

int heap_compare(priority_queue *q, int i, int count, int x)
{
    if ((count <= 0) || (i > q->n))
        return(count);

    
    if (q->q[i] < x) {
        count = heap_compare(q, pq_young_child(i), count-1, x);
        count = heap_compare(q, pq_young_child(i)+1, count, x);
    }

    return(count);
}