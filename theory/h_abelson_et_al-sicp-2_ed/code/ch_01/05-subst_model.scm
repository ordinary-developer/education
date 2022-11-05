#lang sicp

(display "=> Applicative order versus normal order")(newline)

;; # Applicative-order evaluation ("evaluate the arguments and then apply")
;; The interpreter first evaluates the operator and operands
;; and then applies the resulting arguments.
;; Lisp uses applicative-order evaluation.

;; # Normal-order evaluation ("fully expand and then reduce")
;; The interpreter will first substitute operand expressions for parameters
;; until it obtain an expression involving only primitive operators,
;; and will then perform the evaluation.
;; (The interpreter will not evaluate the operands
;; until their values were needed).

(define (square x) (* x x))
(define (sum-of-squares x y)
    (+ (square x) (square y)))
(define (f a)
    (sum-of-squares (+ a 1) (* a 2)))
(define a 5)
    
;; Applicative-order
(f a)
(sum-of-squares (+ a 1) (* a 2))
(sum-of-squares (+ 5 1) (* 5 2))
(sum-of-squares 6 10)
(+ (square 6) (square 10))
(+ (* 6 6) (* 10 10))
(+ 36 100)
136

;; Normal-order
(f a)
(sum-of-squares (+ a 1) (* a 2))
(sum-of-squares (+ 5 1) (* 5 2))
(+ (square (+ 5 1)) (square (* 5 2)))
(+ (* (+ 5 1) (+ 5 1)) (* (* 5 2) (* 5 2)))
(+ (* 6 6) (* 10 10))
(+ 36 100)
136
