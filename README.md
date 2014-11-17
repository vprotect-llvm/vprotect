Motivation
==========
Code­Pointer Separation [1] (CPS) is a new technique that provides protection against 
control­flow hijack attacks for programs written in C/C++, without imposing undue 
performance overhead. CPS separates code pointers from the rest of data in program 
memory and ensures that code pointers cannot be directly modified by corrupt 
non­code­pointer memory accesses, which prevents an attacker from forging code­pointers. 
 
In presence of indirection, an attacker might be able to cause a CPS­protected program to 
use different code pointer than what the programmer intended (as long as that pointer was 
previously taken and stored in memory). Normally, this flexibility is not enough to perform a 
control­flow hijack attack, but it might be enough to trick a program to perform certain 
undesirable actions, especially when the number of functions that are called indirectly is large. 
CPI policy prevents this at a cost of imposing higher performance overhead then CPS. 
 
One common example of programs with large number of indirectly callable functions are 
programs written in C++ that use virtual functions. Fortunately, C++ type­based rules for 
virtual function calls restrict the set of possible targets of each such call to a limited set, as 
determined by class inheritance. Enforcing these rules at runtime, as proposed by VTV [2], 
significantly reduces the flexibility of an attacker to change the control flow of a program. 
Combined with CPS, such protection could provide extra security guarantees for C++ 
programs that use virtual functions extensively. Moreover, we believe that such virtual 
function call protection can be enforced without imposing much overhead (in particular, with 
lower overhead than the original VTV [2]). 

Project Goal
============ 
Implement low­overhead virtual call protection mechanism on top of CPS, as described 
above. The mechanism should ensure that, despite any memory corruptions during program 
execution, at each virtual function callsite that calls a method f() of class C (according to the 
static type of the callsite), the program may only call f() itself or any method that overwrites f() 
in some subclass of C. 
 
The key idea behind fast implementation of virtual call protection mechanism is to place virtual 
tables in memory in a such a way that would enable performing the check described above 
without any extra memory accesses (in fact, two comparisons and a bitmask should be 
sufficient). This idea is to be discussed in person at the start of the project. Evaluation criteria
 
The following provides an overall evaluation criteria for the project. Passing criteria is required 
to get 4, excellence criteria is required to get 6. Note that each milestone outlined below will 
be graded separately and the final grade will be averaged. 
 
Passing criteria: 
-----------------
Test the implemented protection mechanism on SPEC2006 benchmark and 
demonstrate that, for all benchmarks written in C++ that do not mix multiple inheritance with 
virtual functions: 
1. The benchmarks successfully compile with the protection mechanism when the 
link­time optimizations are enabled and run without errors on SPEC workloads. 
2. The mechanism prevents at least 5 manually injected vulnerabilities. 
3. The overhead of the protection on the “ref” workload is less than or equals to the 
reported overhead of VTV [2]. 
 
Excellence criteria: 
--------------------
4. The overhead of the protection mechanism is within 1­2% (or explain why this is not 
possible to achieve). 
5. The mechanism supports separate compilation (i.e., SPEC can be compiled without 
link­time optimizations). 
6. The mechanism fully supports multiple inheritance. 
 
Bonus: 
------
7. The mechanism works on Phoronix benchmark that are used in the CPI paper [1]. 
8. The mechanism prevents at least one real exploits that overwrite virtual table pointers. 
