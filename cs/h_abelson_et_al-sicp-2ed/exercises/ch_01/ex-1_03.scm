#lang sicp

; [exercise] =>
; Define a procedure that takes three numbers
; as arguments and returns the sum of the squares of the two
; larger numbers



; [solution] =>
(define (square x) (* x x))
(and (= 4 (square 2)) (= 9 (square 3)) (= 16 (square 4)))

(define (sum-of-squares x y) (+ (square x) (square y)))
(and (= 5 (sum-of-squares 1 2)) (= 13 (sum-of-squares 2 3)) (= 25 (sum-of-squares 3 4)))

(define (max2 x y) (if (> x y) x y))
(and (= 2 (max2 1 2)) (= 3 (max2 2 3)) (= 4 (max2 3 4)))

(define (max3 x y z) (max2 x (max2 y z)))
(and (= 3 (max3 1 2 3)) (= 4 (max3 2 3 4)) (= 5 (max3 3 4 5)))

(define (min2 x y) (if (< x y) x y))
(and (= 1 (min2 1 2)) (= 2 (min2 2 3)) (= 3 (min2 3 4)))

(define (min3 x y z) (min2 x (min2 y z)))
(and (= 1 (min3 1 2 3)) (= 2 (min3 2 3 4)) (= 3 (min3 3 4 5)))

(define (first-largest x y z) (max3 x y z))
(and (= 3 (first-largest 1 2 3)) (= 4 (first-largest 2 3 4)) (= 5 (first-largest 3 4 5)))

(define (second-largest x y z) (- (+ x y z) (max3 x y z) (min3 x y z)))
(and (= 2 (second-largest 1 2 3)) (= 3 (second-largest 2 3 4)) (= 4 (second-largest 3 4 5)))


(define (f x y z)
    (sum-of-squares (first-largest x y z) (second-largest x y z)))
(and (= 13 (f 1 2 3)) (= 25 (f 2 3 4)) (= 41 (f 3 4 5)))
