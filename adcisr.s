


    extern     _adc_isr
    extern     _OSIntExit
    extern     _OSIntNestingCtr
    extern     _OSTCBCurPtr

;/*$PAGE*/
;********************************************************************************************************
;                                             AdcIsr()
;********************************************************************************************************

    section .text:CODE:ROOT

    public  _AdcIsr

_AdcIsr:

    PUSHC   FPSW                        ; Save processor registers on the stack
    PUSHM   R1-R15
    MVFACHI R1
    MVFACMI R2
    PUSHM   R1-R2

    MOV.L   #_OSIntNestingCtr, R5       ; Notify uC/OS-III about ISR
    MOV.B   [R5], R3
    ADD     #1, R3
    MOV.B   R3, [R5]

    CMP     #1, R3                      ; if (OSNestingCtr == 1)
    BNE     _AdcIsr1
    MOV.L   #_OSTCBCurPtr, R5           ; Save current task's SP into its TCB
    MOV.L   [R5], R3
    MOV.L   R0, [R3]

_AdcIsr1  MOV.L   #_adc_isr, R5
    JSR     R5

    MOV.L   #_OSIntExit, R5
    JSR     R5                          ; Notify uC/OS-III about end of ISR

    POPM    R1-R2                       ; Restore processor registers from stack
    SHLL    #16, R2
    MVTACLO R2
    MVTACHI R1
    POPM    R1-R15
    POPC    FPSW

    RTE

    end

