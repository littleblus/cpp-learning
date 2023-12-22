#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

int tickets = 20;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* getTickets(void* arg) {
    unsigned long num = reinterpret_cast<unsigned long>(arg);
    while (true) {
        pthread_mutex_lock(&mtx);
        pthread_cond_wait(&cond, &mtx);
        if (tickets > 0) {
            usleep(3000);
            cout << "Thread " << num << " get ticket " << tickets << endl;
            tickets--;
            pthread_cond_signal(&cond);
        }
        else if (tickets == 0) {
            cout << "No more tickets" << endl;
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mtx);
            break;
        }
        pthread_mutex_unlock(&mtx);
    }
    return nullptr;
}

int main() {
    vector<pthread_t> vt;
    for (unsigned long i = 0; i < 4; i++) {
        pthread_t tid;
        pthread_create(&tid, nullptr, getTickets, reinterpret_cast<void*>(i));
        vt.push_back(tid);
    }
    sleep(1);
    pthread_cond_signal(&cond);
    for (int i = 0; i < 4; i++) {
        pthread_join(vt[i], nullptr);
    }
    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cond);
    return 0;
}