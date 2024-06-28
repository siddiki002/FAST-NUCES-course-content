#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
sem_t north_available,east_available,intersection_available_north,lock,intersection_available_east;
int neast,nnorth,intersection=0,iseast=0,isnorth=0,count1=0,count2=0;
void gosouth()
{
	for (int i=0;i<intersection;i++)
	{
		printf("Car %d is going North to south\n",i+1);
		//sleep(1);
	}
	//sem_wait(&lock);
	nnorth = nnorth-intersection;
	intersection=0;
	//sem_post(&lock);
	
	if(nnorth==0)
	{
	isnorth=0;
	sem_post(&intersection_available_east);}
	
	//sem_post(&east_available);
}
void* north_algo()
{
	if(iseast)
	{
		//count1++;
		//printf("Waiting for intersection to get free for north\n");
		sem_wait(&intersection_available_north);
		//printf("Intersection freed for north\n");
		//sem_post(&intersection_available);
		
	}
	isnorth = 1;
	sem_wait(&north_available);
	sem_wait(&lock);
	intersection++;
	sem_post(&lock);
	if(intersection==3)
	{
		count1-=3;
		sem_wait(&lock);
		gosouth();
		sem_post(&lock);
	}
	else if (intersection<3 && intersection==nnorth)
	{
		sem_wait(&lock);
		gosouth();
		sem_post(&lock);
	}
	else 
	{sem_post(&intersection_available_north);}
	sem_post(&north_available);
	
}
void go_west()
{
	//printf("go west () executed\n");
	//printf("Value of intersection = %d\n",intersection);
	for (int i=0;i<intersection;i++)
	{
		printf("Car %d is going east to west\n",i+1);
	}
	//sem_wait(&lock);
	neast = neast - intersection;
	intersection=0;
	//sem_post(&loiseast = 0;
	if(neast==0)
	{
	iseast=0;
	sem_post(&intersection_available_north);}
	
}

void* east_algo()
{
	if (isnorth)
	{
		//printf("Waiting for intersection to get free for east\n");
		sem_wait(&intersection_available_east);	
		//printf("Intersection freed for east\n");
		//sem_post(&intersection_available);
	}
	iseast=1;
	sem_wait(&east_available);
	sem_wait(&lock);
	intersection++;
	sem_post(&lock);
	if(intersection==3)
	{
		sem_wait(&lock);
		go_west();
		sem_post(&lock);
	}
	else if (intersection<3 && intersection==neast)
	{
		sem_wait(&lock);
		go_west();
		sem_post(&lock);
	}
	sem_post(&east_available);
	sem_post(&intersection_available_east);
	
	
}

int main()
{
	sem_init(&east_available, 0 , 1);
	sem_init(&north_available, 0 , 1);
	sem_init(&intersection_available_north, 0 , 0);
		sem_init(&intersection_available_east, 0 , 0);
	sem_init(&lock, 0 , 1);
	printf("Enter number of cars going east to west");
	scanf("%d",&neast);
	printf("Enter number of cars going north to south");
	scanf("%d",&nnorth);
	pthread_t threadEast[neast];
	pthread_t threadNorth[nnorth];
	for (long i=0,j=0;i<neast || j<nnorth;i++,j++)
	{
		if (i<neast)
		{
			pthread_create(&threadEast[i],NULL,east_algo,NULL);	
		}
		//sleep(1);
		if (j<nnorth)
		{
			pthread_create(&threadNorth[j],NULL,north_algo,NULL);
		}
		//sleep(1);
	}
	for(long i=0,j=0;i<neast || j<nnorth;i++,j++)
	{
		if (i<neast)
		{
			pthread_join(threadEast[i],NULL);
		}
		if (j<nnorth)
		{
			pthread_join(threadNorth[j],NULL);
		}
	}
}
