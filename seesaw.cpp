/*
 * Author: Majid Aziz
 * email: aziz112@mail.chapman.edu
 * Date: 4/10/18
 * Program: Seesaw simulation of two people on either side with different velocities.
 *
 * */
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

void *fred_see(void* args);
void *wilma_see(void* args);

sem_t fred;
sem_t wilma;

double fred_height = 1.0;
double wilma_height = 7.0;

//This program is simple enough for no comments
int main(int argc, char* argv[])
{   
    int temp = sem_init(&fred,1,1);
    sem_init(&wilma,1,0);

    cout << "temp : " << temp << endl;

    pthread_t fred_thread;
    pthread_t wilma_thread;

    for(int i=0; i<10; i++)
    {
    pthread_create(&fred_thread, NULL, fred_see, NULL);
    pthread_join(fred_thread, NULL);
    pthread_create(&wilma_thread, NULL, wilma_see, NULL);
    pthread_join(wilma_thread, NULL);
    }

    return 0;
}
void *fred_see(void *args)
{
    sem_wait(&fred);
    while(fred_height < 7)
    {
        cout << "Fred's height:  " << fred_height << endl;
        cout << "Wilma's height: " << wilma_height << endl;
        fred_height++;
        wilma_height--;
        sleep(1);
    }
    cout << endl << "Fred's up" << endl << endl;
    sem_post(&wilma);
}

void *wilma_see(void *args)
{
    sem_wait(&wilma);
    while(wilma_height < 7 )
    {
        cout << "Fred's height:  " << fred_height << endl;
        cout << "Wilma's height: " << wilma_height << endl;
        fred_height -= 1.5;
        wilma_height += 1.5;
        sleep(1);
    }
    cout << endl << "Wilma's up" << endl << endl;
    sem_post(&fred);
}
