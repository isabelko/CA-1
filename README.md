# Coding Assignment #1
##### By: Isak Sabelko

## How to run my program

In the terminal you would type "./compile.sh" which has "gcc producer.c -pthread -lrt -o producer
and gcc consumer.c -pthread -lrt -o consumer" in it. Next you would type "./producer & ./consumer"
which will then run the 2 processes. 

## What does my code do?

My producer will pass char's starting from 'a' and will continue moving up the alphabet until 
the TOTAL_CONS_PRODUCE variable is reached. The TOTAL_CONS_PRODUCE variable determines how many times the producer and consumer will produce and consume a variable. I have the value to be 20 right now so it will produce and consume 20 variables meaning it should end by producing the variable 't' and then consumer 't'. The buffer size is set to 2 and the text that prints will tell the user if the varibale was placed or consumed from the first or second slot in the buffer. The text also states what variable was produced or recieved. 

## Challenges

The biggest challenge I faced was making sure the consumer and producer were in synch. I had it at one point where the producer was overriding its own data and wasn't letting the consumer consume data so I was losing data I had passed. By solving this cahllenge I was then only able to producer one variable then consume said variable. I couldn't find a way to have the producer and consumer produce and consume at random without losing data. This leads me to some issues with my code.

## Issues

One issue I had was that I couldn't find a way to have the producer and consumer produce and consume at random without losing data. So my code currently will produce a value and store it in the first location and then the consumer will consume that value. The prodcer will then produce a value and store it in the second location and the consumer will consume from that location. It will then produce and consume in the first location and continue this loop. Another issue is that my code will run completely through but once it finishes you have to hit enter at the end in order to kill the processes and memory space allocated. 

## Lessons

I learned how to create a shared memory space. I also learned about how to use semaphores in order to make sure the producer didn't produce too many variables and the consumer wasn't consuming too many variables. 


## Output of program 
```code 
producer sent value "a" to location 0
Consumer recieved data from location 0: it recieved the value "a"
producer sent value "b" to location 1
Consumer recieved data from location 1: it recieved the value "b"
producer sent value "c" to location 0
Consumer recieved data from location 0: it recieved the value "c"
producer sent value "d" to location 1
Consumer recieved data from location 1: it recieved the value "d"
producer sent value "e" to location 0
Consumer recieved data from location 0: it recieved the value "e"
producer sent value "f" to location 1
Consumer recieved data from location 1: it recieved the value "f"
producer sent value "g" to location 0
Consumer recieved data from location 0: it recieved the value "g"
producer sent value "h" to location 1
Consumer recieved data from location 1: it recieved the value "h"
producer sent value "i" to location 0
Consumer recieved data from location 0: it recieved the value "i"
producer sent value "j" to location 1
Consumer recieved data from location 1: it recieved the value "j"
producer sent value "k" to location 0
Consumer recieved data from location 0: it recieved the value "k"
producer sent value "l" to location 1
Consumer recieved data from location 1: it recieved the value "l"
producer sent value "m" to location 0
Consumer recieved data from location 0: it recieved the value "m"
producer sent value "n" to location 1
Consumer recieved data from location 1: it recieved the value "n"
producer sent value "o" to location 0
Consumer recieved data from location 0: it recieved the value "o"
producer sent value "p" to location 1
Consumer recieved data from location 1: it recieved the value "p"
producer sent value "q" to location 0
Consumer recieved data from location 0: it recieved the value "q"
producer sent value "r" to location 1
Consumer recieved data from location 1: it recieved the value "r"
producer sent value "s" to location 0
Consumer recieved data from location 0: it recieved the value "s"
producer sent value "t" to location 1
Consumer recieved data from location 1: it recieved the value "t"
```
