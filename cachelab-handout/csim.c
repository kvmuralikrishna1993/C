#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <strings.h>
#include <math.h>

#include "cachelab.h"

/*64 bit address to hold memory */
typedef unsigned long long int memoryaddress;

/* a struct that groups cache parameters together */
typedef struct {
	int s; /* 2**s cache sets */
	int b; /* cacheline block size 2**b bytes */
	int E; /* number of cachelines per set */
	int S; /* number of sets, derived from S = 2**s */
	int B; /* cacheline block size (bytes), derived from B = 2**b */

	int hits;
	int misses;
	int evicts;
} cache_parameters;

/* Structure of set line */
typedef struct {
	int last_used;
	int valid;
	memoryaddress tag;
} set_line;

/* Structure of cache set */
typedef struct {
	set_line *lines;
} cache_set;

/* Structure of cache */
typedef struct {
	 cache_set *sets;
} cache;



/* build a cache from the input paramaters */
cache build(long long num_sets, int num_lines) 
{

	cache new_cache;	
	cache_set set;
	set_line line;
	int setIndex;
	int lineIndex;

	new_cache.sets = (cache_set *) malloc(sizeof(cache_set) * num_sets);

	for (setIndex = 0; setIndex < num_sets; setIndex++) 
	{
		
		set.lines =  (set_line *) malloc(sizeof(set_line) * num_lines);
		new_cache.sets[setIndex] = set;

		for (lineIndex = 0; lineIndex < num_lines; lineIndex++) 
		{
			
			line.last_used = 0;
			line.valid = 0;
			line.tag = 0; 
			set.lines[lineIndex] = line;	
		}
		
	} 

	return new_cache;
	
}

/* Finds an empty line in the given cache set */
int find_empty_line(cache_set query_set, cache_parameters par) {
	int num_lines = par.E;
	int index;
	set_line line;

	for (index = 0; index < num_lines; index ++) {
		line = query_set.lines[index];
		if (line.valid == 0) {
			return index;
		}
	}	
	return -1;
}

/* Finds the least used line to evict from the cache */
int find_evict_line(cache_set query_set, cache_parameters par, int *used_lines) {

	int num_lines = par.E;
	int min_used = query_set.lines[0].last_used;
	int max_used = query_set.lines[0].last_used;
	int min_used_index = 0;

	set_line line; 
	int lineIndex;

	for (lineIndex = 1; lineIndex < num_lines; lineIndex ++) {
		line = query_set.lines[lineIndex];

		if (min_used > line.last_used) {
			min_used_index = lineIndex;	
			min_used = line.last_used;
		}

		if (max_used < line.last_used) {
			max_used = line.last_used;
		}

	}

	used_lines[0] = min_used;
	used_lines[1] = max_used;
	return min_used_index;
}

/* Runs the cache simulation */
cache_parameters run_sim(cache sim_cache, cache_parameters par, memoryaddress address) {
		
		int lineIndex;
		int cache_full = 1;

		int num_lines = par.E;
		int prev_hits = par.hits;

		int tag_size = (64 - (par.s + par.b));
		memoryaddress input_tag = address >> (par.s + par.b);
		unsigned long long temp = address << (tag_size);
		unsigned long long setIndex = temp >> (tag_size + par.b);
		
  		cache_set query_set = sim_cache.sets[setIndex];

		for (lineIndex = 0; lineIndex < num_lines; lineIndex ++) 	{
			
			set_line line = query_set.lines[lineIndex];
			
			if (line.valid) {
					
				if (line.tag == input_tag) {
						
					line.last_used ++;
					par.hits ++;
					query_set.lines[lineIndex] = line;
				}

			} else if (!(line.valid) && (cache_full)) {
				//We found an empty line
				cache_full = 0;		
			}

		}	

		if (prev_hits == par.hits) {
			//Miss in cache;
			par.misses++;
		} else {
			//Data is in cache
			return par;
		}

		//We missed, so evict if necessary and write data into cache.
		
		int *used_lines = (int*) malloc(sizeof(int)*2);
		int min_used_index = find_evict_line(query_set, par, used_lines);	

		if (cache_full) 
		{
			par.evicts++;

			//Found least-recently-used line, overwrite it.
			query_set.lines[min_used_index].tag = input_tag;
			query_set.lines[min_used_index].last_used = used_lines[1]+1;		
		}

		else
	        {
			int empty_index = find_empty_line(query_set, par);

			//Found first empty line, write to it.
			query_set.lines[empty_index].tag = input_tag;
			query_set.lines[empty_index].valid = 1;
			query_set.lines[empty_index].last_used = used_lines[1]+1;
		}						

		free(used_lines);
		return par;
}

/* Main function */
int main(int argc, char **argv)
{
	
	cache sim_cache;
	cache_parameters par;

	long long num_sets;
 
	FILE *read_trace;
	char trace_cmd;
	memoryaddress address;
	int size;
	
	char *trace_file;
	char c;
    while( (c=getopt(argc,argv,"s:E:b:t:vh")) != -1)
	{
        switch(c)
		{
        case 's':
            par.s = atoi(optarg);
            break;
        case 'E':
            par.E = atoi(optarg);
            break;
        case 'b':
            par.b = atoi(optarg);
            break;
        case 't':
            trace_file = optarg;
            break;
        default:
        	break;
        }
    }

    if (par.s == 0 || par.E == 0 || par.b == 0 || trace_file == NULL) 
	{
        printf("%s: Missing required command line argument\n", argv[0]);
        exit(1);
    }

	
	// We need to compute S
	num_sets = pow(2.0, par.s);
	par.hits = 0;
	par.misses = 0;
	par.evicts = 0;
	
	sim_cache = build(num_sets, par.E);
 	
	// fill in rest of the simulator routine
	read_trace  = fopen(trace_file, "r");
	
	
	if (read_trace != NULL) {
		while (fscanf(read_trace, " %c %llx,%d", &trace_cmd, &address, &size) == 3) {

		
			switch(trace_cmd) {
				case 'I':
					break;
				case 'L':
					par = run_sim(sim_cache, par, address);
					break;
				case 'S':
					par = run_sim(sim_cache, par, address);
					break;
				case 'M':
					par = run_sim(sim_cache, par, address);
					par = run_sim(sim_cache, par, address);	
					break;
				default:
					break;
			}
		}
	}
	
	/* Prints the summary of hits, misses and evictions */	
   	printSummary(par.hits, par.misses, par.evicts);
	fclose(read_trace);

    return 0;
}

