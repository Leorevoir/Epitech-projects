/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-raphael.petrequin
** File description:
** bucket
*/

#include "peinture.h"

bucket_t *create_bucket(int size)
{
    bucket_t *bucket = malloc(sizeof(bucket_t));

    bucket->x = malloc(sizeof(int) * size);
    bucket->y = malloc(sizeof(int) * size);
    bucket->front = 0;
    bucket->rear = 0;
    bucket->size = size;
    return bucket;
}

void enqueue_bucket(bucket_t *bucket, int x, int y)
{
    bucket->x[bucket->rear] = x;
    bucket->y[bucket->rear] = y;
    bucket->rear = (bucket->rear + 1) % bucket->size;
}

void dequeue_bucket(bucket_t *bucket, int *x, int *y)
{
    *x = bucket->x[bucket->front];
    *y = bucket->y[bucket->front];
    bucket->front = (bucket->front + 1) % bucket->size;
}

void free_bucket(bucket_t *bucket)
{
    free(bucket->x);
    free(bucket->y);
    free(bucket);
}
