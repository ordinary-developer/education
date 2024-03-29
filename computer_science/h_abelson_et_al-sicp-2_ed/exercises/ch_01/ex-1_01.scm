#lang sicp

; [exercise] ->
; Below is a sequence of expressions.
; What is the result printed by the interpreter
; to each exression?
; Assume that the sequence is to be evaluated
; in the order which it is presented
;
; 10
; (+ 5 3 4)
; (- 9 1)
; (/ 6 2)
; (+ (* 2 4) (- 4 6))
; (define a 3)
; (define b (+ a 1))
; (+ a b (* a b))
; (= a b)
; (if (and (> b a) (< b (* a b)))
;     b
;     a)
;
; (cond ((= a 4) 6)
;       ((= b 4) (+ 6 7 a))
;       (else 25))
;
; (+ 2 (if (> b a) b a))
;
; (* (cond ((> a b) a)
;          ((< a b) b)
;          (else -1))
;    (+ a 1))



; [solution] ->
10
(+ 5 3 4)
(- 9 1)
(/ 6 2)
(+ (* 2 4) (- 4 6))

(define a 3)
(define b (+ a 1))
(+ a b (* a b))
(= a b)
(if (and (> b a) (< b (* a b)))
    b
    a)
    
(cond ((= a 4) 6)
      ((= b 4) (+ 6 7 a))
      (else 25))

(+ 2 (if (> b a) b a))

(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1))
