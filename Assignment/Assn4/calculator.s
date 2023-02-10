#
# Filename: calculator.s

# Description: Assignment 4 - Question 3

# Name: Van Khai Nguyen & Duc Manh To

# Date: Feb 09, 2023
#

	.globl	isLess # Make sure you change the name of this function - see XX function below
	.globl	plus
	.globl	minus
	.globl	mul


isLess: # Description: Return 1 if the first argument is less than the second argument
    # Change the name of this function to something more descriptive and add a description above
	xorl	%eax, %eax
	cmpl	%esi, %edi
	setl	%al         # See Section 3.6.2 of our textbook for a  
	ret                 # description of the set* instruction family

plus: # Description: Performs integer addition
# Requirement:
# - you cannot use add* instruction
# - you cannot use a loop
	leal (%edi, %esi), %eax # x (%edi) + y (%esi) then load to return value (%eax)
	ret

# Put your code here


minus: # Description: Performs integer subtraction
# Requirement:
# - you cannot use sub* instruction
# - you cannot use a loop
	negl %esi # negate y (%esi)
	leal (%edi, %esi), %eax # x (R[%edi]) + y (R[%esi]) then load to return value (%eax)
	ret

# Put your code here


mul: # Description: Performs integer multiplication - when both operands are non-negative!
# You can assume that both operands are non-negative.
# Requirements:
# - you cannot use imul* instruction 
#   (or any kind of instruction that multiplies such as mul)
# - you must use a loop
	xorl %eax, %eax # return (%eax) = 0
    jmp cond # jump to condition

	loop:
    	addl %edi, %eax # return (%eax) += x (%edi)
    	subl $1, %esi # y (%esi) -= 1

	cond:
    	testl %esi, %esi # check if y (%esi) > 0
    	jg loop # if y > 0, then jump to loop
    ret
# algorithm:
# set answer to 0
# if (y < 0) , answer += x
# subtract 1 from y
# continue loop until y < 0
# return answer

# Put your code here