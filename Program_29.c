/*
============================================================================
Name : Program 29 
Author : Hari Prasad C
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR). 
Date: 6th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

void get_policy ( int sch ) {
	if ( sch & SCHED_FIFO ) printf ("FIFO\n");
	else if ( sch & SCHED_RR   ) printf ("RR\n");
	else printf ("SCHED_OTHER\n");
}

int main() {
	pid_t id;
	id = getpid();
	struct sched_param param;

	int sch = sched_getscheduler(id);
	printf ("Initial Scheduling Policy : ");
	get_policy(sch);

	param.sched_priority = 25;
	if ( -1 == sched_setscheduler(id, SCHED_FIFO, &param)) {
		perror ("Set Scheduler Error");
		return -1;
	}

	sch = sched_getscheduler(id);
	printf ("Changed Scheduling Policy : ");
       	get_policy(sch);

	if ( -1 == sched_setscheduler(id, SCHED_RR, &param)) {
		perror ("Set Scheduler Error");
		return -1;
	}

	sch = sched_getscheduler(id);
	printf ("Changed Scheduling Policy : ");
	get_policy(sch);

	return 0;
}
