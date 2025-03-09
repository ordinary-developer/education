#lang sicp

; [exercise] =>
; Ben Bitdiddle has invetend a test to determine
; whether the interpreter he is faced with
; is using applicative-order evalution or normal-order evaluation.
; He defines the following two procedures:
; (define (p) (p))
; (define (test x y)
;     (if (= x 0) 0 y))
;
; Then he evaluates the expression
; (test 0 (p))
;
; What behavior will Ben observe with an interpreter
; that uses applicative-order evaluation?
; What behavior will he observe with an interpreter
; that uses normal-order evalution?
; Explain your answer.
;
; (Assume that the evaluation rule for the special form 'if'
;   is the same whether the interpreter is using normal or applicative order:
;  The predicate expression is evaluated first,
;  and the result determines whether to evaluate the consequent
;  or the alternative expression.)



; -------------
; [solution] =>
; # Applicative order
; (test 0 (p))
; will become
; (if (= 0 0) 0 (p))
; after that it will become
; (if (= 0 0) 0 (p))
; and so on.
; So this evaluation will never be completed.

; # Normal order
; (test 0 (p))
; will become
; (if (= 0 0) 0 (p))
; after that according to normal-order evaluation rules it will become
; (if (#t) 0 (p))
; and after that it will become
; 0
; So in this case the result of (test 0 (p)) will be '0'.
