spoj/problems/CRYPTO2/

[-],>[-],>[-],+         read input and plus 1

>[-]>[-]                copy least significant digit to next cell
<<[->+>+<<]
>>[-<<+>>]

>+++++ +++++[<+++++ +>-]<---   character '9' = 57
>[-]>[-]>[-]
<<<<[
    >>>+
    <<[->>[-]>+<<<]
    >>[-<+>]
    >[-<<<+>>>]
    <<<-<-
]

>>[                     if last digit greater than 9
    <<<<+               add 1 to previous second last digit
    >----- -----        minus current digit by 10
    >>>[-]
]

same logic for second last digit
<+++++ +++++[-]
<+++++ +++++[-]

<<[->>+>+<<<]
>>>[-<<<+>>>]

>+++++ +++++[<+++++ +>-]<---  character '9' = 57
>[-]>[-]>[-]
<<<<[
    >>>+
    <<[->>[-]>+<<<]
    >>[-<+>]
    >[-<<<+>>>]
    <<<-<-
]

>>[
    <<<<<+
    >----- -----
    >>>>[-]
]

<<<<<
.>.>.
