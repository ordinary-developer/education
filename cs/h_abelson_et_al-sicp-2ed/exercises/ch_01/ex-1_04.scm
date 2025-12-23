#lang sicp

; [exercise] =>
; Observe that our model of evaluation allows for combinations
; whose operators are compound expressions.
; Use this observation to describe the behavior of the following procedure:
; (define (a-plus-abs-b a b)
;   ((if (> b 0) + -) a b))



; [solution] =>
(define (a-plus-abs-b a b)
    ((if (> b 0) + -) a b))

(and (= 3 (a-plus-abs-b 1 (- 2))) (= 5 (a-plus-abs-b 2 (- 3))) (= 7 (a-plus-abs-b 3 (- 4))))


; note:
; this procedure returns the sum of the "a" parameter and the absolute value of the "b" parameter
