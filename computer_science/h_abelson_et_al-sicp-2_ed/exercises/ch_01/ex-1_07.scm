#lang sicp

; [exercise] =>
; The `good-enough?` test used in computing square roots
; will not be very effective
; for finding the square roots of very small numbers.
; Also, in real computers, arithmetic operations
; are almost always performed with limited precision.
; This makes our test inadequate for very large numbers.
; Explain these statements, with examples
; showing how the test fail for small and large numbers.
; An alternative strategy for implementing `good-enough?`
; is to watch how `guess` changes from one iteration to the next
; and to stop when the change is a very small fraction of the guess.
; Design a square-root procedure that uses this kind of end test.
; Does this work better for small and large numbers.

; -------------
; [solution] =>

; default (from the tutorial) solution
(define (int-power-iter x exponent accumulator)
    (if (= exponent 0) 
        accumulator
        (int-power-iter x (- exponent 1) (* accumulator x))))
(define (int-power x exponent)
    (int-power-iter x exponent 1))


(define k-epsilon (/ 1 (int-power 10 100)))

(define (default-sqrt-iter guess x)
    (if (default-good-enough? guess x)
        guess
        (default-sqrt-iter (default-improve guess x) x)))

(define (default-improve guess x)
    (default-average guess (/ x guess)))

(define (default-average x y)
    (/ (+ x y) 2))

(define (default-good-enough? guess x)
    (< (abs (- (default-square guess) x)) k-epsilon))

(define (default-square x) (* x x))

(define (default-sqrt x)
    (default-sqrt-iter 1.0 x))


; tests for the default solution
(display "base test #1: ") (default-sqrt (* 17 17))
(display "base test #2: ") (default-sqrt(* 42 42))
(newline)

; will run infinitely     
; (sqrt (/ 9 (int-power 10 5)))     

; will run infinitely
; (sqrt (int-power 10 29))


; new solution
(define (sqrt-iter-02 guess x prev-guess)
    (if (good-enough-02? guess x prev-guess)
        guess
        (sqrt-iter-02 (improve-02 guess x) x guess)))

(define (improve-02 guess x)
    (average-02 guess (/ x guess)))

(define (average-02 x y)
    (/ (+ x y) 2))
    
(define (good-enough-02? guess x prev-guess)
    (if (> (/ (abs (- guess prev-guess)) guess) k-epsilon)
        (< (abs (- (square-02 guess) x)) k-epsilon) 
        #t))

(define (square-02 x) (* x x))

(define (sqrt-02 x)
    (sqrt-iter-02 1.0 x 0.0))

; tests for a new solution
(display "test #1: ") (sqrt-02 (/ 9 (int-power 10 5)))    
(display "test #2: ") (sqrt-02 (int-power 10 29))
