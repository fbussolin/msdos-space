.model large

.data
PUBLIC          __pressed_keys_
                __pressed_keys_            db      256 dup(0)
oldint9         dd      0
e0flag          db      0
kSYSREQ         EQU     054h
kCAPSLOCK       EQU     03Ah
kNUMLOCK        EQU     045h
kSCROLLLOCK     EQU     046h
kLEFTCTRL       EQU     01Dh
kLEFTALT        EQU     038h
kLEFTSHIFT      EQU     02Ah
kRIGHTCTRL      EQU     09Dh
kRIGHTALT       EQU     0B8h
kRIGHTSHIFT     EQU     036h
kESC            EQU     001h
kBACKSPACE      EQU     00Eh
kENTER          EQU     01Ch
kSPACE          EQU     039h
kTAB            EQU     00Fh
kF1             EQU     03Bh
kF2             EQU     03Ch
kF3             EQU     03Dh
kF4             EQU     03Eh
kF5             EQU     03Fh
kF6             EQU     040h
kF7             EQU     041h
kF8             EQU     042h
kF9             EQU     043h
kF10            EQU     044h
kF11            EQU     057h
kF12            EQU     058h
kA              EQU     01Eh
kB              EQU     030h
kC              EQU     02Eh
kD              EQU     020h
kE              EQU     012h
kF              EQU     021h
kG              EQU     022h
kH              EQU     023h
kI              EQU     017h
kJ              EQU     024h
kK              EQU     025h
kL              EQU     026h
kM              EQU     032h
kN              EQU     031h
kO              EQU     018h
kP              EQU     019h
kQ              EQU     010h
kR              EQU     013h
kS              EQU     01Fh
kT              EQU     014h
kU              EQU     016h
kV              EQU     02Fh
kW              EQU     011h
kX              EQU     02Dh
kY              EQU     015h
kZ              EQU     02Ch
k1              EQU     002h
k2              EQU     003h
k3              EQU     004h
k4              EQU     005h
k5              EQU     006h
k6              EQU     007h
k7              EQU     008h
k8              EQU     009h
k9              EQU     00Ah
k0              EQU     00Bh
kMINUS          EQU     00Ch
kEQUAL          EQU     00Dh
kLBRACKET       EQU     01Ah
kRBRACKET       EQU     01Bh
kSEMICOLON      EQU     027h
kTICK           EQU     028h
kAPOSTROPHE     EQU     029h
kBACKSLASH      EQU     02Bh
kCOMMA          EQU     033h
kPERIOD         EQU     034h
kSLASH          EQU     035h
kINS            EQU     0D2h
kDEL            EQU     0D3h
kHOME           EQU     0C7h
kEND            EQU     0CFh
kPGUP           EQU     0C9h
kPGDN           EQU     0D1h
kLARROW         EQU     0CBh
kRARROW         EQU     0CDh
kUARROW         EQU     0C8h
kDARROW         EQU     0D0h
kKEYPAD0        EQU     052h
kKEYPAD1        EQU     04Fh
kKEYPAD2        EQU     050h
kKEYPAD3        EQU     051h
kKEYPAD4        EQU     04Bh
kKEYPAD5        EQU     04Ch
kKEYPAD6        EQU     04Dh
kKEYPAD7        EQU     047h
kKEYPAD8        EQU     048h
kKEYPAD9        EQU     049h
kKEYPADDEL      EQU     053h
kKEYPADSTAR     EQU     037h
kKEYPADMINUS    EQU     04Ah
kKEYPADPLUS     EQU     04Eh
kKEYPADENTER    EQU     09Ch
kCTRLPRTSC      EQU     0B7h
kSHIFTPRTSC     EQU     0B7h
kKEYPADSLASH    EQU     0B5h

.code

                        PUBLIC _set_new_int9
_set_new_int9           PROC    FAR
                push    ds
                cli

                mov     ax,3509h                ; get old INT 9
                int     21h
                mov     si,offset oldint9
                mov     [si],bx                 ; save offset
                mov     [si + 2],es             ; save segment

                mov     ax,2509h                ; set new INT 9
                mov     dx,seg _New_Int9
                mov     ds,dx
                mov     dx,offset _New_Int9
                int     21h

                sti
                pop     ds
                ret
_set_new_int9           ENDP

                        PUBLIC _set_old_int9
_set_old_int9           PROC    FAR
                push    ds
                cli

                mov     ax,2509h                ; set new INT 9
                mov     si,offset oldint9
                mov     dx,word ptr [si]        ; load offset
                mov     ds,word ptr [si + 2]    ; load segment
                int     21h

                sti
                pop     ds
                ret
_set_old_int9           ENDP

_New_Int9       PROC    FAR
                cli
                push    ds
                push    ax
                push    bx

                mov     ax,@data
                mov     ds,ax

                in      al,60h          ; Get scan code in AL
                cmp     al,0E0h         ; was it an E0 key?
                jne     setscancode

; E0 key routine
                mov     [e0flag],128
                mov     al,20h          ; Send generic EOI to PIC
                out     20h,al          ; 001 00 000
                                        ;  |   |  |
                                        ;  |   |  +--- INT request level
                                        ;  |   +------ OCW2
                                        ;  +---------- non-specific EOI command
                pop     bx
                pop     ax
                pop     ds
                sti
                iret

setscancode:    mov     bl,al                   ; Save scan code in BL
                and     bl,01111111b
                add     bl,[e0flag]
                xor     bh,bh                   ; clear for index use
                and     al,10000000b            ; keep break bit, if set
                xor     al,10000000b            ; flip bit - 1 means pressed
                                                ;          - 0 means released
                rol     al,1                    ; put it in bit 0
                mov     [__pressed_keys_ + bx],al         ; set index for key
                mov     [e0flag],0

                mov     al,20h          ; Send generic EOI to PIC
                out     20h,al          ; 001 00 000
                                        ;  |   |  |
                                        ;  |   |  +--- INT request level
                                        ;  |   +------ OCW2
                                        ;  +---------- non-specific EOI command
                pop     bx
                pop     ax
                pop     ds
                sti
                iret
_New_Int9       ENDP

                END
