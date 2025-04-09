#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#define OXY_SEM_NAME "/OXY"
#define HYDRO_SEM_NAME "/HYDRO"

void* make_oxygen(void* _m);
void* make_hydrogen(void* _m);
typedef struct {
    sem_t* hydro_sem_ready;
    sem_t* hydro_sem_release;
    sem_t* hydro_sem_done;
    pthread_mutex_t mtx;
}WaterMolecule_t;

pthread_t oxy_thread, hyd_thread, generate_thread;

void semaphore_ex__init_molecule(WaterMolecule_t* m) {
    assert(m != NULL);

    sem_unlink("/SEM_READY");
    sem_unlink("/SEM_RELEASE");
    sem_unlink("/SEM_DONE");
    m->hydro_sem_ready = sem_open("/SEM_READY", O_CREAT, 0644, 0);
    m->hydro_sem_release = sem_open("/SEM_RELEASE", O_CREAT, 0644, 0);
    m->hydro_sem_done = sem_open("/SEM_DONE", O_CREAT, 0644, 0);
    pthread_mutex_init(&m->mtx, NULL);
}

void semaphore_ex__destruct_molecule(WaterMolecule_t* m) {
    assert(m != NULL);
}

void* generate_elements(void* _m) {
    assert(_m != NULL);
    WaterMolecule_t* m = (WaterMolecule_t*)_m;
    while (1) {
        /*if (rand() % 2 == 0) {*/
        /*    pthread_t oxy_thread;*/
        /*    pthread_create(&oxy_thread, NULL, make_oxygen, &m);*/
        /*} else {*/
        /*    pthread_t hyd_thread;*/
        /*    pthread_create(&hyd_thread, NULL, make_hydrogen, &m);*/
        /*}*/

        
        pthread_t hyd_thread1, hyd_thread2, oxy_thread;
        pthread_create(&hyd_thread, NULL, make_hydrogen, &m);
        pthread_create(&hyd_thread, NULL, make_hydrogen, &m);
        pthread_create(&hyd_thread, NULL, make_hydrogen, &m);
        pthread_create(&oxy_thread, NULL, make_oxygen, &m);
        sleep(1);
    }
    return NULL;
}
void* make_hydrogen(void* _m) {
    assert(_m != NULL);
    WaterMolecule_t* m = (WaterMolecule_t*)_m;
    sem_post(m->hydro_sem_ready);
    sem_wait(m->hydro_sem_release);

    printf("H");
    fflush(stdout);

    sem_post(m->hydro_sem_done);
    return NULL;
}
void* make_oxygen(void* _m) {
    assert(_m != NULL);
    WaterMolecule_t* m = (WaterMolecule_t*)_m;

    pthread_mutex_lock(&m->mtx);

    sem_wait(m->hydro_sem_ready);
    sem_wait(m->hydro_sem_ready);

    sem_post(m->hydro_sem_release);
    sem_post(m->hydro_sem_release);

    sem_wait(m->hydro_sem_done);
    sem_wait(m->hydro_sem_done);

    pthread_mutex_unlock(&m->mtx);

    printf("O");
    fflush(stdout);

    return NULL;
}

int main() {
    WaterMolecule_t m;
    semaphore_ex__init_molecule(&m);

    /*pthread_create(&oxy_thread, NULL, make_oxygen, &m);*/
    /*pthread_create(&hyd_thread, NULL, make_hydrogen, &m);*/
    pthread_create(&generate_thread, NULL, generate_elements, &m);


    /*pthread_join(oxy_thread, NULL);*/
    /*pthread_join(hyd_thread, NULL);*/
    pthread_join(generate_thread, NULL);

    semaphore_ex__destruct_molecule(&m);
    return 0;

}
