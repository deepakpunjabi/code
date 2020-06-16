# Queue

- Follows FIFO: first in last out, eg. line of people waiting for their order to be served
- front: start of the queue
- rear: end of the queue
- enqueue: insert into the queue
- dequeue: delete from the queue

## Types of Queue

- single ended queue: insert at back, delete from front
- double ended queue: insert/delete from front/back, can do rear+1 or rear-1 based on operation
- circular queue: use: reutilize deleted element space, need to keep `count/size` to implement `isEmpty()` and `isFull`

## Notes

- `q.pop()` does not return front element, you need to explicitly call `q.front()`

## Example Problems

- rotate a string by n
- invert a binary tree iteratively
