#lang sicp

; [exercise] =>
; Observe that our model of evaluation allows for combinations
; whose operators are compound expressions.
; Use this observaration to describe the behavior
; of the following procedure
; (define (a-plus-abs-b a b)
;   ((if (> b 0) + -) a b))     



; -------------
; [solution] =>
(define (a-plus-abs-b a b)
    ((if (> b 0) + -) a b))

(define assert (= 3
                  (a-plus-abs-b 1 2)
                  (a-plus-abs-b 1 (- 2))
                  (a-plus-abs-b 3 0)))
assert

; Note:
; This procedure returns the sum of the "a" parameter and the absolute value of the "b" parameter.
