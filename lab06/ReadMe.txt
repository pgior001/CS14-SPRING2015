The algoritum is not stable. This is because the way it sorts swaps the lowest value
with the current position. So it the lowest value is right after another element in the
list with the same value it will have swaped them out of order. This is shown in
my test case in the selectionsort.h called void question2(). 6 and two fives are entered into the list.
They are given a pair so you can trak them (5,1) (5,2) (4,0). When this function
sorts the (5,2) will end up before (5, 1) because the first and last element
are swaped because last is least and then the list is in order leaveing (5,1)
after (5,2).