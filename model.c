#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
    {5,10} 
};

#define train_count sizeof(train)/sizeof(train[0])

float rand_float(void){
    
    return (float) rand() / (float) RAND_MAX;
}

float cost(float w , float b){
    float result = 0.0f;
    for(int i=0; i<train_count; i++){
        float x = train[i][0];
        float y = (x*w)+b;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    // printf("%f\n", result);
    return result;
};

int main(){
    srand(time(0));
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;
    float lr = 1e-3;
    float eps=1e-3;
    for(size_t i=0; i<500;i++){
       float dw = (cost(w+eps , b) - cost(w , b))/eps;
       float db = (cost(w, b+eps) - cost(w , b))/eps;
       w-= lr*dw;
       b -= lr*db;
       printf("%f\n", cost(w , b));

    }
    printf("------------\n");
    printf("%f\n", w );
    return 0;
}