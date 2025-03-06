#lang sicp

; [exercise] =>
; Define a procedure that takes three numbers
; as arguments and returns the sum of the squares of the two
; larger numbers



; [solution] =>
(define (sum-of-squares-of-two-max param1 param2 param3)
    (define (min2 p1 p2) (if (< p1 p2) p1 p2))    
    (define (max2 p1 p2) (if (> p1 p2) p1 p2))

    (define (first-max p1 p2 p3) (max2 (max2 p1 p2) p3))
    (define (second-max p1 p2 p3)
        (- (+ p1 p2 p3) (first-max p1 p2 p3) (min2 (min2 p1 p2) p3)))

    (define (square p) (* p p))

    (+ (square (first-max param1 param2 param3)) (square (second-max param1 param2 param3))))

(define assert (= 5
                  (sum-of-squares-of-two-max 0 1 2)
                  (sum-of-squares-of-two-max 0 2 1)
                  (sum-of-squares-of-two-max 1 0 2)
                  (sum-of-squares-of-two-max 1 2 0)
                  (sum-of-squares-of-two-max 2 0 1)
                  (sum-of-squares-of-two-max 2 1 0)))
assert
