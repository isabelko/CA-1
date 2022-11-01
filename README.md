# Coding Assignment #1
##### By: Isak Sabelko

## How to run my program

In the terminal you would type ./compile.sh which has "gcc producer.c -pthread -lrt -o producer
and gcc consumer.c -pthread -lrt -o consumer" in it. Next you would type ./producer & ./consumer
which will then run the 2 processes. 

##What does my code do?

My producer will pass char's starting from 'a' and will continue moving up the alphabet until 
the TOTAL_CONS_PRODUCE variable is reached. The TOTAL_CONS_PRODUCE variable determines how many times the producer and consumer will produce and consume a variable. I have the value to be 20 right now so it will produce and consume 20 variables meaning it should end by producing the variable 't' and then consumer 't'. The buffer size is set to 2 and the text that prints will tell the user if the varibale was placed or consumed from the first or second slot in the buffer. The text also states what variable was produced or recieved. 

##challenges

