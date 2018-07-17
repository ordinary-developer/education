#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

static pthread_mutex_t func_mutex = PTHREAD_MUTEX_INITIALIZER;
void func() {
    pthread_mutex_lock(&func_mutex);
    
    pthread_mutex_unlock(&func_mutex);
    
}
int main(int argc, char** argv) {
    func();
    
    exit(0);
}