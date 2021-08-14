/*
 * This code is provided solely for the personal and private use of students
 * taking the CSC369H course at the University of Toronto. Copying for purposes
 * other than this use is expressly prohibited. All forms of distribution of
 * this code, including but not limited to public repositories on GitHub,
 * GitLab, Bitbucket, or any other online platform, whether as given or with
 * any changes, are expressly prohibited.
 *
 * Authors: Andrew Peterson, Karen Reid, Alexey Khrabrov
 *
 * All of the files in this directory and all subdirectories are:
 * Copyright (c) 2019, 2021 Karen Reid
 */

#include "pagetable.h"
#include "sim.h"
#include <stdlib.h>
#include <stdio.h>

static struct Node *last;

/* Page to evict is chosen using the accurate MRU algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */
int mru_evict(void)
{
	//TODO
	int ans = 0;
	if (last != NULL)
	{
		// we will delete the last element (the newest element)
		struct Node *toDelete = last;

		// record its page frame number
		ans = toDelete->index;

		// init its page frame number
		toDelete->index = -1;

		//remove it from the linked list
		last = last->previous;

		if (last != NULL)
		{
			last->next = NULL;
		}
	}
	return ans;
}

/* This function is called on each access to a page to update any information
 * needed by the MRU algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void mru_ref(pt_entry_t *pte)
{
	//TODO
	struct frame *curr = &(coremap[pte->frame >> PAGE_SHIFT]);
	// if it's already the last one, we don't need to add again
	if (last == NULL || (int)(pte->frame >> PAGE_SHIFT) != last->index)
	{
		// we need to remove the curr's node from our linked list first
		if (curr->node->index >= 0)
		{
			if (curr->node->next)
			{
				curr->node->next->previous = curr->node->previous;
			}
			if (curr->node->previous)
			{
				curr->node->previous->next = curr->node->next;
			}
		}

		// add the node back into the linked list as a new element
		if (last != NULL)
		{
			last->next = curr->node;
		}
		curr->node->previous = last;
		last = curr->node;
		curr->node->next = NULL;
		curr->node->index = (int)(pte->frame >> PAGE_SHIFT);
	}
}

/* Initialize any data structures needed for this replacement algorithm. */
void mru_init(void)
{
	//TODO

	// keep track of the end of the linked list (the newest added element)
	last = NULL;

	// init the coremap 's node
	for (size_t i = 0; i < memsize; i++)
	{
		coremap[i].node = malloc(sizeof(struct Node));
		coremap[i].node->previous = NULL;
		coremap[i].node->next = NULL;
		coremap[i].node->index = 0;
	}
}

/* Cleanup any data structures created in mru_init(). */
void mru_cleanup(void)
{
	//TODO
	last = NULL;

	// free the coremap's node
	for (size_t i = 0; i < memsize; i++)
	{
		free(coremap[i].node);
	}
}
